#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../rttr/rttr_enable.h"
#include "C_ItemHealthProvider.h"
#include "E_ActorGender.h"

namespace wh::entitymodule {

class S_ClothingPreset : public C_ItemHealthProvider {
public:
    ~S_ClothingPreset() override; // [0] 0x180D8C678
    RTTR_ENABLE(C_ItemHealthProvider) // [1..3]

    CryGUID m_id;                     // +0x20 RTTR "clothing_preset_id"
    CryStringT<char> m_name;          // +0x30 RTTR "clothing_preset_name"
    E_ActorGender m_gender;           // +0x38 RTTR "gender"
    bool m_prefersHoodOn;             // +0x39 RTTR "prefers_hood_on"
    std::uint8_t m_padding3A[2];
    std::int32_t m_socialClassId;     // +0x3C RTTR "social_class_id"
    std::int32_t m_wealthLevel;       // +0x40 RTTR "wealth_level"
    std::uint32_t m_padding44;
    std::vector<CryGUID> m_items;     // +0x48 RTTR "Items"
};

static_assert(offsetof(S_ClothingPreset, m_id) == 0x20,
              "S_ClothingPreset::m_id offset mismatch");
static_assert(offsetof(S_ClothingPreset, m_items) == 0x48,
              "S_ClothingPreset::m_items offset mismatch");
static_assert(sizeof(S_ClothingPreset) == 0x60,
              "S_ClothingPreset size mismatch");

} // namespace wh::entitymodule
