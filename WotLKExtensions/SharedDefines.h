#pragma once

#include "PatchConfig.h"
#include "Util.h"

struct lua_State;

static uint32_t dummy = 0;

static std::unordered_map<char*, void*> luaFuncts;

namespace Addresses
{
	constexpr uintptr_t ACHIEVEMENTDB = 0x00AD305C;
	constexpr uintptr_t ACHIEVEMENT_CATEGORYDB = 0x00AD30A4;
	constexpr uintptr_t ACHIEVEMENT_CRITERIADB = 0x00AD3080;
	constexpr uintptr_t ANIMATIONDATADB = 0x00AD30C8;
	constexpr uintptr_t AREAGROUPDB = 0x00AD30EC;
	constexpr uintptr_t AREAPOIDB = 0x00AD3110;
	constexpr uintptr_t AREATABLEDB = 0x00AD3134;
	constexpr uintptr_t AREATRIGGERDB = 0x00AD3158;
	constexpr uintptr_t ATTACKANIMKITSDB = 0x00AD317C;
	constexpr uintptr_t ATTACKANIMTYPESDB = 0x00AD31A0;
	constexpr uintptr_t AUCTIONHOUSEDB = 0x00AD31C4;
	constexpr uintptr_t BANKBAGSLOTPRICESDB = 0x00AD31E8;
	constexpr uintptr_t BANNEDADDONSDB = 0x00AD320C;
	constexpr uintptr_t BARBERSHOP_STYLE_DB = 0x00AD3230;
	constexpr uintptr_t BATTLEMASTER_LIST_DB = 0x00AD3254;
	constexpr uintptr_t CAMERA_SHAKES_DB = 0x00AD3278;
	constexpr uintptr_t CFG_CATEGORIES_DB = 0x00AD329C;
	constexpr uintptr_t CFG_CONFIGS_DB = 0x00AD32C0;
	constexpr uintptr_t CHARACTER_FACIAL_HAIRSTYLES_DB = 0x00AD3398;
	constexpr uintptr_t CHAR_BASE_INFO_DB = 0x00AD32E4;
	constexpr uintptr_t CHAR_HAIR_GEOSETS_DB = 0x00AD3308;
	constexpr uintptr_t CHAR_SECTIONS_DB = 0x00AD332C;
	constexpr uintptr_t CHAR_STARTOUT_FIT_DB = 0x00AD3350;
	constexpr uintptr_t CHAR_TITLES_DB = 0x00AD3374;
	constexpr uintptr_t CHAT_CHANNELS_DB = 0x00AD33BC;
	constexpr uintptr_t CHAT_PROFANITY_DB = 0x00AD33E0;
	constexpr uintptr_t CHR_CLASSES_DB = 0x00AD3404;
	constexpr uintptr_t CHR_RACES_DB = 0x00AD3428;
	constexpr uintptr_t CINEMATIC_CAMERA_DB = 0x00AD344C;
	constexpr uintptr_t CINEMATIC_SEQUENCES_DB = 0x00AD3470;
	constexpr uintptr_t CREATURE_DISPLAYINFO_DB = 0x00AD34B8;
	constexpr uintptr_t CREATURE_DISPLAYINFO_EXTRA_DB = 0x00AD3494;
	constexpr uintptr_t CREATURE_FAMILY_DB = 0x00AD34DC;
	constexpr uintptr_t CREATURE_MODELDATA_DB = 0x00AD3500;
	constexpr uintptr_t CREATURE_MOVEMENTINFO_DB = 0x00AD3524;
	constexpr uintptr_t CREATURE_SOUNDDATA_DB = 0x00AD3548;
	constexpr uintptr_t CREATURE_SPELLDATA_DB = 0x00AD356C;
	constexpr uintptr_t CREATURE_TYPE_DB = 0x00AD3590;
	constexpr uintptr_t CURRENCY_CATEGORY_DB = 0x00AD35D8;
	constexpr uintptr_t CURRENCY_TYPES_DB = 0x00AD35B4;
	constexpr uintptr_t DANCEMOVES_DB = 0x00AD35FC;
	constexpr uintptr_t DEATHTHUD_LOOKUPS_DB = 0x00AD3620;
	constexpr uintptr_t DESTRUCTIBLEMODELDATADB = 0x00AD368C;
	constexpr uintptr_t DUNGEONENCOUNTERDB = 0x00AD36B0;
	constexpr uintptr_t DUNGEONMAPCHUNKDB = 0x00AD36F8;
	constexpr uintptr_t DUNGEONMAPDB = 0x00AD36D4;
	constexpr uintptr_t DURABILITYCOSTSDB = 0x00AD371C;
	constexpr uintptr_t DURABILITYQUALITYDB = 0x00AD3740;
	constexpr uintptr_t EMOTESDB = 0x00AD3764;
	constexpr uintptr_t EMOTESTEXTDATADB = 0x00AD3788;
	constexpr uintptr_t EMOTESTEXTDB = 0x00AD37D0;
	constexpr uintptr_t EMOTESTEXTSOUNDDB = 0x00AD37AC;
	constexpr uintptr_t ENVIRONMENTALDAMAGEDB = 0x00AD37F4;
	constexpr uintptr_t EXHAUSTIONDB = 0x00AD3818;
	constexpr uintptr_t FACTIONDB = 0x00AD3860;
	constexpr uintptr_t FACTIONGROUPDB = 0x00AD383C;
	constexpr uintptr_t FACTIONTEMPLATEDB = 0x00AD3884;
	constexpr uintptr_t FILEDATADB = 0x00AD38A8;
	constexpr uintptr_t FOOTPRINTTEXTURESDB = 0x00AD38CC;
	constexpr uintptr_t FOOTSTEPTERRAINLOOKUPDB = 0x00AD38F0;
	constexpr uintptr_t GAMEOBJECTARTKITDB = 0x00AD3914;
	constexpr uintptr_t GAMEOBJECTDISPLAYINFODB = 0x00AD3938;
	constexpr uintptr_t GAMETABLESDB = 0x00AD395C;
	constexpr uintptr_t GAMETIPSDB = 0x00AD3980;
	constexpr uintptr_t GEMPROPERTIESDB = 0x00AD39A4;
	constexpr uintptr_t GLYPHPROPERTIESDB = 0x00AD39C8;
	constexpr uintptr_t GLYPHSLOTDB = 0x00AD39EC;
	constexpr uintptr_t GMSURVEYANSWERSDB = 0x00AD3A10;
	constexpr uintptr_t GMSURVEYCURRENTSURVEYDB = 0x00AD3A34;
	constexpr uintptr_t GMSURVEYQUESTIONSDB = 0x00AD3A58;
	constexpr uintptr_t GMSURVEYSURVEYSDB = 0x00AD3A7C;
	constexpr uintptr_t GMTICKETCATEGORYDB = 0x00AD3AA0;
	constexpr uintptr_t GROUNDEFFECTDOODADDB = 0x00AD3AC4;
	constexpr uintptr_t GROUNDEFFECTTEXTUREDB = 0x00AD3AE8;
	constexpr uintptr_t GTBARBERSHOPCOSTBASEDB = 0x00AD3B0C;
	constexpr uintptr_t GTCHANCETOMELEECRITBASEDB = 0x00AD3B78;
	constexpr uintptr_t GTCHANCETOMELEECRITDB = 0x00AD3B54;
	constexpr uintptr_t GTCHANCETOSPELLCRITBASEDB = 0x00AD3BC0;
	constexpr uintptr_t GTCHANCETOSPELLCRITDB = 0x00AD3B9C;
	constexpr uintptr_t GTCOMBATRATINGSDB = 0x00AD3B30;
	constexpr uintptr_t GTNPCMANACOSTSCALERDB = 0x00AD3BE4;
	constexpr uintptr_t GTOCTCLASSCOMBATRATINGSCALARDB = 0x00AD3C08;
	constexpr uintptr_t GTOCTREGENHPDB = 0x00AD3C2C;
	constexpr uintptr_t GTOCTREGENMPDB = 0x00AD3C50;
	constexpr uintptr_t GTREGENHPPERSPTDB = 0x00AD3C74;
	constexpr uintptr_t GTREGENMPPERSPTDB = 0x00AD3C98;
	constexpr uintptr_t HELMETGEOSETVISDATADB = 0x00AD3CBC;
	constexpr uintptr_t HOLIDAYDESCRIPTIONSDB = 0x00AD3CE0;
	constexpr uintptr_t HOLIDAYNAMESDB = 0x00AD3D04;
	constexpr uintptr_t HOLIDAYSDB = 0x00AD3D28;
	constexpr uintptr_t ITEMBAGFAMILYDB = 0x00AD3D70;
	constexpr uintptr_t ITEMCLASSDB = 0x00AD3D94;
	constexpr uintptr_t ITEMCONDEXTCOSTSDB = 0x00AD3DB8;
	constexpr uintptr_t ITEMDB = 0x00AD3D4C;
	constexpr uintptr_t ITEMDISPLAYINFODB = 0x00AD3DDC;
	constexpr uintptr_t ITEMEXTENDEDCOSTDB = 0x00AD3E00;
	constexpr uintptr_t ITEMGROUPSOUNDSDB = 0x00AD3E24;
	constexpr uintptr_t ITEMLIMITCATEGORYDB = 0x00AD3E48;
	constexpr uintptr_t ITEMPETFOODDB = 0x00AD3E6C;
	constexpr uintptr_t ITEMPURCHASEGROUPDB = 0x00AD3E90;
	constexpr uintptr_t ITEMRANDOMPROPERTIESDB = 0x00AD3EB4;
	constexpr uintptr_t ITEMRANDOMSUFFIXDB = 0x00AD3ED8;
	constexpr uintptr_t ITEMSETDB = 0x00AD3EFC;
	constexpr uintptr_t ITEMSUBCLASSDB = 0x00AD3F44;
	constexpr uintptr_t ITEMSUBCLASSMASKDB = 0x00AD3F20;
	constexpr uintptr_t ITEMVISUALEFFECTSDB = 0x00AD3F68;
	constexpr uintptr_t ITEMVISUALSDB = 0x00AD3F8C;
	constexpr uintptr_t LANGUAGESDB = 0x00AD3FD4;
	constexpr uintptr_t LANGUAGEWORDSDB = 0x00AD3FB0;
	constexpr uintptr_t LFGDUNGEONEXPANSIONDB = 0x00AD3FF8;
	constexpr uintptr_t LFGDUNGEONGROUPDB = 0x00AD401C;
	constexpr uintptr_t LFGDUNGEONSDB = 0x00AD4040;
	constexpr uintptr_t LIQUIDMATERIALDB = 0x00AD4088;
	constexpr uintptr_t LIQUIDTYPEDB = 0x00AD4064;
	constexpr uintptr_t LOADINGSCREENSDB = 0x00AD40AC;
	constexpr uintptr_t LOADINGSCREENTAXISPLINESDB = 0x00AD40D0;
	constexpr uintptr_t LOCKDB = 0x00AD40F4;
	constexpr uintptr_t LOCKTYPEDB = 0x00AD4118;
	constexpr uintptr_t MAILTEMPLATEDB = 0x00AD413C;
	constexpr uintptr_t MAPDB = 0x00AD4160;
	constexpr uintptr_t MAPDIFFICULTYDB = 0x00AD4184;
	constexpr uintptr_t MATERIALDB = 0x00AD41A8;
	constexpr uintptr_t MOVIEDB = 0x00AD41CC;
	constexpr uintptr_t MOVIEFILEDATADB = 0x00AD41F0;
	constexpr uintptr_t MOVIEVARIATIONDB = 0x00AD4214;
	constexpr uintptr_t NAMEGENDB = 0x00AD4238;
	constexpr uintptr_t NAMESPROFANITYDB = 0x00AD4280;
	constexpr uintptr_t NAMESRESERVEDDB = 0x00AD42A4;
	constexpr uintptr_t NPCSOUNDSDB = 0x00AD425C;
	constexpr uintptr_t OBJECTEFFECTDB = 0x00AD5048;
	constexpr uintptr_t OBJECTEFFECTGROUPDB = 0x00AD506C;
	constexpr uintptr_t OBJECTEFFECTMODIFIERDB = 0x00AD5090;
	constexpr uintptr_t OBJECTEFFECTPACKAGEDB = 0x00AD50B4;
	constexpr uintptr_t OBJECTEFFECTPACKAGEELEMDB = 0x00AD50D8;
	constexpr uintptr_t OVERRIDESPELLDATADB = 0x00AD42C8;
	constexpr uintptr_t PACKAGEDB = 0x00AD42EC;
	constexpr uintptr_t PAGETEXTMATERIALDB = 0x00AD4310;
	constexpr uintptr_t PAPERDOLLITEMFRAMEDB = 0x00AD4334;
	constexpr uintptr_t PARTICLECOLORDB = 0x00AD4358;
	constexpr uintptr_t PETPERSONALITYDB = 0x00AD437C;
	constexpr uintptr_t POWERDISPLAYDB = 0x00AD43A0;
	constexpr uintptr_t PVPDIFFICULTYDB = 0x00AD43C4;
	constexpr uintptr_t QUESTFACTIONREWARDDB = 0x00AD43E8;
	constexpr uintptr_t QUESTINFODB = 0x00AD440C;
	constexpr uintptr_t QUESTSORTDB = 0x00AD4430;
	constexpr uintptr_t QUESTXPDB = 0x00AD4454;
	constexpr uintptr_t RANDPROPPOINTSDB = 0x00AD449C;
	constexpr uintptr_t RESISTANCESDB = 0x00AD4478;
	constexpr uintptr_t SCALINGSTATDISTRIBUTIONDB = 0x00AD44C0;
	constexpr uintptr_t SCALINGSTATVALUESDB = 0x00AD44E4;
	constexpr uintptr_t SCREENEFFECTDB = 0x00AD4508;
	constexpr uintptr_t SERVERMESSAGESDB = 0x00AD452C;
	constexpr uintptr_t SHEATHESOUNDLOOKUPSDB = 0x00AD4550;
	constexpr uintptr_t SKILLCOSTSDATADB = 0x00AD4574;
	constexpr uintptr_t SKILLLINEABILITYDB = 0x00AD4598;
	constexpr uintptr_t SKILLLINECATEGORYDB = 0x00AD45BC;
	constexpr uintptr_t SKILLLINEDB = 0x00AD45E0;
	constexpr uintptr_t SKILLRACECLASSINFODB = 0x00AD4604;
	constexpr uintptr_t SKILLTIERSDB = 0x00AD4628;
	constexpr uintptr_t SOUNDAMBIENCEDB = 0x00AD464C;
	constexpr uintptr_t SOUNDEMITTERSDB = 0x00AD4694;
	constexpr uintptr_t SOUNDENTRIESADVANCEDDB = 0x00AD5024;
	constexpr uintptr_t SOUNDENTRIESDB = 0x00AD4670;
	constexpr uintptr_t SOUNDFILTERDB = 0x00AD50FC;
	constexpr uintptr_t SOUNDFILTERELEMDB = 0x00AD5120;
	constexpr uintptr_t SOUNDPROVIDERPREFERENCESDB = 0x00AD46B8;
	constexpr uintptr_t SOUNDSAMPLEPREFERENCESDB = 0x00AD46DC;
	constexpr uintptr_t SOUNDWATERTYPEDB = 0x00AD4700;
	constexpr uintptr_t SPAMMESSAGESDB = 0x00AD4724;
	constexpr uintptr_t SPELLCASTTIMESDB = 0x00AD4748;
	constexpr uintptr_t SPELLCATEGORYDB = 0x00AD476C;
	constexpr uintptr_t SPELLCHAINEFFECTSDB = 0x00AD4790;
	constexpr uintptr_t SPELLDB = 0x00AD49D0;
	constexpr uintptr_t SPELLDESCRIPTIONVARIABLESDB = 0x00AD47B4;
	constexpr uintptr_t SPELLDIFFICULTYDB = 0x00AD47D8;
	constexpr uintptr_t SPELLDISPELTYPEDB = 0x00AD47FC;
	constexpr uintptr_t SPELLDURATIONDB = 0x00AD4820;
	constexpr uintptr_t SPELLEFFECTCAMERASHAKESDB = 0x00AD4844;
	constexpr uintptr_t SPELLFOCUSOBJECTDB = 0x00AD4868;
	constexpr uintptr_t SPELLICONDB = 0x00AD488C;
	constexpr uintptr_t SPELLITEMENCHANTMENTCONDITIONDB = 0x00AD48D4;
	constexpr uintptr_t SPELLITEMENCHANTMENTDB = 0x00AD48B0;
	constexpr uintptr_t SPELLMECHANICDB = 0x00AD48F8;
	constexpr uintptr_t SPELLMISSILEDB = 0x00AD491C;
	constexpr uintptr_t SPELLMISSILEMOTIONDB = 0x00AD4940;
	constexpr uintptr_t SPELLRADIUSDB = 0x00AD4964;
	constexpr uintptr_t SPELLRANGEDB = 0x00AD4988;
	constexpr uintptr_t SPELLRUNECOSTDB = 0x00AD49AC;
	constexpr uintptr_t SPELLSHAPESHIFTFORMDB = 0x00AD49F4;
	constexpr uintptr_t SPELLVISUALDB = 0x00AD4AA8;
	constexpr uintptr_t SPELLVISUALEFFECTNAMEDB = 0x00AD4A18;
	constexpr uintptr_t SPELLVISUALKITAREAMODELDB = 0x00AD4A60;
	constexpr uintptr_t SPELLVISUALKITDB = 0x00AD4A3C;
	constexpr uintptr_t SPELLVISUALKITMODELATTACHDB = 0x00AD4A84;
	constexpr uintptr_t STABLESLOTPRICESDB = 0x00AD4ACC;
	constexpr uintptr_t STATIONERYDB = 0x00AD4AF0;
	constexpr uintptr_t STRINGLOOKUPSDB = 0x00AD4B14;
	constexpr uintptr_t SUMMONPROPERTIESDB = 0x00AD4B38;
	constexpr uintptr_t TALENTDB = 0x00AD4B5C;
	constexpr uintptr_t TALENTTABDB = 0x00AD4B80;
	constexpr uintptr_t TAXINODESDB = 0x00AD4BA4;
	constexpr uintptr_t TAXIPATHDB = 0x00AD4BEC;
	constexpr uintptr_t TAXIPATHNODEDB = 0x00AD4BC8;
	constexpr uintptr_t TEAMCONTRIBUTIONPOINTSDB = 0x00AD4C10;
	constexpr uintptr_t TERRAINTYPEDB = 0x00AD4C34;
	constexpr uintptr_t TERRAINTYPESOUNDSDB = 0x00AD4C58;
	constexpr uintptr_t TOTEMCATEGORYDB = 0x00AD4C7C;
	constexpr uintptr_t TRANSPORTANIMATIONDB = 0x00AD4CA0;
	constexpr uintptr_t TRANSPORTPHYSICSDB = 0x00AD4CC4;
	constexpr uintptr_t TRANSPORTROTATIONDB = 0x00AD4CE8;
	constexpr uintptr_t UISOUNDLOOKUPSDB = 0x00AD4D0C;
	constexpr uintptr_t UNITBLOODDB = 0x00AD4D54;
	constexpr uintptr_t UNITBLOODLEVELSDB = 0x00AD4D30;
	constexpr uintptr_t VEHICLEDB = 0x00AD4D78;
	constexpr uintptr_t VEHICLESEATDB = 0x00AD4D9C;
	constexpr uintptr_t VEHICLEUIINDICATORDB = 0x00AD4DC0;
	constexpr uintptr_t VEHICLEUIINDSEATDB = 0x00AD4DE4;
	constexpr uintptr_t VOCALUISOUNDSDB = 0x00AD4E08;
	constexpr uintptr_t WEAPONIMPACTSOUNDSDB = 0x00AD4E50;
	constexpr uintptr_t WEAPONSWINGSOUNDS2DB = 0x00AD4E74;
	constexpr uintptr_t WEATHERDB = 0x00AD4E98;
	constexpr uintptr_t WMOAREATABLEDB = 0x00AD4E2C;
	constexpr uintptr_t WORLDCHUNKSOUNDSDB = 0x00AD5000;
	constexpr uintptr_t WORLDMAPAREADB = 0x00AD4EBC;
	constexpr uintptr_t WORLDMAPCONTINENTDB = 0x00AD4EE0;
	constexpr uintptr_t WORLDMAPOVERLAYDB = 0x00AD4F04;
	constexpr uintptr_t WORLDMAPTRANSFORMSDB = 0x00AD4F28;
	constexpr uintptr_t WORLDSAFELOCSDB = 0x00AD4F4C;
	constexpr uintptr_t WORLDSTATEUIDB = 0x00AD4F70;
	constexpr uintptr_t WORLDSTATEZONESOUNDSDB = 0x00AD4FDC;
	constexpr uintptr_t ZONEINTROMUSICTABLEDB = 0x00AD4F94;
	constexpr uintptr_t ZONEMUSICDB = 0x00AD4FB8;


