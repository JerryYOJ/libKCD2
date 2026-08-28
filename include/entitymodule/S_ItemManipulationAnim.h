#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule {

struct S_ItemManipulationAnim {
    CryStringT<char> m_fragment;                          // +0x00 RTTR "Fragment"
    std::uint8_t m_unknown08[0x18];                       // +0x08 Tags accessor
};

static_assert(sizeof(S_ItemManipulationAnim) == 0x20,
              "S_ItemManipulationAnim size mismatch");

}  // namespace wh::entitymodule
