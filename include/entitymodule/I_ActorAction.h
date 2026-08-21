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
    virtual int32_t GetStaticTypeId() const { return 0; }                 // [26]
    virtual void    SetPriority(uint32_t) {}                              // [27]
    virtual void    vfE0() {}                                             // [28] nullsub
    virtual void    vfE8() {}                                             // [29] nullsub
    virtual void    GetDebugLabel(CryStringT<char>* ) {}                  // [30]
    virtual void    GetTagRange(void* ) {}                                // [31]
    virtual bool    StopAndRelease(void* smartPtr) { return false; }      // [32]
    virtual void    vf108() {}                                            // [33]
    virtual void    GetDefaultAnimBlock(void* ) {}                        // [34]
    virtual void    SetObjectFlagsAndAdvance(char, char) {}               // [35]
    virtual void    Serialize(void* archive) {}                           // [36]
};
static_assert(sizeof(I_ActorAction) == 0x10, "I_ActorAction = I_Action");

}  // namespace wh::entitymodule
