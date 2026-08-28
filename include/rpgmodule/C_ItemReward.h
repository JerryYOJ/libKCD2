#pragma once
#include <cstddef>
#include <cstdint>
#include "../entitymodule/S_ItemClassGUID.h"
#include "I_Reward.h"

namespace wh::rpgmodule {

class C_ItemReward : public I_Reward {
public:
    ~C_ItemReward() override;
    bool Give(void* target, CryStringT<char>* context, int a4) override;
    RTTR_ENABLE(I_Reward)

    wh::entitymodule::S_ItemClassGUID m_itemClass;           // +0x08 RTTR "ItemClass"
    int m_amount;                                           // +0x18 RTTR "Amount"
    std::uint8_t _pad1C[4];                                 // +0x1C
};

static_assert(offsetof(C_ItemReward, m_itemClass) == 0x08,
              "C_ItemReward::m_itemClass offset mismatch");
static_assert(offsetof(C_ItemReward, m_amount) == 0x18,
              "C_ItemReward::m_amount offset mismatch");
static_assert(sizeof(C_ItemReward) == 0x20,
              "C_ItemReward size mismatch");

}  // namespace wh::rpgmodule
