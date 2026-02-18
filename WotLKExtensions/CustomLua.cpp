#include "CustomLua.h"
#include "Player.h"
#include "CDBCMgr/CDBCDefs/LFGRoles.h"
#include "GameObjects/CGObject.h"
#include "GameObjects/CGItem.h"
#include <DBCReloader/DBCReloader.h>
#include <Hotpatches/HotpatchManager.h>
#include <GameData/Database.h>


void CustomLua::Apply()
{
	Util::OverwriteUInt32AtAddress(0x52AB17, (uint32_t)&LoadScriptFunctionsCustom - 0x52AB1B);

	RegisterFunctions();
}

int CustomLua::LoadScriptFunctionsCustom()
{
	for (auto it = luaFuncts.begin(); it != luaFuncts.end(); it++)
	{
		char* funcName = it->first;
		void* funcPtr = it->second;
	
		FrameScript::RegisterFunction(funcName, funcPtr);
	}

	return FrameScript::LoadFunctions();
}

int CustomLua::GetShapeshiftFormID(lua_State* L)
{
	uint64_t activePlayer = ClntObjMgr::GetActivePlayer();

	if (activePlayer)
	{
		CGUnit* activeObjectPtr = (CGUnit*)ClntObjMgr::ObjectPtr(activePlayer, TYPEMASK_UNIT);
		FrameScript::PushNumber(L, CGUnit_C::GetShapeshiftFormId(activeObjectPtr));
		return 1;
	}

	FrameScript::PushNumber(L, 0);
	return 1;
}

int CustomLua::GetSpellDescription(lua_State* L)
{
	if (FrameScript::IsNumber(L, 1))
	{
		uint32_t spellId = (uint32_t)FrameScript::GetNumber(L, 1);
		SpellRow row;
		char desc[1024];

		if (ClientDB::GetLocalizedRow((void*)0xAD49D0, spellId, &row))
		{
			SpellParser::ParseText(&row, &desc, 1024, 0, 0, 0, 0, 1, 0);
			FrameScript::PushString(L, desc);
			return 1;
		}
	}

	FrameScript::PushNil(L);
	return 1;
}

int CustomLua::GetSpellNameById(lua_State* L)
{
	if (FrameScript::IsNumber(L, 1))
	{
		uint32_t spellId = (uint32_t)FrameScript::GetNumber(L, 1);
		SpellRow row;

		if (ClientDB::GetLocalizedRow((void*)0xAD49D0, spellId, &row))
		{
			FrameScript::PushString(L, row.m_name_lang);
			FrameScript::PushString(L, row.m_nameSubtext_lang);
			return 2;
		}
	}

	FrameScript::PushNil(L);
	FrameScript::PushNil(L);
	return 2;
}

int CustomLua::FindSpellActionBarSlots(lua_State* L)
{
	uint32_t spellID = FrameScript::GetNumber(L, 1);
	uintptr_t* actionBarSpellIDs = (uintptr_t*)0xC1E358;
	uint8_t count = 0;

	for (uint8_t i = 0; i < 144; i++)
	{
		if (actionBarSpellIDs[i] == spellID)
		{
			FrameScript::PushNumber(L, i);
			count++;
		}
	}

	if (!count)
	{
		FrameScript::PushNil(L);
		return 1;
	}
	else
		return count;
}

int CustomLua::ReplaceActionBarSpell(lua_State* L)
{
	uint32_t oldSpellID = FrameScript::GetNumber(L, 1);
	uint32_t newSpellID = FrameScript::GetNumber(L, 2);
	uintptr_t* actionBarSpellIDs = (uintptr_t*)0xC1E358;
	uintptr_t* actionButtons = (uintptr_t*)0xC1DED8;

	for (uint8_t i = 0; i < 144; i++)
	{
		if (actionBarSpellIDs[i] == oldSpellID)
		{
			actionBarSpellIDs[i] = newSpellID;
			ClientPacket::MSG_SET_ACTION_BUTTON(i, 1, 0);

			for (uint8_t j = i + 72; j < 144; j += 12)
			{
				if (!actionButtons[j])
				{
					actionBarSpellIDs[i] = newSpellID;
					actionButtons[j] = 1;
					ClientPacket::MSG_SET_ACTION_BUTTON(j, 1, 0);
				}
			}
		}
	}

	return 0;
}

