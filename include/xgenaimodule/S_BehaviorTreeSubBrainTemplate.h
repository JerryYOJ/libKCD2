#pragma once
#include <cstddef>
#include "S_SubBrainTemplate.h"

namespace wh::xgenaimodule {

class S_BehaviorTreeSubBrainTemplate : public S_SubBrainTemplate {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_BehaviorTreeSubBrainTemplate;

    ~S_BehaviorTreeSubBrainTemplate() override;  // [0] 0x183208850
    RTTR_ENABLE(S_SubBrainTemplate)
    S_BehaviorTreeSubBrainTemplate* Clone() override;  // [4] 0x183208B74
    E_SubBrainType::Type GetSubbrainType() override;    // [5] 0x18066CD10

    CryStringT<char> m_fileName;  // +0x30
    CryStringT<char> m_treeName;  // +0x38
};
static_assert(sizeof(S_BehaviorTreeSubBrainTemplate) == 0x40,
              "S_BehaviorTreeSubBrainTemplate must be 0x40");
static_assert(offsetof(S_BehaviorTreeSubBrainTemplate, m_fileName) == 0x30,
              "behavior-tree file name must be at 0x30");
static_assert(offsetof(S_BehaviorTreeSubBrainTemplate, m_treeName) == 0x38,
              "behavior-tree name must be at 0x38");

}  // namespace wh::xgenaimodule
