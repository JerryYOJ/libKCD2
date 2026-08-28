#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../databasemodule/C_ObjectTreeDBMultipartBase.h"
#include "../rttr/rttr_enable.h"
#include "C_ItemHealthProvider.h"
#include "S_WeaponPresetItem.h"

namespace wh::entitymodule {

class C_WeaponPreset
    : public wh::databasemodule::C_ObjectTreeDBMultipartBase,
      public C_ItemHealthProvider {
public:
    ~C_WeaponPreset() override; // [0] 0x180D8C284
    RTTR_ENABLE(C_ItemHealthProvider) // [1..3]

    CryGUID m_id;                          // +0x20 RTTR "weapon_preset_id"
    CryStringT<char> m_name;               // +0x30 RTTR "weapon_preset_name"
    std::int32_t m_socialClassId;          // +0x38 RTTR "social_class_id"
    std::int32_t m_wealthLevel;            // +0x3C RTTR "wealth_level"
    std::vector<S_WeaponPresetItem> m_items; // +0x40 RTTR "items"
};

static_assert(offsetof(C_WeaponPreset, m_id) == 0x20,
              "C_WeaponPreset::m_id offset mismatch");
static_assert(offsetof(C_WeaponPreset, m_items) == 0x40,
              "C_WeaponPreset::m_items offset mismatch");
static_assert(sizeof(C_WeaponPreset) == 0x58,
              "C_WeaponPreset size mismatch");

} // namespace wh::entitymodule
