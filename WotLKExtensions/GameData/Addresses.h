// GameData/Addresses.h
#pragma once
#include <cstdint>

// Base needed to call the load function of WowClientDB
const uintptr_t DBCLIENT_BASE = 0x626E8C;

namespace DBCAddresses
{
	// DBCs
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
}

namespace DBCacheAddresses 
{
	// GetInfoByID functions
	constexpr uintptr_t DB_CREATURE_CACHE_GETINFOBYID = 0x67B6A0;
	constexpr uintptr_t DB_GAMEOBBJECT_CACHE_GETINFOBYID = 0x67BD40;
	constexpr uintptr_t DB_ARENA_TEAM_CACHE_GETINFOBYID = 0x67C3E0;
	constexpr uintptr_t DB_ITEM_CACHE_GETINFOBYID = 0x67CA30;
	constexpr uintptr_t DB_NPC_CACHE_GETINFOBYID = 0x67D0D0;
	constexpr uintptr_t DB_NAME_CACHE_GETINFOBYID = 0x67D770;
	constexpr uintptr_t DB_GUILD_CACHE_GETINFOBYID = 0x67D930;
	constexpr uintptr_t DB_QUEST_CACHE_GETINFOBYID = 0x67DE90;
	constexpr uintptr_t DB_ITEMNAME_CACHE_GETINFOBYID = 0x67E3E0;
	constexpr uintptr_t DB_PETNAME_CACHE_GETINFOBYID = 0x67EA30;
	constexpr uintptr_t DB_ITEMTEXT_CACHE_GETINFOBYID = 0x67F4C0;
	constexpr uintptr_t DB_PAGETEXT_CACHE_GETINFOBYID = 0x680170;
	constexpr uintptr_t DB_DANCE_CACHE_GETINFOBYID = 0x6806D0;

	// DBCache Addresses
	constexpr uintptr_t DB_DANCE_CACHE = 0xC5D690;
	constexpr uintptr_t DB_GAMEOBJECT_CACHE = 0xC5D718;
	constexpr uintptr_t DB_PAGETEXT_CACHE = 0xC5D828;
	constexpr uintptr_t DB_ITEMTEXT_CACHE = 0xC5D7A0;
	constexpr uintptr_t DB_ITEMNAME_CACHE = 0xC5D8B0;
	constexpr uintptr_t DB_GUILD_CACHE = 0xC5D938;
	constexpr uintptr_t DB_ARENATEAM_CACHE = 0xC5D9C0;
	constexpr uintptr_t DB_NAME_CACHE = 0xC5DA48;
	constexpr uintptr_t DB_PETNAME_CACHE = 0xC5DAD0;
	constexpr uintptr_t DB_QUEST_CACHE = 0xC5DB58;
	constexpr uintptr_t DB_NPC_CACHE = 0xC5DBE0;
	constexpr uintptr_t DB_CREATURE_CACHE = 0xC5DC68;
	constexpr uintptr_t DB_WOW_CACHE = 0xC5DCF0;
	constexpr uintptr_t DB_ITEM_CACHE = 0xC5DD78;
	constexpr uintptr_t DB_PETITION_CACHE = 0xC5DE00;
}

namespace FuncAddresses {

	


	// Functions
	constexpr uintptr_t GET_SPELL_VISUAL_ROW = 0x007FA290;
	constexpr uintptr_t GET_LOCALIZED_ROW = 0x4CFD20;
	constexpr uintptr_t GET_ROW = 0x65C290;
	constexpr uintptr_t GET_GAME_TABLE_VALUE = 0x7F6990;
}

namespace CDataStore_C_Addresses {
	constexpr uintptr_t GEN_PACKET = 0x401050;
	constexpr uintptr_t GET_INT8 = 0x47B340;
	constexpr uintptr_t PUT_INT8 = 0x47AFE0;
	constexpr uintptr_t GET_INT16 = 0x47B380;
	constexpr uintptr_t PUT_INT16 = 0x47AFE0;
	constexpr uintptr_t GET_INT32 = 0x47B3C0;
	constexpr uintptr_t PUT_INT32 = 0x47B0A0;
	constexpr uintptr_t GET_INT64 = 0x47B400;
	constexpr uintptr_t GET_CSTRING = 0x47B480;
	constexpr uintptr_t PUT_CSTRING = 0x47B300;
	constexpr uintptr_t RELEASE = 0x403880;
	constexpr uintptr_t PUT_PACKED_GUID = 0x76DD00;			// Not tested yet, just implemented.
	constexpr uintptr_t GET_WOW_GUID = 0x76DC20;
}

