#include "Hotpatches/HotpatchManager.h"
#include "Hotpatches/ItemNameHotpatches.h"
#include "Hotpatches/SpellVisualPatches.h"
#include "PatchConfig.h"

bool HotpatchManager::allIsInitialized = false;

void HotpatchManager::InitializeAll() {
    if(allIsInitialized)
        return;
    ItemNameHotpatches::InstallHook();

    SetSpellVisualOverride(67, 13);  // Example: Fireball visual (67) -> Frostbolt visual (13)

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