	// Functions
	constexpr uintptr_t GET_SPELL_VISUAL_ROW = 0x007FA290;
	constexpr uintptr_t GET_LOCALIZED_ROW = 0x4CFD20;
	constexpr uintptr_t GET_ROW = 0x65C290;

	// Client functions
	constexpr uintptr_t PROCESS_MESSAGE = 0x631FE0;
	constexpr uintptr_t SET_MESSAGE_HANDLER = 0x631FA0;
	// ... add more as you find them
}

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

namespace DB
{
	// Usage: uint32_t* dbPtr = *DB::g_spellDB;

	static void** g_achievementDB = (void**)Addresses::ACHIEVEMENTDB;
	static void** g_achievement_CategoryDB = (void**)Addresses::ACHIEVEMENT_CATEGORYDB;
	static void** g_achievement_CriteriaDB = (void**)Addresses::ACHIEVEMENT_CRITERIADB;
	static void** g_animationDataDB = (void**)Addresses::ANIMATIONDATADB;
	static void** g_areaGroupDB = (void**)Addresses::AREAGROUPDB;
	static void** g_areaPOIDB = (void**)Addresses::AREAPOIDB;
	static void** g_areaTableDB = (void**)Addresses::AREATABLEDB;
	static void** g_areaTriggerDB = (void**)Addresses::AREATRIGGERDB;
	static void** g_attackAnimKitsDB = (void**)Addresses::ATTACKANIMKITSDB;
	static void** g_attackAnimTypesDB = (void**)Addresses::ATTACKANIMTYPESDB;
	static void** g_auctionHouseDB = (void**)Addresses::AUCTIONHOUSEDB;

