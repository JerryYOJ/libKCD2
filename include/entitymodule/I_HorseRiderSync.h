#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::I_HorseRiderSync -- KCD2 WHGame.dll.  sizeof 8.  24 slots.
// -----------------------------------------------
// RTTI .?AVI_HorseRiderSync@entitymodule@wh@@. Only impl is C_RiderSync;
// primary vt 0x183EAACF0 IS this interface. Slot 0 is RequestPhase, not a dtor.
// Slot 23 Destroy is the deleting dtor. Slot 15 GetRider is 0x1806CCCD4 vf+0x78.

namespace wh::entitymodule {

class C_Actor;

class I_HorseRiderSync {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_HorseRiderSync;
    virtual void     RequestPhase() = 0;                 // [0]  0x1829F1C20
    virtual void     TrySetPhase5() = 0;                 // [1]  0x1829F2004
    virtual void     EnterPhase4() = 0;                  // [2]  0x1829F1B30
    virtual void     LatchFastStop() = 0;                // [3]  0x1829F2D08  HorseData+0x10B
    virtual void     TryBeginFollowAttach() = 0;         // [4]  0x180CF8248
    virtual bool     PhaseReady() = 0;                   // [5]  0x180CF8504
    virtual bool     TrySetPhase6() = 0;                 // [6]  0x1829F0E64
    virtual void*    GetRiderSlot790() = 0;              // [7]  0x180B703C0
    virtual void     PushRiderAction(void* packed, bool skip) = 0; // [8] 0x18059BC40
    virtual bool     IsPhase3() const = 0;               // [9]  0x1814D3AC4
    virtual bool     HasActionType1B() const = 0;        // [10] 0x18151EFE0
    virtual bool     CanActNotChatFollow() const = 0;    // [11] 0x181302A0C
    virtual bool     IsPhase2orA() const = 0;            // [12] 0x1829F0E80
    virtual bool     IsPhase2DashRank4() const = 0;      // [13] 0x1829F27E0
    virtual void     SyncAnims() = 0;                    // [14] 0x180AB1CE4  horse+0x30 -> rider+0x28
    virtual C_Actor* GetRider() const = 0;               // [15] 0x18113CE50
    virtual C_Actor* GetHorse() const = 0;               // [16] 0x18072DD20
    virtual bool     CanDismount() const = 0;            // [17] 0x1810E30BC
    virtual uint8_t  GetAnimFlag10() const = 0;          // [18] 0x181A88660
    virtual void     QueueDefer() = 0;                   // [19] 0x1814AE39C
    virtual void     FillTypeBox(void* out) = 0;         // [20] 0x1829F4024
    virtual I_HorseRiderSync* Self() = 0;                // [21] 0x1805F5DA0
    virtual void     FillSelfAndType(void* out) = 0;     // [22] 0x1829F3F90
    virtual void     Destroy(uint8_t dealloc) = 0;       // [23] 0x1817AB088
};
static_assert(sizeof(I_HorseRiderSync) == 8, "I_HorseRiderSync is vtable-only");

}  // namespace wh::entitymodule