int CustomLua::SetSpellInActionBarSlot(lua_State* L)
{
	uint32_t spellID = FrameScript::GetNumber(L, 1);
	uint8_t slotID = FrameScript::GetNumber(L, 2);
	uintptr_t* actionBarSpellIDs = (uintptr_t*)0xC1E358;
	uintptr_t* actionButtons = (uintptr_t*)0xC1DED8;

	if (slotID < 144)
	{
		if (!actionButtons[slotID])
			actionButtons[slotID] = 1;

		actionBarSpellIDs[slotID] = spellID;
		ClientPacket::MSG_SET_ACTION_BUTTON(slotID, 1, 0);
	}

	return 0;
}

int CustomLua::ReloadMap(lua_State* L)
{
	uint64_t activePlayer = ClntObjMgr::GetActivePlayer();

	if (activePlayer)
	{
		MapRow* row = 0;
		int32_t mapId = *(uint32_t*)0xBD088C;
		CGUnit* activeObjectPtr = (CGUnit*)ClntObjMgr::ObjectPtr(activePlayer, TYPEMASK_UNIT);
		CMovement* moveInfo = activeObjectPtr->movementInfo;

		if (mapId > -1)
		{
			row = (MapRow*)ClientDB::GetRow((void*)0xAD4178, mapId);

			if (row)
			{
				char buffer[512];

				World::UnloadMap();
				World::LoadMap(row->m_Directory, &moveInfo->position, mapId);
				SStr::Printf(buffer, 512, "Map ID: %d (Directory: \"%s\", x: %f, y: %f, z: %f) reloaded.", mapId, row->m_Directory, moveInfo->position.x, moveInfo->position.y, moveInfo->position.z);
				CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			}
		}
	}

	return 0;
}

