/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#ifndef DEF_STEAM_VAULT_H
#define DEF_STEAM_VAULT_H

enum steamVault
{
	TYPE_HYDROMANCER_THESPIA			= 0,
	TYPE_MEKGINEER_STEAMRIGGER			= 1,
	TYPE_WARLORD_KALITHRESH				= 2,
	MAX_ENCOUNTER						= 3
};

enum steamVaultNPCGO
{
	GO_MAIN_CHAMBERS_DOOR				= 183049,
	GO_ACCESS_PANEL_HYDRO				= 184125,
	GO_ACCESS_PANEL_MEK					= 184126,

	NPC_MEKGINEER_STEAMRIGGER			= 17796,
	NPC_WARLORD_KALITHRESH				= 17798,
};

#endif

