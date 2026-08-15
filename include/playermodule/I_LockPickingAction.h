#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::I_LockPickingAction -- Mannequin lockpicking action
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x90.
// -----------------------------------------------
// RTTI .?AVI_LockPickingAction@playermodule@wh@@ (TD 0x184DF9C98).
// vtable 0x183A5A928, 30 slots; object layout is the 0x90-byte body filled by
// sub_180899CB0. Not framework::I_Action (different slot map).

namespace wh::playermodule {

class I_LockPickingAction {
public:
    virtual ~I_LockPickingAction();                         // [0]
    virtual void unk_01() = 0;                              // [1] 0x18126AC90
    virtual void unk_02() = 0;                              // [2]
    virtual void unk_03() = 0;                              // [3]
    virtual void OnActionStart() = 0;                       // [4] leave -> Destroy / fail-idle -> fail
    virtual void unk_05() = 0;                              // [5]
    virtual void unk_06() = 0;                              // [6]
    virtual void unk_07() = 0;                              // [7]
    virtual void unk_08() = 0;                              // [8]
    virtual void unk_09() = 0;                              // [9]
    virtual void unk_10() = 0;                              // [10]
    virtual void unk_11() = 0;                              // [11]
    virtual void unk_12() = 0;                              // [12]
    virtual void unk_13() = 0;                              // [13]
    virtual void OnActionUpdate() = 0;                      // [14] 0x180897C60, state==Ready
    virtual void unk_15() = 0;                              // [15]
    virtual void unk_16() = 0;                              // [16]
    virtual void unk_17() = 0;                              // [17]
    virtual void unk_18() = 0;                              // [18]
    virtual void unk_19() = 0;                              // [19]
    virtual void OnAnimEvent(int32_t eventCrc) = 0;         // [20] 0x180897CAC
    virtual void unk_21() = 0;                              // [21]
    virtual void unk_22() = 0;                              // [22]
    virtual void unk_23() = 0;                              // [23]
    virtual void unk_24() = 0;                              // [24]
    virtual void unk_25() = 0;                              // [25]
    virtual void unk_26() = 0;                              // [26]
    virtual void unk_27() = 0;                              // [27]
    virtual void unk_28() = 0;                              // [28]
    virtual void unk_29() = 0;                              // [29]

    uint8_t _opaque08[0x88];                                // +0x08  sub_180899CB0 body
};
static_assert(sizeof(I_LockPickingAction) == 0x90,
              "I_LockPickingAction must match sub_180899CB0 extent");

}  // namespace wh::playermodule