namespace ClntObjMgr
{
	constexpr uintptr_t GET_ACTIVE_PLAYER = 0x4D3790;
	constexpr uintptr_t GET_OBJECT_PTR = 0x4D4DB0;
	constexpr uintptr_t ENUM_VISIBLE_OBJECTS = 0x004D4B30;
}

namespace ClientServices {
	constexpr uintptr_t INITIALIZE_PLAYER = 0x6E83B0;
	constexpr uintptr_t SEND_PACKET = 0x6B0B50;
	constexpr uintptr_t GET_CHARACTER_CLASS = 0x6B1080;
}

namespace CNetClient {
	constexpr uintptr_t PROCESS_MESSAGE = 0x631FE0;
	constexpr uintptr_t SET_MESSAGE_HANDLER = 0x631FA0;
}

namespace CGPlayer_Vitrual_Functions {

	constexpr uintptr_t CGPLAYER_IS_DEAD_OR_GHOST = 0x6DAC10;

}

// Implemented by xidk
// CM2SceneRender pipeline (RE): Draw(0x823130) loops elements, sets m_model/m_skin from elem, dispatches by elem->m_type.
// DrawBatch(0x8203B0): sets m_currentBatch(0x88), m_skinSection(0x90), computes m_textureDef(0x98); then SetupLighting, SetupMaterial, BindPassTextures.
// BindPassTextures(0x81F450) called from DrawBatch+6B, DrawBatchProj+2BF, DrawBatchDoodad+6C, DrawRibbon+5F, DrawCallback+6.
namespace CM2SceneRender_Addresses {
	constexpr uintptr_t ADDR_DRAW = 0x823130;             // void __thiscall Draw(this, viewMatrix, elementPool, indices, count) - main render loop
	constexpr uintptr_t ADDR_SETUP_LIGHTING = 0x81FB10;   // void __thiscall SetupLighting(this)
	constexpr uintptr_t ADDR_SETUP_TEXTURES = 0x81F450;   // BindPassTextures
	constexpr uintptr_t ADDR_DRAW_BATCH = 0x8203B0;       // DrawBatch - type 0
	constexpr uintptr_t ADDR_DRAW_BATCH_PROJ = 0x820720;  // DrawBatchProj - type 1
	constexpr uintptr_t ADDR_DRAW_BATCH_DOODAD = 0x820AE0; // DrawBatchDoodad - type 2
	constexpr uintptr_t ADDR_DRAW_RIBBON = 0x820F40;      // DrawRibbon - type 3
	constexpr uintptr_t ADDR_DRAW_PARTICLE = 0x8214E0;   // DrawParticle - type 4
	constexpr uintptr_t OFF_MODEL = 0x48;                 // CM2Model* m_model - set in Draw from elem->m_model
	constexpr uintptr_t OFF_ELEMENT = 0x50;               // M2RenderElement* m_element
	constexpr uintptr_t OFF_PASS_INDEX = 0x58;            // uint32_t m_passIndex
	constexpr uintptr_t OFF_SKIN = 0x60;                  // CM2Skin* m_skin - set in Draw from elem->m_model->m_skin
	constexpr uintptr_t OFF_MODEL_FROM_DRAW = 0x60;       // alias: some paths may store model here; RE says 0x60 = m_skin
	constexpr uintptr_t OFF_SHARED = 0x68;               // CM2Shared* m_shared
	constexpr uintptr_t OFF_LIGHTING_SOURCE = 0x70;       // CM2Lighting* - from m_model->m_lighting (0x1D4)
	constexpr uintptr_t OFF_BATCH = 0x88;                // M2Batch* m_currentBatch
	constexpr uintptr_t OFF_SKIN_SECTION = 0x90;         // M2SkinSection* m_skinSection - from elem->m_skinSection (0x2C)
	constexpr uintptr_t OFF_BATCH_DATA = 0x98;           // void* m_textureDef / batch data - (flags&1)==0 → use local lighting
	constexpr uintptr_t OFF_TEXTURE_DEF = 0x98;          // alias - DrawBatch sets from batch->textureLookupId
	constexpr uintptr_t OFF_BATCH_TEXTURE_COUNT = 0x0E;   // uint16_t M2Batch.textureCount
	constexpr uintptr_t OFF_BATCH_TEXTURE_LOOKUP_ID = 0x10; // uint16_t M2Batch.textureLookupId
	constexpr uintptr_t OFF_SKIN_TEXTURE_LIST = 0xA4;    // CTexture** CM2Skin::m_textureList
}

