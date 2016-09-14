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

class instance_scarlet_monastery : public InstanceMapScript
{
	public:
		instance_scarlet_monastery() : InstanceMapScript("instance_scarlet_monastery", 189) { }

		InstanceScript* GetInstanceScript(InstanceMap* map) const
		{
			return new instance_scarlet_monastery_InstanceMapScript(map);
		}

		struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
		{
			instance_scarlet_monastery_InstanceMapScript(Map* map) : InstanceScript(map) {}
		};
};

void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}
