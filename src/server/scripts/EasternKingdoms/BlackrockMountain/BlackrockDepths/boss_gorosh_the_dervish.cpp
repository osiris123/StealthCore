/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_WHIRLWIND                                        = 15589,
    SPELL_MORTALSTRIKE                                     = 24573
};

class boss_gorosh_the_dervish : public CreatureScript
{
public:
    boss_gorosh_the_dervish() : CreatureScript("boss_gorosh_the_dervish") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_gorosh_the_dervishAI(creature);
    }

    struct boss_gorosh_the_dervishAI : public ScriptedAI
    {
        boss_gorosh_the_dervishAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 WhirlWind_Timer;
        uint32 MortalStrike_Timer;

        void Reset()
        {
            WhirlWind_Timer = 12000;
            MortalStrike_Timer = 22000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //WhirlWind_Timer
            if (WhirlWind_Timer <= diff)
            {
                DoCast(me, SPELL_WHIRLWIND);
                WhirlWind_Timer = 15000;
            } else WhirlWind_Timer -= diff;

            //MortalStrike_Timer
            if (MortalStrike_Timer <= diff)
            {
                DoCastVictim(SPELL_MORTALSTRIKE);
                MortalStrike_Timer = 15000;
            } else MortalStrike_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_gorosh_the_dervish()
{
    new boss_gorosh_the_dervish();
}
