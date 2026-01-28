#pragma once

#include "PatchConfig.h"
#include "Util.h"

struct lua_State;

static uint32_t dummy = 0;

static std::unordered_map<char*, void*> luaFuncts;

// enums
enum CustomSMSG
{
	CUSTOM_SMSG_BASE							= 1311,
	SMSG_UPDATE_CUSTOM_COMBAT_RATING			= CUSTOM_SMSG_BASE,
	NUM_CUSTOM_SMSG_OPCODES
};

enum CustomCMSG
{
	CMSG_TELEPORT_GRAVEYARD_REQUEST = 1410,
	CMSG_EXAMPLE_PACKET = 1411
};

enum DefaultBlizzardSMSG
{
	SMSG_SPELL_START = 305,
	SMSG_SPELL_GO	 = 306
};

enum FrameXMLEvent : uint32_t
{
	EVENT_LFG_ROLE_UPDATE                       = 506,
};

enum PlayerFlags
{
	PLAYER_FLAGS_GHOST							= 0x10,
};

enum TypeMask
{
	TYPEMASK_OBJECT								= 0x0001,
	TYPEMASK_ITEM								= 0x0002,
	TYPEMASK_CONTAINER							= 0x0004,
	TYPEMASK_UNIT								= 0x0008,
	TYPEMASK_PLAYER								= 0x0010,
	TYPEMASK_GAMEOBJECT							= 0x0020,
	TYPEMASK_DYNAMICOBJECT						= 0x0040,
	TYPEMASK_CORPSE								= 0x0080,
};

// structures
struct C2Vector
{
	float x;
	float y;
};

struct C3Vector
{
	float x;
	float y;
	float z;
};

struct CDataStore_vTable
{
	uint32_t padding0x00[6];
	void* IsRead;
	uint32_t padding0x1C[3];
};

struct CDataStore
{
	CDataStore_vTable* vTable;
	int32_t* m_buffer;
	int32_t m_base;
	int32_t m_alloc;
	int32_t m_size;
	int32_t m_read;
};

struct CMovement
{
	uint32_t padding0x00[4];
	C3Vector position;
	float padding0x1C;
	float orientation;
	float pitch;
	uint32_t padding28[7];
	uint32_t movementFlags;
	uint32_t movementFlags2;
	uint32_t padding0x4C[63];
};

struct UnitBytes0
{
	uint8_t unitRace;
	uint8_t unitClass;
	uint8_t unitGender;
	uint8_t unitPowerType;
};

struct UnitFields
{
	uint32_t padding0x00[17];
	UnitBytes0 bytes0;
	uint32_t padding0x48[30];
	uint32_t level;
	uint32_t padding0xC4[93];
};

struct CGUnit
{
	uint32_t padding0x00[52];
	UnitFields* unitFields;
	uint32_t padding0xD4;
	CMovement* movementInfo;
	uint32_t padding0x34[971];
};

struct PlayerFields
{
	uint64_t playerDuelArbiter;
	uint32_t playerFlags;
	uint32_t padding0x0C[1175];
};

struct CGPlayer
{
	CGUnit unitData;
	PlayerFields* playerData;
	uint32_t padding0x1008[1024];
};

struct ChrClassesRow
{
	uint32_t m_ID;
	uint32_t padding0x04[13];
};

struct CustomNetClient
{
	void* handler[NUM_CUSTOM_SMSG_OPCODES - CUSTOM_SMSG_BASE];
	void* handlerParam[NUM_CUSTOM_SMSG_OPCODES - CUSTOM_SMSG_BASE];
};

struct MapRow
{
	uint32_t m_ID;
	char* m_Directory;
	uint32_t padding0x08[17];
};

struct SpellRow
{
	uint32_t m_ID;
	uint32_t padding0x04[135];
	char* m_name_lang;
	char* m_nameSubtext_lang;
	char* m_description_lang;
	char* m_auraDescription_lang;
	uint32_t padding0x230[30];
};


struct SpellVisualRec
{
	int32_t m_ID;
	int32_t m_precastKit;
	int32_t m_castKit;
	int32_t m_impactKit;
	int32_t m_stateKit;
	int32_t m_stateDoneKit;
	int32_t m_channelKit;
	int32_t m_hasMissile;
	int32_t m_missileModel;
	int32_t m_missilePathType;
	int32_t m_missileDestinationAttachment;
	int32_t m_missileSound;
	int32_t m_animEventSoundID;
	int32_t m_flags;
	int32_t m_casterImpactKit;
	int32_t m_targetImpactKit;
	int32_t m_missileAttachment;
	int32_t m_missileFollowGroundHeight;
	int32_t m_missileFollowGroundDropSpeed;
	int32_t m_missileFollowGroundApproach;
	int32_t m_missileFollowGroundFlags;
	int32_t m_missileMotion;
	int32_t m_missileTargetingKit;
	int32_t m_instantAreaKit;
	int32_t m_impactAreaKit;
	int32_t m_persistentAreaKit;
	float m_missileCastOffset[3];
	float m_missileImpactOffset[3];
};

struct SpellVisualKitRec
{
	int32_t m_ID;
	int32_t m_startAnimID;
	int32_t m_animID;
	int32_t m_headEffect;
	int32_t m_chestEffect;
	int32_t m_baseEffect;
	int32_t m_leftHandEffect;
	int32_t m_rightHandEffect;
	int32_t m_breathEffect;
	int32_t m_leftWeaponEffect;
	int32_t m_rightWeaponEffect;
	int32_t m_specialEffect[3];
	int32_t m_worldEffect;
	int32_t m_soundID;
	int32_t m_shakeID;
	int32_t m_charProc[4];
	float m_charParamZero[4];
	float m_charParamOne[4];
	float m_charParamTwo[4];
	float m_charParamThree[4];
	int32_t m_flags;
};

// Aleist3r: afaik it's not a full structure but I don't need the rest defined
struct WoWTime
{
	int32_t minute;
	int32_t hour;
	int32_t weekDay;
	int32_t monthDay;
	int32_t month;
	int32_t year;
	int32_t flags;
};

