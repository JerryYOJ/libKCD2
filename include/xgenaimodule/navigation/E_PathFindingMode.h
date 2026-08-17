#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::navigation::E_PathFindingMode -- S_PathFindingRequest::m_mode
// (KCD2 WHGame.dll 1.5.6).
// -----------------------------------------------
// Values written by S_PathFindingRequestDefault ctor (7) and C_FastTravel ComputePath
// sub_182DDE2A4 (`(flags & 4) | 3` -> 3 or 7). Other values exist on other request
// kinds and are not modeled here.

namespace wh::xgenaimodule::navigation {

struct E_PathFindingMode {
    enum Type : int32_t {
        Normal = 3,
        Forced = 7,
    };
};

}  // namespace wh::xgenaimodule::navigation
