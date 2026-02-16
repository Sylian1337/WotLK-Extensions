//GameData/Database.h
#pragma once
#include "Addresses.h"

namespace DBCGloabls
{
	// Usage: uint32_t* dbPtr = *DB::g_spellDB;

	static void** g_achievementDB = (void**)DBCAddresses::ACHIEVEMENTDB;
	static void** g_achievement_CategoryDB = (void**)DBCAddresses::ACHIEVEMENT_CATEGORYDB;
	static void** g_achievement_CriteriaDB = (void**)DBCAddresses::ACHIEVEMENT_CRITERIADB;
	static void** g_animationDataDB = (void**)DBCAddresses::ANIMATIONDATADB;
	static void** g_areaGroupDB = (void**)DBCAddresses::AREAGROUPDB;
	static void** g_areaPOIDB = (void**)DBCAddresses::AREAPOIDB;
	static void** g_areaTableDB = (void**)DBCAddresses::AREATABLEDB;
	static void** g_areaTriggerDB = (void**)DBCAddresses::AREATRIGGERDB;
	static void** g_attackAnimKitsDB = (void**)DBCAddresses::ATTACKANIMKITSDB;
	static void** g_attackAnimTypesDB = (void**)DBCAddresses::ATTACKANIMTYPESDB;
	static void** g_auctionHouseDB = (void**)DBCAddresses::AUCTIONHOUSEDB;

	static void** g_bankBagSlotPricesDB = (void**)DBCAddresses::BANKBAGSLOTPRICESDB;
	static void** g_bannedAddOnsDB = (void**)DBCAddresses::BANNEDADDONSDB;
	static void** g_barberShopStyleDB				= (void**)DBCAddresses::BARBERSHOP_STYLE_DB;
	static void** g_battlemasterListDB				= (void**)DBCAddresses::BATTLEMASTER_LIST_DB;

	static void** g_cameraShakesDB					= (void**)DBCAddresses::CAMERA_SHAKES_DB;
	static void** g_cfg_CategoriesDB				= (void**)DBCAddresses::CFG_CATEGORIES_DB;
	static void** g_cfg_ConfigsDB					= (void**)DBCAddresses::CFG_CONFIGS_DB;
	static void** g_characterFacialHairStylesDB		= (void**)DBCAddresses::CHARACTER_FACIAL_HAIRSTYLES_DB;
	static void** g_charBaseInfoDB					= (void**)DBCAddresses::CHAR_BASE_INFO_DB;
	static void** g_charHairGeosetsDB				= (void**)DBCAddresses::CHAR_HAIR_GEOSETS_DB;
	static void** g_charSectionsDB					= (void**)DBCAddresses::CHAR_SECTIONS_DB;
	static void** g_charStartOutfitDB				= (void**)DBCAddresses::CHAR_STARTOUT_FIT_DB;
	static void** g_charTitlesDB					= (void**)DBCAddresses::CHAR_TITLES_DB;
	static void** g_chatChannelsDB					= (void**)DBCAddresses::CHAT_CHANNELS_DB;
	static void** g_chatProfanityDB					= (void**)DBCAddresses::CHAT_PROFANITY_DB;
	static void** g_chrClassesDB					= (void**)DBCAddresses::CHR_CLASSES_DB;
	static void** g_chrRacesDB						= (void**)DBCAddresses::CHR_RACES_DB;
	static void** g_cinematicCameraDB				= (void**)DBCAddresses::CINEMATIC_CAMERA_DB;
	static void** g_cinematicSequencesDB			= (void**)DBCAddresses::CINEMATIC_SEQUENCES_DB;
	static void** g_creatureDisplayInfoDB			= (void**)DBCAddresses::CREATURE_DISPLAYINFO_DB;
	static void** g_creatureDisplayInfoExtraDB		= (void**)DBCAddresses::CREATURE_DISPLAYINFO_EXTRA_DB;
	static void** g_creatureFamilyDB				= (void**)DBCAddresses::CREATURE_FAMILY_DB;
	static void** g_creatureModelDataDB				= (void**)DBCAddresses::CREATURE_MODELDATA_DB;
	static void** g_creatureMovementInfoDB			= (void**)DBCAddresses::CREATURE_MOVEMENTINFO_DB;
	static void** g_creatureSoundDataDB				= (void**)DBCAddresses::CREATURE_SOUNDDATA_DB;
	static void** g_creatureSpellDataDB				= (void**)DBCAddresses::CREATURE_SPELLDATA_DB;
	static void** g_creatureTypeDB					= (void**)DBCAddresses::CREATURE_TYPE_DB;
	static void** g_currencyCategoryDB				= (void**)DBCAddresses::CURRENCY_CATEGORY_DB;
	static void** g_currencyTypesDB					= (void**)DBCAddresses::CURRENCY_TYPES_DB;

