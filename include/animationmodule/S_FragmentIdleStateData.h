#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../entitymodule/E_StanceCategory.h"

// -----------------------------------------------
// wh::animationmodule::S_FragmentIdleStateData
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::animationmodule {

struct S_FragmentIdleStateData {
    CryStringT<char> m_fragment;                          // +0x00 RTTR "Fragment"
    wh::entitymodule::E_StanceCategory::Type m_stance;    // +0x08 RTTR "Stance"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(offsetof(S_FragmentIdleStateData, m_fragment) == 0x00,
              "S_FragmentIdleStateData::m_fragment offset mismatch");
static_assert(offsetof(S_FragmentIdleStateData, m_stance) == 0x08,
              "S_FragmentIdleStateData::m_stance offset mismatch");
static_assert(sizeof(S_FragmentIdleStateData) == 0x10,
              "S_FragmentIdleStateData size mismatch");

}  // namespace wh::animationmodule
