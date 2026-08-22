#pragma once
#include <cstdint>
#include <vector>
#include "../framework/C_Signal.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_ObjectivePlanner
// (KCD2 WHGame.dll 1.5.6). sizeof 0x58. No vptr / no .?AV.
// -----------------------------------------------
// Trailing member of C_DogObjectivePack at +0x1480 (C_DogCompanionContext+0x1D90).
// Constructed by C_DogCompanionContext ctor 0x180BC9D10 AFTER pack ctor 0x1809F5960
// returns — not by the pack ctor itself. I_DogObjectiveContext [6]/[7] ICF to
// 0x1809F6CC0 = &pack.m_planner. Enqueue 0x180C58ACC pushes S_Request* (0x98,
// vtable 0x183A8A940, ctor 0x180C58B90) onto m_queue.

namespace wh::xgenaimodule::activitysystem {

class I_ObjectivePlannerContext;

class C_ObjectivePlanner {
public:
    struct S_Request;  // 0x98 polymorphic queue entry : I_ObjectivePlannerRunnable

    wh::shared::C_Signal<>       m_signal;    // +0x00  empty sentinel 0x18566A3F8; Args [U]
    uint8_t                      _pad10[0x18]; // +0x10
    std::vector<S_Request*>      m_queue;     // +0x28
    I_ObjectivePlannerContext*   m_pContext;  // +0x40  C_DogCompanionContext+0x10
    uint64_t                     m_unk48;     // +0x48  zero-init
    uint8_t                      m_flag50;    // +0x50  zero-init
    uint8_t                      _pad51[7];   // +0x51
};
static_assert(sizeof(C_ObjectivePlanner) == 0x58,
              "C_ObjectivePlanner must be 0x58");
static_assert(offsetof(C_ObjectivePlanner, m_queue) == 0x28,
              "request queue at +0x28");
static_assert(offsetof(C_ObjectivePlanner, m_pContext) == 0x40,
              "planner context at +0x40");

}  // namespace wh::xgenaimodule::activitysystem
