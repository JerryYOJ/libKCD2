#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::navigation::S_PathFindingStatus -- 12-byte FindPath out-status
// (KCD2 WHGame.dll 1.5.6). [SYNTHETIC name]
// -----------------------------------------------
// Written by C_PathFinder::FindPath (sub_183414120): m_status = 1 (fail) by default,
// 0 on success; m_requestId = 0xFFFFFFFF; m_unk08 = 0. No RTTI.

namespace wh::xgenaimodule::navigation {

struct S_PathFindingStatus {
    int32_t  m_status;      // +0x00  0 = success, 1 = fail
    uint32_t m_requestId;   // +0x04  0xFFFFFFFF from the sync path
    uint32_t m_unk08;       // +0x08  written 0; role UNVERIFIED
};
static_assert(sizeof(S_PathFindingStatus) == 0x0C, "S_PathFindingStatus must be 0x0C");

}  // namespace wh::xgenaimodule::navigation
