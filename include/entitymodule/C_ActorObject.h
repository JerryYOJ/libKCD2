#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::C_ActorObject -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// RTTI .?AVC_ActorObject@entitymodule@wh@@. MI of C_ActorAction at +0x58
// when TBase is the 0x58 ParamAction (vt 0x183C1DC18, 6 slots).

namespace wh::entitymodule {

class C_ActionActor;

class C_ActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ActorObject;
    virtual ~C_ActorObject() = default;              // [0]
    virtual void        vf08() {}                    // [1] nullsub
    virtual int32_t     GetObjectKind() const { return 3; } // [2] ActorAction
    virtual const char* GetName() const { return ""; }      // [3]
    virtual void*       GetDebugLabel(void* out) { return out; }  // [4]
    virtual void*       GetDebugDetail(void* out) { return out; } // [5]

    C_ActionActor* m_pActionActor;  // +0x08
    uint8_t        m_flag10;        // +0x10  I_ActorAction[35]
    uint8_t        m_flag11;        // +0x11
    uint16_t       _pad12;          // +0x12
    uint32_t       m_zero14;        // +0x14
};
static_assert(sizeof(C_ActorObject) == 0x18, "C_ActorObject must be 0x18");
static_assert(offsetof(C_ActorObject, m_pActionActor) == 0x08, "action actor");

}  // namespace wh::entitymodule