	static void** g_bankBagSlotPricesDB = (void**)Addresses::BANKBAGSLOTPRICESDB;
	static void** g_bannedAddOnsDB = (void**)Addresses::BANNEDADDONSDB;
	static void** g_barberShopStyleDB				= (void**)Addresses::BARBERSHOP_STYLE_DB;
	static void** g_battlemasterListDB				= (void**)Addresses::BATTLEMASTER_LIST_DB;

	static void** g_cameraShakesDB					= (void**)Addresses::CAMERA_SHAKES_DB;
	static void** g_cfg_CategoriesDB				= (void**)Addresses::CFG_CATEGORIES_DB;
	static void** g_cfg_ConfigsDB					= (void**)Addresses::CFG_CONFIGS_DB;
	static void** g_characterFacialHairStylesDB		= (void**)Addresses::CHARACTER_FACIAL_HAIRSTYLES_DB;
	static void** g_charBaseInfoDB					= (void**)Addresses::CHAR_BASE_INFO_DB;
	static void** g_charHairGeosetsDB				= (void**)Addresses::CHAR_HAIR_GEOSETS_DB;
	static void** g_charSectionsDB					= (void**)Addresses::CHAR_SECTIONS_DB;
	static void** g_charStartOutfitDB				= (void**)Addresses::CHAR_STARTOUT_FIT_DB;
	static void** g_charTitlesDB					= (void**)Addresses::CHAR_TITLES_DB;
	static void** g_chatChannelsDB					= (void**)Addresses::CHAT_CHANNELS_DB;
	static void** g_chatProfanityDB					= (void**)Addresses::CHAT_PROFANITY_DB;
	static void** g_chrClassesDB					= (void**)Addresses::CHR_CLASSES_DB;
	static void** g_chrRacesDB						= (void**)Addresses::CHR_RACES_DB;
	static void** g_cinematicCameraDB				= (void**)Addresses::CINEMATIC_CAMERA_DB;
	static void** g_cinematicSequencesDB			= (void**)Addresses::CINEMATIC_SEQUENCES_DB;
	static void** g_creatureDisplayInfoDB			= (void**)Addresses::CREATURE_DISPLAYINFO_DB;
	static void** g_creatureDisplayInfoExtraDB		= (void**)Addresses::CREATURE_DISPLAYINFO_EXTRA_DB;
	static void** g_creatureFamilyDB				= (void**)Addresses::CREATURE_FAMILY_DB;
	static void** g_creatureModelDataDB				= (void**)Addresses::CREATURE_MODELDATA_DB;
	static void** g_creatureMovementInfoDB			= (void**)Addresses::CREATURE_MOVEMENTINFO_DB;
	static void** g_creatureSoundDataDB				= (void**)Addresses::CREATURE_SOUNDDATA_DB;
	static void** g_creatureSpellDataDB				= (void**)Addresses::CREATURE_SPELLDATA_DB;
	static void** g_creatureTypeDB					= (void**)Addresses::CREATURE_TYPE_DB;
	static void** g_currencyCategoryDB				= (void**)Addresses::CURRENCY_CATEGORY_DB;
	static void** g_currencyTypesDB					= (void**)Addresses::CURRENCY_TYPES_DB;

