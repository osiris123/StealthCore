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
#include "InstanceScript.h"

class instance_the_stockade : public InstanceMapScript
{
	public:
		instance_the_stockade() : InstanceMapScript("instance_the_stockade", 34) { }

		InstanceScript* GetInstanceScript(InstanceMap* map) const
		{
			return new instance_the_stockade_InstanceMapScript(map);
		}

		struct instance_the_stockade_InstanceMapScript : public InstanceScript
		{
			instance_the_stockade_InstanceMapScript(Map* map) : InstanceScript(map) { }
		};
};

void AddSC_instance_the_stockade()
{
    new instance_the_stockade();
}
