#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_SmartBehaviorState.h"
#include "C_ElementInitializerBase.h"

// Binary spelling C_ElementInitiazerChangeBehaviorState (missing 'l') is preserved.

namespace wh::xgenaimodule::scheduler {

class C_ElementInitiazerChangeBehaviorState : public C_ElementInitializerBase {
public:
    ~C_ElementInitiazerChangeBehaviorState() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    std::uint8_t m_unknown18[4];                          // +0x18 Behavior accessor
    wh::xgenaimodule::E_SmartBehaviorState::Type m_state; // +0x1C RTTR "State"
    bool m_mlodMaster;                                    // +0x1D RTTR "MLodMaster"
    std::uint8_t _pad1E[2];                               // +0x1E
};

static_assert(offsetof(C_ElementInitiazerChangeBehaviorState, m_state) == 0x1C,
              "C_ElementInitiazerChangeBehaviorState::m_state offset mismatch");
static_assert(sizeof(C_ElementInitiazerChangeBehaviorState) == 0x20,
              "C_ElementInitiazerChangeBehaviorState size mismatch");

}  // namespace wh::xgenaimodule::scheduler