struct ZoneLightData
{
	int32_t mapID;
	int32_t lightID;
	void* pointData;
	int32_t pointNum;
	float minX;
	float minY;
	float maxX;
	float maxY;
};

// Client functions
namespace CDataStore_C
{
	CLIENT_FUNCTION(GenPacket, 0x401050, __thiscall, void, (CDataStore*))
	CLIENT_FUNCTION(GetInt8, 0x47B340, __thiscall, void, (CDataStore*, int8_t*))
	CLIENT_FUNCTION(PutInt8, 0x47AFE0, __thiscall, void, (CDataStore*, int8_t))
	CLIENT_FUNCTION(GetInt16, 0x47B380, __thiscall, void, (CDataStore*, int16_t*))
	CLIENT_FUNCTION(PutInt16, 0x47AFE0, __thiscall, void, (CDataStore*, int16_t))
	CLIENT_FUNCTION(GetInt32, 0x47B3C0, __thiscall, void, (CDataStore*, int32_t*))
	CLIENT_FUNCTION(PutInt32, 0x47B0A0, __thiscall, void, (CDataStore*, int32_t))
	CLIENT_FUNCTION(GetInt64, 0x47B400, __thiscall, void, (CDataStore*, int64_t*))
	CLIENT_FUNCTION(GetCString, 0x47B480, __thiscall, void, (CDataStore*, char*, int32_t))
	CLIENT_FUNCTION(PutCString, 0x47B300, __thiscall, void, (CDataStore*, char* string))
	CLIENT_FUNCTION(Release, 0x403880, __thiscall, void, (CDataStore*))
	CLIENT_FUNCTION(PutPackedGuid, 0x76DD00, __cdecl, void, (CDataStore*, int64_t))			// Not tested yet, just implemented.
	CLIENT_FUNCTION(GetWoWGuid, 0x76DC20, __cdecl, void, (CDataStore*, int64_t*))
}

namespace CGChat
{
	CLIENT_FUNCTION(AddChatMessage, 0x509DD0, __cdecl, bool, (char*, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t, char*, uint64_t, uint32_t, uint64_t, uint32_t, uint32_t, uint32_t*))
}

namespace CGPlayer_C
{
	CLIENT_FUNCTION(IsDeadOrGhost, 0x6DAC10, __thiscall, bool, (CGPlayer*))
}

namespace CGUnit_C
{
	CLIENT_FUNCTION(GetShapeshiftFormId, 0x71AF70, __thiscall, uint32_t, (CGUnit*))
}

namespace ClientDB
{
	CLIENT_FUNCTION(GetSpellVisualRow, 0x007FA290, __cdecl, SpellVisualRec*, (void*))
	CLIENT_FUNCTION(GetLocalizedRow, 0x4CFD20, __thiscall, int, (void*, uint32_t, void*))
	CLIENT_FUNCTION(GetRow, 0x65C290, __thiscall, void*, (void*, uint32_t))
	CLIENT_FUNCTION(GetGameTableValue, 0x7F6990, __cdecl, double, (uint32_t, uint32_t, uint32_t)) // this technically is not a part of ClientDB iirc but who cares
}

namespace ClientPacket
{
	CLIENT_FUNCTION(MSG_SET_ACTION_BUTTON, 0x5AA390, __cdecl, void, (uint32_t, bool, bool))
}

namespace ClientServices
{
	CLIENT_FUNCTION(InitializePlayer, 0x6E83B0, __cdecl, void, ())
	CLIENT_FUNCTION(SendPacket, 0x6B0B50, __cdecl, void, (CDataStore*))
	CLIENT_FUNCTION(GetCharacterClass, 0x6B1080, __cdecl, uint8_t, ())
}

namespace ClntObjMgr
{
	CLIENT_FUNCTION(GetActivePlayer, 0x4D3790, __cdecl, uint64_t, ())
	CLIENT_FUNCTION(ObjectPtr, 0x4D4DB0, __cdecl, void*, (uint64_t, uint32_t))
}

namespace CNetClient
{
	CLIENT_FUNCTION(ProcessMessage, 0x631FE0, __thiscall, int, (void*, uint32_t, CDataStore*, uint32_t))
	CLIENT_FUNCTION(SetMessageHandler, 0x631FA0, __thiscall, void, (void*, uint32_t, void*, void*))
}

namespace CVar
{
	CLIENT_FUNCTION(sub_766940, 0x766940, __thiscall, void, (void*, int, char, char, char, char))
	CLIENT_FUNCTION(SetCvar, 0x76C9C0, __thiscall, void, (void* cvar, const char* value, bool setDirty, bool, bool, bool forceUpdate))
	CLIENT_FUNCTION(LookupCvar, 0x767460, __cdecl, void*, (const char* name))
}

namespace DNInfo
{
	CLIENT_FUNCTION(AddZoneLight, 0x7ED150, __thiscall, void, (void*, int32_t, float))
	CLIENT_FUNCTION(GetDNInfoPtr, 0x7ECEF0, __stdcall, void*, ())
}

namespace FrameScript
{
	CLIENT_FUNCTION(DisplayError, 0x84F280, __cdecl, void, (lua_State* L, char*, ...))
	CLIENT_FUNCTION(GetNumber, 0x84E030, __cdecl, double, (lua_State*, int32_t))   // Also known as tonumber.
	CLIENT_FUNCTION(GetParam, 0x815500, __cdecl, bool, (lua_State*, int, int))
	CLIENT_FUNCTION(ToLString, 0x84E0E0, __cdecl, char*, (lua_State*, int, bool))	// Also known as GetString
	CLIENT_FUNCTION(IsString, 0x84DF60, __cdecl, char*, (lua_State*, int))
	CLIENT_FUNCTION(IsNumber, 0x84DF20, __cdecl, int32_t, (lua_State*, int32_t))
	CLIENT_FUNCTION(LoadFunctions, 0x5120E0, __cdecl, int, ())
	CLIENT_FUNCTION(PushBoolean, 0x84E4D0, __cdecl, int, (lua_State* L, bool))
	CLIENT_FUNCTION(PushNil, 0x84E280, __cdecl, int, (lua_State*))
	CLIENT_FUNCTION(GetTop, 0x84DBD0, __cdecl, int, (lua_State* L, int))
	CLIENT_FUNCTION(SetTop, 0x84DBF0, __cdecl, int, (lua_State* L, int))
	CLIENT_FUNCTION(PushNumber, 0x84E2A0, __cdecl, int, (lua_State* L, double value))
	CLIENT_FUNCTION(PushString, 0x84E350, __cdecl, int, (lua_State*, char const*))
	CLIENT_FUNCTION(RegisterFunction, 0x817F90, __cdecl, int, (char*, void*))
	CLIENT_FUNCTION(SignalEvent, 0x81B530, __cdecl, int, (uint32_t, char*, ...))
}

