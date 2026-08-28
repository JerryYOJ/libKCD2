#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::entitymodule {
class S_WeaponPresetItem {
public:
    virtual ~S_WeaponPresetItem();
    RTTR_ENABLE()  // [1..3]
    CryGUID m_item_class_id;  // +0x8 RTTR "item_class_id"
    std::int32_t m_amount;  // +0x18 RTTR "amount"
    std::uint8_t m_unknown1C[0x4];                  // +0x1C
};

static_assert(offsetof(S_WeaponPresetItem, m_amount) == 0x18, "S_WeaponPresetItem::m_amount offset mismatch");
static_assert(offsetof(S_WeaponPresetItem, m_item_class_id) == 0x8, "S_WeaponPresetItem::m_item_class_id offset mismatch");
static_assert(sizeof(S_WeaponPresetItem) == 0x20, "S_WeaponPresetItem size mismatch");

}  // namespace wh::entitymodule
