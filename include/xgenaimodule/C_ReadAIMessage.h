#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_LinkableObject.h"

namespace wh::xgenaimodule {

class C_ReadAIMessage
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    ~C_ReadAIMessage() override;                                             // [0] 0x183233210
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183FDE940
    void OnEffectActivate() override;                                        // [43] 0x183234838
    void OnEffectDeactivate() override;                                      // [44] 0x183234A5C

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onMessage;                           // +0xB0 RTTR "OnMessage"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_mailboxHost;      // +0xF0 RTTR "MailboxHost"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_sender;           // +0x130 RTTR "Sender"
    CryStringT<char> m_messageType;                                          // +0x170 RTTR "MessageType"
    std::uint8_t m_unknown178[0x20];                                         // +0x178
};

static_assert(offsetof(C_ReadAIMessage, m_onMessage) == 0xB0,
              "C_ReadAIMessage::m_onMessage offset mismatch");
static_assert(offsetof(C_ReadAIMessage, m_sender) == 0x130,
              "C_ReadAIMessage::m_sender offset mismatch");
static_assert(offsetof(C_ReadAIMessage, m_messageType) == 0x170,
              "C_ReadAIMessage::m_messageType offset mismatch");
static_assert(sizeof(C_ReadAIMessage) == 0x198,
              "C_ReadAIMessage size mismatch");

} // namespace wh::xgenaimodule
