#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::C_ActorAnimsExpansion -- anim-request factory service passed
// to C_AnimActionBase slots 45/46. (KCD2 WHGame.dll Steam 1.5.6.)
// vtable 0x183B55EC8 (13 slots). sizeof not certified; no static_assert.
// -----------------------------------------------
// Slot 8 [+0x40] builds S_ActorAnimRequest contents (callers 0x1806780EC /
// 0x1816FDCCC / 0x180FE6E2C); slot 10 [+0x50] fills S_ActorAnimActionDataInstance
// by hidden sret (caller 0x18039EFE8). Remaining slot semantics pending.

namespace wh::entitymodule {

class C_ActorAnimsExpansion {
public:
    virtual ~C_ActorAnimsExpansion();   // [0]
    virtual void unk_01() {}            // [1]
    virtual void unk_02() {}            // [2]
    virtual void unk_03() {}            // [3]
    virtual void unk_04() {}            // [4]
    virtual void unk_05() {}            // [5]
    virtual void unk_06() {}            // [6]
    virtual void unk_07() {}            // [7]
    virtual void unk_08() {}            // [8] 0x...+0x40 anim-request builder
    virtual void unk_09() {}            // [9]
    virtual void unk_10() {}            // [10] 0x...+0x50 action-data fill (sret)
    virtual void unk_11() {}            // [11]
    virtual void unk_12() {}            // [12]
};

}  // namespace wh::entitymodule
