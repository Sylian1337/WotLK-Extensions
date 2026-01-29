#pragma once

#include "PatchConfig.h"
#include "Util.h"
#include "GameData/Addresses.h"

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
	CLIENT_FUNCTION(GetSpellVisualRow, FuncAddresses::GET_SPELL_VISUAL_ROW, __cdecl, SpellVisualRec*, (void*))
	CLIENT_FUNCTION(GetLocalizedRow, FuncAddresses::GET_LOCALIZED_ROW, __thiscall, int, (void*, uint32_t, void*))
	CLIENT_FUNCTION(GetRow, FuncAddresses::GET_ROW, __thiscall, void*, (void*, uint32_t))
	CLIENT_FUNCTION(GetGameTableValue, FuncAddresses::GET_GAME_TABLE_VALUE, __cdecl, double, (uint32_t, uint32_t, uint32_t)) // this technically is not a part of ClientDB iirc but who cares
}

namespace ClientPacket
{
	CLIENT_FUNCTION(MSG_SET_ACTION_BUTTON, 0x5AA390, __cdecl, void, (uint32_t, bool, bool))
}

namespace ClientServices
{
	CLIENT_FUNCTION(InitializePlayer, FuncAddresses::INITIALIZE_PLAYER, __cdecl, void, ())
	CLIENT_FUNCTION(SendPacket, FuncAddresses::GET_ACTIVE_PLAYER, __cdecl, void, (CDataStore*))
	CLIENT_FUNCTION(GetCharacterClass, 0x6B1080, __cdecl, uint8_t, ())
}

namespace ClntObjMgr
{
	CLIENT_FUNCTION(GetActivePlayer, FuncAddresses::GET_ACTIVE_PLAYER, __cdecl, uint64_t, ())
	CLIENT_FUNCTION(ObjectPtr, FuncAddresses::GET_OBJECT_PTR, __cdecl, void*, (uint64_t, uint32_t))
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