// Implemented by xidk
// M2RenderElement: stride 68. +0x00 m_type, +0x04 m_model, +0x18 m_batch, +0x2C m_skinSection.
namespace M2RenderElement_Offsets {
	constexpr uintptr_t OFF_TYPE = 0x00;
	constexpr uintptr_t OFF_MODEL = 0x04;
	constexpr uintptr_t OFF_BATCH = 0x18;
	constexpr uintptr_t OFF_SKIN_SECTION = 0x2C;
	constexpr uintptr_t STRIDE = 68;
}

// Implemented by xidk
// M2SkinSection: geometry batch. boneCount at +0x0A; set to 0 to skip hardware skinning loop (static mesh).
namespace M2SkinSection_Offsets {
	constexpr uintptr_t OFF_BONE_COUNT = 0x0A;  // uint16_t - skinning loop uses this; 0 = no bones = no crash
}

// Implemented by xidk
// Draw (0x823130): at 0x823A1D sets ctx+0x60 = elem->m_model (sheep); at 0x823A60 sets ctx+0x48 = shared->m_parent (player).
// BindPassTextures then uses 0x48 for lookup (model+0x84) and 0x60 for tex list (model+0xA4) -> index mismatch for attachments.
namespace CM2Shared_Offsets {
	constexpr uintptr_t OFF_PARENT = 0x150;  // CM2Model* m_parent - Draw injects this into ctx+0x48
}

// Implemented by xidk
// Texture loading and binding - from IDA analysis of Build 12340
namespace TextureLoader_Addresses {
	constexpr uintptr_t ADDR_TEXTURE = 0x004B9760;        // int __cdecl texture(filename, flags, status, unk)
	constexpr uintptr_t ADDR_TEXTURE_RELEASE = 0x0047BF30; // void __cdecl TextureRelease(void* pTexture) - validated 1-arg refcount release
	constexpr uintptr_t ADDR_SOLID_WHITE_TEXTURE = 0x00AC3354; // CTexture* g_solidWhiteTexture - fallback when file not found
	constexpr uintptr_t ADDR_TEXTURE_GET_GX_TEX = 0x004B6CB0; // CGxTex* __cdecl TextureGetGxTex(CTexture* tex, int, int) - gets hardware texture handle
}

// Implemented by xidk
// Graphics device and texture binding
namespace GraphicsDevice_Addresses {
	constexpr uintptr_t ADDR_CGXDEVICE_RS_SET = 0x00685F50; // void __thiscall CGxDevice::RsSet(this, state, value) - sets render state
	constexpr uintptr_t GLOBAL_GX_DEVICE_PTR = 0x00C5DF88; // CGxDevice* g_theGxDevicePtr - global graphics device
	constexpr uint32_t GxRs_Texture0 = 21;                // First texture unit
}

// Implemented by xidk
// Shader UV matrix: parent context can set wrong UV scale/scroll -> texture sampled at 0,0 or off-image -> white.
// Set to 0 to disable. 0x873480 = SetTexMtx_Identity(int slot) per RE.
namespace ShaderEffect_Addresses {
	constexpr uintptr_t ADDR_SET_TEX_MTX_IDENTITY = 0x00873480; // void __cdecl SetTexMtx_Identity(int slot) - force identity UV; 0 to disable
}


namespace CM2Scene_Addresses {
	constexpr uintptr_t ADDR_ATTACH_PARENT = 0x831630;
}

namespace CM2Model_Addresses {
	constexpr uintptr_t ADDR_CREATE_MODEL = 0x81F8F0;
	constexpr uintptr_t ADDR_INIT_LOADED = 0x832EA0;


