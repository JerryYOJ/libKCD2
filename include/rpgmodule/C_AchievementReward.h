#pragma once
#include <cstddef>
#include "I_Reward.h"

namespace wh::rpgmodule {

class C_AchievementReward : public I_Reward {
public:
    ~C_AchievementReward() override;
    bool Give(void* target, CryStringT<char>* context, int a4) override;
    RTTR_ENABLE(I_Reward)

    CryStringT<char> m_achievement;                         // +0x08 RTTR "Achievement"
};

static_assert(offsetof(C_AchievementReward, m_achievement) == 0x08,
              "C_AchievementReward::m_achievement offset mismatch");
static_assert(sizeof(C_AchievementReward) == 0x10,
              "C_AchievementReward size mismatch");

}  // namespace wh::rpgmodule
