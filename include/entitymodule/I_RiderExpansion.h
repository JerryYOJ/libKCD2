#pragma once
#include "I_ActionActorExpansion.h"

// -----------------------------------------------
// wh::entitymodule::I_RiderExpansion -- KCD2 WHGame.dll.  sizeof 8.  22 slots.
// -----------------------------------------------
// RTTI .?AVI_RiderExpansion@entitymodule@wh@@ : I_ActionActorExpansion.
// 8 parent slots + 14 own. Sole impl C_RiderExpansion vt 0x183B5D670.

namespace wh::entitymodule {

class C_Actor;

class I_RiderExpansion : public I_ActionActorExpansion {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_RiderExpansion;
    virtual bool     CanStartOnHorse(C_Actor* horse) = 0;          // [8]  0x180AD4BEC
    virtual bool     IsNotMounting() const = 0;                    // [9]  0x1829F0184
    virtual bool     IsStableForInput() const = 0;                 // [10] 0x1819C0A3C
    virtual void     RequestStart(void* req, char, char) = 0;      // [11] 0x180AD468C
    virtual void     TryStateTransition(char, char, char, char) = 0; // [12] 0x180AD338C
    virtual void     StopAction() = 0;                             // [13] 0x180682AB0
    virtual bool     IsRiderModelFlag2() const = 0;                // [14] 0x1829F1FE0
    virtual void*    GetHorseField38() const = 0;                  // [15] 0x180AD38EC
    virtual uint32_t GetHorseEntityId() const = 0;                 // [16] 0x181A72C80
    virtual void     SyncOp(char) = 0;                             // [17] 0x1829F2CDC
    virtual bool     HelperReady() const = 0;                      // [18] 0x1829F00D0
    virtual void*    GetHelperAnim() const = 0;                    // [19] 0x1829F0D5C
    virtual bool     HasNoSubActions() const = 0;                  // [20] 0x181ECBF60
    virtual void     StopHelperAnims() = 0;                        // [21] 0x1829F282C
};
static_assert(sizeof(I_RiderExpansion) == 8, "I_RiderExpansion is vtable-only");

}  // namespace wh::entitymodule
