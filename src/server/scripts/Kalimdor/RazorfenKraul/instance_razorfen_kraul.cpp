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

class instance_razorfen_kraul : public InstanceMapScript
{
	public:
		instance_razorfen_kraul() : InstanceMapScript("instance_razorfen_kraul", 47) { }

		InstanceScript* GetInstanceScript(InstanceMap* map) const
		{
			return new instance_razorfen_kraul_InstanceMapScript(map);
		}

		struct instance_razorfen_kraul_InstanceMapScript : public InstanceScript
		{
			instance_razorfen_kraul_InstanceMapScript(Map* map) : InstanceScript(map) { }
		};
};

void AddSC_instance_razorfen_kraul()
{
    new instance_razorfen_kraul();
}