	static void** g_danceMovesDB					= (void**)Addresses::DANCEMOVES_DB;
	static void** g_deathThudLookupsDB				= (void**)Addresses::DEATHTHUD_LOOKUPS_DB;
	static void** g_destructibleModelDataDB = (void**)Addresses::DESTRUCTIBLEMODELDATADB;
	static void** g_dungeonEncounterDB = (void**)Addresses::DUNGEONENCOUNTERDB;
	static void** g_dungeonMapChunkDB = (void**)Addresses::DUNGEONMAPCHUNKDB;
	static void** g_dungeonMapDB = (void**)Addresses::DUNGEONMAPDB;
	static void** g_durabilityCostsDB = (void**)Addresses::DURABILITYCOSTSDB;
	static void** g_durabilityQualityDB = (void**)Addresses::DURABILITYQUALITYDB;

	static void** g_emotesDB = (void**)Addresses::EMOTESDB;
	static void** g_emotesTextDataDB = (void**)Addresses::EMOTESTEXTDATADB;
	static void** g_emotesTextDB = (void**)Addresses::EMOTESTEXTDB;
	static void** g_emotesTextSoundDB = (void**)Addresses::EMOTESTEXTSOUNDDB;
	static void** g_environmentalDamageDB = (void**)Addresses::ENVIRONMENTALDAMAGEDB;
	static void** g_exhaustionDB = (void**)Addresses::EXHAUSTIONDB;

