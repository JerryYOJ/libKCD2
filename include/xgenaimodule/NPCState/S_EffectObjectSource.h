#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"
#include "S_EffectObjectEventSource.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::S_EffectObjectSource
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20. No vtable.
// -----------------------------------------------
// Both fields are RTTR member_object_ptr registrations.

namespace wh::xgenaimodule::NPCState {

struct S_EffectObjectSource {
    CryStringT<char> m_linkName;                                  // +0x00 RTTR "LinkName"
    S_EffectObjectEventSource m_eventSource;                      // +0x08 RTTR "EventSource"
};

static_assert(offsetof(S_EffectObjectSource, m_linkName) == 0x00,
              "S_EffectObjectSource::m_linkName offset mismatch");
static_assert(offsetof(S_EffectObjectSource, m_eventSource) == 0x08,
              "S_EffectObjectSource::m_eventSource offset mismatch");
static_assert(sizeof(S_EffectObjectSource) == 0x20,
              "S_EffectObjectSource size mismatch");

}  // namespace wh::xgenaimodule::NPCState
