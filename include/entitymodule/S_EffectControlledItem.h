#pragma once

#include <cstddef>
#include <cstdint>

#include "S_ActiveQuestItem.h"

namespace wh::entitymodule {

class C_ItemHolder;

class S_EffectControlledItem : public S_ActiveQuestItem {
public:
    ~S_EffectControlledItem() override;                     // [0] 0x180515E04
    RTTR_ENABLE(S_ActiveQuestItem)                          // [1..3], vtable 0x183A3D640

    C_ItemHolder* m_backupLocation;                         // +0x108, borrowed
    C_ItemHolder* m_startingLocation;                       // +0x110, borrowed
    bool m_unknown118;                                      // +0x118, constructor-written
    std::uint8_t m_padding119[7];                           // +0x119
};

static_assert(offsetof(S_EffectControlledItem, m_backupLocation) == 0x108,
              "S_EffectControlledItem::m_backupLocation offset mismatch");
static_assert(offsetof(S_EffectControlledItem, m_startingLocation) == 0x110,
              "S_EffectControlledItem::m_startingLocation offset mismatch");
static_assert(offsetof(S_EffectControlledItem, m_unknown118) == 0x118,
              "S_EffectControlledItem::m_unknown118 offset mismatch");
static_assert(sizeof(S_EffectControlledItem) == 0x120,
              "S_EffectControlledItem size mismatch");

}  // namespace wh::entitymodule
