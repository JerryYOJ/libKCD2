#pragma once
#include <cstdint>
#include "S_FastForwardRequest.h"

// -----------------------------------------------
// wh::dialogmodule::data::S_FastForwardRequestForRole -- skip one role's lines
// (KCD2 1.5.6, kd7u).  sizeof 0x10.
// -----------------------------------------------
// RTTI TD 0x184B6F1E0; vtable 0x183B8ED08 (5 slots); ctor sub_18146A438; sender
// sub_1828502A0. Adds the target role field at +0x08 (width/encoding UNVERIFIED --
// modeled as a qword).

namespace wh::dialogmodule::data {

struct S_FastForwardRequestForRole : S_FastForwardRequest {
    inline static constexpr auto RTTI = Offsets::RTTI_S_FastForwardRequestForRole;
    uint64_t m_role;   // +0x08  target role [width/encoding UNVERIFIED]
};
static_assert(sizeof(S_FastForwardRequestForRole) == 0x10, "S_FastForwardRequestForRole must be 0x10");

}  // namespace wh::dialogmodule::data