	static void** g_factionDB = (void**)Addresses::FACTIONDB;
	static void** g_factionGroupDB = (void**)Addresses::FACTIONGROUPDB;
	static void** g_factionTemplateDB = (void**)Addresses::FACTIONTEMPLATEDB;
	static void** g_fileDataDB = (void**)Addresses::FILEDATADB;
	static void** g_footprintTexturesDB = (void**)Addresses::FOOTPRINTTEXTURESDB;
	static void** g_footstepTerrainLookupDB = (void**)Addresses::FOOTSTEPTERRAINLOOKUPDB;

	static void** g_gameObjectArtKitDB = (void**)Addresses::GAMEOBJECTARTKITDB;
	static void** g_gameObjectDisplayInfoDB = (void**)Addresses::GAMEOBJECTDISPLAYINFODB;
	static void** g_gameTablesDB = (void**)Addresses::GAMETABLESDB;
	static void** g_gameTipsDB = (void**)Addresses::GAMETIPSDB;
	static void** g_gemPropertiesDB = (void**)Addresses::GEMPROPERTIESDB;
	static void** g_glyphPropertiesDB = (void**)Addresses::GLYPHPROPERTIESDB;
	static void** g_glyphSlotDB = (void**)Addresses::GLYPHSLOTDB;
	static void** g_gMSurveyAnswersDB = (void**)Addresses::GMSURVEYANSWERSDB;
	static void** g_gMSurveyCurrentSurveyDB = (void**)Addresses::GMSURVEYCURRENTSURVEYDB;
	static void** g_gMSurveyQuestionsDB = (void**)Addresses::GMSURVEYQUESTIONSDB;
	static void** g_gMSurveySurveysDB = (void**)Addresses::GMSURVEYSURVEYSDB;
	static void** g_gMTicketCategoryDB = (void**)Addresses::GMTICKETCATEGORYDB;
	static void** g_groundEffectDoodadDB = (void**)Addresses::GROUNDEFFECTDOODADDB;
	static void** g_groundEffectTextureDB = (void**)Addresses::GROUNDEFFECTTEXTUREDB;
	static void** g_gtBarberShopCostBaseDB = (void**)Addresses::GTBARBERSHOPCOSTBASEDB;
	static void** g_gtChanceToMeleeCritBaseDB = (void**)Addresses::GTCHANCETOMELEECRITBASEDB;
	static void** g_gtChanceToMeleeCritDB = (void**)Addresses::GTCHANCETOMELEECRITDB;
	static void** g_gtChanceToSpellCritBaseDB = (void**)Addresses::GTCHANCETOSPELLCRITBASEDB;
	static void** g_gtChanceToSpellCritDB = (void**)Addresses::GTCHANCETOSPELLCRITDB;
	static void** g_gtCombatRatingsDB = (void**)Addresses::GTCOMBATRATINGSDB;
	static void** g_gtNPCManaCostScalerDB = (void**)Addresses::GTNPCMANACOSTSCALERDB;
	static void** g_gtOCTClassCombatRatingScalarDB = (void**)Addresses::GTOCTCLASSCOMBATRATINGSCALARDB;
	static void** g_gtOCTRegenHPDB = (void**)Addresses::GTOCTREGENHPDB;
	static void** g_gtOCTRegenMPDB = (void**)Addresses::GTOCTREGENMPDB;
	static void** g_gtRegenHPPerSptDB = (void**)Addresses::GTREGENHPPERSPTDB;
	static void** g_gtRegenMPPerSptDB = (void**)Addresses::GTREGENMPPERSPTDB;

