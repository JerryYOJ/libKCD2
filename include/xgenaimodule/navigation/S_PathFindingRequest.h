#pragma once
#include <cstdint>
#include <functional>
#include "E_PathFindingMode.h"
#include "S_PathFindingResult.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::S_PathFindingRequest -- path-query base
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x78. RTTI .?AUS_PathFindingRequest@...
// -----------------------------------------------
// Base ctor sub_18087A10C: vptr 0x183A59810, m_navMeshId=0, m_pResult=0,
// m_start zeroed, m_mode=7, m_limit=-1.0, m_kind=1, m_pPolicy=qword_185324A60.
// 8-slot vtable. Validator sub_180879D00 requires a live m_onComplete
// (`std::function` _Ptr at +0x48) and a non-null m_pResult.

namespace wh::xgenaimodule::navigation {

struct S_PathFindingRequest {
    inline static constexpr auto RTTI = Offsets::RTTI_S_PathFindingRequest;
    virtual ~S_PathFindingRequest() = default;              // [0]
    virtual void unk_1() = 0;                               // [1]
    virtual S_PathFindingRequest* Clone() = 0;              // [2] Default: sub_1809FEC80 (alloc 0x98)
    virtual void unk_3() = 0;                               // [3]
    virtual void unk_4() = 0;                               // [4]
    virtual void unk_5() = 0;                               // [5]
    virtual void unk_6() = 0;                               // [6] 0x1805F5DA0  `return this`
    virtual void unk_7() = 0;                               // [7]

    uint32_t m_navMeshId;                                   // +0x08  I_Navigation::GetDefaultNavMeshId
    uint32_t _pad0C;                                        // +0x0C
    std::function<void(const S_PathFindingResult&)> m_onComplete; // +0x10  (0x40; _Ptr at +0x48)
    S_PathFindingResult* m_pResult;                         // +0x50  required by the validator
    Vec3     m_start;                                       // +0x58
    E_PathFindingMode::Type m_mode;                         // +0x64  ctor default Forced (7)
    float    m_limit;                                       // +0x68  ctor -1.0f [role UNVERIFIED]
    uint8_t  m_kind;                                        // +0x6C  ctor 1; PathsOnly writes 3
    uint8_t  _pad6D[3];                                     // +0x6D
    void*    m_pPolicy;                                     // +0x70  ctor = qword_185324A60 [type UNVERIFIED]
};
static_assert(sizeof(S_PathFindingRequest) == 0x78, "S_PathFindingRequest base must be 0x78");
static_assert(offsetof(S_PathFindingRequest, m_onComplete) == 0x10, "callback at +0x10");
static_assert(offsetof(S_PathFindingRequest, m_pResult) == 0x50, "result at +0x50");
static_assert(offsetof(S_PathFindingRequest, m_start) == 0x58, "start at +0x58");
static_assert(offsetof(S_PathFindingRequest, m_mode) == 0x64, "mode at +0x64");

}  // namespace wh::xgenaimodule::navigation
