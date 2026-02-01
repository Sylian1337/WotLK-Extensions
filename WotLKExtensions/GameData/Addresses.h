// GameData/Addresses.h
#pragma once
#include <cstdint>

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

namespace FuncAddresses {

# pragma region Client-Manager

	constexpr uintptr_t INITIALIZE_PLAYER = 0x6E83B0;
	constexpr uintptr_t GET_ACTIVE_PLAYER = 0x4D3790;
	constexpr uintptr_t GET_OBJECT_PTR = 0x4D4DB0;

# pragma endregion


	// Functions
	constexpr uintptr_t GET_SPELL_VISUAL_ROW = 0x007FA290;
	constexpr uintptr_t GET_LOCALIZED_ROW = 0x4CFD20;
	constexpr uintptr_t GET_ROW = 0x65C290;
	constexpr uintptr_t GET_GAME_TABLE_VALUE = 0x7F6990;

	// Client functions
	constexpr uintptr_t PROCESS_MESSAGE = 0x631FE0;
	constexpr uintptr_t SET_MESSAGE_HANDLER = 0x631FA0;
}

namespace CGPlayer_Vitrual_Functions {

	constexpr uintptr_t CGPLAYER_IS_DEAD_OR_GHOST = 0x6DAC10;

}