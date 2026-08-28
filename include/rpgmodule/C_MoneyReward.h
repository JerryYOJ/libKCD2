#pragma once
#include <cstddef>
#include "I_Reward.h"

namespace wh::rpgmodule {

class C_MoneyReward : public I_Reward {
public:
    ~C_MoneyReward() override;
    bool Give(void* target, CryStringT<char>* context, int a4) override;
    RTTR_ENABLE(I_Reward)

    CryStringT<char> m_amount;                              // +0x08 RTTR "Amount"
};

static_assert(offsetof(C_MoneyReward, m_amount) == 0x08,
              "C_MoneyReward::m_amount offset mismatch");
static_assert(sizeof(C_MoneyReward) == 0x10,
              "C_MoneyReward size mismatch");

}  // namespace wh::rpgmodule