	static void** g_helmetGeosetVisDataDB = (void**)Addresses::HELMETGEOSETVISDATADB;
	static void** g_holidayDescriptionsDB = (void**)Addresses::HOLIDAYDESCRIPTIONSDB;
	static void** g_holidayNamesDB = (void**)Addresses::HOLIDAYNAMESDB;
	static void** g_holidaysDB = (void**)Addresses::HOLIDAYSDB;

	static void** g_itemBagFamilyDB = (void**)Addresses::ITEMBAGFAMILYDB;
	static void** g_itemClassDB = (void**)Addresses::ITEMCLASSDB;
	static void** g_itemCondExtCostsDB = (void**)Addresses::ITEMCONDEXTCOSTSDB;
	static void** g_itemDB = (void**)Addresses::ITEMDB;
	static void** g_itemDisplayInfoDB = (void**)Addresses::ITEMDISPLAYINFODB;
	static void** g_itemExtendedCostDB = (void**)Addresses::ITEMEXTENDEDCOSTDB;
	static void** g_itemGroupSoundsDB = (void**)Addresses::ITEMGROUPSOUNDSDB;
	static void** g_itemLimitCategoryDB = (void**)Addresses::ITEMLIMITCATEGORYDB;
	static void** g_itemPetFoodDB = (void**)Addresses::ITEMPETFOODDB;
	static void** g_itemPurchaseGroupDB = (void**)Addresses::ITEMPURCHASEGROUPDB;
	static void** g_itemRandomPropertiesDB = (void**)Addresses::ITEMRANDOMPROPERTIESDB;
	static void** g_itemRandomSuffixDB = (void**)Addresses::ITEMRANDOMSUFFIXDB;
	static void** g_itemSetDB = (void**)Addresses::ITEMSETDB;
	static void** g_itemSubClassDB = (void**)Addresses::ITEMSUBCLASSDB;
	static void** g_itemSubClassMaskDB = (void**)Addresses::ITEMSUBCLASSMASKDB;
	static void** g_itemVisualEffectsDB = (void**)Addresses::ITEMVISUALEFFECTSDB;
	static void** g_itemVisualsDB = (void**)Addresses::ITEMVISUALSDB;

	static void** g_languagesDB = (void**)Addresses::LANGUAGESDB;
	static void** g_languageWordsDB = (void**)Addresses::LANGUAGEWORDSDB;
	static void** g_lfgDungeonExpansionDB = (void**)Addresses::LFGDUNGEONEXPANSIONDB;
	static void** g_lfgDungeonGroupDB = (void**)Addresses::LFGDUNGEONGROUPDB;
	static void** g_lfgDungeonsDB = (void**)Addresses::LFGDUNGEONSDB;
	static void** g_liquidMaterialDB = (void**)Addresses::LIQUIDMATERIALDB;
	static void** g_liquidTypeDB = (void**)Addresses::LIQUIDTYPEDB;
	static void** g_loadingScreensDB = (void**)Addresses::LOADINGSCREENSDB;
	static void** g_loadingScreenTaxiSplinesDB = (void**)Addresses::LOADINGSCREENTAXISPLINESDB;
	static void** g_lockDB = (void**)Addresses::LOCKDB;
	static void** g_lockTypeDB = (void**)Addresses::LOCKTYPEDB;

