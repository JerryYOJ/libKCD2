#pragma once
#include <cstddef>

#include "S_DoorThroughData.h"

namespace wh::entitymodule {

struct S_DoorAnimSet {
    CryStringT<char> m_tags;                // +0x000 RTTR "Tags"
    S_DoorThroughData m_openIn;             // +0x008 RTTR "OpenIn"
    S_DoorThroughData m_closeOut;           // +0x078 RTTR "CloseOut"
    S_DoorThroughData m_openOut;            // +0x0E8 RTTR "OpenOut"
    S_DoorThroughData m_automaticOpen;      // +0x158 RTTR "AutomaticOpen"
    S_DoorThroughData m_playerClosed;       // +0x1C8 RTTR "PlayerClosed"
    S_DoorThroughData m_fragment;           // +0x238 RTTR "Fragment"
    CryStringT<char> m_doorAnims;           // +0x2A8 RTTR "DoorAnims"
};

static_assert(offsetof(S_DoorAnimSet, m_openIn) == 0x08,
              "S_DoorAnimSet::m_openIn offset mismatch");
static_assert(offsetof(S_DoorAnimSet, m_fragment) == 0x238,
              "S_DoorAnimSet::m_fragment offset mismatch");
static_assert(offsetof(S_DoorAnimSet, m_doorAnims) == 0x2A8,
              "S_DoorAnimSet::m_doorAnims offset mismatch");
static_assert(sizeof(S_DoorAnimSet) == 0x2B0,
              "S_DoorAnimSet size mismatch");

} // namespace wh::entitymodule