	static void** g_danceMovesDB					= (void**)DBCAddresses::DANCEMOVES_DB;
	static void** g_deathThudLookupsDB				= (void**)DBCAddresses::DEATHTHUD_LOOKUPS_DB;
	static void** g_destructibleModelDataDB = (void**)DBCAddresses::DESTRUCTIBLEMODELDATADB;
	static void** g_dungeonEncounterDB = (void**)DBCAddresses::DUNGEONENCOUNTERDB;
	static void** g_dungeonMapChunkDB = (void**)DBCAddresses::DUNGEONMAPCHUNKDB;
	static void** g_dungeonMapDB = (void**)DBCAddresses::DUNGEONMAPDB;
	static void** g_durabilityCostsDB = (void**)DBCAddresses::DURABILITYCOSTSDB;
	static void** g_durabilityQualityDB = (void**)DBCAddresses::DURABILITYQUALITYDB;

	static void** g_emotesDB = (void**)DBCAddresses::EMOTESDB;
	static void** g_emotesTextDataDB = (void**)DBCAddresses::EMOTESTEXTDATADB;
	static void** g_emotesTextDB = (void**)DBCAddresses::EMOTESTEXTDB;
	static void** g_emotesTextSoundDB = (void**)DBCAddresses::EMOTESTEXTSOUNDDB;
	static void** g_environmentalDamageDB = (void**)DBCAddresses::ENVIRONMENTALDAMAGEDB;
	static void** g_exhaustionDB = (void**)DBCAddresses::EXHAUSTIONDB;

	static void** g_factionDB = (void**)DBCAddresses::FACTIONDB;
	static void** g_factionGroupDB = (void**)DBCAddresses::FACTIONGROUPDB;
	static void** g_factionTemplateDB = (void**)DBCAddresses::FACTIONTEMPLATEDB;
	static void** g_fileDataDB = (void**)DBCAddresses::FILEDATADB;
	static void** g_footprintTexturesDB = (void**)DBCAddresses::FOOTPRINTTEXTURESDB;
	static void** g_footstepTerrainLookupDB = (void**)DBCAddresses::FOOTSTEPTERRAINLOOKUPDB;

	static void** g_gameObjectArtKitDB = (void**)DBCAddresses::GAMEOBJECTARTKITDB;
	static void** g_gameObjectDisplayInfoDB = (void**)DBCAddresses::GAMEOBJECTDISPLAYINFODB;
	static void** g_gameTablesDB = (void**)DBCAddresses::GAMETABLESDB;
	static void** g_gameTipsDB = (void**)DBCAddresses::GAMETIPSDB;
	static void** g_gemPropertiesDB = (void**)DBCAddresses::GEMPROPERTIESDB;
	static void** g_glyphPropertiesDB = (void**)DBCAddresses::GLYPHPROPERTIESDB;
	static void** g_glyphSlotDB = (void**)DBCAddresses::GLYPHSLOTDB;
	static void** g_gMSurveyAnswersDB = (void**)DBCAddresses::GMSURVEYANSWERSDB;
	static void** g_gMSurveyCurrentSurveyDB = (void**)DBCAddresses::GMSURVEYCURRENTSURVEYDB;
	static void** g_gMSurveyQuestionsDB = (void**)DBCAddresses::GMSURVEYQUESTIONSDB;
	static void** g_gMSurveySurveysDB = (void**)DBCAddresses::GMSURVEYSURVEYSDB;
	static void** g_gMTicketCategoryDB = (void**)DBCAddresses::GMTICKETCATEGORYDB;
	static void** g_groundEffectDoodadDB = (void**)DBCAddresses::GROUNDEFFECTDOODADDB;
	static void** g_groundEffectTextureDB = (void**)DBCAddresses::GROUNDEFFECTTEXTUREDB;
	static void** g_gtBarberShopCostBaseDB = (void**)DBCAddresses::GTBARBERSHOPCOSTBASEDB;
	static void** g_gtChanceToMeleeCritBaseDB = (void**)DBCAddresses::GTCHANCETOMELEECRITBASEDB;
	static void** g_gtChanceToMeleeCritDB = (void**)DBCAddresses::GTCHANCETOMELEECRITDB;
	static void** g_gtChanceToSpellCritBaseDB = (void**)DBCAddresses::GTCHANCETOSPELLCRITBASEDB;
	static void** g_gtChanceToSpellCritDB = (void**)DBCAddresses::GTCHANCETOSPELLCRITDB;
	static void** g_gtCombatRatingsDB = (void**)DBCAddresses::GTCOMBATRATINGSDB;
	static void** g_gtNPCManaCostScalerDB = (void**)DBCAddresses::GTNPCMANACOSTSCALERDB;
	static void** g_gtOCTClassCombatRatingScalarDB = (void**)DBCAddresses::GTOCTCLASSCOMBATRATINGSCALARDB;
	static void** g_gtOCTRegenHPDB = (void**)DBCAddresses::GTOCTREGENHPDB;
	static void** g_gtOCTRegenMPDB = (void**)DBCAddresses::GTOCTREGENMPDB;
	static void** g_gtRegenHPPerSptDB = (void**)DBCAddresses::GTREGENHPPERSPTDB;
	static void** g_gtRegenMPPerSptDB = (void**)DBCAddresses::GTREGENMPPERSPTDB;

