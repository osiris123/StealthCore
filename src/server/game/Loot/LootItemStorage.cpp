/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#include "LootItemStorage.h"

LootItemStorage::LootItemStorage()
{
}

LootItemStorage::~LootItemStorage()
{
}

void LootItemStorage::LoadStorageFromDB()
{
    uint32 oldMSTime = getMSTime();
	lootItemStore.clear();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEMCONTAINER_ITEMS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        sLog->outString(">>  Loaded 0 stored items!");
		sLog->outString();
        return;
    }

	uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
		
		StoredLootItemList& itemList = lootItemStore[fields[0].GetUInt32()];
		itemList.push_back(StoredLootItem(fields[1].GetUInt32(), fields[2].GetUInt32(), fields[3].GetInt32(), fields[4].GetUInt32()));

		++count;
	} while (result->NextRow());

    sLog->outString(">> Loaded %d stored items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void LootItemStorage::RemoveEntryFromDB(uint32 containerId, uint32 itemid, uint32 count)
{
	SQLTransaction trans = CharacterDatabase.BeginTransaction();
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_SINGLE_ITEM);
    stmt->setUInt32(0, containerId);
	stmt->setUInt32(1, itemid);
	stmt->setUInt32(2, count);
	trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void LootItemStorage::AddNewStoredLoot(Loot* loot, Player* player)
{
	if (lootItemStore.find(loot->containerId) != lootItemStore.end())
	{
		sLog->outMisc("LootItemStorage::AddNewStoredLoot (A1) - %u!", loot->containerId);
		return;
	}

	SQLTransaction trans = CharacterDatabase.BeginTransaction();
	PreparedStatement* stmt = NULL;

	StoredLootItemList& itemList = lootItemStore[loot->containerId];

	// Gold at first
	if (loot->gold)
	{
		itemList.push_back(StoredLootItem(0, loot->gold, 0, 0));

		stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_SINGLE_ITEM);
		stmt->setUInt32(0, loot->containerId);
		stmt->setUInt32(1, 0);
		stmt->setUInt32(2, loot->gold);
		stmt->setInt32(3, 0);
		stmt->setUInt32(4, 0);
		trans->Append(stmt);
	}

	// And normal items
	if (!loot->isLooted())
		for (LootItemList::const_iterator li = loot->items.begin(); li != loot->items.end(); li++)
		{
			if (!li->AllowedForPlayer(player))
				continue;

			const ItemTemplate* itemTemplate = sObjectMgr->GetItemTemplate(li->itemid);
			if (!itemTemplate || itemTemplate->IsCurrencyToken())
				continue;

			itemList.push_back(StoredLootItem(li->itemid, li->count, li->randomPropertyId, li->randomSuffix));

			stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_SINGLE_ITEM);
			stmt->setUInt32(0, loot->containerId);
			stmt->setUInt32(1, li->itemid);
			stmt->setUInt32(2, li->count);
			stmt->setInt32 (3, li->randomPropertyId);
			stmt->setUInt32(4, li->randomSuffix);
			trans->Append(stmt);
		}

    CharacterDatabase.CommitTransaction(trans);
}

bool LootItemStorage::LoadStoredLoot(Item* item)
{
	Loot* loot = &item->loot;
	LootItemContainer::iterator itr = lootItemStore.find(loot->containerId);
	if (itr == lootItemStore.end())
		return false;

	StoredLootItemList& itemList = itr->second;
	for (StoredLootItemList::iterator it2 = itemList.begin(); it2 != itemList.end(); ++it2)
	{
		if (it2->itemid == 0)
		{
			loot->gold = it2->count;
			continue;
		}

		LootItem li;
		li.itemid = it2->itemid;
		li.count = it2->count;
		li.follow_loot_rules = false;
		li.freeforall = false;
		li.is_blocked = false;
		li.is_counted = false;
		li.is_underthreshold = false;
		li.is_looted = false;
		li.needs_quest = false;
		li.randomPropertyId = it2->randomPropertyId;
		li.randomSuffix = it2->randomSuffix;
		li.rollWinnerGUID = 0;

		loot->items.push_back(li);
		loot->unlootedCount++;
	}

   // Mark the item if it has loot so it won't be generated again on open
   item->m_lootGenerated = true;
   return true;
}

void LootItemStorage::RemoveStoredLootItem(uint32 containerId, uint32 itemid, uint32 count)
{
	LootItemContainer::iterator itr = lootItemStore.find(containerId);
	if (itr == lootItemStore.end())
		return;

	StoredLootItemList& itemList = itr->second;
	for (StoredLootItemList::iterator it2 = itemList.begin(); it2 != itemList.end(); ++it2)
		if (it2->itemid == itemid && it2->count == count)
		{
			RemoveEntryFromDB(containerId, itemid, count);
			itemList.erase(it2);
			break;
		}

	if (itemList.empty())
		lootItemStore.erase(itr);
}

void LootItemStorage::RemoveStoredLootMoney(uint32 containerId)
{
	LootItemContainer::iterator itr = lootItemStore.find(containerId);
	if (itr == lootItemStore.end())
		return;

	StoredLootItemList& itemList = itr->second;
	for (StoredLootItemList::iterator it2 = itemList.begin(); it2 != itemList.end(); ++it2)
		if (it2->itemid == 0)
		{
			RemoveEntryFromDB(containerId, 0, it2->count);
			itemList.erase(it2);
			break;
		}

	if (itemList.empty())
		lootItemStore.erase(itr);
}

void LootItemStorage::RemoveStoredLoot(uint32 containerId)
{
	lootItemStore.erase(containerId);

	SQLTransaction trans = CharacterDatabase.BeginTransaction();
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_CONTAINER);
    stmt->setUInt32(0, containerId);
	trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}