namespace NTempest
{
	CLIENT_FUNCTION(DistanceSquaredFromEdge, 0x7F9C90, __cdecl, bool, (int32_t, void*, C2Vector*, float*))
}

namespace SErr
{
	CLIENT_FUNCTION(PrepareAppFatal, 0x772A80, _cdecl, void, (uint32_t, const char*, ...))
}

namespace SFile
{
	// Defs cherrypicked from StormLib: https://github.com/ladislav-zezula/StormLib
	CLIENT_FUNCTION(OpenFileEx, 0x424B50, __stdcall, bool, (HANDLE, const char*, uint32_t, HANDLE*))
	CLIENT_FUNCTION(ReadFile, 0x422530, __stdcall, bool, (HANDLE handle /*likely a handle*/, void* data, uint32_t bytesToRead, uint32_t* bytesRead, uint32_t* overlap /*just set to 0*/, uint32_t unk))
	CLIENT_FUNCTION(CloseFile, 0x422910, __stdcall, void, (HANDLE a1))
}

namespace SMem
{
	CLIENT_FUNCTION(Alloc, 0x76E540, __stdcall, void*, (uint32_t, const char*, uint32_t, uint32_t))
	CLIENT_FUNCTION(Free, 0x76E5A0, __stdcall, bool, (void*, const char*, uint32_t, uint32_t))
}

namespace SpellParser
{
	CLIENT_FUNCTION(ParseText, 0x57ABC0, __cdecl, void, (void*, void*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))
}

namespace SStr
{
	CLIENT_FUNCTION(Printf, 0x76F070, __cdecl, int, (char*, uint32_t, char*, ...))
}

namespace World
{
	CLIENT_FUNCTION(LoadMap, 0x781430, __cdecl, void, (char*, C3Vector*, uint32_t))
	CLIENT_FUNCTION(UnloadMap, 0x783180, __cdecl, void, ())
	CLIENT_FUNCTION(Pos3Dto2D, 0x4F6D20, __fastcall, int, (void* This, void* edx, C3Vector* pos3d, C3Vector* pos2d, uint32_t* flags))
}


#pragma region UpdateFields

enum EUnitFlags : uint32_t {
	UNIT_FLAG_SERVER_CONTROLLED = 0x00000001,           // set only when unit movement is controlled by server - by SPLINE/MONSTER_MOVE packets, together with UNIT_FLAG_STUNNED; only set to units controlled by client; client function CGUnit_C::IsClientControlled returns false when set for owner
	UNIT_FLAG_NON_ATTACKABLE = 0x00000002,           // not attackable, set when creature starts to cast spells with SPELL_EFFECT_SPAWN and cast time, removed when spell hits caster, original name is UNIT_FLAG_SPAWNING. Rename when it will be removed from all scripts
	UNIT_FLAG_REMOVE_CLIENT_CONTROL = 0x00000004,           // This is a legacy flag used to disable movement player's movement while controlling other units, SMSG_CLIENT_CONTROL replaces this functionality clientside now. CONFUSED and FLEEING flags have the same effect on client movement asDISABLE_MOVE_CONTROL in addition to preventing spell casts/autoattack (they all allow climbing steeper hills and emotes while moving)
	UNIT_FLAG_PLAYER_CONTROLLED = 0x00000008,           // controlled by player, use _IMMUNE_TO_PC instead of _IMMUNE_TO_NPC
	UNIT_FLAG_RENAME = 0x00000010,
	UNIT_FLAG_PREPARATION = 0x00000020,           // don't take reagents for spells with SPELL_ATTR5_NO_REAGENT_WHILE_PREP
	UNIT_FLAG_UNK_6 = 0x00000040,
	UNIT_FLAG_NOT_ATTACKABLE_1 = 0x00000080,           // ?? (UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE
	UNIT_FLAG_IMMUNE_TO_PC = 0x00000100,           // disables combat/assistance with PlayerCharacters (PC) - see Unit::IsValidAttackTarget, Unit::IsValidAssistTarget
	UNIT_FLAG_IMMUNE_TO_NPC = 0x00000200,           // disables combat/assistance with NonPlayerCharacters (NPC) - see Unit::IsValidAttackTarget, Unit::IsValidAssistTarget
	UNIT_FLAG_LOOTING = 0x00000400,           // loot animation
	UNIT_FLAG_PET_IN_COMBAT = 0x00000800,           // on player pets: whether the pet is chasing a target to attack || on other units: whether any of the unit's minions is in combat
	UNIT_FLAG_PVP_ENABLING = 0x00001000,           // changed in 3.0.3, now UNIT_BYTES_2_OFFSET_PVP_FLAG from UNIT_FIELD_BYTES_2
	UNIT_FLAG_SILENCED = 0x00002000,           // silenced, 2.1.1
	UNIT_FLAG_CANT_SWIM = 0x00004000,           // TITLE Can't Swim
	UNIT_FLAG_CAN_SWIM = 0x00008000,           // TITLE Can Swim DESCRIPTION shows swim animation in water
	UNIT_FLAG_NON_ATTACKABLE_2 = 0x00010000,           // removes attackable icon, if on yourself, cannot assist self but can cast TARGET_SELF spells - added by SPELL_AURA_MOD_UNATTACKABLE
	UNIT_FLAG_PACIFIED = 0x00020000,           // 3.0.3 ok
	UNIT_FLAG_STUNNED = 0x00040000,           // 3.0.3 ok
	UNIT_FLAG_IN_COMBAT = 0x00080000,
	UNIT_FLAG_ON_TAXI = 0x00100000,           // disable casting at client side spell not allowed by taxi flight (mounted?), probably used with 0x4 flag
	UNIT_FLAG_DISARMED = 0x00200000,           // 3.0.3, disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.
	UNIT_FLAG_CONFUSED = 0x00400000,
	UNIT_FLAG_FLEEING = 0x00800000,
	UNIT_FLAG_POSSESSED = 0x01000000,           // under direct client control by a player (possess or vehicle)
	UNIT_FLAG_UNINTERACTIBLE = 0x02000000,
	UNIT_FLAG_SKINNABLE = 0x04000000,
	UNIT_FLAG_MOUNT = 0x08000000,
	UNIT_FLAG_UNK_28 = 0x10000000,
	UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT = 0x20000000,   // Prevent automatically playing emotes from parsing chat text, for example "lol" in /say, ending message with ? or !, or using /yell
	UNIT_FLAG_SHEATHE = 0x40000000,
	UNIT_FLAG_IMMUNE = 0x80000000,           // Immune to damage

