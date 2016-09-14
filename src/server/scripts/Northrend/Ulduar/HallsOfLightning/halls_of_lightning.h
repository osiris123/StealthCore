/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#ifndef DEF_HALLS_OF_LIGHTNING_H
#define DEF_HALLS_OF_LIGHTNING_H


enum HoLEvents
{
	TYPE_BJARNGRIM			= 0,
	TYPE_IONAR				= 1,
	TYPE_LOKEN				= 2,
	TYPE_VOLKHAN			= 3,
	TYPE_LOKEN_INTRO		= 4,
	MAX_ENCOUNTER			= 5,

	DATA_BJARNGRIM_ACHIEVEMENT	= 10,
	DATA_VOLKHAN_ACHIEVEMENT	= 11,
};

enum HoLNPCs
{
	NPC_BJARNGRIM			= 28586,
	NPC_VOLKHAN				= 28587,
	NPC_IONAR				= 28546,
	NPC_LOKEN				= 28923,
};

enum HoLGOs
{
	GO_BJARNGRIM_DOOR		= 191416,					   //_doors10
	GO_VOLKHAN_DOOR			= 191325,					   //_doors07
	GO_IONAR_DOOR			= 191326,					   //_doors05
	GO_LOKEN_DOOR			= 191324,					   //_doors02
	GO_LOKEN_THRONE			= 192654,
};

#endif
