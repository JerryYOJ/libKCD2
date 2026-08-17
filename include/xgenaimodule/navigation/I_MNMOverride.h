#pragma once

// -----------------------------------------------
// I_MNMOverride -- Recast/Detour MNM override listener (KCD2 WHGame.dll 1.5.6).
// sizeof 0x08. RTTI .?AVI_MNMOverride@@ (global, not in wh::).
// -----------------------------------------------
// C_Navigation secondary base @+0x08, vtable 0x18400C550, 10 slots (0-9; slot 10 is
// a float constant, not a function). Slot roles not needed for the path-query
// surface -- left unnamed. [UNVERIFIED slot meanings]

class I_MNMOverride {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_MNMOverride;
    virtual ~I_MNMOverride() = default;   // [0] 0x18213D6E8
    virtual void unk_1() = 0;             // [1] 0x18213D6F4
    virtual void unk_2() = 0;             // [2] 0x18213D700
    virtual void unk_3() = 0;             // [3] 0x180B1039C
    virtual void unk_4() = 0;             // [4] 0x1807DC0F8
    virtual void unk_5() = 0;             // [5] nullsub
    virtual void unk_6() = 0;             // [6] nullsub
    virtual void unk_7() = 0;             // [7] nullsub
    virtual void unk_8() = 0;             // [8] 0x180619D10
    virtual void unk_9() = 0;             // [9] 0x18059A95C
};
static_assert(sizeof(I_MNMOverride) == 0x08, "I_MNMOverride is a vptr-only interface");
