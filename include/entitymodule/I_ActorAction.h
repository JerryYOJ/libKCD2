#pragma once
#include "../framework/I_Action.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::I_ActorAction -- KCD2 WHGame.dll.  sizeof 0x10.
// -----------------------------------------------
// RTTI .?AVI_ActorAction@entitymodule@wh@@ : I_Action.
// 11 extra slots [26..36] before C_Action's own tail.

namespace wh::entitymodule {

class I_ActorAction : public wh::framework::I_Action {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ActorAction;
    virtual int32_t GetStaticTypeId() const;                              // [26] 0x181A823B0; Dead overrides
    virtual void    SetPriority(uint32_t priority);                       // [27] 0x180F493D8
    virtual void    vfE0();                                               // [28] 0x1803B6E80 nullsub
    virtual void    vfE8(void* event);                                    // [29] 0x1803B6E80; Dead reads event+0x08
    virtual void    GetDebugLabel(CryStringT<char>* output);              // [30] 0x18287B51C
    virtual void    GetTagRange(void* output);                            // [31] leaf-specific
    virtual bool    StopAndRelease(void* smartPtr);                       // [32] 0x1828790D8
    virtual void    vf108();                                              // [33] 0x1803B6E80 nullsub
    virtual void    GetDefaultAnimBlock(void* output);                    // [34] 0x180E8B75C
    virtual void    SetObjectFlagsAndAdvance(char flag0, char flag1);     // [35] 0x1808569E8
    virtual void    Serialize(void* archive);                             // [36] 0x18041A6A0
};
static_assert(sizeof(I_ActorAction) == 0x10, "I_ActorAction = I_Action");

}  // namespace wh::entitymodule