	static void** g_mailTemplateDB = (void**)Addresses::MAILTEMPLATEDB;
	static void** g_mapDB = (void**)Addresses::MAPDB;
	static void** g_mapDifficultyDB = (void**)Addresses::MAPDIFFICULTYDB;
	static void** g_materialDB = (void**)Addresses::MATERIALDB;
	static void** g_movieDB = (void**)Addresses::MOVIEDB;
	static void** g_movieFileDataDB = (void**)Addresses::MOVIEFILEDATADB;
	static void** g_movieVariationDB = (void**)Addresses::MOVIEVARIATIONDB;

	static void** g_nameGenDB = (void**)Addresses::NAMEGENDB;
	static void** g_namesProfanityDB = (void**)Addresses::NAMESPROFANITYDB;
	static void** g_namesReservedDB = (void**)Addresses::NAMESRESERVEDDB;
	static void** g_nPCSoundsDB = (void**)Addresses::NPCSOUNDSDB;

	static void** g_objectEffectDB = (void**)Addresses::OBJECTEFFECTDB;
	static void** g_objectEffectGroupDB = (void**)Addresses::OBJECTEFFECTGROUPDB;
	static void** g_objectEffectModifierDB = (void**)Addresses::OBJECTEFFECTMODIFIERDB;
	static void** g_objectEffectPackageDB = (void**)Addresses::OBJECTEFFECTPACKAGEDB;
	static void** g_objectEffectPackageElemDB = (void**)Addresses::OBJECTEFFECTPACKAGEELEMDB;
	static void** g_overrideSpellDataDB = (void**)Addresses::OVERRIDESPELLDATADB;

	static void** g_packageDB = (void**)Addresses::PACKAGEDB;
	static void** g_pageTextMaterialDB = (void**)Addresses::PAGETEXTMATERIALDB;
	static void** g_paperDollItemFrameDB = (void**)Addresses::PAPERDOLLITEMFRAMEDB;
	static void** g_particleColorDB = (void**)Addresses::PARTICLECOLORDB;
	static void** g_petPersonalityDB = (void**)Addresses::PETPERSONALITYDB;
	static void** g_powerDisplayDB = (void**)Addresses::POWERDISPLAYDB;
	static void** g_pvpDifficultyDB = (void**)Addresses::PVPDIFFICULTYDB;

	static void** g_questFactionRewardDB = (void**)Addresses::QUESTFACTIONREWARDDB;
	static void** g_questInfoDB = (void**)Addresses::QUESTINFODB;
	static void** g_questSortDB = (void**)Addresses::QUESTSORTDB;
	static void** g_questXPDB = (void**)Addresses::QUESTXPDB;

	static void** g_randPropPointsDB = (void**)Addresses::RANDPROPPOINTSDB;
	static void** g_resistancesDB = (void**)Addresses::RESISTANCESDB;

	static void** g_scalingStatDistributionDB = (void**)Addresses::SCALINGSTATDISTRIBUTIONDB;
	static void** g_scalingStatValuesDB = (void**)Addresses::SCALINGSTATVALUESDB;
	static void** g_screenEffectDB = (void**)Addresses::SCREENEFFECTDB;
	static void** g_serverMessagesDB = (void**)Addresses::SERVERMESSAGESDB;
	static void** g_sheatheSoundLookupsDB = (void**)Addresses::SHEATHESOUNDLOOKUPSDB;
	static void** g_skillCostsDataDB = (void**)Addresses::SKILLCOSTSDATADB;
	static void** g_skillLineAbilityDB = (void**)Addresses::SKILLLINEABILITYDB;
	static void** g_skillLineCategoryDB = (void**)Addresses::SKILLLINECATEGORYDB;
	static void** g_skillLineDB = (void**)Addresses::SKILLLINEDB;
	static void** g_skillRaceClassInfoDB = (void**)Addresses::SKILLRACECLASSINFODB;
	static void** g_skillTiersDB = (void**)Addresses::SKILLTIERSDB;
	static void** g_soundAmbienceDB = (void**)Addresses::SOUNDAMBIENCEDB;
	static void** g_soundEmittersDB = (void**)Addresses::SOUNDEMITTERSDB;
	static void** g_soundEntriesAdvancedDB = (void**)Addresses::SOUNDENTRIESADVANCEDDB;
	static void** g_soundEntriesDB = (void**)Addresses::SOUNDENTRIESDB;
	static void** g_soundFilterDB = (void**)Addresses::SOUNDFILTERDB;
	static void** g_soundFilterElemDB = (void**)Addresses::SOUNDFILTERELEMDB;
	static void** g_soundProviderPreferencesDB = (void**)Addresses::SOUNDPROVIDERPREFERENCESDB;
	static void** g_soundSamplePreferencesDB = (void**)Addresses::SOUNDSAMPLEPREFERENCESDB;
	static void** g_soundWaterTypeDB = (void**)Addresses::SOUNDWATERTYPEDB;
	static void** g_spamMessagesDB = (void**)Addresses::SPAMMESSAGESDB;
	static void** g_spellCastTimesDB = (void**)Addresses::SPELLCASTTIMESDB;
	static void** g_spellCategoryDB = (void**)Addresses::SPELLCATEGORYDB;
	static void** g_spellChainEffectsDB = (void**)Addresses::SPELLCHAINEFFECTSDB;
	static void** g_spellDB = (void**)Addresses::SPELLDB;
	static void** g_spellDescriptionVariablesDB = (void**)Addresses::SPELLDESCRIPTIONVARIABLESDB;
	static void** g_spellDifficultyDB = (void**)Addresses::SPELLDIFFICULTYDB;
	static void** g_spellDispelTypeDB = (void**)Addresses::SPELLDISPELTYPEDB;
	static void** g_spellDurationDB = (void**)Addresses::SPELLDURATIONDB;
	static void** g_spellEffectCameraShakesDB = (void**)Addresses::SPELLEFFECTCAMERASHAKESDB;
	static void** g_spellFocusObjectDB = (void**)Addresses::SPELLFOCUSOBJECTDB;
	static void** g_spellIconDB = (void**)Addresses::SPELLICONDB;
	static void** g_spellItemEnchantmentConditionDB = (void**)Addresses::SPELLITEMENCHANTMENTCONDITIONDB;
	static void** g_spellItemEnchantmentDB = (void**)Addresses::SPELLITEMENCHANTMENTDB;
	static void** g_spellMechanicDB = (void**)Addresses::SPELLMECHANICDB;
	static void** g_spellMissileDB = (void**)Addresses::SPELLMISSILEDB;
	static void** g_spellMissileMotionDB = (void**)Addresses::SPELLMISSILEMOTIONDB;
	static void** g_spellRadiusDB = (void**)Addresses::SPELLRADIUSDB;
	static void** g_spellRangeDB = (void**)Addresses::SPELLRANGEDB;
	static void** g_spellRuneCostDB = (void**)Addresses::SPELLRUNECOSTDB;
	static void** g_spellShapeshiftFormDB = (void**)Addresses::SPELLSHAPESHIFTFORMDB;
	static void** g_spellVisualDB = (void**)Addresses::SPELLVISUALDB;
	static void** g_spellVisualEffectNameDB = (void**)Addresses::SPELLVISUALEFFECTNAMEDB;
	static void** g_spellVisualKitAreaModelDB = (void**)Addresses::SPELLVISUALKITAREAMODELDB;
	static void** g_spellVisualKitDB = (void**)Addresses::SPELLVISUALKITDB;
	static void** g_spellVisualKitModelAttachDB = (void**)Addresses::SPELLVISUALKITMODELATTACHDB;
	static void** g_stableSlotPricesDB = (void**)Addresses::STABLESLOTPRICESDB;
	static void** g_stationeryDB = (void**)Addresses::STATIONERYDB;
	static void** g_stringLookupsDB = (void**)Addresses::STRINGLOOKUPSDB;
	static void** g_summonPropertiesDB = (void**)Addresses::SUMMONPROPERTIESDB;

