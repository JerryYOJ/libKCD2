#pragma once
#include <cstddef>
#include "I_Reward.h"

namespace wh::rpgmodule {

class C_StatReward : public I_Reward {
public:
    ~C_StatReward() override;
    bool Give(void* target, CryStringT<char>* context, int a4) override;
    RTTR_ENABLE(I_Reward)

    CryStringT<char> m_type;                                // +0x08 RTTR "Type"
    CryStringT<char> m_experienceChange;                    // +0x10 RTTR "ExperienceChange"
};

static_assert(offsetof(C_StatReward, m_type) == 0x08,
              "C_StatReward::m_type offset mismatch");
static_assert(offsetof(C_StatReward, m_experienceChange) == 0x10,
              "C_StatReward::m_experienceChange offset mismatch");
static_assert(sizeof(C_StatReward) == 0x18,
              "C_StatReward size mismatch");

}  // namespace wh::rpgmodule