int CustomLua::ToggleDisplayNormals(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774F;
	bool areNormalsDisplayed = renderFlags & 0x40;

	if (areNormalsDisplayed)
	{
		*(uint8_t*)0xCD774F = renderFlags - 0x40;
		SStr::Printf(buffer, 512, "Normal display turned off.");
	}
	else
	{
		*(uint8_t*)0xCD774F = renderFlags + 0x40;
		SStr::Printf(buffer, 512, "Normal display turned on.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleGroundEffects(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774E;
	bool areGroundEffectsDisplayed = renderFlags & 0x10;

	if (areGroundEffectsDisplayed)
	{
		*(uint8_t*)0xCD774E = renderFlags - 0x10;
		SStr::Printf(buffer, 512, "Ground clutter hidden.");
	}
	else
	{
		*(uint8_t*)0xCD774E = renderFlags + 0x10;
		SStr::Printf(buffer, 512, "Ground clutter shown.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleLiquids(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774F;
	bool areLiquidsShowing = renderFlags & 0x3;

	if (areLiquidsShowing)
	{
		*(uint8_t*)0xCD774F = renderFlags - 0x3;
		SStr::Printf(buffer, 512, "Liquids hidden.");
	}
	else
	{
		*(uint8_t*)0xCD774F = renderFlags + 0x3;
		SStr::Printf(buffer, 512, "Liquids shown.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleM2(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774C;
	bool areM2Displayed = renderFlags & 0x1;

	if (areM2Displayed)
	{
		*(uint8_t*)0xCD774C = renderFlags - 0x1;
		SStr::Printf(buffer, 512, "Client-side M2s hidden.");
	}
	else
	{
		*(uint8_t*)0xCD774C = renderFlags + 0x1;
		SStr::Printf(buffer, 512, "Client-side M2s shown.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleTerrain(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774C;
	bool isTerrainShown = renderFlags & 0x2;

	if (isTerrainShown)
	{
		*(uint8_t*)0xCD774C = renderFlags - 0x2;
		SStr::Printf(buffer, 512, "Terrain hidden.");
	}
	else
	{
		*(uint8_t*)0xCD774C = renderFlags + 0x2;
		SStr::Printf(buffer, 512, "Terrain shown.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleTerrainCulling(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774C;
	bool isTerrainCullingOn = renderFlags & 0x32;

	if (isTerrainCullingOn)
	{
		*(uint8_t*)0xCD774C = renderFlags - 0x32;
		SStr::Printf(buffer, 512, "Terrain culling disabled.");
	}
	else
	{
		*(uint8_t*)0xCD774C = renderFlags + 0x32;
		SStr::Printf(buffer, 512, "Terrain culling enabled.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleWireframeMode(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774F;
	bool isWireframeModeOn = renderFlags & 0x20;

	if (isWireframeModeOn)
	{
		*(uint8_t*)0xCD774F = renderFlags - 0x20;
		SStr::Printf(buffer, 512, "Wireframe mode off.");
	}
	else
	{
		*(uint8_t*)0xCD774F = renderFlags + 0x20;
		SStr::Printf(buffer, 512, "Wireframe mode on.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::ToggleWMO(lua_State* L)
{
	char buffer[512];
	uint8_t renderFlags = *(uint8_t*)0xCD774D;
	bool areWMOsDisplayed = renderFlags & 0x1;

	if (areWMOsDisplayed)
	{
		*(uint8_t*)0xCD774D = renderFlags - 0x1;
		SStr::Printf(buffer, 512, "WMOs hidden.");
	}
	else
	{
		*(uint8_t*)0xCD774D = renderFlags + 0x1;
		SStr::Printf(buffer, 512, "WMOs shown.");
	}

	CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}

int CustomLua::FlashGameWindow(lua_State* L)
{
	HWND activeWindow = *(HWND*)0x00D41620;

	if (activeWindow && GetForegroundWindow() != activeWindow) {
		FLASHWINFO flashInfo;

		flashInfo.cbSize = sizeof(flashInfo);
		flashInfo.hwnd = activeWindow;
		flashInfo.dwFlags = FLASHW_TIMERNOFG | FLASHW_TRAY;
		flashInfo.uCount = -1;
		flashInfo.dwTimeout = 500;

		FlashWindowEx(&flashInfo);
	}

	return 0;
}

int CustomLua::GetCustomCombatRating(lua_State* L)
{
	uint8_t cr = 0;
	float value = 0;

	if (!FrameScript::IsNumber(L, 1))
		FrameScript::DisplayError(L, "Usage: GetCustomCombatRating(ratingIndex)");

	cr = FrameScript::GetNumber(L, 1) - 1;

	if (cr < 25 || cr >= 32)
		FrameScript::DisplayError(L, "ratingIndex is in the range %d .. %d", 26, 32);

	CGUnit* activeObjectPtr = (CGUnit*)ClntObjMgr::ObjectPtr(ClntObjMgr::GetActivePlayer(), TYPEMASK_PLAYER);

	if (activeObjectPtr)
		value = CustomFields::GetCustomCombatRating(cr - 25);

	FrameScript::PushNumber(L, value);
	return 1;
}

int CustomLua::GetCustomCombatRatingBonus(lua_State* L)
{
	uint32_t cr = 0;
	float value = 0.f;
	float gtCombatRating = 0.f;
	float gtOctClasCombatRatingScalar = 0.f;

	if (!FrameScript::IsNumber(L, 1))
		FrameScript::DisplayError(L, "Usage: GetCustomCombatRating(ratingIndex)");

	cr = FrameScript::GetNumber(L, 1) - 1;

	if (cr < 25 || cr >= 32)
		FrameScript::DisplayError(L, "ratingIndex is in the range %d .. %d", 26, 32);

	CGUnit* activeObjectPtr = (CGUnit*)ClntObjMgr::ObjectPtr(ClntObjMgr::GetActivePlayer(), TYPEMASK_PLAYER);

	if (activeObjectPtr)
	{
		gtCombatRating = ClientDB::GetGameTableValue(1, activeObjectPtr->unitFields->level, cr);
		gtOctClasCombatRatingScalar = ClientDB::GetGameTableValue(1, activeObjectPtr->unitFields->bytes0.unitClass, cr);

		if (gtCombatRating && gtOctClasCombatRatingScalar)
			value = gtOctClasCombatRatingScalar * CustomFields::GetCustomCombatRating(cr - 25) / gtCombatRating;
	}

	FrameScript::PushNumber(L, value);
	return 1;
}

int CustomLua::GetAvailableRoles(lua_State* L)
{
	ChrClassesRow* row = (ChrClassesRow*)ClientDB::GetRow((void*)(0xAD341C), ClientServices::GetCharacterClass());
	uint32_t classId = 0;
	LFGRolesRow* cdbcRole = 0;

	if (row)
		classId = row->m_ID;

	cdbcRole = GlobalCDBCMap.getRow<LFGRolesRow>("LFGRoles", classId);

	FrameScript::PushBoolean(L, cdbcRole->Roles & 2);
	FrameScript::PushBoolean(L, cdbcRole->Roles & 4);
	FrameScript::PushBoolean(L, cdbcRole->Roles & 8);
	return 3;
}

int CustomLua::SetLFGRole(lua_State* L)
{
	ChrClassesRow* row = (ChrClassesRow*)ClientDB::GetRow((void*)0xAD341C, ClientServices::GetCharacterClass());
	LFGRolesRow* cdbcRole = 0;
	uint32_t roles = FrameScript::GetParam(L, 1, 0) != 0;
	uint32_t classId = 0;
	uintptr_t ptr = *(uintptr_t*)0xBD0A28;

	if (FrameScript::GetParam(L, 2, 0))
		roles |= 2;
	if (FrameScript::GetParam(L, 3, 0))
		roles |= 4;
	if (FrameScript::GetParam(L, 4, 0))
		roles |= 8;

	if (row)
		classId = row->m_ID;

	cdbcRole = GlobalCDBCMap.getRow<LFGRolesRow>("LFGRoles", classId);

	CVar::sub_766940((void*)ptr, roles & cdbcRole->Roles, 1, 0, 0, 1);
	FrameScript::SignalEvent(EVENT_LFG_ROLE_UPDATE, 0);
	return 0;
}

int CustomLua::ConvertCoordsToScreenSpace(lua_State* L)
{
	float ox = FrameScript::GetNumber(L, 1);
	float oy = FrameScript::GetNumber(L, 2);
	float oz = FrameScript::GetNumber(L, 3);
	void* worldFrame = *(void**)0x00B7436C;
	C3Vector pos3d = { ox, oy, oz };
	C3Vector pos2d = {};
	uint32_t flags = 0;
	int result = World::Pos3Dto2D(worldFrame, nullptr, &pos3d, &pos2d, &flags);
	float x;
	float y;

	Util::PercToScreenPos(pos2d.x, pos2d.y, &x, &y);
	FrameScript::PushNumber(L, x);
	FrameScript::PushNumber(L, y);
	FrameScript::PushNumber(L, pos2d.z);
	return 3;
}

int CustomLua::PortGraveyard(lua_State* L)
{
	CGPlayer* activeObjectPtr = (CGPlayer*)ClntObjMgr::ObjectPtr(ClntObjMgr::GetActivePlayer(), TYPEMASK_PLAYER);

	if (activeObjectPtr && (activeObjectPtr->playerData->playerFlags & PLAYER_FLAGS_GHOST))
	{
		CDataStore pkt;

		CDataStore_C::GenPacket(&pkt);
		CDataStore_C::PutInt32(&pkt, CMSG_TELEPORT_GRAVEYARD_REQUEST);

		pkt.m_read = 0;

		ClientServices::SendPacket(&pkt);
		CDataStore_C::Release(&pkt);
	}

	return 0;
}

int CustomLua::SendExamplePacket(lua_State* L)
{
	// Optional: Get parameters from Lua if you want
	// Example: Get a message string from Lua argument
	char* customMessage = "";
	int32_t customNumber = 100;

	if (FrameScript::GetTop(L, 1) >= 1 && FrameScript::IsString(L, 1))
	{
		customMessage = FrameScript::ToLString(L, 1, 0);
	}

	if (FrameScript::GetTop(L, 2) >= 2 && FrameScript::IsNumber(L, 2))
	{
		customNumber = (int32_t)FrameScript::GetNumber(L, 2);
	}

	// Create and send packet
	CDataStore pkt;
	CDataStore_C::GenPacket(&pkt);

	// Write the CMSG opcode
	CDataStore_C::PutInt32(&pkt, CMSG_EXAMPLE_PACKET);

	// Write the custom data
	CDataStore_C::PutCString(&pkt, customMessage);
	CDataStore_C::PutInt32(&pkt, customNumber);
	pkt.m_read = 0;
	ClientServices::SendPacket(&pkt);
	CDataStore_C::Release(&pkt);

	return 0;
}

int CustomLua::GetLocalPlayer(lua_State* L) {


	uint64_t playerGUID = ClntObjMgr::GetActivePlayer();

	if (playerGUID) {
		

		void* playerAddr = ClntObjMgr::ObjectPtr(playerGUID, TYPEMASK_PLAYER);

		CGObject obj(playerAddr);

		char buffer[512];
		SStr::Printf(buffer, 512,
			"Player Address -> %p",
			playerAddr);

		/*
		char buffer[512];
		SStr::Printf(buffer, 512,
			"Health: %u/%u, Money: %u, Pos: (%.1f, %.1f, %.1f), Target Health: %d",
			obj.m_rawObject->UnitHealth,
			obj.m_rawObject->UnitMaxHealth,
			obj.m_rawObject->PlayerMoney,
			obj.GetX(), obj.GetY(), obj.GetZ());
		*/
		// Just pass a pointer to the display ID integer
		
		//uint32_t displayIdPtr = 51719;

		// Slot 0 = head, 1 = shoulders, etc.
		//CGPlayer_C::EquipVisibleItem(target, &displayIdPtr, 0);

		CGChat::AddChatMessage(buffer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}
	else {
		CGChat::AddChatMessage("No active player found!", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}

	return 0;
}

int CustomLua::HotReloadDBC(lua_State* L) {

    int result = -1;

    if (FrameScript::GetTop(L, 1) >= 1 && FrameScript::IsString(L, 1)) {
        const char* name = FrameScript::ToLString(L, 1, 0);
        result = DBCReloader::ReloadDBCByName(name);
        if (result == 0)
            CGChat::AddChatMessage("DBC reloaded successfully.", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        else
            CGChat::AddChatMessage("DBC reload failed: name not found or error.", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    else {
        result = DBCReloader::LoadAllDBCs();
        if (result == 0)
            CGChat::AddChatMessage("All DBCs reloaded successfully.", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        else
            CGChat::AddChatMessage("Reloading all DBCs failed.", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }

    FrameScript::PushBoolean(L, result == 0);
    return 1;
}

// Implemented by xidk (https://github.com/AzDeltaQQ)
int CustomLua::AttachToParentTestingFunction(lua_State* L)
{
	char debugMsg[256];

	// === VERIFIED ADDRESSES FROM IDA PRO ===
	// CGUnit_C -> CM2Model* offset (CORRECTED from 0x88 to 0xB4)
	const uintptr_t OFF_UNIT_MODEL = 0xB4;

	// Step 1: Get active player GUID
	uint64_t playerGUID = ClntObjMgr::GetActivePlayer();
	if (playerGUID == 0) {
		CGChat::AddChatMessage("[AttachToParentTestingFunction] No active player found", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		return 0;
	}

	// Step 2: Get player object pointer
	void* pPlayer = ClntObjMgr::ObjectPtr(playerGUID, TYPEMASK_PLAYER);
	if (!pPlayer) {
		CGChat::AddChatMessage("[AttachToParentTestingFunction] Failed to get player object pointer", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		return 0;
	}

	sprintf_s(debugMsg, "[AttachToParentTestingFunction] Player object at: 0x%p", pPlayer);
	CGChat::AddChatMessage(debugMsg, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	// Step 3: Get the M2 scene pointer
	void* pScene = *(void**)Globals::CGWorldScene__m2Scene;
	if (!pScene) {
		CGChat::AddChatMessage("[AttachToParentTestingFunction] World Scene not initialized", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		return 0;
	}

	// Step 4: Create the model
	void* pChildModel = CM2Scene::CreateModel(pScene, "Spells\\ErrorCube.mdx", 0);
	if (!pChildModel) {
		CGChat::AddChatMessage("[AttachToParentTestingFunction] Failed to create model", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		return 0;
	}

	sprintf_s(debugMsg, "[AttachToParentTestingFunction] Model created at: 0x%p", pChildModel);
	CGChat::AddChatMessage(debugMsg, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	// Step 5: Get player's internal model pointer at CORRECT offset 0xB4
	// This was verified in CGObject_C__AddWorldObject at 0x743767
	void* pParentModel = *(void**)((uintptr_t)pPlayer + OFF_UNIT_MODEL);

	if (!pParentModel) {
		CGChat::AddChatMessage("[AttachToParentTestingFunction] Player model not loaded (not fully initialized?)", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		return 0;
	}

	sprintf_s(debugMsg, "[AttachToParentTestingFunction] Player model at: 0x%p (offset 0xB4)", pParentModel);
	CGChat::AddChatMessage(debugMsg, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	// Step 6: Attach child model to parent model
	// Signature from CGlueMgr::ProcessAttachment (0x4E2C30):
	// void __thiscall AttachToParent(CM2Model* pChild, CM2Model* pParent, int boneId, int unk1, int unk2)
	// Bone IDs: 0 = Root/Feet, 14 = Right Hand, 25 = Left Hand (varies by race model)
	int boneId = 0;  // Attach at root (player's feet)

	__try {
		// Call: ECX = pChildModel, Stack = pParentModel, boneId, 0, 0
		CM2Model::AttachToParent(pChildModel, pParentModel, boneId, 0, 0);

		// Force visibility flag to ensure model is rendered
		// This tells the engine the model is part of the scene graph
		__try {
			*(uint32_t*)((uintptr_t)pChildModel + 0x10) |= 0x8000;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			CGChat::AddChatMessage("[AttachToParentTestingFunction] Warning: Could not set visibility flag", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		}

		sprintf_s(debugMsg, "[AttachToParentTestingFunction] SUCCESS! Model attached to bone %d", boneId);
		CGChat::AddChatMessage(debugMsg, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		CGChat::AddChatMessage("[AttachToParentTestingFunction] ErrorCube should now be visible at your feet!", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		sprintf_s(debugMsg, "[AttachToParentTestingFunction] CRASH AVOIDED - AttachToParent failed at 0x%X", CM2Scene_Addresses::ADDR_ATTACH_PARENT);
		CGChat::AddChatMessage(debugMsg, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}

	return 0;
}

int CustomLua::InstallAllHotpatches(lua_State* L)
{
	HotpatchManager::InitializeAll();
	HotpatchManager::InitializeAll();
	return 0;
}

int CustomLua::UninstallAllHotpatches(lua_State* L) {
	HotpatchManager::ShutdownAll();
	return 0;
}


void CustomLua::AddToFunctionMap(char* name, void* ptr)
{
	luaFuncts.insert(std::make_pair(name, ptr));
}

void CustomLua::RegisterFunctions()
{
	if (outOfBoundLuaFunctions)
	{
		AddToFunctionMap("FlashGameWindow", &FlashGameWindow);
		AddToFunctionMap("GetShapeshiftFormID", &GetShapeshiftFormID);
		AddToFunctionMap("GetSpellDescription", &GetSpellDescription);
		AddToFunctionMap("GetSpellNameById", &GetSpellNameById);
		AddToFunctionMap("ConvertCoordsToScreenSpace", &ConvertCoordsToScreenSpace);
	}

	if (customActionBarFunctions)
	{
		AddToFunctionMap("FindSpellActionBarSlots", &FindSpellActionBarSlots);
		AddToFunctionMap("ReplaceActionBarSpell", &ReplaceActionBarSpell);
		AddToFunctionMap("SetSpellInActionBarSlot", &SetSpellInActionBarSlot);
	}
	
	if (devHelperFunctions)
	{
		AddToFunctionMap("ReloadMap", &ReloadMap);
		AddToFunctionMap("ToggleDisplayNormals", &ToggleDisplayNormals);
		AddToFunctionMap("ToggleGroundEffects", &ToggleGroundEffects);
		AddToFunctionMap("ToggleM2", &ToggleM2);
		AddToFunctionMap("ToggleLiquids", &ToggleLiquids);
		AddToFunctionMap("ToggleTerrain", &ToggleTerrain);
		AddToFunctionMap("ToggleTerrainCulling", &ToggleTerrainCulling);
		AddToFunctionMap("ToggleWireframeMode", &ToggleWireframeMode);
		AddToFunctionMap("ToggleWMO", &ToggleWMO);
		AddToFunctionMap("GetLocalPlayer", &GetLocalPlayer);
		AddToFunctionMap("HotReloadDBC", &HotReloadDBC);
		AddToFunctionMap("AttachToParentTestingFunction", &AttachToParentTestingFunction);
		AddToFunctionMap("InstallAllHotpatches", &InstallAllHotpatches);
		AddToFunctionMap("UninstallAllHotpatches", &UninstallAllHotpatches);
	}

	if (customPackets)
	{
		AddToFunctionMap("GetCustomCombatRating", &GetCustomCombatRating);
		AddToFunctionMap("GetCustomCombatRatingBonus", &GetCustomCombatRatingBonus);
		AddToFunctionMap("PortGraveyard", &PortGraveyard);
		AddToFunctionMap("SendCustomPacket", &SendExamplePacket);
	}
}
