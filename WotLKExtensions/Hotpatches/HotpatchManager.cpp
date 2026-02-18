#include "Hotpatches/HotpatchManager.h"
#include "Hotpatches/ItemNameHotpatches.h"   // Contains the hooking logic
#include "Hotpatches/QuestHotpatcher.h"   // Contains the hooking logic
#include "Hotpatches/SpellVisualPatches.h"   // Contains the hooking logic
#include "PatchConfig.h"       // Your existing config header

bool HotpatchManager::allIsInitialized = false;

void HotpatchManager::InitializeAll() {
    if(allIsInitialized)
        return; // Prevent multiple initializations
    ItemNameHotpatches::InstallHook();  // Your MinHook installation from the previous answer
    QuestHotpatcher::InstallQuestHooks();  // Your MinHook installation from the previous answer

    SetSpellVisualOverride(67, 13);

    InstallSpellVisualHooks();  // Your MinHook installation from the previous answer

    // Set it true here then.
	HotpatchManager::allIsInitialized = true; // Mark as initialized after all patches are registered
}

void HotpatchManager::ShutdownAll()
{
    if(!allIsInitialized)
		return; // Prevent multiple shutdowns
	ItemNameHotpatches::UninstallHook();  // Uninstall the hook when shutting down the hotpatch manager

	// Set it false here then.
	allIsInitialized = false; // Mark as not initialized after shutdown
}

void HotpatchManager::RegisterItemNamePatches()
{
    ItemNameHotpatches::InstallHook();
}

void HotpatchManager::RegisterNPCTextPatches()
{
}
