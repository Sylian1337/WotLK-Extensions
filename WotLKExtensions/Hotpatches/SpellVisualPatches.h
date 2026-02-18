// SpellVisualPatches.h
#pragma once
#include <cstdint>
#include <unordered_map>

void InstallSpellVisualHooks();
void SetSpellVisualOverride(uint32_t originalVisualId, uint32_t newVisualId);
void RemoveSpellVisualOverride(uint32_t originalVisualId);