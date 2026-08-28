#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::xgenaimodule {

class C_AIConceptSignalTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_AIConceptSignalTrigger();                                              // 0x18119CF7C
    ~C_AIConceptSignalTrigger() override;                                    // [0] 0x18096856C
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183B0EA28
    void OnEffectActivate() override;                                        // [43] 0x1813D3FE8
    void OnEffectDeactivate() override;                                      // [44] 0x1813D3E98

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onNotification;                      // +0xB0 RTTR "OnNotification"
    CryStringT<char> m_notificationName;                                     // +0xF0 RTTR "NotificationName"
    std::uint8_t m_paddingF8[8];                                             // +0xF8
};

static_assert(offsetof(C_AIConceptSignalTrigger, m_onNotification) == 0xB0,
              "C_AIConceptSignalTrigger::m_onNotification offset mismatch");
static_assert(offsetof(C_AIConceptSignalTrigger, m_notificationName) == 0xF0,
              "C_AIConceptSignalTrigger::m_notificationName offset mismatch");
static_assert(sizeof(C_AIConceptSignalTrigger) == 0x100,
              "C_AIConceptSignalTrigger size mismatch");

} // namespace wh::xgenaimodule