	UNIT_FLAG_DISALLOWED = (UNIT_FLAG_SERVER_CONTROLLED | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL |
		UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_RENAME | UNIT_FLAG_PREPARATION | /* UNIT_FLAG_UNK_6 | */
		UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_LOOTING | UNIT_FLAG_PET_IN_COMBAT | UNIT_FLAG_PVP_ENABLING |
		UNIT_FLAG_SILENCED | UNIT_FLAG_NON_ATTACKABLE_2 | UNIT_FLAG_PACIFIED | UNIT_FLAG_STUNNED |
		UNIT_FLAG_IN_COMBAT | UNIT_FLAG_ON_TAXI | UNIT_FLAG_DISARMED | UNIT_FLAG_CONFUSED | UNIT_FLAG_FLEEING |
		UNIT_FLAG_POSSESSED | UNIT_FLAG_SKINNABLE | UNIT_FLAG_MOUNT | UNIT_FLAG_UNK_28 |
		UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT | UNIT_FLAG_SHEATHE | UNIT_FLAG_IMMUNE), // SKIP

	UNIT_FLAG_ALLOWED = (0xFFFFFFFF & ~UNIT_FLAG_DISALLOWED) // SKIP
};

enum ETypeID
{
	TYPEID_OBJECT = 0,
	TYPEID_ITEM = 1,
	TYPEID_CONTAINER = 2,
	TYPEID_UNIT = 3,
	TYPEID_PLAYER = 4,
	TYPEID_GAMEOBJECT = 5,
	TYPEID_DYNAMICOBJECT = 6,
	TYPEID_CORPSE = 7,
	NUM_TYPEIDS = 8
};

enum EObjectFields
{
	OBJECT_FIELD_GUID = 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
	OBJECT_FIELD_TYPE = 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
	OBJECT_FIELD_ENTRY = 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
	OBJECT_FIELD_SCALE_X = 0x0004, // Size: 1, Type: FLOAT, Flags: PUBLIC
	OBJECT_FIELD_PADDING = 0x0005, // Size: 1, Type: INT, Flags: NONE
	OBJECT_END = 0x0006,
};

enum EGameObjectFields
{
	OBJECT_FIELD_CREATED_BY = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
	GAMEOBJECT_DISPLAYID = OBJECT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
	GAMEOBJECT_FLAGS = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
	GAMEOBJECT_PARENTROTATION = OBJECT_END + 0x0004, // Size: 4, Type: FLOAT, Flags: PUBLIC
	GAMEOBJECT_DYNAMIC = OBJECT_END + 0x0008, // Size: 1, Type: TWO_SHORT, Flags: DYNAMIC
	GAMEOBJECT_FACTION = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
	GAMEOBJECT_LEVEL = OBJECT_END + 0x000A, // Size: 1, Type: INT, Flags: PUBLIC
	GAMEOBJECT_BYTES_1 = OBJECT_END + 0x000B, // Size: 1, Type: BYTES, Flags: PUBLIC
	GAMEOBJECT_END = OBJECT_END + 0x000C,
};

enum EGameobjectTypes
{
	GAMEOBJECT_TYPE_DOOR = 0,
	GAMEOBJECT_TYPE_BUTTON = 1,
	GAMEOBJECT_TYPE_QUESTGIVER = 2,
	GAMEOBJECT_TYPE_CHEST = 3,
	GAMEOBJECT_TYPE_BINDER = 4,
	GAMEOBJECT_TYPE_GENERIC = 5,
	GAMEOBJECT_TYPE_TRAP = 6,
	GAMEOBJECT_TYPE_CHAIR = 7,
	GAMEOBJECT_TYPE_SPELL_FOCUS = 8,
	GAMEOBJECT_TYPE_TEXT = 9,
	GAMEOBJECT_TYPE_GOOBER = 10,
	GAMEOBJECT_TYPE_TRANSPORT = 11,
	GAMEOBJECT_TYPE_AREADAMAGE = 12,
	GAMEOBJECT_TYPE_CAMERA = 13,
	GAMEOBJECT_TYPE_MAP_OBJECT = 14,
	GAMEOBJECT_TYPE_MO_TRANSPORT = 15,
	GAMEOBJECT_TYPE_DUEL_ARBITER = 16,
	GAMEOBJECT_TYPE_FISHINGNODE = 17,
	GAMEOBJECT_TYPE_SUMMONING_RITUAL = 18,
	GAMEOBJECT_TYPE_MAILBOX = 19,
	GAMEOBJECT_TYPE_DO_NOT_USE = 20,
	GAMEOBJECT_TYPE_GUARDPOST = 21,
	GAMEOBJECT_TYPE_SPELLCASTER = 22,
	GAMEOBJECT_TYPE_MEETINGSTONE = 23,
	GAMEOBJECT_TYPE_FLAGSTAND = 24,
	GAMEOBJECT_TYPE_FISHINGHOLE = 25,
	GAMEOBJECT_TYPE_FLAGDROP = 26,
	GAMEOBJECT_TYPE_MINI_GAME = 27,
	GAMEOBJECT_TYPE_DO_NOT_USE_2 = 28,
	GAMEOBJECT_TYPE_CAPTURE_POINT = 29,
	GAMEOBJECT_TYPE_AURA_GENERATOR = 30,
	GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY = 31,
	GAMEOBJECT_TYPE_BARBER_CHAIR = 32,
	GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING = 33,
	GAMEOBJECT_TYPE_GUILD_BANK = 34,
	GAMEOBJECT_TYPE_TRAPDOOR = 35
};

