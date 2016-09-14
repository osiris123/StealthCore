/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#ifndef DEF_SHADOW_LABYRINTH_H
#define DEF_SHADOW_LABYRINTH_H

enum slData
{
	TYPE_OVERSEER					= 0,
	TYPE_HELLMAW					= 1,
	DATA_BLACKHEARTTHEINCITEREVENT	= 2,
	DATA_GRANDMASTERVORPILEVENT		= 3,
	DATA_MURMUREVENT				= 4,
	MAX_ENCOUNTER					= 5
};

enum slNPCandGO
{
	NPC_FEL_OVERSEER			= 18796,
	NPC_HELLMAW					= 18731,

	REFECTORY_DOOR				= 183296,                     //door opened when blackheart the inciter dies
	SCREAMING_HALL_DOOR			= 183295                      //door opened when grandmaster vorpil dies
};

#endif

