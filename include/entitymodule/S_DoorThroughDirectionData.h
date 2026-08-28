#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_DoorAnimData.h"

namespace wh::entitymodule {

struct S_DoorThroughDirectionData {
    CryStringT<char> m_fragment;                          // +0x00 RTTR "Fragment"
    std::uint8_t m_unknown08[0x18];                       // +0x08 Tags accessor
    std::vector<S_DoorAnimData> m_doorAnims;              // +0x20 RTTR "DoorAnims"
};

static_assert(offsetof(S_DoorThroughDirectionData, m_doorAnims) == 0x20,
              "S_DoorThroughDirectionData::m_doorAnims offset mismatch");
static_assert(sizeof(S_DoorThroughDirectionData) == 0x38,
              "S_DoorThroughDirectionData size mismatch");

}  // namespace wh::entitymodule
