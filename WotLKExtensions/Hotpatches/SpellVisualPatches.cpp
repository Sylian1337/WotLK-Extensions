// SpellVisualPatches.cpp
#include "SpellVisualPatches.h"
#include <MinHook.h>
#include <unordered_map>
#include "GameData/Database.h"
#include <cstdint>
#include <SharedDefines.h>

// ------------------------------------------------------------------
// GetSpellVisualRow(0x7FA290) signature:
//   SpellVisualRec* __cdecl GetSpellVisualRow(SpellRec* pSpellRec)
//
// It reads pSpellRec->m_spellVisualID[0] (or [1] in low-violence mode)
// and returns the matching SpellVisualRec* from the SpellVisual DBC.
//
// The override map is therefore keyed by spellVisualID, not by spell ID.
// SetSpellVisualOverride(67, 13) means:
//   "whenever a spell uses visual ID 67 (Fireball r1), return visual 13 (Frostbolt) instead"
// ------------------------------------------------------------------

typedef SpellVisualRec* (__cdecl* tGetSpellVisualRow)(SpellRec* pSpellRec);
static tGetSpellVisualRow Original_GetSpellVisualRow = nullptr;

// Override map: original spellVisualID -> replacement spellVisualID
static std::unordered_map<uint32_t, uint32_t> s_visualOverrides;

// ------------------------------------------------------------------
// Helper: look up a SpellVisualRec by visual ID from the live DBC
// ------------------------------------------------------------------
static SpellVisualRec* GetSpellVisualRecById(uint32_t visualId)
{
    auto* db = DBCGloabls::g_spellVisualDB;
    if (!db)
        return nullptr;

    int32_t minId = db->b_base_01.b_base.m_minID;
    int32_t maxId = db->b_base_01.b_base.m_maxID;

    if (static_cast<int32_t>(visualId) < minId || static_cast<int32_t>(visualId) > maxId)
        return nullptr;

    return db->b_base_02.m_recordsById[visualId - minId];
}

// ------------------------------------------------------------------
// Hooked function
// ------------------------------------------------------------------
SpellVisualRec* __cdecl Hooked_GetSpellVisualRow(SpellRec* pSpellRec)
{
    if (!pSpellRec)
        return Original_GetSpellVisualRow(pSpellRec);

    // Mirror the client's own selection logic:
    // m_spellVisualID[0] is the normal visual, [1] is the low-violence alternate.
    // We always key overrides off [0] (the primary visual ID).
    uint32_t primaryVisualId = static_cast<uint32_t>(pSpellRec->m_spellVisualID[0]);

    auto it = s_visualOverrides.find(primaryVisualId);
    if (it != s_visualOverrides.end())
    {
        SpellVisualRec* newRecord = GetSpellVisualRecById(it->second);
        if (newRecord)
            return newRecord;
        // Override entry exists but target ID is invalid — fall through to original
    }

    return Original_GetSpellVisualRow(pSpellRec);
}

// ------------------------------------------------------------------
// Hook installation
// ------------------------------------------------------------------
void InstallSpellVisualHooks()
{
    const uintptr_t FUNC_ADDR = FuncAddresses::GET_SPELL_VISUAL_ROW; // 0x007FA290

    MH_Initialize();

    if (MH_CreateHook(reinterpret_cast<LPVOID>(FUNC_ADDR),
                      reinterpret_cast<LPVOID>(&Hooked_GetSpellVisualRow),
                      reinterpret_cast<LPVOID*>(&Original_GetSpellVisualRow)) == MH_OK)
    {
        MH_EnableHook(reinterpret_cast<LPVOID>(FUNC_ADDR));
    }
}

// ------------------------------------------------------------------
// Public API
// ------------------------------------------------------------------
void SetSpellVisualOverride(uint32_t originalVisualId, uint32_t newVisualId)
{
    s_visualOverrides[originalVisualId] = newVisualId;
}

void RemoveSpellVisualOverride(uint32_t originalVisualId)
{
    s_visualOverrides.erase(originalVisualId);
}