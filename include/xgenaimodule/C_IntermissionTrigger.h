#pragma once

#include <cstddef>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_IntermissionAwaiter.h"

namespace wh::xgenaimodule {

class C_IntermissionTrigger
    : public wh::conceptmodule::C_Effect,
      public I_IntermissionAwaiter {
public:
    C_IntermissionTrigger();                                                 // 0x18134D2C8
    ~C_IntermissionTrigger() override;                                       // [0] 0x181531AB0
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                                 // [5..7], vtable 0x183B6BD50
    void OnEffectActivate() override;                                        // [43] 0x180623564
    void OnEffectDeactivate() override;                                      // [44] 0x1819D56F4
    void OnIntermission() override;                                          // +0x88 [0] 0x1806235DC
    void unk_1() override;                                                   // +0x88 [1] nullsub

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onIntermission;                      // +0x90 RTTR "OnIntermission"
};

static_assert(offsetof(C_IntermissionTrigger, m_onIntermission) == 0x90,
              "C_IntermissionTrigger::m_onIntermission offset mismatch");
static_assert(sizeof(C_IntermissionTrigger) == 0xD0,
              "C_IntermissionTrigger size mismatch");

} // namespace wh::xgenaimodule
