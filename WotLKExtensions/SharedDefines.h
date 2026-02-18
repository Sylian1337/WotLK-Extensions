#pragma once

#include "PatchConfig.h"
#include "Util.h"
#include "GameData/Addresses.h"

typedef uint64_t WOWGUID;

struct lua_State;

static uint32_t dummy = 0;

static std::unordered_map<char*, void*> luaFuncts;

// Function signature
typedef void(__thiscall* WowClientDB__SpellRec__LoadDB_t)(uintptr_t thisptr, char* filename, int32_t ExitCode);


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

enum Globals
{

	PlayerName = 0x00C79D18,                    // 3.3.5a 12340
	CurrentAccount = 0x00B6AA40,                // 3.3.5a 12340
	CurrentRealm = 0x00C79B9E,                  // 3.3.5a 12340
	CurrentTargetGUID = 0x00BD07B0,             // 3.3.5a 12340
	LastTargetGUID = 0x00BD07B8,                // 3.3.5a 12340
	MouseOverGUID = 0x00BD07A0,                 // 3.3.5a 12340
	FollowGUID = 0x00CA11F8,                    // 3.3.5a 12340
	ComboPoint = 0x00BD084D,                    // 3.3.5a 12340
	LootWindow = 0x00BFA8D8,                    // 3.3.5a 12340
	KnownSpell = 0x00BE5D88,                    // 3.3.5a 12340
	IsLoadingOrConnecting = 0x00B6AA38,         // 3.3.5a 12340
	Movement_Field = 0xD8,                      // 3.3.5a 12340
	SpellCooldownPtr = 0x00D3F5AC,              // 3.3.5a 12340
	Timestamp = 0x00B1D618,                     // 3.3.5a 12340
	LastHardwareAction = 0x00B499A4,            // 3.3.5a 12340
	ClntObjMgrObjectPtr = 0x004D4DB0,           // 3.3.5a 12340
	ClntObjMgrGetActivePlayer = 0x004D3790,     // 3.3.5a 12340
	ClntObjMgrGetActivePlayerObj = 0x4038F0,    // 3.3.5a 12340
	HandleTerrainClick = 0x00527830,            // 3.3.5a 12340
	CGGameUI_Target = 0x00524BF0,               // 3.3.5a 12340
	Spell_C_CastSpell = 0x0080DA40,             // 3.3.5a 12340
	CGUnit_C__GetCreatureType = 0x0071F300,     // 3.3.5a 12340
	UnitName1 = 0x964,                          // 3.3.5a 12340
	UnitName2 = 0x5C,                           // 3.3.5a 12340
	nbItemsSellByMerchant = 0x00BFA3F0,         // 3.3.5a 12340
	CInputControl = 0x00C24954,                 // 3.3.5a 12340
	BuildNumber = 0x00B3203C,                   // 3.3.5a 12340
	GetMinimapZoneText = 0x00BD077C,            // 3.3.5a 12340
	GetZoneText = 0x00BD0788,                   // 3.3.5a 12340
	GetSubZoneText = 0x00BD0784,                // 3.3.5a 12340
	GetInternalMapName = 0x00CE06D0,            // 3.3.5a 12340
	LocalGUID = 0x00CA1238,                     // 3.3.5a 12340
	GetZoneID = 0x00BD080C,                     // 3.3.5a 12340
	IsBobbingOffset = 0xBC,                     // 3.3.5a 12340
	ChatboxIsOpen = 0x00D41660,                 // 3.3.5a 12340
	M2Model__IsOutdoors = 0x0077FBF0,           // 3.3.5a 12340
	CVar_MaxFPS = 0x00C5DF7C,                   // 3.3.5a 12340
	CGWorldFrame__RenderWorld = 0x004FAF90,     // 3.3.5a 12340
	CGWorldFrame__Intersect = 0x0077F310,       // 3.3.5a 12340
	// CWorldScene::s_m2Scene - Global pointer to M2 scene manager
	CGWorldScene__m2Scene	= 0x00CD754C,
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

struct CDataStore__v_table
{
	void* fn_InternalInitialize;
	void* fn_InternalDestroy;
	void* fn_InternalFetchRead;
	void* fn_InternalFetchWrite;
	void* fn_destructor;
	void* fn_IsRead;
	void* fn_Reset;
	void* fn_Finalize;
	void* fn_GetBufferParams;
	void* fn_DetachBuffer;
	void* fn_GetHeaderSpace;
};

struct CDataStore
{
	CDataStore__v_table* vTable;
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
	CLIENT_FUNCTION(GenPacket, CDataStore_C_Addresses::GEN_PACKET, __thiscall, void, (CDataStore*))