	// Implemented by xidk
	// Verified addresses for Build 12340 from IDA Pro analysis
	constexpr uintptr_t ADDR_IS_LOADED = 0x824F00;
	constexpr uintptr_t ADDR_IS_RENDER_READY = 0x824FC0;   // int __thiscall (pModel, loadData, checkChildren) - GATEKEEPER for rendering
	constexpr uintptr_t ADDR_IS_DRAWABLE = 0x824FC0;       // bool __thiscall (pModel, wait, checkChildren) - same as ADDR_IS_RENDER_READY
	constexpr uintptr_t ADDR_WAIT_FOR_LOAD = 0x823ED0;    // int __thiscall (pModel, int) - blocks until async load completes; calls PostLoadInit if m_instanceFlags & 0x20
	constexpr uintptr_t ADDR_SET_ANIMATING = 0x823F10;    // void __thiscall (pModel, bool) - adds/removes model from scene animation list (m_scene+0x28)
	constexpr uintptr_t ADDR_REPLACE_TEXTURE = 0x825260;   // void __thiscall (pModel, slot, hTexture)
	constexpr uintptr_t ADDR_INITIALIZE_LOADED = 0x832EA0; // void __thiscall (pModel) - PostLoadInit: allocates bones/matrices/textures, builds runtime state
	constexpr uintptr_t ADDR_UPDATE_RENDER_BATCHES = 0x97FAD0; // int __thiscall (pBatch, slot, hTexture) - directly updates GPU batches
	constexpr uintptr_t ADDR_SET_BONE_SEQUENCE = 0x825EE0;  // CheckSequenceId(pModel, sequenceId) - wrong for PlayBoneAnimation
	constexpr uintptr_t ADDR_PLAY_BONE_SEQUENCE = 0x832AB0; // void __thiscall SetBoneSequence(this, boneId, animId, variationId, startTime, speed, transitionTime, flags)
	constexpr uintptr_t ADDR_IS_ANIMATION_VALID = 0x826A60;
	constexpr uintptr_t ADDR_GET_ATTACHMENT_POS = 0x827460;
	constexpr uintptr_t ADDR_ANIMATE = 0x830DC0;
	constexpr uintptr_t ADDR_FORCE_ANIMATE = 0x830F90;
	constexpr uintptr_t ADDR_ATTACH_TO_PARENT = 0x831630;
	constexpr uintptr_t ADDR_ATTACH_TO_SCENE = 0x834540;  // void __thiscall (pModel, pScene) - links model into scene+8 list; when loaded, inits lights and PlayBoneAnimation
	constexpr uintptr_t ADDR_SETUP_LIGHTING = 0x831AF0;   // void __thiscall CM2Model::UpdateLighting(this) - fills m_lighting at +0x1D4 (same as SetupLighting)