enum EUnitFields
{
	UNIT_FIELD_CHARM = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_FIELD_SUMMON = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_FIELD_CRITTER = OBJECT_END + 0x0004, // Size: 2, Type: LONG, Flags: PRIVATE
	UNIT_FIELD_CHARMEDBY = OBJECT_END + 0x0006, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_FIELD_SUMMONEDBY = OBJECT_END + 0x0008, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_FIELD_CREATEDBY = OBJECT_END + 0x000A, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_FIELD_TARGET = OBJECT_END + 0x000C, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_FIELD_CHANNEL_OBJECT = OBJECT_END + 0x000E, // Size: 2, Type: LONG, Flags: PUBLIC
	UNIT_CHANNEL_SPELL = OBJECT_END + 0x0010, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_BYTES_0 = OBJECT_END + 0x0011, // Size: 1, Type: BYTES, Flags: PUBLIC
	UNIT_FIELD_HEALTH = OBJECT_END + 0x0012, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER1 = OBJECT_END + 0x0013, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER2 = OBJECT_END + 0x0014, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER3 = OBJECT_END + 0x0015, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER4 = OBJECT_END + 0x0016, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER5 = OBJECT_END + 0x0017, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER6 = OBJECT_END + 0x0018, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER7 = OBJECT_END + 0x0019, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXHEALTH = OBJECT_END + 0x001A, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER1 = OBJECT_END + 0x001B, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER2 = OBJECT_END + 0x001C, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER3 = OBJECT_END + 0x001D, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER4 = OBJECT_END + 0x001E, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER5 = OBJECT_END + 0x001F, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER6 = OBJECT_END + 0x0020, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MAXPOWER7 = OBJECT_END + 0x0021, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER = OBJECT_END + 0x0022, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER = OBJECT_END + 0x0029, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_LEVEL = OBJECT_END + 0x0030, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_FACTIONTEMPLATE = OBJECT_END + 0x0031, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_VIRTUAL_ITEM_SLOT_ID = OBJECT_END + 0x0032, // Size: 3, Type: INT, Flags: PUBLIC
	UNIT_FIELD_FLAGS = OBJECT_END + 0x0035, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_FLAGS_2 = OBJECT_END + 0x0036, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_AURASTATE = OBJECT_END + 0x0037, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_BASEATTACKTIME = OBJECT_END + 0x0038, // Size: 2, Type: INT, Flags: PUBLIC
	UNIT_FIELD_RANGEDATTACKTIME = OBJECT_END + 0x003A, // Size: 1, Type: INT, Flags: PRIVATE
	UNIT_FIELD_BOUNDINGRADIUS = OBJECT_END + 0x003B, // Size: 1, Type: FLOAT, Flags: PUBLIC
	UNIT_FIELD_COMBATREACH = OBJECT_END + 0x003C, // Size: 1, Type: FLOAT, Flags: PUBLIC
	UNIT_FIELD_DISPLAYID = OBJECT_END + 0x003D, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_NATIVEDISPLAYID = OBJECT_END + 0x003E, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MOUNTDISPLAYID = OBJECT_END + 0x003F, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_MINDAMAGE = OBJECT_END + 0x0040, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
	UNIT_FIELD_MAXDAMAGE = OBJECT_END + 0x0041, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
	UNIT_FIELD_MINOFFHANDDAMAGE = OBJECT_END + 0x0042, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
	UNIT_FIELD_MAXOFFHANDDAMAGE = OBJECT_END + 0x0043, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
	UNIT_FIELD_BYTES_1 = OBJECT_END + 0x0044, // Size: 1, Type: BYTES, Flags: PUBLIC
	UNIT_FIELD_PETNUMBER = OBJECT_END + 0x0045, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_PET_NAME_TIMESTAMP = OBJECT_END + 0x0046, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_PETEXPERIENCE = OBJECT_END + 0x0047, // Size: 1, Type: INT, Flags: OWNER
	UNIT_FIELD_PETNEXTLEVELEXP = OBJECT_END + 0x0048, // Size: 1, Type: INT, Flags: OWNER
	UNIT_DYNAMIC_FLAGS = OBJECT_END + 0x0049, // Size: 1, Type: INT, Flags: DYNAMIC
	UNIT_MOD_CAST_SPEED = OBJECT_END + 0x004A, // Size: 1, Type: FLOAT, Flags: PUBLIC
	UNIT_CREATED_BY_SPELL = OBJECT_END + 0x004B, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_NPC_FLAGS = OBJECT_END + 0x004C, // Size: 1, Type: INT, Flags: DYNAMIC
	UNIT_NPC_EMOTESTATE = OBJECT_END + 0x004D, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_STAT0 = OBJECT_END + 0x004E, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_STAT1 = OBJECT_END + 0x004F, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_STAT2 = OBJECT_END + 0x0050, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_STAT3 = OBJECT_END + 0x0051, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_STAT4 = OBJECT_END + 0x0052, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POSSTAT0 = OBJECT_END + 0x0053, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POSSTAT1 = OBJECT_END + 0x0054, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POSSTAT2 = OBJECT_END + 0x0055, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POSSTAT3 = OBJECT_END + 0x0056, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POSSTAT4 = OBJECT_END + 0x0057, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_NEGSTAT0 = OBJECT_END + 0x0058, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_NEGSTAT1 = OBJECT_END + 0x0059, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_NEGSTAT2 = OBJECT_END + 0x005A, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_NEGSTAT3 = OBJECT_END + 0x005B, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_NEGSTAT4 = OBJECT_END + 0x005C, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_RESISTANCES = OBJECT_END + 0x005D, // Size: 7, Type: INT, Flags: PRIVATE, OWNER, PARTY_LEADER
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE = OBJECT_END + 0x0064, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE = OBJECT_END + 0x006B, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_BASE_MANA = OBJECT_END + 0x0072, // Size: 1, Type: INT, Flags: PUBLIC
	UNIT_FIELD_BASE_HEALTH = OBJECT_END + 0x0073, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_BYTES_2 = OBJECT_END + 0x0074, // Size: 1, Type: BYTES, Flags: PUBLIC
	UNIT_FIELD_ATTACK_POWER = OBJECT_END + 0x0075, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_ATTACK_POWER_MODS = OBJECT_END + 0x0076, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER
	UNIT_FIELD_ATTACK_POWER_MULTIPLIER = OBJECT_END + 0x0077, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_RANGED_ATTACK_POWER = OBJECT_END + 0x0078, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_RANGED_ATTACK_POWER_MODS = OBJECT_END + 0x0079, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER
	UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER = OBJECT_END + 0x007A, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_MINRANGEDDAMAGE = OBJECT_END + 0x007B, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_MAXRANGEDDAMAGE = OBJECT_END + 0x007C, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POWER_COST_MODIFIER = OBJECT_END + 0x007D, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
	UNIT_FIELD_POWER_COST_MULTIPLIER = OBJECT_END + 0x0084, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_MAXHEALTHMODIFIER = OBJECT_END + 0x008B, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
	UNIT_FIELD_HOVERHEIGHT = OBJECT_END + 0x008C, // Size: 1, Type: FLOAT, Flags: PUBLIC
	UNIT_FIELD_PADDING = OBJECT_END + 0x008D, // Size: 1, Type: INT, Flags: NONE
	UNIT_END = OBJECT_END + 0x008E,

