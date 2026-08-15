#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_LockPickingState -- live C_LockPicking+0x88 byte
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Store width is one byte (mov byte [this+0x88], N). Values are the writers:
//   0  ctor / Start idle
//   1  exact-positioning / enter montage (sub_180899020)
//   2  enter complete, ready to play (sub_180898BEC)
//   3  play idle (sub_18089A070 / sub_18089BAEC)
//   4  play turning (sub_18089BAEC)
//   5  (unread as a writer in the play loop; factory action type 5 is TurnFail)
//   6  success hold: 0.5s countdown at +0x184 (sub_18089BAEC)
//   7  hold expired, commit (sub_18089A940)
//   8  pick broke / fail recover (sub_182E8835C)
//   9  leaving after fail/success teardown (sub_180899D48)
//   10 leave-action requested session destroy (sub_180897D4C)
//   11 finished (IsFinished; dtor / Destroy)

namespace wh::playermodule {

struct E_LockPickingState {
    enum Type : uint8_t {
        Idle          = 0,
        Entering      = 1,
        Ready         = 2,
        PlayIdle      = 3,
        Turning       = 4,
        TurnFail      = 5,
        SuccessHold   = 6,
        SuccessCommit = 7,
        PickBroke     = 8,
        Leaving       = 9,
        Destroying    = 10,
        Finished      = 11,
    };
};
static_assert(sizeof(E_LockPickingState::Type) == 1,
              "C_LockPicking+0x88 is a single-byte store");

}  // namespace wh::playermodule
