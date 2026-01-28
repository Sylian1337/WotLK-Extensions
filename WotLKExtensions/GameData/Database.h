//GameData/Database.h
#pragma once
#include "Addresses.h"

namespace DBGloabls
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