	static void** g_helmetGeosetVisDataDB = (void**)DBCAddresses::HELMETGEOSETVISDATADB;
	static void** g_holidayDescriptionsDB = (void**)DBCAddresses::HOLIDAYDESCRIPTIONSDB;
	static void** g_holidayNamesDB = (void**)DBCAddresses::HOLIDAYNAMESDB;
	static void** g_holidaysDB = (void**)DBCAddresses::HOLIDAYSDB;

	static void** g_itemBagFamilyDB = (void**)DBCAddresses::ITEMBAGFAMILYDB;
	static void** g_itemClassDB = (void**)DBCAddresses::ITEMCLASSDB;
	static void** g_itemCondExtCostsDB = (void**)DBCAddresses::ITEMCONDEXTCOSTSDB;
	static void** g_itemDB = (void**)DBCAddresses::ITEMDB;
	static void** g_itemDisplayInfoDB = (void**)DBCAddresses::ITEMDISPLAYINFODB;
	static void** g_itemExtendedCostDB = (void**)DBCAddresses::ITEMEXTENDEDCOSTDB;
	static void** g_itemGroupSoundsDB = (void**)DBCAddresses::ITEMGROUPSOUNDSDB;
	static void** g_itemLimitCategoryDB = (void**)DBCAddresses::ITEMLIMITCATEGORYDB;
	static void** g_itemPetFoodDB = (void**)DBCAddresses::ITEMPETFOODDB;
	static void** g_itemPurchaseGroupDB = (void**)DBCAddresses::ITEMPURCHASEGROUPDB;
	static void** g_itemRandomPropertiesDB = (void**)DBCAddresses::ITEMRANDOMPROPERTIESDB;
	static void** g_itemRandomSuffixDB = (void**)DBCAddresses::ITEMRANDOMSUFFIXDB;
	static void** g_itemSetDB = (void**)DBCAddresses::ITEMSETDB;
	static void** g_itemSubClassDB = (void**)DBCAddresses::ITEMSUBCLASSDB;
	static void** g_itemSubClassMaskDB = (void**)DBCAddresses::ITEMSUBCLASSMASKDB;
	static void** g_itemVisualEffectsDB = (void**)DBCAddresses::ITEMVISUALEFFECTSDB;
	static void** g_itemVisualsDB = (void**)DBCAddresses::ITEMVISUALSDB;

	static void** g_languagesDB = (void**)DBCAddresses::LANGUAGESDB;
	static void** g_languageWordsDB = (void**)DBCAddresses::LANGUAGEWORDSDB;
	static void** g_lfgDungeonExpansionDB = (void**)DBCAddresses::LFGDUNGEONEXPANSIONDB;
	static void** g_lfgDungeonGroupDB = (void**)DBCAddresses::LFGDUNGEONGROUPDB;
	static void** g_lfgDungeonsDB = (void**)DBCAddresses::LFGDUNGEONSDB;
	static void** g_liquidMaterialDB = (void**)DBCAddresses::LIQUIDMATERIALDB;
	static void** g_liquidTypeDB = (void**)DBCAddresses::LIQUIDTYPEDB;
	static void** g_loadingScreensDB = (void**)DBCAddresses::LOADINGSCREENSDB;
	static void** g_loadingScreenTaxiSplinesDB = (void**)DBCAddresses::LOADINGSCREENTAXISPLINESDB;
	static void** g_lockDB = (void**)DBCAddresses::LOCKDB;
	static void** g_lockTypeDB = (void**)DBCAddresses::LOCKTYPEDB;

	static void** g_mailTemplateDB = (void**)DBCAddresses::MAILTEMPLATEDB;
	static void** g_mapDB = (void**)DBCAddresses::MAPDB;
	static void** g_mapDifficultyDB = (void**)DBCAddresses::MAPDIFFICULTYDB;
	static void** g_materialDB = (void**)DBCAddresses::MATERIALDB;
	static void** g_movieDB = (void**)DBCAddresses::MOVIEDB;
	static void** g_movieFileDataDB = (void**)DBCAddresses::MOVIEFILEDATADB;
	static void** g_movieVariationDB = (void**)DBCAddresses::MOVIEVARIATIONDB;

	static void** g_nameGenDB = (void**)DBCAddresses::NAMEGENDB;
	static void** g_namesProfanityDB = (void**)DBCAddresses::NAMESPROFANITYDB;
	static void** g_namesReservedDB = (void**)DBCAddresses::NAMESRESERVEDDB;
	static void** g_nPCSoundsDB = (void**)DBCAddresses::NPCSOUNDSDB;

