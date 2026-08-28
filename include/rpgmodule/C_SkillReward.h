#pragma once
#include <cstddef>
#include "I_Reward.h"

namespace wh::rpgmodule {

class C_SkillReward : public I_Reward {
public:
    ~C_SkillReward() override;
    bool Give(void* target, CryStringT<char>* context, int a4) override;
    RTTR_ENABLE(I_Reward)

    CryStringT<char> m_type;                                // +0x08 RTTR "Type"
    CryStringT<char> m_experienceChange;                    // +0x10 RTTR "ExperienceChange"
};

static_assert(offsetof(C_SkillReward, m_type) == 0x08,
              "C_SkillReward::m_type offset mismatch");
static_assert(offsetof(C_SkillReward, m_experienceChange) == 0x10,
              "C_SkillReward::m_experienceChange offset mismatch");
static_assert(sizeof(C_SkillReward) == 0x18,
              "C_SkillReward size mismatch");

}  // namespace wh::rpgmodule
