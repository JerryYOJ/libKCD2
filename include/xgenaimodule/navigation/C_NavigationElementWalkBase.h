#pragma once
#include <cstdint>
#include <vector>
#include "I_NavigationElement.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::C_NavigationElementWalkBase -- walkable path leg
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x38.
// -----------------------------------------------
// RTTI .?AVC_NavigationElementWalkBase@navigation@xgenaimodule@wh@@.  vtable
// 0x183A6AC70, 12 slots (adds [11] over I_NavigationElement). ctor sub_18059CFC8
// copies the +0x20 vector; dtor sub_180A03048 tears +0x20 then the base points
// vector. +0x20 free-size is `& ~3` => 4-byte elements [element type UNVERIFIED].

namespace wh::xgenaimodule::navigation {

class C_NavigationElementWalkBase : public I_NavigationElement {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_NavigationElementWalkBase;

    std::vector<uint32_t> m_indices;                        // +0x20  4-byte elems [type UNVERIFIED]
};
static_assert(sizeof(C_NavigationElementWalkBase) == 0x38, "WalkBase is 0x38 (two vectors)");
static_assert(offsetof(C_NavigationElementWalkBase, m_indices) == 0x20, "second vector at +0x20");

}  // namespace wh::xgenaimodule::navigation