	CLIENT_FUNCTION(GetInt8, CDataStore_C_Addresses::GET_INT8, __thiscall, void, (CDataStore*, int8_t*))
	CLIENT_FUNCTION(GetInt16, CDataStore_C_Addresses::GET_INT16, __thiscall, void, (CDataStore*, int16_t*))
	CLIENT_FUNCTION(GetInt32, CDataStore_C_Addresses::GET_INT32, __thiscall, void, (CDataStore*, int32_t*))
	CLIENT_FUNCTION(GetInt64, CDataStore_C_Addresses::GET_INT64, __thiscall, void, (CDataStore*, int64_t*))
	CLIENT_FUNCTION(GetCString, CDataStore_C_Addresses::GET_CSTRING, __thiscall, void, (CDataStore*, char*, int32_t))
	CLIENT_FUNCTION(GetWoWGuid, CDataStore_C_Addresses::GET_WOW_GUID, __cdecl, void, (CDataStore*, int64_t*))

	CLIENT_FUNCTION(PutInt8, CDataStore_C_Addresses::PUT_INT8, __thiscall, void, (CDataStore*, int8_t))
	CLIENT_FUNCTION(PutInt16, CDataStore_C_Addresses::PUT_INT16, __thiscall, void, (CDataStore*, int16_t))
	CLIENT_FUNCTION(PutInt32, CDataStore_C_Addresses::PUT_INT32, __thiscall, void, (CDataStore*, int32_t))
	CLIENT_FUNCTION(PutCString, CDataStore_C_Addresses::PUT_CSTRING, __thiscall, void, (CDataStore*, char* string))
	CLIENT_FUNCTION(PutPackedGuid, CDataStore_C_Addresses::PUT_PACKED_GUID, __cdecl, void, (CDataStore*, int64_t))			// Not tested yet, just implemented.

	CLIENT_FUNCTION(Release, CDataStore_C_Addresses::RELEASE, __thiscall, void, (CDataStore*))
}

namespace CGChat
{
	CLIENT_FUNCTION(AddChatMessage, 0x509DD0, __cdecl, bool, (char*, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t, char*, uint64_t, uint32_t, uint64_t, uint32_t, uint32_t, uint32_t*))
}

namespace CGPlayer_C
{
	CLIENT_FUNCTION(EquipVisibleItem, 0x6E08C0, __thiscall, void, (void*, uint32_t*, uint32_t))
	CLIENT_FUNCTION(IsDeadOrGhost, CGPlayer_Vitrual_Functions::CGPLAYER_IS_DEAD_OR_GHOST, __thiscall, bool, (CGPlayer*))
}

namespace CGUnit_C
{
	CLIENT_FUNCTION(GetShapeshiftFormId, 0x71AF70, __thiscall, uint32_t, (CGUnit*))
}

namespace ClientDB
{
	//CLIENT_FUNCTION(GetSpellVisualRow, FuncAddresses::GET_SPELL_VISUAL_ROW, __cdecl, SpellVisualRec*, (void*))
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
	CLIENT_FUNCTION(InitializePlayer, ClientServices::INITIALIZE_PLAYER, __cdecl, void, ())
	CLIENT_FUNCTION(SendPacket, ClientServices::SEND_PACKET, __cdecl, void, (CDataStore*))
	CLIENT_FUNCTION(GetCharacterClass, ClientServices::GET_CHARACTER_CLASS, __cdecl, uint8_t, ())
}

namespace ClntObjMgr
{
	CLIENT_FUNCTION(GetActivePlayer, ClntObjMgr::GET_ACTIVE_PLAYER, __cdecl, uint64_t, ())
	CLIENT_FUNCTION(ObjectPtr, ClntObjMgr::GET_OBJECT_PTR, __cdecl, void*, (uint64_t, uint32_t))
	CLIENT_FUNCTION(EnumVisibleObjects, ClntObjMgr::GET_OBJECT_PTR, __cdecl, void*, (uint64_t, uint32_t))
}

namespace CNetClient
{
	CLIENT_FUNCTION(ProcessMessage, CNetClient::PROCESS_MESSAGE, __thiscall, int, (void*, uint32_t, CDataStore*, uint32_t))
	CLIENT_FUNCTION(SetMessageHandler, CNetClient::SET_MESSAGE_HANDLER, __thiscall, void, (void*, uint32_t, void*, void*))
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
	CLIENT_FUNCTION(ToBoolean, 0x84E0B0, __cdecl, char*, (lua_State*, int))	// Also known as GetBoolean
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

namespace CM2Scene {
	// CM2Scene::CreateModel - Creates a new M2 model instance
	CLIENT_FUNCTION(CreateModel, CM2Model_Addresses::ADDR_CREATE_MODEL, __thiscall, void*,
		(void* pScene, const char* szModel, uint32_t flags))
}

namespace CM2Model {

