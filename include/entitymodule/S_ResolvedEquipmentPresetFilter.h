#pragma once
#include <cstddef>
#include <unordered_set>

namespace wh::entitymodule {

class C_EquipmentSlot;
class S_MeleeWeaponClass;
class S_MissileWeaponClass;

// Synthetic name; layout and set element types are binary-exact.
struct S_ResolvedEquipmentPresetFilter {
    std::unordered_set<const C_EquipmentSlot*> m_equipmentSlots; // +0x00
    std::unordered_set<const S_MeleeWeaponClass*> m_meleeClasses; // +0x40
    std::unordered_set<const S_MissileWeaponClass*> m_missileClasses; // +0x80
};

static_assert(offsetof(S_ResolvedEquipmentPresetFilter, m_meleeClasses) == 0x40,
              "S_ResolvedEquipmentPresetFilter::m_meleeClasses offset mismatch");
static_assert(offsetof(S_ResolvedEquipmentPresetFilter, m_missileClasses) == 0x80,
              "S_ResolvedEquipmentPresetFilter::m_missileClasses offset mismatch");
static_assert(sizeof(S_ResolvedEquipmentPresetFilter) == 0xC0,
              "S_ResolvedEquipmentPresetFilter size mismatch");

} // namespace wh::entitymodule