	static void** g_objectEffectDB = (void**)DBCAddresses::OBJECTEFFECTDB;
	static void** g_objectEffectGroupDB = (void**)DBCAddresses::OBJECTEFFECTGROUPDB;
	static void** g_objectEffectModifierDB = (void**)DBCAddresses::OBJECTEFFECTMODIFIERDB;
	static void** g_objectEffectPackageDB = (void**)DBCAddresses::OBJECTEFFECTPACKAGEDB;
	static void** g_objectEffectPackageElemDB = (void**)DBCAddresses::OBJECTEFFECTPACKAGEELEMDB;
	static void** g_overrideSpellDataDB = (void**)DBCAddresses::OVERRIDESPELLDATADB;

	static void** g_packageDB = (void**)DBCAddresses::PACKAGEDB;
	static void** g_pageTextMaterialDB = (void**)DBCAddresses::PAGETEXTMATERIALDB;
	static void** g_paperDollItemFrameDB = (void**)DBCAddresses::PAPERDOLLITEMFRAMEDB;
	static void** g_particleColorDB = (void**)DBCAddresses::PARTICLECOLORDB;
	static void** g_petPersonalityDB = (void**)DBCAddresses::PETPERSONALITYDB;
	static void** g_powerDisplayDB = (void**)DBCAddresses::POWERDISPLAYDB;
	static void** g_pvpDifficultyDB = (void**)DBCAddresses::PVPDIFFICULTYDB;

	static void** g_questFactionRewardDB = (void**)DBCAddresses::QUESTFACTIONREWARDDB;
	static void** g_questInfoDB = (void**)DBCAddresses::QUESTINFODB;
	static void** g_questSortDB = (void**)DBCAddresses::QUESTSORTDB;
	static void** g_questXPDB = (void**)DBCAddresses::QUESTXPDB;

	static void** g_randPropPointsDB = (void**)DBCAddresses::RANDPROPPOINTSDB;
	static void** g_resistancesDB = (void**)DBCAddresses::RESISTANCESDB;

	static void** g_scalingStatDistributionDB = (void**)DBCAddresses::SCALINGSTATDISTRIBUTIONDB;
	static void** g_scalingStatValuesDB = (void**)DBCAddresses::SCALINGSTATVALUESDB;
	static void** g_screenEffectDB = (void**)DBCAddresses::SCREENEFFECTDB;
	static void** g_serverMessagesDB = (void**)DBCAddresses::SERVERMESSAGESDB;
	static void** g_sheatheSoundLookupsDB = (void**)DBCAddresses::SHEATHESOUNDLOOKUPSDB;
	static void** g_skillCostsDataDB = (void**)DBCAddresses::SKILLCOSTSDATADB;
	static void** g_skillLineAbilityDB = (void**)DBCAddresses::SKILLLINEABILITYDB;
	static void** g_skillLineCategoryDB = (void**)DBCAddresses::SKILLLINECATEGORYDB;
	static void** g_skillLineDB = (void**)DBCAddresses::SKILLLINEDB;
	static void** g_skillRaceClassInfoDB = (void**)DBCAddresses::SKILLRACECLASSINFODB;
	static void** g_skillTiersDB = (void**)DBCAddresses::SKILLTIERSDB;
	static void** g_soundAmbienceDB = (void**)DBCAddresses::SOUNDAMBIENCEDB;
	static void** g_soundEmittersDB = (void**)DBCAddresses::SOUNDEMITTERSDB;
	static void** g_soundEntriesAdvancedDB = (void**)DBCAddresses::SOUNDENTRIESADVANCEDDB;
	static void** g_soundEntriesDB = (void**)DBCAddresses::SOUNDENTRIESDB;
	static void** g_soundFilterDB = (void**)DBCAddresses::SOUNDFILTERDB;
	static void** g_soundFilterElemDB = (void**)DBCAddresses::SOUNDFILTERELEMDB;
	static void** g_soundProviderPreferencesDB = (void**)DBCAddresses::SOUNDPROVIDERPREFERENCESDB;
	static void** g_soundSamplePreferencesDB = (void**)DBCAddresses::SOUNDSAMPLEPREFERENCESDB;
	static void** g_soundWaterTypeDB = (void**)DBCAddresses::SOUNDWATERTYPEDB;
	static void** g_spamMessagesDB = (void**)DBCAddresses::SPAMMESSAGESDB;
	static void** g_spellCastTimesDB = (void**)DBCAddresses::SPELLCASTTIMESDB;
	static void** g_spellCategoryDB = (void**)DBCAddresses::SPELLCATEGORYDB;
	static void** g_spellChainEffectsDB = (void**)DBCAddresses::SPELLCHAINEFFECTSDB;
	static void** g_spellDB = (void**)DBCAddresses::SPELLDB;
	static void** g_spellDescriptionVariablesDB = (void**)DBCAddresses::SPELLDESCRIPTIONVARIABLESDB;
	static void** g_spellDifficultyDB = (void**)DBCAddresses::SPELLDIFFICULTYDB;
	static void** g_spellDispelTypeDB = (void**)DBCAddresses::SPELLDISPELTYPEDB;
	static void** g_spellDurationDB = (void**)DBCAddresses::SPELLDURATIONDB;
	static void** g_spellEffectCameraShakesDB = (void**)DBCAddresses::SPELLEFFECTCAMERASHAKESDB;
	static void** g_spellFocusObjectDB = (void**)DBCAddresses::SPELLFOCUSOBJECTDB;
	static void** g_spellIconDB = (void**)DBCAddresses::SPELLICONDB;
	static void** g_spellItemEnchantmentConditionDB = (void**)DBCAddresses::SPELLITEMENCHANTMENTCONDITIONDB;
	static void** g_spellItemEnchantmentDB = (void**)DBCAddresses::SPELLITEMENCHANTMENTDB;
	static void** g_spellMechanicDB = (void**)DBCAddresses::SPELLMECHANICDB;
	static void** g_spellMissileDB = (void**)DBCAddresses::SPELLMISSILEDB;
	static void** g_spellMissileMotionDB = (void**)DBCAddresses::SPELLMISSILEMOTIONDB;
	static void** g_spellRadiusDB = (void**)DBCAddresses::SPELLRADIUSDB;
	static void** g_spellRangeDB = (void**)DBCAddresses::SPELLRANGEDB;
	static void** g_spellRuneCostDB = (void**)DBCAddresses::SPELLRUNECOSTDB;
	static void** g_spellShapeshiftFormDB = (void**)DBCAddresses::SPELLSHAPESHIFTFORMDB;
	static void** g_spellVisualDB = (void**)DBCAddresses::SPELLVISUALDB;
	static void** g_spellVisualEffectNameDB = (void**)DBCAddresses::SPELLVISUALEFFECTNAMEDB;
	static void** g_spellVisualKitAreaModelDB = (void**)DBCAddresses::SPELLVISUALKITAREAMODELDB;
	static void** g_spellVisualKitDB = (void**)DBCAddresses::SPELLVISUALKITDB;
	static void** g_spellVisualKitModelAttachDB = (void**)DBCAddresses::SPELLVISUALKITMODELATTACHDB;
	static void** g_stableSlotPricesDB = (void**)DBCAddresses::STABLESLOTPRICESDB;
	static void** g_stationeryDB = (void**)DBCAddresses::STATIONERYDB;
	static void** g_stringLookupsDB = (void**)DBCAddresses::STRINGLOOKUPSDB;
	static void** g_summonPropertiesDB = (void**)DBCAddresses::SUMMONPROPERTIESDB;