	// CM2Model::AttachToParent - Attaches child model to parent model
	CLIENT_FUNCTION(AttachToParent, CM2Scene_Addresses::ADDR_ATTACH_PARENT, __thiscall, void,
		(void* pChild, void* pParent, int boneId, int unk1, int unk2))


	CLIENT_FUNCTION(ReplaceTexture, CM2Model_Addresses::ADDR_REPLACE_TEXTURE, __thiscall, void,
		(int model, int unk1, const char* textureBlock))

	CLIENT_FUNCTION(InitializeLoaded, CM2Model_Addresses::ADDR_INIT_LOADED, __thiscall, int,
		(int pThis))
}

namespace CTexture
{
	// TextureCreate - Creates a texture from file/data
	// Parameters: a1 = texture path/name, a2 = ?, a3 = ?, a4 = ?
	// NOTE: Not tested yet, I simply added it so it would be easier for you ma dude :D
	CLIENT_FUNCTION(Create_3, CTexture_Addresses::ADDR_TEXTURE_CREATE_3, __cdecl, int,
		(char* textureBlock, int a2, int a3, int a4))

	CLIENT_FUNCTION(Create, CTexture_Addresses::ADDR_TEXTURE_CREATE, __cdecl, int,
		(int a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, char* a10, int a11))

	CLIENT_FUNCTION(CreateBlob, CTexture_Addresses::ADDR_TEXTURE_CREATE_BLOB, __cdecl, int,
		(char* a1, int a2, int a3, int a4))

	CLIENT_FUNCTION(CreateSolid, CTexture_Addresses::ADDR_TEXTURE_CREATE_SOLID, __cdecl, int,
		(int* a1))
}

namespace CGxTexFlags
{
	// NOTE: Not tested yet, I simply added it so it would be easier for you ma dude :D
	CLIENT_FUNCTION(TexConstructor, CGxTexFlags_Addresses::ADDR_CONSTRUCTOR, __thiscall, uint32_t,
		(unsigned int* pThis, int a2, char* a3, char* a4, char* a5, char* a6, char* a7, unsigned int a8, char* a9, char* a10, char* a11))

	CLIENT_FUNCTION(TexFlags, CGxTexFlags_Addresses::ADDR_TEX_FLAGS, __thiscall, uint32_t,
		(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char* a8, int a9))
}

namespace CCharacterComponent
{
	CLIENT_FUNCTION(AddHandItem, CCharacterComponent_Addresses::ADDR_ADD_HAND_ITEM, __cdecl, uint32_t,
		(int a1, int a2, uint32_t a3, int a4, char* a5, char* a6, char* a7, void* itemVisualsRec))

	CLIENT_FUNCTION(RemoveLinkPt, CCharacterComponent_Addresses::ADDR_REMOVE_LINK_PT, __cdecl, void,
		(int a1, uint32_t a2))
}