	PLAYER_DUEL_ARBITER = UNIT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
	PLAYER_FLAGS = UNIT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_GUILDID = UNIT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_GUILDRANK = UNIT_END + 0x0004, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_BYTES = UNIT_END + 0x0005, // Size: 1, Type: BYTES, Flags: PUBLIC
	PLAYER_BYTES_2 = UNIT_END + 0x0006, // Size: 1, Type: BYTES, Flags: PUBLIC
	PLAYER_BYTES_3 = UNIT_END + 0x0007, // Size: 1, Type: BYTES, Flags: PUBLIC
	PLAYER_DUEL_TEAM = UNIT_END + 0x0008, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_GUILD_TIMESTAMP = UNIT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_QUEST_LOG_1_1 = UNIT_END + 0x000A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_1_2 = UNIT_END + 0x000B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_1_3 = UNIT_END + 0x000C, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_1_4 = UNIT_END + 0x000E, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_2_1 = UNIT_END + 0x000F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_2_2 = UNIT_END + 0x0010, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_2_3 = UNIT_END + 0x0011, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_2_5 = UNIT_END + 0x0013, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_3_1 = UNIT_END + 0x0014, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_3_2 = UNIT_END + 0x0015, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_3_3 = UNIT_END + 0x0016, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_3_5 = UNIT_END + 0x0018, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_4_1 = UNIT_END + 0x0019, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_4_2 = UNIT_END + 0x001A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_4_3 = UNIT_END + 0x001B, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_4_5 = UNIT_END + 0x001D, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_5_1 = UNIT_END + 0x001E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_5_2 = UNIT_END + 0x001F, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_5_3 = UNIT_END + 0x0020, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_5_5 = UNIT_END + 0x0022, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_6_1 = UNIT_END + 0x0023, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_6_2 = UNIT_END + 0x0024, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_6_3 = UNIT_END + 0x0025, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_6_5 = UNIT_END + 0x0027, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_7_1 = UNIT_END + 0x0028, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_7_2 = UNIT_END + 0x0029, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_7_3 = UNIT_END + 0x002A, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_7_5 = UNIT_END + 0x002C, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_8_1 = UNIT_END + 0x002D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_8_2 = UNIT_END + 0x002E, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_8_3 = UNIT_END + 0x002F, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_8_5 = UNIT_END + 0x0031, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_9_1 = UNIT_END + 0x0032, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_9_2 = UNIT_END + 0x0033, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_9_3 = UNIT_END + 0x0034, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_9_5 = UNIT_END + 0x0036, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_10_1 = UNIT_END + 0x0037, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_10_2 = UNIT_END + 0x0038, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_10_3 = UNIT_END + 0x0039, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_10_5 = UNIT_END + 0x003B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_11_1 = UNIT_END + 0x003C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_11_2 = UNIT_END + 0x003D, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_11_3 = UNIT_END + 0x003E, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_11_5 = UNIT_END + 0x0040, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_12_1 = UNIT_END + 0x0041, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_12_2 = UNIT_END + 0x0042, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_12_3 = UNIT_END + 0x0043, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_12_5 = UNIT_END + 0x0045, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_13_1 = UNIT_END + 0x0046, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_13_2 = UNIT_END + 0x0047, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_13_3 = UNIT_END + 0x0048, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_13_5 = UNIT_END + 0x004A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_14_1 = UNIT_END + 0x004B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_14_2 = UNIT_END + 0x004C, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_14_3 = UNIT_END + 0x004D, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_14_5 = UNIT_END + 0x004F, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_15_1 = UNIT_END + 0x0050, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_15_2 = UNIT_END + 0x0051, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_15_3 = UNIT_END + 0x0052, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_15_5 = UNIT_END + 0x0054, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_16_1 = UNIT_END + 0x0055, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_16_2 = UNIT_END + 0x0056, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_16_3 = UNIT_END + 0x0057, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_16_5 = UNIT_END + 0x0059, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_17_1 = UNIT_END + 0x005A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_17_2 = UNIT_END + 0x005B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_17_3 = UNIT_END + 0x005C, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_17_5 = UNIT_END + 0x005E, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_18_1 = UNIT_END + 0x005F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_18_2 = UNIT_END + 0x0060, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_18_3 = UNIT_END + 0x0061, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_18_5 = UNIT_END + 0x0063, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_19_1 = UNIT_END + 0x0064, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_19_2 = UNIT_END + 0x0065, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_19_3 = UNIT_END + 0x0066, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_19_5 = UNIT_END + 0x0068, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_20_1 = UNIT_END + 0x0069, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_20_2 = UNIT_END + 0x006A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_20_3 = UNIT_END + 0x006B, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_20_5 = UNIT_END + 0x006D, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_21_1 = UNIT_END + 0x006E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_21_2 = UNIT_END + 0x006F, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_21_3 = UNIT_END + 0x0070, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_21_5 = UNIT_END + 0x0072, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_22_1 = UNIT_END + 0x0073, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_22_2 = UNIT_END + 0x0074, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_22_3 = UNIT_END + 0x0075, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_22_5 = UNIT_END + 0x0077, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_23_1 = UNIT_END + 0x0078, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_23_2 = UNIT_END + 0x0079, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_23_3 = UNIT_END + 0x007A, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_23_5 = UNIT_END + 0x007C, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_24_1 = UNIT_END + 0x007D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_24_2 = UNIT_END + 0x007E, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_24_3 = UNIT_END + 0x007F, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_24_5 = UNIT_END + 0x0081, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_25_1 = UNIT_END + 0x0082, // Size: 1, Type: INT, Flags: PARTY_MEMBER
	PLAYER_QUEST_LOG_25_2 = UNIT_END + 0x0083, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_QUEST_LOG_25_3 = UNIT_END + 0x0084, // Size: 2, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_QUEST_LOG_25_5 = UNIT_END + 0x0086, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_VISIBLE_ITEM_1_ENTRYID = UNIT_END + 0x0087, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_1_ENCHANTMENT = UNIT_END + 0x0088, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_2_ENTRYID = UNIT_END + 0x0089, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_2_ENCHANTMENT = UNIT_END + 0x008A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_3_ENTRYID = UNIT_END + 0x008B, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_3_ENCHANTMENT = UNIT_END + 0x008C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_4_ENTRYID = UNIT_END + 0x008D, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_4_ENCHANTMENT = UNIT_END + 0x008E, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_5_ENTRYID = UNIT_END + 0x008F, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_5_ENCHANTMENT = UNIT_END + 0x0090, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_6_ENTRYID = UNIT_END + 0x0091, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_6_ENCHANTMENT = UNIT_END + 0x0092, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_7_ENTRYID = UNIT_END + 0x0093, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_7_ENCHANTMENT = UNIT_END + 0x0094, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_8_ENTRYID = UNIT_END + 0x0095, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_8_ENCHANTMENT = UNIT_END + 0x0096, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_9_ENTRYID = UNIT_END + 0x0097, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_9_ENCHANTMENT = UNIT_END + 0x0098, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_10_ENTRYID = UNIT_END + 0x0099, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_10_ENCHANTMENT = UNIT_END + 0x009A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_11_ENTRYID = UNIT_END + 0x009B, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_11_ENCHANTMENT = UNIT_END + 0x009C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_12_ENTRYID = UNIT_END + 0x009D, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_12_ENCHANTMENT = UNIT_END + 0x009E, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_13_ENTRYID = UNIT_END + 0x009F, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_13_ENCHANTMENT = UNIT_END + 0x00A0, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_14_ENTRYID = UNIT_END + 0x00A1, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_14_ENCHANTMENT = UNIT_END + 0x00A2, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_15_ENTRYID = UNIT_END + 0x00A3, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_15_ENCHANTMENT = UNIT_END + 0x00A4, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_16_ENTRYID = UNIT_END + 0x00A5, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_16_ENCHANTMENT = UNIT_END + 0x00A6, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_17_ENTRYID = UNIT_END + 0x00A7, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_17_ENCHANTMENT = UNIT_END + 0x00A8, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_18_ENTRYID = UNIT_END + 0x00A9, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_18_ENCHANTMENT = UNIT_END + 0x00AA, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_19_ENTRYID = UNIT_END + 0x00AB, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_VISIBLE_ITEM_19_ENCHANTMENT = UNIT_END + 0x00AC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
	PLAYER_CHOSEN_TITLE = UNIT_END + 0x00AD, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_FAKE_INEBRIATION = UNIT_END + 0x00AE, // Size: 1, Type: INT, Flags: PUBLIC
	PLAYER_FIELD_PAD_0 = UNIT_END + 0x00AF, // Size: 1, Type: INT, Flags: NONE
	PLAYER_FIELD_INV_SLOT_HEAD = UNIT_END + 0x00B0, // Size: 46, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_PACK_SLOT_1 = UNIT_END + 0x00DE, // Size: 32, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_BANK_SLOT_1 = UNIT_END + 0x00FE, // Size: 56, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_BANKBAG_SLOT_1 = UNIT_END + 0x0136, // Size: 14, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_VENDORBUYBACK_SLOT_1 = UNIT_END + 0x0144, // Size: 24, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_KEYRING_SLOT_1 = UNIT_END + 0x015C, // Size: 64, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_CURRENCYTOKEN_SLOT_1 = UNIT_END + 0x019C, // Size: 64, Type: LONG, Flags: PRIVATE
	PLAYER_FARSIGHT = UNIT_END + 0x01DC, // Size: 2, Type: LONG, Flags: PRIVATE
	PLAYER__FIELD_KNOWN_TITLES = UNIT_END + 0x01DE, // Size: 2, Type: LONG, Flags: PRIVATE
	PLAYER__FIELD_KNOWN_TITLES1 = UNIT_END + 0x01E0, // Size: 2, Type: LONG, Flags: PRIVATE
	PLAYER__FIELD_KNOWN_TITLES2 = UNIT_END + 0x01E2, // Size: 2, Type: LONG, Flags: PRIVATE
	PLAYER_FIELD_KNOWN_CURRENCIES = UNIT_END + 0x01E4, // Size: 2, Type: LONG, Flags: PRIVATE
	PLAYER_XP = UNIT_END + 0x01E6, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_NEXT_LEVEL_XP = UNIT_END + 0x01E7, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_SKILL_INFO_1_1 = UNIT_END + 0x01E8, // Size: 384, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_CHARACTER_POINTS1 = UNIT_END + 0x0368, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_CHARACTER_POINTS2 = UNIT_END + 0x0369, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_TRACK_CREATURES = UNIT_END + 0x036A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_TRACK_RESOURCES = UNIT_END + 0x036B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_BLOCK_PERCENTAGE = UNIT_END + 0x036C, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_DODGE_PERCENTAGE = UNIT_END + 0x036D, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_PARRY_PERCENTAGE = UNIT_END + 0x036E, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_EXPERTISE = UNIT_END + 0x036F, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_OFFHAND_EXPERTISE = UNIT_END + 0x0370, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_CRIT_PERCENTAGE = UNIT_END + 0x0371, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_RANGED_CRIT_PERCENTAGE = UNIT_END + 0x0372, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_OFFHAND_CRIT_PERCENTAGE = UNIT_END + 0x0373, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_SPELL_CRIT_PERCENTAGE1 = UNIT_END + 0x0374, // Size: 7, Type: FLOAT, Flags: PRIVATE
	PLAYER_SHIELD_BLOCK = UNIT_END + 0x037B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_SHIELD_BLOCK_CRIT_PERCENTAGE = UNIT_END + 0x037C, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_EXPLORED_ZONES_1 = UNIT_END + 0x037D, // Size: 128, Type: BYTES, Flags: PRIVATE
	PLAYER_REST_STATE_EXPERIENCE = UNIT_END + 0x03FD, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_COINAGE = UNIT_END + 0x03FE, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MOD_DAMAGE_DONE_POS = UNIT_END + 0x03FF, // Size: 7, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG = UNIT_END + 0x0406, // Size: 7, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT = UNIT_END + 0x040D, // Size: 7, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MOD_HEALING_DONE_POS = UNIT_END + 0x0414, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MOD_HEALING_PCT = UNIT_END + 0x0415, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_FIELD_MOD_HEALING_DONE_PCT = UNIT_END + 0x0416, // Size: 1, Type: FLOAT, Flags: PRIVATE
	PLAYER_FIELD_MOD_TARGET_RESISTANCE = UNIT_END + 0x0417, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE = UNIT_END + 0x0418, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_BYTES = UNIT_END + 0x0419, // Size: 1, Type: BYTES, Flags: PRIVATE
	PLAYER_AMMO_ID = UNIT_END + 0x041A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_SELF_RES_SPELL = UNIT_END + 0x041B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_PVP_MEDALS = UNIT_END + 0x041C, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_BUYBACK_PRICE_1 = UNIT_END + 0x041D, // Size: 12, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_BUYBACK_TIMESTAMP_1 = UNIT_END + 0x0429, // Size: 12, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_KILLS = UNIT_END + 0x0435, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE
	PLAYER_FIELD_TODAY_CONTRIBUTION = UNIT_END + 0x0436, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_YESTERDAY_CONTRIBUTION = UNIT_END + 0x0437, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_LIFETIME_HONORBALE_KILLS = UNIT_END + 0x0438, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_BYTES2 = UNIT_END + 0x0439, // Size: 1, Type: 6, Flags: PRIVATE
	PLAYER_FIELD_WATCHED_FACTION_INDEX = UNIT_END + 0x043A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_COMBAT_RATING_1 = UNIT_END + 0x043B, // Size: 25, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_ARENA_TEAM_INFO_1_1 = UNIT_END + 0x0454, // Size: 21, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_HONOR_CURRENCY = UNIT_END + 0x0469, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_ARENA_CURRENCY = UNIT_END + 0x046A, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_MAX_LEVEL = UNIT_END + 0x046B, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_DAILY_QUESTS_1 = UNIT_END + 0x046C, // Size: 25, Type: INT, Flags: PRIVATE
	PLAYER_RUNE_REGEN_1 = UNIT_END + 0x0485, // Size: 4, Type: FLOAT, Flags: PRIVATE
	PLAYER_NO_REAGENT_COST_1 = UNIT_END + 0x0489, // Size: 3, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_GLYPH_SLOTS_1 = UNIT_END + 0x048C, // Size: 6, Type: INT, Flags: PRIVATE
	PLAYER_FIELD_GLYPHS_1 = UNIT_END + 0x0492, // Size: 6, Type: INT, Flags: PRIVATE
	PLAYER_GLYPHS_ENABLED = UNIT_END + 0x0498, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_PET_SPELL_POWER = UNIT_END + 0x0499, // Size: 1, Type: INT, Flags: PRIVATE
	PLAYER_END = UNIT_END + 0x049A,
};

enum EGoFields
{
	GO_FLAG_NONE = 0x00000000,
	GO_FLAG_IN_USE = 0x00000001,
	GO_FLAG_LOCKED = 0x00000002,
	GO_FLAG_INTERACT_COND = 0x00000004,
	GO_FLAG_TRANSPORT = 0x00000008,
	GO_FLAG_NOT_SELECTABLE = 0x00000010,
	GO_FLAG_NODESPAWN = 0x00000020,
	GO_FLAG_TRIGGERED = 0x00000040,
	GO_FLAG_DAMAGED = 0x00000200,
	GO_FLAG_DESTROYED = 0x00000400,
};
#pragma endregion