	static void** g_talentDB = (void**)DBCAddresses::TALENTDB;
	static void** g_talentTabDB = (void**)DBCAddresses::TALENTTABDB;
	static void** g_taxiNodesDB = (void**)DBCAddresses::TAXINODESDB;
	static void** g_taxiPathDB = (void**)DBCAddresses::TAXIPATHDB;
	static void** g_taxiPathNodeDB = (void**)DBCAddresses::TAXIPATHNODEDB;
	static void** g_teamContributionPointsDB = (void**)DBCAddresses::TEAMCONTRIBUTIONPOINTSDB;
	static void** g_terrainTypeDB = (void**)DBCAddresses::TERRAINTYPEDB;
	static void** g_terrainTypeSoundsDB = (void**)DBCAddresses::TERRAINTYPESOUNDSDB;
	static void** g_totemCategoryDB = (void**)DBCAddresses::TOTEMCATEGORYDB;
	static void** g_transportAnimationDB = (void**)DBCAddresses::TRANSPORTANIMATIONDB;
	static void** g_transportPhysicsDB = (void**)DBCAddresses::TRANSPORTPHYSICSDB;
	static void** g_transportRotationDB = (void**)DBCAddresses::TRANSPORTROTATIONDB;

	static void** g_uISoundLookupsDB = (void**)DBCAddresses::UISOUNDLOOKUPSDB;
	static void** g_unitBloodDB = (void**)DBCAddresses::UNITBLOODDB;
	static void** g_unitBloodLevelsDB = (void**)DBCAddresses::UNITBLOODLEVELSDB;

	static void** g_vehicleDB = (void**)DBCAddresses::VEHICLEDB;
	static void** g_vehicleSeatDB = (void**)DBCAddresses::VEHICLESEATDB;
	static void** g_vehicleUIIndicatorDB = (void**)DBCAddresses::VEHICLEUIINDICATORDB;
	static void** g_vehicleUIIndSeatDB = (void**)DBCAddresses::VEHICLEUIINDSEATDB;
	static void** g_vocalUISoundsDB = (void**)DBCAddresses::VOCALUISOUNDSDB;

