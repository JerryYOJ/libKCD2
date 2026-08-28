#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_RuntimeState.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::xgenaimodule {

class C_PostLoadReconstructionFinishedWaiter
    : public wh::conceptmodule::C_RuntimeState {
public:
    C_PostLoadReconstructionFinishedWaiter();                                // 0x182078170
    ~C_PostLoadReconstructionFinishedWaiter() override;                      // [0] 0x18207B440
    RTTR_ENABLE(wh::conceptmodule::C_RuntimeState)                           // [5..7], vtable 0x183FE2D28
    void OnDeserializationComplete() override;                               // [41] 0x18207B950

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_startWaiting;                        // +0x40 RTTR "StartWaiting"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onFinished;                          // +0x80 RTTR "OnFinished"
    bool m_waiting;                                                          // +0xC0
    std::uint8_t m_paddingC1[7];                                             // +0xC1
};

static_assert(offsetof(C_PostLoadReconstructionFinishedWaiter, m_startWaiting) ==
                  0x40,
              "C_PostLoadReconstructionFinishedWaiter::m_startWaiting offset mismatch");
static_assert(offsetof(C_PostLoadReconstructionFinishedWaiter, m_onFinished) ==
                  0x80,
              "C_PostLoadReconstructionFinishedWaiter::m_onFinished offset mismatch");
static_assert(offsetof(C_PostLoadReconstructionFinishedWaiter, m_waiting) == 0xC0,
              "C_PostLoadReconstructionFinishedWaiter::m_waiting offset mismatch");
static_assert(sizeof(C_PostLoadReconstructionFinishedWaiter) == 0xC8,
              "C_PostLoadReconstructionFinishedWaiter size mismatch");

} // namespace wh::xgenaimodule
