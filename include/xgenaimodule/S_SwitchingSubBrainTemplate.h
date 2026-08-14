#pragma once
#include "S_BehaviorTreeSubBrainTemplate.h"

namespace wh::xgenaimodule {

class S_SwitchingSubBrainTemplate : public S_BehaviorTreeSubBrainTemplate {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_SwitchingSubBrainTemplate;

    ~S_SwitchingSubBrainTemplate() override;  // [0] 0x183208850
    RTTR_ENABLE(S_BehaviorTreeSubBrainTemplate)
    S_SwitchingSubBrainTemplate* Clone() override;  // [4] 0x183208E6C
    E_SubBrainType::Type GetSubbrainType() override;       // [5] 0x181A72480
    bool IsSubbrainType(E_SubBrainType::Type type) override; // [6] 0x18143DAB0
};
static_assert(sizeof(S_SwitchingSubBrainTemplate) == 0x40,
              "S_SwitchingSubBrainTemplate must be 0x40");

}  // namespace wh::xgenaimodule
