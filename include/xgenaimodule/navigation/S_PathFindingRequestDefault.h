#pragma once
#include <cstdint>
#include "S_PathFindingRequest.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::S_PathFindingRequestDefault -- point-to-point
// path query (KCD2 WHGame.dll 1.5.6).  sizeof 0x98.
// -----------------------------------------------
// RTTI .?AUS_PathFindingRequestDefault@navigation@xgenaimodule@wh@@.  Leaf ctor
// sub_18087A060 (vptr 0x183A597C8) calls the base ctor then writes +0x84/+0x88/+0x90.
// Clone [2] sub_1809FEC80 allocates 0x98. Fast travel ComputePath uses this leaf.
// Construct via the game ctor (src forwarder); that installs the game vtable.

namespace wh::xgenaimodule::navigation {

struct S_PathFindingRequestDefault : S_PathFindingRequest {
    inline static constexpr auto RTTI = Offsets::RTTI_S_PathFindingRequestDefault;
    S_PathFindingRequestDefault();                          // game ctor sub_18087A060  REL::ID 46454
    // Stubs so the type is concrete; the game ctor overwrites the vptr.
    void unk_1() override {}
    S_PathFindingRequest* Clone() override { return nullptr; }
    void unk_3() override {}
    void unk_4() override {}
    void unk_5() override {}
    void unk_6() override {}
    void unk_7() override {}

    Vec3     m_target;                                      // +0x78  filled by the caller (not the ctor)
    uint8_t  m_flag84;                                      // +0x84  ctor 1
    uint8_t  _pad85[3];                                     // +0x85
    void*    m_unk88;                                       // +0x88  ctor 0 [role UNVERIFIED]
    int32_t  m_unk90;                                       // +0x90  ctor 0 [role UNVERIFIED]
    uint32_t _pad94;                                        // +0x94
};
static_assert(sizeof(S_PathFindingRequestDefault) == 0x98, "Default request must be 0x98");
static_assert(offsetof(S_PathFindingRequestDefault, m_target) == 0x78, "target at +0x78");
static_assert(offsetof(S_PathFindingRequestDefault, m_flag84) == 0x84, "leaf flag at +0x84");

}  // namespace wh::xgenaimodule::navigation
