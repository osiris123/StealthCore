/*
 * Copyright (C) 2011-2016 StealthCore <http://www.stealthcoders.net/>
 *
 * A Private Project by StealthCoders. Emulator Codename: StealthCore [SC]
 *
 * Do not Share this Source. All contributors from [SC] StealthCoders, shouldn't remove any 
 * Copyright Text or notice.
 *
 */

#ifndef DEF_BRD_H
#define DEF_BRD_H

enum FactionIds
{
    FACTION_NEUTRAL            = 734,
    FACTION_HOSTILE            = 754,
    FACTION_FRIEND             = 35
};

enum DataTypes
{
    TYPE_RING_OF_LAW        = 1,
    TYPE_VAULT              = 2,
    TYPE_BAR                = 3,
    TYPE_TOMB_OF_SEVEN      = 4,
    TYPE_LYCEUM             = 5,
    TYPE_IRON_HALL          = 6,

    DATA_EMPEROR            = 10,
    DATA_PHALANX            = 11,

    DATA_ARENA1             = 12,
    DATA_ARENA2             = 13,
    DATA_ARENA3             = 14,
    DATA_ARENA4             = 15,

    DATA_GO_BAR_KEG         = 16,
    DATA_GO_BAR_KEG_TRAP    = 17,
    DATA_GO_BAR_DOOR        = 18,
    DATA_GO_CHALICE         = 19,

    DATA_GHOSTKILL          = 20,
    DATA_EVENSTARTER        = 21,

    DATA_GOLEM_DOOR_N       = 22,
    DATA_GOLEM_DOOR_S       = 23,

    DATA_THRONE_DOOR        = 24,

    DATA_SF_BRAZIER_N       = 25,
    DATA_SF_BRAZIER_S       = 26,
    DATA_MOIRA              = 27,

	DATA_OPEN_COFFER_DOORS	= 30,
};

#endif
