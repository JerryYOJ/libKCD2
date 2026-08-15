#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_LODAnimEvent.h"
#include "S_LODScopeAnimLayer.h"
#include "../CryEngine/CryCommon/smartptr.h"

class IAction;

namespace wh::animationmodule {

struct S_LODScope {
    std::uint32_t m_scopeId;                  // +0x00
    std::uint32_t _pad04;                     // +0x04
    _smart_ptr<IAction> m_action;             // +0x08, intrusive ownership
    float m_currentTime;                      // +0x10
    float m_previousTime;                     // +0x14
    float m_duration;                         // +0x18
    std::uint32_t _pad1C;                     // +0x1C
    std::vector<S_LODScopeAnimLayer> m_layers; // +0x20
    std::vector<S_LODAnimEvent> m_events;      // +0x38
};
static_assert(sizeof(S_LODScope) == 0x50,
              "S_LODScope must be 0x50");
static_assert(offsetof(S_LODScope, m_action) == 0x08,
              "LOD scope action must be at 0x08");
static_assert(offsetof(S_LODScope, m_layers) == 0x20,
              "LOD scope layers must be at 0x20");
static_assert(offsetof(S_LODScope, m_events) == 0x38,
              "LOD scope events must be at 0x38");

}  // namespace wh::animationmodule
