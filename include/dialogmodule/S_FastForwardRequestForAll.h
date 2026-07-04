#pragma once
#include "S_FastForwardRequest.h"

// -----------------------------------------------
// wh::dialogmodule::data::S_FastForwardRequestForAll -- skip the whole conversation
// (KCD2 1.5.6, kd7u).  sizeof 0x08.
// -----------------------------------------------
// RTTI TD 0x184B6EF90; vtable 0x183BCE468 (5 slots); ctor sub_1815EF728; sender
// sub_182850284. CHEAT: push into the dialog message queue to skip an entire
// conversation programmatically.

namespace wh::dialogmodule::data {

struct S_FastForwardRequestForAll : S_FastForwardRequest {
    inline static constexpr auto RTTI = Offsets::RTTI_S_FastForwardRequestForAll;
};
static_assert(sizeof(S_FastForwardRequestForAll) == 0x08, "S_FastForwardRequestForAll adds no data");

}  // namespace wh::dialogmodule::data