	// Verified offsets
	constexpr uintptr_t OFF_INSTANCE_FLAGS = 0x04;  // m_instanceFlags - Bit 0x20: PostLoadRequired (WaitForLoad calls PostLoadInit when set)
	constexpr uintptr_t OFF_ALPHA = 0x178;  // Verified from CGUnit_C::ReleaseMissiles at 0x72DF5B
	constexpr uintptr_t OFF_FLAGS = 0x10;   // m_statusFlags - visibility/state (Bit 0: Loaded, Bit 2: TexturesReady)
	constexpr uint32_t FLAG_POST_LOAD_REQUIRED = 0x20; // OFF_INSTANCE_FLAGS - must set before WaitForLoad so it runs PostLoadInit
	constexpr uintptr_t OFF_CALLBACK_BONE_IDX = 0x14; // uint16_t - set 0xFFFF to disable callbacks on standalone model
	constexpr uint32_t FLAG_VISIBLE = 0x8000;
	constexpr uint32_t FLAG_HAS_CALLBACKS = 0x400000; // Clear to avoid ProcessCallbacks crash on standalone model
	constexpr uint32_t FLAG_INITIALIZED = 0x1; // Bit 0: Model has completed InitializeLoaded
	constexpr uint32_t FLAG_OPTIMIZED = 0x10; // When set, prevents geometry rebuild
	constexpr uintptr_t OFF_SCENE = 0x28;        // CM2Scene* - required for SetupLighting/SelectLights
	constexpr uintptr_t OFF_SHARED_DATA = 0x2C;  // M2ModelData* / M2Shared* - resource data, null until file loads
	constexpr uintptr_t OFF_PENDING_CMDS = 0x34; // M2Command* head
	constexpr uintptr_t OFF_PENDING_TAIL = 0x38; // M2Command** tail
	constexpr uintptr_t OFF_BONES = 0x94; // CBoneInstance* array
	constexpr uintptr_t OFF_BONE_LOOKUP = 0x7C;  // animation bone indices - DrawBatch skinning loop (0x82048D) uses with 0x48
	constexpr uintptr_t OFF_BONE_MATRICES = 0x98; // C44Matrix* array - DrawBatch skinning loop uses with 0x60
	constexpr uintptr_t OFF_GEOSET_VIS = 0x9C; // uint32_t* visibility bitmask
	constexpr uintptr_t OFF_NUM_TEXTURES = 0x50;   // uint32_t - used by BindPassTextures for texId bounds
	constexpr uintptr_t OFF_TEXTURE_LOOKUP = 0x84;  // uint16_t* - batch uses textureLookupId + unit to index this
	constexpr uintptr_t OFF_TEXTURE_OVERRIDE_ARRAY = 0xA4; // CTexture** array
	constexpr uintptr_t OFF_WORLD_TRANSFORM = 0xB4; // C44Matrix
	constexpr uintptr_t OFF_NEXT_IN_SCENE = 0x44;   // CM2Model* next for animation list (scene+0x28)
	constexpr uintptr_t OFF_NEXT_IN_RENDER = 0x6C;  // CM2Model* next for RENDER list (scene+0x2C) - loop 0x821C50
	constexpr uintptr_t OFF_PREV_IN_SCENE = 0x40;   // CM2Model* prev - Animate clears [ecx+40h],[ecx+44h] at 0x821C1A
	constexpr uint32_t FLAG_HIDDEN = 0x4000;        // If set at 0x10, render loop skips (0x821C7F)
	constexpr uintptr_t OFF_PARENT = 0x48;          // CM2Model* m_parent - if non-NULL, Animate skips UpdateLighting (treat as root = set to NULL)
	constexpr uintptr_t OFF_RENDER_BATCHES = 0x2BC; // Pointer to array of render batch pointers
	constexpr uintptr_t OFF_RENDER_BATCH_COUNT = 0x2B8; // Number of render batches
	constexpr uintptr_t OFF_OPTIMIZED_GEOM = 0x2D0; // void* - hardware buffer batch
	constexpr uintptr_t OFF_LIGHTING = 0x1D4;       // CM2Lighting / lighting state - SetupLighting reads this; only first 128 bytes used
	constexpr uintptr_t OFF_LIGHTING_SIZE = 128;    // Copy only 128 bytes (32 floats). Full struct is 0xD4; copying more overwrites m_centerOffset (0x292) and corrupts rendering (white model).
	constexpr uintptr_t OFF_M_POSITION = 0x124;     // C3Vector - position used by UpdateLighting (TransformPoint then BeginFrame/SelectLights); set to world X,Y,Z
	constexpr uintptr_t OFF_CENTER_OFFSET = 0x292;  // C3Vector - lighting center; we also set 0x124 (m_position) as that is what UpdateLighting uses for SelectLights
	constexpr uintptr_t OFF_VISIBILITY_RADIUS = 0x118;  // float - visibility/bounding sphere radius for culling
	constexpr uintptr_t OFF_VISIBILITY_MIN = 0x10C;     // C3Vector - bounding box min for frustum culling
	constexpr uintptr_t OFF_VISIBILITY_MAX = 0x11C;     // C3Vector - bounding box max for frustum culling
}

namespace CTexture_Addresses {
		constexpr uintptr_t ADDR_TEXTURE_CREATE_3 = 0x4B9760;
		constexpr uintptr_t ADDR_TEXTURE_CREATE = 0x4B8C80;
		constexpr uintptr_t ADDR_TEXTURE_CREATE_BLOB = 0x4B8D70;
		constexpr uintptr_t ADDR_TEXTURE_CREATE_SOLID = 0x4B9550;
}

namespace CGxTexFlags_Addresses {
		constexpr uintptr_t ADDR_CONSTRUCTOR = 0x681BE0;
		constexpr uintptr_t ADDR_TEX_FLAGS = 0x4B9200;
}

namespace CCharacterComponent_Addresses {
		constexpr uintptr_t ADDR_ADD_HAND_ITEM = 0x4EACD0;
		constexpr uintptr_t ADDR_REMOVE_LINK_PT = 0x4E79A0;
}