#pragma once
#include <cstddef>
#include <string>
#include <vector>

namespace wh::entitymodule {

struct S_EquipmentPresetFilter {
    std::string GetEquipmentSlotNames() const;        // 0x1829E1474
    void SetEquipmentSlotNames(std::string names);    // 0x1812721E0
    std::string GetMeleeClassNames() const;           // 0x182A1F73C
    void SetMeleeClassNames(std::string names);       // 0x18137179C
    std::string GetMissileClassNames() const;         // 0x182A1F75C
    void SetMissileClassNames(std::string names);     // 0x1813717BC

    CryStringT<char> m_name;                          // +0x00 RTTR "Name"
    std::vector<CryStringT<char>> m_equipmentSlotNames; // +0x08 accessor-backed
    std::vector<CryStringT<char>> m_meleeClassNames;    // +0x20 accessor-backed
    std::vector<CryStringT<char>> m_missileClassNames;  // +0x38 accessor-backed
};

static_assert(offsetof(S_EquipmentPresetFilter, m_equipmentSlotNames) == 0x08,
              "S_EquipmentPresetFilter::m_equipmentSlotNames offset mismatch");
static_assert(offsetof(S_EquipmentPresetFilter, m_missileClassNames) == 0x38,
              "S_EquipmentPresetFilter::m_missileClassNames offset mismatch");
static_assert(sizeof(S_EquipmentPresetFilter) == 0x50,
              "S_EquipmentPresetFilter size mismatch");

} // namespace wh::entitymodule
