#pragma once
#include <cstddef>
#include "I_LockPickingAction.h"

// -----------------------------------------------
// wh::playermodule::C_LockPickingLeaveAction
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x98.
// -----------------------------------------------
// RTTI .?AVC_LockPickingLeaveAction@playermodule@wh@@ (TD 0x184DF95F8).
// Factory sub_1808998E0 types 6/7/8/9; ctor sub_1808994EC writes
// ??_7 @ 0x183A5A810 and +0x90 = factory type. OnStart (slot [4]
// 0x180897C34) calls C_LockPicking::Destroy.

namespace wh::playermodule {

class C_LockPickingLeaveAction : public I_LockPickingAction {
public:
    ~C_LockPickingLeaveAction() override;                   // [0] 0x180681EF8
    void OnActionStart() override;                          // [4] 0x180897C34
    void OnAnimEvent(int32_t eventCrc) override;            // [20] 0x180897CAC

    int32_t m_leaveKind;                                    // +0x90  factory type 6/7/8/9
    uint8_t _pad94[4];                                      // +0x94
};
static_assert(sizeof(C_LockPickingLeaveAction) == 0x98,
              "leave action alloc is 0x98 in sub_1808998E0");
static_assert(offsetof(C_LockPickingLeaveAction, m_leaveKind) == 0x90,
              "leave kind must sit at +0x90");

}  // namespace wh::playermodule
