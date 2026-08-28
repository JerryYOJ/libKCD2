#pragma once
#include <cstddef>

#include "S_DoorThroughDirectionData.h"

namespace wh::entitymodule {

struct S_DoorThroughData {
    S_DoorThroughDirectionData m_fragment;  // +0x00 RTTR "Fragment"
    S_DoorThroughDirectionData m_doorAnims; // +0x38 RTTR "DoorAnims"
};

static_assert(offsetof(S_DoorThroughData, m_doorAnims) == 0x38,
              "S_DoorThroughData::m_doorAnims offset mismatch");
static_assert(sizeof(S_DoorThroughData) == 0x70,
              "S_DoorThroughData size mismatch");

} // namespace wh::entitymodule