	static void** g_weaponImpactSoundsDB = (void**)DBCAddresses::WEAPONIMPACTSOUNDSDB;
	static void** g_weaponSwingSounds2DB = (void**)DBCAddresses::WEAPONSWINGSOUNDS2DB;
	static void** g_weatherDB = (void**)DBCAddresses::WEATHERDB;
	static void** g_wMOAreaTableDB = (void**)DBCAddresses::WMOAREATABLEDB;
	static void** g_worldChunkSoundsDB = (void**)DBCAddresses::WORLDCHUNKSOUNDSDB;
	static void** g_worldMapAreaDB = (void**)DBCAddresses::WORLDMAPAREADB;
	static void** g_worldMapContinentDB = (void**)DBCAddresses::WORLDMAPCONTINENTDB;
	static void** g_worldMapOverlayDB = (void**)DBCAddresses::WORLDMAPOVERLAYDB;
	static void** g_worldMapTransformsDB = (void**)DBCAddresses::WORLDMAPTRANSFORMSDB;
	static void** g_worldSafeLocsDB = (void**)DBCAddresses::WORLDSAFELOCSDB;
	static void** g_worldStateUIDB = (void**)DBCAddresses::WORLDSTATEUIDB;
	static void** g_worldStateZoneSoundsDB = (void**)DBCAddresses::WORLDSTATEZONESOUNDSDB;

	static void** g_zoneIntroMusicTableDB = (void**)DBCAddresses::ZONEINTROMUSICTABLEDB;
	static void** g_zoneMusicDB = (void**)DBCAddresses::ZONEMUSICDB;

	// Helper function to get a database record
	template<typename T>
	inline T* GetRecord(void** db, uint32_t id)
	{
		if (!db || !*db) return nullptr;
		// Database access logic here
		return (T*)((uintptr_t)(*db) + (id * sizeof(T)));
	}
}

// These are static locations, like the DBGlobals, just these holds the data gotten from the server at start-up.
namespace CacheGloabls {
	//static void** g_itemCacheDB = (void**)DBCacheAddresses::DB_ITEM_CACHE_GETINFOBYID;

}

namespace DBCacheStructs
{
	struct DBQuestCache {
		// 4‑byte fields at offsets 0, 4, 8, …, 176
		uint32_t questID;
		uint32_t questType;
		uint32_t questLevel;
		uint32_t minLevel;
		uint32_t questSortID;
		uint32_t questInfoID;
		uint32_t suggestedGroupNum;
		uint32_t requiredFactionId1;
		uint32_t requiredFactionId2;
		uint32_t requiredFactionId3;
		uint32_t requiredFactionValue1;
		uint32_t requiredFactionValue2;
		uint32_t rewardNextQuest;
		uint32_t rewardXPDifficulty;
		uint32_t rewardMoney;
		uint32_t field_60;
		uint32_t field_64;
		uint32_t field_68;
		uint32_t field_72;
		uint32_t flags;
		uint32_t field_80;
		uint32_t field_84;
		uint32_t field_88;
		uint32_t field_92;
		uint32_t field_96;
		uint32_t field_100;
		uint32_t field_104;
		uint32_t field_108;
		uint32_t field_112;
		uint32_t field_116;
		uint32_t field_120;
		uint32_t field_124;
		uint32_t field_128;
		uint32_t field_132;
		uint32_t field_136;
		uint32_t field_140;
		uint32_t field_144;
		uint32_t field_148;
		uint32_t field_152;
		uint32_t field_156;
		uint32_t field_160;
		uint32_t field_164;
		uint32_t field_168;
		uint32_t field_172;
		uint32_t field_176;

		// 19‑byte string at offset 180
		char questName;
	};

	/// <summary>
	/// Represents a cached database entry for a game object, containing an object type, display identifier, a few pointer fields, and numerous data/reserved fields.
	/// </summary>
	struct DBGameObjectCache
	{
		uint32_t Type;               // 0x000
		uint32_t DisplayID;          // 0x004
		uintptr_t unkPtr1;           // 0x008
		uintptr_t unkPtr2;           // 0x00C
		uintptr_t unkPtr3;           // 0x010
		uint32_t Data0;         	 // 0x014
		uint32_t Data1;          	 // 0x018
		uint32_t Data2;              // 0x01C
		uint32_t Data3;       		 // 0x020
		uint32_t Data4;              // 0x024
		uint32_t Data5;   			 // 0x028
		uint32_t Data6;           	 // 0x02C
		uint32_t Data7;        		 // 0x030
		uint32_t Data8;      		 // 0x034
		uint32_t Data9;        		 // 0x038
		uint32_t Data10;    		 // 0x03C
		uint32_t Data11;             // 0x040
		uint32_t Data12;             // 0x044
		uint32_t Data13;             // 0x048
		uint32_t Data14;             // 0x04C
		uint32_t Data15;             // 0x050
		uint32_t Data16;             // 0x054
		uint32_t Data17;             // 0x058
		uint32_t Data18;             // 0x05C
		uint32_t Data19;             // 0x060
		uint32_t Data20;             // 0x064
		uint32_t Data21;             // 0x068
		uint32_t Data22;             // 0x06C
		uint32_t Data23;             // 0x070
		uint32_t unk24;              // 0x074
		uint32_t unk25;              // 0x078
		uint32_t unk26;              // 0x07C
		uint32_t unk27;              // 0x080
		uint32_t unk28;              // 0x084
		uint32_t unk29;              // 0x088
		uint32_t unk30;              // 0x08C
		uintptr_t unkPtr4;           // 0x090
		uint32_t unk32;              // 0x094
		uint32_t unk33;              // 0x098
		uint32_t unk34;              // 0x09C
		uint32_t entry;              // 0x0A0
		uint32_t size;               // 0x0A4
		uint32_t unk37;              // 0x0A8
		uintptr_t unkPtr5;           // 0x0AC
		uintptr_t unkPtr6;           // 0x0B0
		uint32_t unk40;              // 0x0B4
		uint32_t unk41;              // 0x0B8
		uint32_t unk42;              // 0x0BC
		uintptr_t unkPtr7;           // 0x0C0
		uint32_t unk44;              // 0x0C4
		uintptr_t unkPtr8;           // 0x0C8
		uintptr_t unkPtr9;           // 0x0CC
		uintptr_t unkPtr10;          // 0x0D0
		uintptr_t unkPtr11;          // 0x0D4
		uintptr_t unkPtr12;          // 0x0D8
		uint32_t unk45;              // 0x0DC
	};
}


