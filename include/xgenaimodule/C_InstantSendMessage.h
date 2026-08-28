#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_LinkableObject.h"

namespace wh::xgenaimodule {

class C_InstantSendMessage : public wh::conceptmodule::C_Node {
public:
    C_InstantSendMessage();                                                  // 0x181188250
    ~C_InstantSendMessage() override;                                        // [0] 0x180AD0DE4
    RTTR_ENABLE(wh::conceptmodule::C_Node)                                   // [5..7], vtable 0x183A741C0
    void OnExecute(wh::conceptmodule::S_NodeExecuteContext const& ctx)
        override;                                                            // [33] 0x180BD8348

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_instantSendMessage;                  // +0x40 RTTR "wh::conceptmodule::InstantSendMessage"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onInstantSendMessage;                // +0x80
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_receiver;         // +0xC0 RTTR "Receiver"
    CryStringT<char> m_messageType;                                          // +0x100 RTTR "MessageType"
};

static_assert(offsetof(C_InstantSendMessage, m_instantSendMessage) == 0x40,
              "C_InstantSendMessage::m_instantSendMessage offset mismatch");
static_assert(offsetof(C_InstantSendMessage, m_onInstantSendMessage) == 0x80,
              "C_InstantSendMessage::m_onInstantSendMessage offset mismatch");
static_assert(offsetof(C_InstantSendMessage, m_receiver) == 0xC0,
              "C_InstantSendMessage::m_receiver offset mismatch");
static_assert(offsetof(C_InstantSendMessage, m_messageType) == 0x100,
              "C_InstantSendMessage::m_messageType offset mismatch");
static_assert(sizeof(C_InstantSendMessage) == 0x108,
              "C_InstantSendMessage size mismatch");

} // namespace wh::xgenaimodule
