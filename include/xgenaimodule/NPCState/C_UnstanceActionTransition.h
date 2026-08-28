#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ChangeUnstanceActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionTransition : public C_ChangeUnstanceActionBase {
public:
    ~C_UnstanceActionTransition() override;
    RTTR_ENABLE(C_ChangeUnstanceActionBase)                                  // [24..26], vtable 0x183BCA8B0

    std::uint8_t m_unknown1A8[0x10];                                         // +0x1A8
    std::uint32_t m_sourceUnstanceId;                                        // +0x1B8 RTTR "SourceUnstanceId"
    std::uint32_t m_targetUnstanceId;                                        // +0x1BC RTTR "TargetUnstanceId"
    std::uint8_t m_unknown1C0[0x40];                                         // +0x1C0
};

static_assert(offsetof(C_UnstanceActionTransition, m_sourceUnstanceId) == 0x1B8,
              "C_UnstanceActionTransition::m_sourceUnstanceId offset mismatch");
static_assert(sizeof(C_UnstanceActionTransition) == 0x200,
              "C_UnstanceActionTransition size mismatch");

} // namespace wh::xgenaimodule::NPCState