struct IDatabase__vtable
{
	void* v_fn_GetRecord;
};


struct WowClientDB_Base
{
	void** v_table;
	int32_t m_loaded;
	int32_t m_numRecords;
	int32_t m_maxID;
	int32_t m_minID;
	const char* m_strings;
};


struct SpellRec
{
	int32_t m_ID;
	int32_t m_category;
	int32_t m_dispelType;
	int32_t m_mechanic;
	int32_t m_attributes;
	int32_t m_attributesEx;
	int32_t m_attributesExB;
	int32_t m_attributesExC;
	int32_t m_attributesExD;
	int32_t m_attributesExE;
	int32_t m_attributesExF;
	int32_t m_attributesExG;
	int32_t m_shapeshiftMask[2];
	int32_t m_shapeshiftExclude[2];
	int32_t m_targets;
	int32_t m_targetCreatureType;
	int32_t m_requiresSpellFocus;
	int32_t m_facingCasterFlags;
	int32_t m_casterAuraState;
	int32_t m_targetAuraState;
	int32_t m_excludeCasterAuraState;
	int32_t m_excludeTargetAuraState;
	int32_t m_casterAuraSpell;
	int32_t m_targetAuraSpell;
	int32_t m_excludeCasterAuraSpell;
	int32_t m_excludeTargetAuraSpell;
	int32_t m_castingTimeIndex;
	int32_t m_recoveryTime;
	int32_t m_categoryRecoveryTime;
	int32_t m_interruptFlags;
	int32_t m_auraInterruptFlags;
	int32_t m_channelInterruptFlags;
	int32_t m_procTypeMask;
	int32_t m_procChance;
	int32_t m_procCharges;
	int32_t m_maxLevel;
	int32_t m_baseLevel;
	int32_t m_spellLevel;
	int32_t m_durationIndex;
	int32_t m_powerType;
	int32_t m_manaCost;
	int32_t m_manaCostPerLevel;
	int32_t m_manaPerSecond;
	int32_t m_manaPerSecondPerLevel;
	int32_t m_rangeIndex;
	float m_speed;
	int32_t m_modalNextSpell;
	int32_t m_cumulativeAura;
	int32_t m_totem[2];
	int32_t m_reagent[8];
	int32_t m_reagentCount[8];
	int32_t m_equippedItemClass;
	int32_t m_equippedItemSubclass;
	int32_t m_equippedItemInvTypes;
	int32_t m_effect[3];
	int32_t m_effectDieSides[3];
	float m_effectRealPointsPerLevel[3];
	int32_t m_effectBasePoints[3];
	int32_t m_effectMechanic[3];
	int32_t m_implicitTargetA[3];
	int32_t m_implicitTargetB[3];
	int32_t m_effectRadiusIndex[3];
	int32_t m_effectAura[3];
	int32_t m_effectAuraPeriod[3];
	float m_effectAmplitude[3];
	int32_t m_effectChainTargets[3];
	int32_t m_effectItemType[3];
	int32_t m_effectMiscValue[3];
	int32_t m_effectMiscValueB[3];
	int32_t m_effectTriggerSpell[3];
	float m_effectPointsPerCombo[3];
	int32_t m_effectSpellClassMaskA[3];
	int32_t m_effectSpellClassMaskB[3];
	int32_t m_effectSpellClassMaskC[3];
	int32_t m_spellVisualID[2];
	int32_t m_spellIconID;
	int32_t m_activeIconID;
	int32_t m_spellPriority;
	const char* m_name;
	const char* m_nameSubtext;
	const char* m_description;
	const char* m_auraDescription;
	int32_t m_manaCostPct;
	int32_t m_startRecoveryCategory;
	int32_t m_startRecoveryTime;
	int32_t m_maxTargetLevel;
	int32_t m_spellClassSet;
	int32_t m_spellClassMask[3];
	int32_t m_maxTargets;
	int32_t m_defenseType;
	int32_t m_preventionType;
	int32_t m_stanceBarOrder;
	float m_effectChainAmplitude[3];
	int32_t m_minFactionID;
	int32_t m_minReputation;
	int32_t m_requiredAuraVision;
	int32_t m_requiredTotemCategoryID[2];
	int32_t m_requiredAreasID;
	int32_t m_schoolMask;
	int32_t m_runeCostID;
	int32_t m_spellMissileID;
	int32_t m_powerDisplayID;
	float m_effectBonusCoefficient[3];
	int32_t m_descriptionVariablesID;
	int32_t m_difficulty;
};