	static void** g_talentDB = (void**)Addresses::TALENTDB;
	static void** g_talentTabDB = (void**)Addresses::TALENTTABDB;
	static void** g_taxiNodesDB = (void**)Addresses::TAXINODESDB;
	static void** g_taxiPathDB = (void**)Addresses::TAXIPATHDB;
	static void** g_taxiPathNodeDB = (void**)Addresses::TAXIPATHNODEDB;
	static void** g_teamContributionPointsDB = (void**)Addresses::TEAMCONTRIBUTIONPOINTSDB;
	static void** g_terrainTypeDB = (void**)Addresses::TERRAINTYPEDB;
	static void** g_terrainTypeSoundsDB = (void**)Addresses::TERRAINTYPESOUNDSDB;
	static void** g_totemCategoryDB = (void**)Addresses::TOTEMCATEGORYDB;
	static void** g_transportAnimationDB = (void**)Addresses::TRANSPORTANIMATIONDB;
	static void** g_transportPhysicsDB = (void**)Addresses::TRANSPORTPHYSICSDB;
	static void** g_transportRotationDB = (void**)Addresses::TRANSPORTROTATIONDB;

	static void** g_uISoundLookupsDB = (void**)Addresses::UISOUNDLOOKUPSDB;
	static void** g_unitBloodDB = (void**)Addresses::UNITBLOODDB;
	static void** g_unitBloodLevelsDB = (void**)Addresses::UNITBLOODLEVELSDB;

	static void** g_vehicleDB = (void**)Addresses::VEHICLEDB;
	static void** g_vehicleSeatDB = (void**)Addresses::VEHICLESEATDB;
	static void** g_vehicleUIIndicatorDB = (void**)Addresses::VEHICLEUIINDICATORDB;
	static void** g_vehicleUIIndSeatDB = (void**)Addresses::VEHICLEUIINDSEATDB;
	static void** g_vocalUISoundsDB = (void**)Addresses::VOCALUISOUNDSDB;

	static void** g_weaponImpactSoundsDB = (void**)Addresses::WEAPONIMPACTSOUNDSDB;
	static void** g_weaponSwingSounds2DB = (void**)Addresses::WEAPONSWINGSOUNDS2DB;
	static void** g_weatherDB = (void**)Addresses::WEATHERDB;
	static void** g_wMOAreaTableDB = (void**)Addresses::WMOAREATABLEDB;
	static void** g_worldChunkSoundsDB = (void**)Addresses::WORLDCHUNKSOUNDSDB;
	static void** g_worldMapAreaDB = (void**)Addresses::WORLDMAPAREADB;
	static void** g_worldMapContinentDB = (void**)Addresses::WORLDMAPCONTINENTDB;
	static void** g_worldMapOverlayDB = (void**)Addresses::WORLDMAPOVERLAYDB;
	static void** g_worldMapTransformsDB = (void**)Addresses::WORLDMAPTRANSFORMSDB;
	static void** g_worldSafeLocsDB = (void**)Addresses::WORLDSAFELOCSDB;
	static void** g_worldStateUIDB = (void**)Addresses::WORLDSTATEUIDB;
	static void** g_worldStateZoneSoundsDB = (void**)Addresses::WORLDSTATEZONESOUNDSDB;

	static void** g_zoneIntroMusicTableDB = (void**)Addresses::ZONEINTROMUSICTABLEDB;
	static void** g_zoneMusicDB = (void**)Addresses::ZONEMUSICDB;

	// Helper function to get a database record
	template<typename T>
	inline T* GetRecord(void** db, uint32_t id)
	{
		if (!db || !*db) return nullptr;
		// Database access logic here
		return (T*)((uintptr_t)(*db) + (id * sizeof(T)));
	}
}


