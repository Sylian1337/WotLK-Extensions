// SpellVisualPatches.cpp
#include "SpellVisualPatches.h"
#include <MinHook.h>
#include <unordered_map>
#include "GameData/Database.h"
#include <cstdint>
#include <SharedDefines.h>

// ------------------------------------------------------------------
// Original function type and pointer
// ------------------------------------------------------------------
typedef SpellVisualRec* (__cdecl* tGetSpellVisual)(SpellVisualRec* pSpellRec);
static tGetSpellVisual Original_GetSpellVisual = nullptr;

// ------------------------------------------------------------------
// Override map: original visual ID -> new visual ID
// ------------------------------------------------------------------
static std::unordered_map<uint32_t, uint32_t> s_visualOverrides;

// ------------------------------------------------------------------
// Hooked function
// ------------------------------------------------------------------
SpellVisualRec* __cdecl Hooked_GetSpellVisual(SpellVisualRec* pSpellRec)
{
    // Read the original visual ID from the record (offset as per your disassembly)
    // In the code: pSpellRec[4].m_impactKit  (so at index 4, field m_impactKit)
    // We assume SpellVisualRec is a struct with fields, and we need the offset.
    // The exact offset may vary; adjust based on your research.
    // Here we use a simple cast to uint32_t* and read at index 4.
    uint32_t* fields = reinterpret_cast<uint32_t*>(pSpellRec);
    uint32_t originalVisualId = fields[4];  // pSpellRec[4].m_impactKit

    // Check if we have an override
    auto it = s_visualOverrides.find(originalVisualId);
    if (it != s_visualOverrides.end())
    {
        uint32_t newVisualId = it->second;

        // Validate new ID against the DB range
        if (newVisualId >= DBCGloabls::g_spellVisualDB->b_base_01.b_base.m_minID &&
            newVisualId <= DBCGloabls::g_spellVisualDB->b_base_01.b_base.m_maxID)
        {
            // Fetch the record from the DB
            uint32_t index = newVisualId - DBCGloabls::g_spellVisualDB->b_base_01.b_base.m_minID;
            SpellVisualRec* newRecord = reinterpret_cast<SpellVisualRec*>(
                DBCGloabls::g_spellVisualDB->b_base_02.m_recordsById[index]);
            if (newRecord)
                return newRecord;
        }
        // If override is invalid, fall through to original
    }

    // No override or invalid, call original function
    return Original_GetSpellVisual(pSpellRec);
}

// ------------------------------------------------------------------
// Hook installation
// ------------------------------------------------------------------
void InstallSpellVisualHooks()
{
    // Replace with the actual address of GetSpellVisual
    const uintptr_t FUNC_ADDR = 0x007FA290;

    if (MH_CreateHook((LPVOID)FUNC_ADDR, &Hooked_GetSpellVisual,
        (LPVOID*)&Original_GetSpellVisual) == MH_OK)
    {
        MH_EnableHook((LPVOID)FUNC_ADDR);
    }
}

// ------------------------------------------------------------------
// Public functions to manage overrides
// ------------------------------------------------------------------
void SetSpellVisualOverride(uint32_t originalVisualId, uint32_t newVisualId)
{
    s_visualOverrides[originalVisualId] = newVisualId;
}

void RemoveSpellVisualOverride(uint32_t originalVisualId)
{
    s_visualOverrides.erase(originalVisualId);
}