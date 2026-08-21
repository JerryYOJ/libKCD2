#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::I_ActionActor -- KCD2 WHGame.dll.  sizeof 8.  21 slots.
// -----------------------------------------------
// RTTI parent of C_ActionActor (vt 0x183E80398, mostly pure).

namespace wh::entitymodule {

class C_Actor;

class I_ActionActor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ActionActor;
    virtual ~I_ActionActor() = default;                 // [0]
    virtual void     vf08() = 0;                        // [1]
    virtual C_Actor* GetActor() const = 0;              // [2] 0x18113CE50
    virtual void*    GetOwnerSubsystem() const = 0;     // [3] 0x180856CF0
    virtual void     vf20() = 0;
    virtual void     vf28() = 0;
    virtual void     vf30() = 0;
    virtual void     vf38() = 0;
    virtual void     vf40() = 0;
    virtual void     vf48() = 0;
    virtual void     vf50() = 0;
    virtual void     vf58() = 0;
    virtual void     vf60() = 0;
    virtual void     vf68() = 0;
    virtual void     vf70() = 0;
    virtual void     vf78() = 0;
    virtual void     vf80() = 0;
    virtual void     vf88() = 0;
    virtual void     vf90() = 0;
    virtual void     vf98() = 0;
    virtual void     vfA0() = 0;
};
static_assert(sizeof(I_ActionActor) == 8, "I_ActionActor is vtable-only");

}  // namespace wh::entitymodule
