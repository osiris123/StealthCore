/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#include "ScriptPCH.h"
#include "Chat.h"

class arena_commandscript : public CommandScript
{
   public:
       arena_commandscript() : CommandScript("arena_commandscriptscript") { }

       ChatCommand* GetCommands() const
       {
           static ChatCommand ArenaCommand[] =
           {
               { "arena", SEC_PLAYER, false, &HandleArenaCommand, "", NULL },
               { NULL, 0, false, NULL, "", NULL }
           };
           return ArenaCommand;
       }

       static bool HandleArenaCommand(ChatHandler* handler, const char* /*args*/)
       {
           BattlegroundTypeId bgTypeId = BATTLEGROUND_AA;
           handler->GetSession()->SendBattleGroundList(handler->GetSession()->GetPlayer()->GetGUID(), bgTypeId);
           return true;
       }       
};

void AddSC_arena_commandscript()
{
new arena_commandscript();
}