struct IDatabase_SpellRec
{
	IDatabase__vtable* v_table;
	SpellRec* m_records;
	SpellRec** m_recordsById;
};


struct WowClientDB_Common_SpellRec
{
	WowClientDB_Base b_base;
};

struct WowClientDB_SpellRec
{
	WowClientDB_Common_SpellRec b_base_01;
	IDatabase_SpellRec b_base_02;
};



// ------------------------------------------------------- //
// Below are all the Record Structs for DBCs. //

namespace AchievementDBC_Rec {

	struct AchievementRec
	{
		int32_t m_ID;
		int32_t m_faction;
		int32_t m_instanceID;
		int32_t m_supercedes;
		const char* m_title;
		const char* m_description;
		int32_t m_category;
		int32_t m_points;
		int32_t m_uiOrder;
		int32_t m_flags;
		int32_t m_iconID;
		const char* m_reward;
		int32_t m_minimumCriteria;
		int32_t m_sharesCriteria;
	};

	struct Achievement_CategoryRec
	{
		int32_t m_ID;
		int32_t m_parent;
		const char* m_name;
		int32_t m_uiOrder;
	};

	struct Achievement_CriteriaRec
	{
		int32_t m_ID;
		int32_t m_achievementID;
		int32_t m_type;
		int32_t m_assetID;
		int32_t m_quantity;
		int32_t m_startEvent;
		int32_t m_startAsset;
		int32_t m_failEvent;
		int32_t m_failAsset;
		const char* m_description;
		int32_t m_flags;
		int32_t m_timerStartEvent;
		int32_t m_timerAssetID;
		int32_t m_timerTime;
		int32_t m_uiOrder;
	};
}

namespace AnimationDBC_Rec {

	struct AnimKitRec
	{
		int32_t m_ID;
		int32_t m_oneShotDuration;
		int32_t m_oneShotStopAnimKitID;
	};

	struct AnimKitBoneSetRec
	{
		int32_t m_ID;
		const char* m_name;
		int32_t m_boneDataID;
		int32_t m_parentAnimKitBoneSetID;
		int32_t m_extraBoneCount;
		int32_t m_altAnimKitBoneSetID;
	};

	struct AnimKitBoneSetAliasRec
	{
		int32_t m_ID;
		int32_t m_boneDataID;
		int32_t m_animKitBoneSetID;
	};

	struct AnimKitConfigRec
	{
		int32_t m_ID;
		int32_t m_configFlags;
	};

	struct AnimKitConfigBoneSetRec
	{
		int32_t m_ID;
		int32_t m_parentAnimKitConfigID;
		int32_t m_animKitBoneSetID;
		int32_t m_animKitPriorityID;
	};

	struct AnimKitPriorityRec
	{
		int32_t m_ID;
		int32_t m_priority;
	};

	struct AnimKitSegmentRec
	{
		int32_t m_ID;
		int32_t m_parentAnimKitID;
		int32_t m_animID;
		int32_t m_animStartTime;
		int32_t m_animKitConfigID;
		int32_t m_startCondition;
		int32_t m_startConditionParam;
		int32_t m_startConditionDelay;
		int32_t m_endCondition;
		int32_t m_endConditionParam;
		int32_t m_endConditionDelay;
		float m_speed;
		int32_t m_segmentFlags;
		int32_t m_forcedVariation;
		int32_t m_overrideConfigFlags;
		int32_t m_loopToSegmentIndex;
	};

	struct AnimReplacementRec
	{
		int32_t m_ID;
		int32_t m_srcAnimID;
		int32_t m_dstAnimID;
		int32_t m_parentAnimReplacementSetID;
	};

	struct AnimReplacementSetRec
	{
		int32_t m_ID;
		int32_t m_execOrder;
	};

	struct AnimationDataRec
	{
		int32_t m_ID;
		const char* m_name;
		int32_t m_weaponflags;
		int32_t m_bodyflags;
		int32_t m_flags;
		int32_t m_fallback;
		int32_t m_behaviorID;
		int32_t m_behaviorTier;
	};

}