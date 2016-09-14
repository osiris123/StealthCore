/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#ifndef DEF_THE_EYE_H
#define DEF_THE_EYE_H

enum EyeData
{
	DATA_ALAR				= 0,
	DATA_ASTROMANCER		= 1,
	DATA_REAVER				= 2,
	DATA_KAELTHAS			= 3,
	MAX_ENCOUNTER			= 4,

	DATA_KAEL_ADVISOR1		= 10,
	DATA_KAEL_ADVISOR2		= 11,
	DATA_KAEL_ADVISOR3		= 12,
	DATA_KAEL_ADVISOR4		= 13
};

enum EyeNPCs
{
	NPC_ALAR				= 19514,
	NPC_KAELTHAS			= 19622,
	NPC_THALADRED			= 20064,
	NPC_LORD_SANGUINAR		= 20060,
	NPC_CAPERNIAN			= 20062,
	NPC_TELONICUS			= 20063
};

enum EyeGOs
{
	GO_BRIDGE_WINDOW		= 184069,
	GO_KAEL_STATUE_RIGHT	= 184596,
	GO_KAEL_STATUE_LEFT		= 184597
};

#endif
