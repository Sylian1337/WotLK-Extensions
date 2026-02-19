#pragma once

#include "SharedDefines.h"

class Main;

class CustomLua {
public:
	static int LoadScriptFunctionsCustom();

	static int GetAvailableRoles(lua_State* L);
	static int SetLFGRole(lua_State* L);
private:
	static void AddToFunctionMap(char* name, void* ptr);
	static void Apply();
	static void RegisterFunctions();


	// Out of bounds functions
	static int FlashGameWindow(lua_State* L);
	static int GetShapeshiftFormID(lua_State* L);
	static int GetSpellDescription(lua_State* L);
	static int GetSpellNameById(lua_State* L);
	static int ConvertCoordsToScreenSpace(lua_State* L);


	// Custom action bar functions
	static int FindSpellActionBarSlots(lua_State* L);
	static int ReplaceActionBarSpell(lua_State* L);
	static int SetSpellInActionBarSlot(lua_State* L);


	// Development functions
	static int ReloadMap(lua_State* L);
	static int ToggleDisplayNormals(lua_State* L);
	static int ToggleGroundEffects(lua_State* L);
	static int ToggleM2(lua_State* L);
	static int ToggleLiquids(lua_State* L);
	static int ToggleTerrain(lua_State* L);
	static int ToggleTerrainCulling(lua_State* L);
	static int ToggleWireframeMode(lua_State* L);
	static int ToggleWMO(lua_State* L);
	static int GetLocalPlayer(lua_State* L);
	static int HotReloadDBC(lua_State* L);
	static int AttachToParentTestingFunction(lua_State* L);
	static int InstallAllHotpatches(lua_State* L);
	static int UninstallAllHotpatches(lua_State* L);
	static int LuaSetSpellVisualOverride(lua_State* L);
	static int LuaRemoveSpellVisualOverride(lua_State* L);


	// Custom packet functions
	static int GetCustomCombatRating(lua_State* L);
	static int GetCustomCombatRatingBonus(lua_State* L);
	static int PortGraveyard(lua_State* L);
	static int SendExamplePacket(lua_State* L);


	friend class Main;
};
