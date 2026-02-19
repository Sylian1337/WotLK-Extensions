// SpellVisualPatches.h
#pragma once
#include <cstdint>

// Installs the MinHook detour on GetSpellVisualRow (0x7FA290).
// Must be called after MH_Initialize() (already handled inside).
void InstallSpellVisualHooks();

// Override map management.
// originalVisualId: the spellVisualID[0] value from Spell.dbc (e.g. 67 for Fireball r1).
// newVisualId:      the SpellVisual.dbc ID to return instead    (e.g. 13 for Frostbolt).
void SetSpellVisualOverride(uint32_t originalVisualId, uint32_t newVisualId);
void RemoveSpellVisualOverride(uint32_t originalVisualId);