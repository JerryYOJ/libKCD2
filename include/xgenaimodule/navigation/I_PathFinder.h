#pragma once
#include <cstdint>
#include "S_PathFindingRequest.h"
#include "S_PathFindingRequestDefault.h"
#include "S_PathFindingStatus.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::I_PathFinder -- pathfinder contract
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x08.
// -----------------------------------------------
// RTTI .?AVI_PathFinder@navigation@xgenaimodule@wh@@.  Interface vtable
// 0x18400CBB8, 4 slots (slot 4 is the next COL). Implemented by C_PathFinder.

namespace wh::xgenaimodule::navigation {

class I_PathFinder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_PathFinder;
    virtual ~I_PathFinder() = default;                      // [0]
    // Queue a request; 0xFFFFFFFF = rejected by the validator.  C_PathFinder: 0x180879B68.
    virtual uint32_t RequestPath(S_PathFindingRequest& request) = 0;          // [1]
    // Drop a previously queued request id.  C_PathFinder: 0x180B54750.
    virtual void CancelRequest(uint32_t requestId) = 0;                       // [2]
    // Blocking find.  12-byte status is returned by value (sret).  C_PathFinder: 0x183414120.
    virtual S_PathFindingStatus FindPath(S_PathFindingRequest& request) = 0;  // [3]
};
static_assert(sizeof(I_PathFinder) == 0x08, "I_PathFinder is a vptr-only interface");

}  // namespace wh::xgenaimodule::navigation
