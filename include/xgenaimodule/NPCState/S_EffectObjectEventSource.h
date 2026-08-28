#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"
#include "E_AnimEventContextSource.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::S_EffectObjectEventSource
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18. No vtable.
// -----------------------------------------------
// All four fields are RTTR member_object_ptr registrations.

namespace wh::xgenaimodule::NPCState {

struct S_EffectObjectEventSource {
    E_AnimEventContextSource::Type m_animEventContextSource;      // +0x00 RTTR "AnimEventContextSource"
    E_AnimEventContextSource::Type m_gameLoadAnimEventContextSource; // +0x01 RTTR "GameLoadAnimEventContextSource"
    std::uint8_t _pad02[6];                                       // +0x02
    CryStringT<char> m_eventTypeName;                             // +0x08 RTTR "EventTypeName"
    CryStringT<char> m_eventName;                                 // +0x10 RTTR "EventName"
};

static_assert(offsetof(S_EffectObjectEventSource, m_animEventContextSource) == 0x00,
              "S_EffectObjectEventSource::m_animEventContextSource offset mismatch");
static_assert(offsetof(S_EffectObjectEventSource, m_eventTypeName) == 0x08,
              "S_EffectObjectEventSource::m_eventTypeName offset mismatch");
static_assert(offsetof(S_EffectObjectEventSource, m_eventName) == 0x10,
              "S_EffectObjectEventSource::m_eventName offset mismatch");
static_assert(sizeof(S_EffectObjectEventSource) == 0x18,
              "S_EffectObjectEventSource size mismatch");

}  // namespace wh::xgenaimodule::NPCState
