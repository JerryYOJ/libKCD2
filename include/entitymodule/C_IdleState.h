#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../framework/C_Signal.h"

// -----------------------------------------------
// wh::entitymodule::C_IdleState -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xA8.
// -----------------------------------------------
// Embedded at C_Actor+0x690 (boundary-proven; owner arg = the actor). ctor sub_1808E25C4, dtor
// sub_1808E1C30. MI (RTTI): I_IdleState (mdisp 0) + I_SynchronizedActorAnim (mdisp 8, 3-slot
// vtable). The registration record at +0x38 is a widely-reused bespoke "named subscription handle"
// (its vtable pointer qword_185322678 is runtime-relocated; class identity unresolvable statically).

namespace wh::entitymodule {

class C_Actor;

// MI bases (vtable-only; slot roles beyond those cited not enumerated).
class I_IdleState {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_IdleState;
    virtual ~I_IdleState() = default;
};
class I_SynchronizedActorAnim {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_SynchronizedActorAnim;
    virtual ~I_SynchronizedActorAnim() = default;    // [0] nullsub
    virtual void* _vf1() = 0;                        // [1] sub_181E80970 (reads owner)
    virtual void* GetOwner() = 0;                    // [2] sub_18113CE50: returns owner
};

// Bespoke named registration/subscription handle (0x28; reused by ~13 classes; vptr runtime-set --
// field names are placeholders, identity UNVERIFIED).
struct S_IdleRegistration {
    void*            m_runtimeVtable;   // +0x00  = qword_185322678 (runtime-relocated)
    CryStringT<char> m_key;             // +0x08  registration name
    void*            m_field10;         // +0x10  (ctor 0)
    int32_t          m_field18;         // +0x18  (ctor 0)
    uint8_t          m_field1C;         // +0x1C  (ctor 0)
    uint8_t          _pad1D[11];        // +0x1D
};
static_assert(sizeof(S_IdleRegistration) == 0x28, "S_IdleRegistration must be 0x28");

class C_IdleState : public I_IdleState, public I_SynchronizedActorAnim {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_IdleState;
    void* _vf1() override { return nullptr; }
    void* GetOwner() override { return m_pOwner; }

    CryStringT<char> m_name;            // +0x10
    CryGUID  m_animId;                  // +0x18  opaque 16-byte id (CryGUID-shaped; identity inferred)
    int32_t  m_variant;                 // +0x28  copied as one 20B record with m_animId (sub_180C89AD0)
    uint8_t  _pad2C[4];                 // +0x2C
    C_Actor* m_pOwner;                  // +0x30
    S_IdleRegistration m_registration;  // +0x38  key for the I_SynchronizedActorAnim (un)registration
    void*    m_pTrackedObject;          // +0x60  intrusively ref-counted (refcount @obj+0x58); pointee class unresolved
    uint8_t  m_flag68;                  // +0x68  vtable-exposed state bool (getter sub_181A7D910)
    uint8_t  _pad69[3];                 // +0x69
    int32_t  m_trackedHandle;           // +0x6C  zeroed when the tracked object is removed
    int32_t  m_field70;                 // +0x70  (cleared with m_trackedHandle; role unproven)
    uint8_t  _pad74[4];                 // +0x74
    wh::shared::C_Signal<> m_signalA;   // +0x78  (sentinel unk_1855D8AC8; args unrecovered)
    wh::shared::C_Signal<> m_signalB;   // +0x88  (sentinel unk_1855D8AB8)
    wh::shared::C_Signal<> m_signalC;   // +0x98  (sentinel unk_1855D8AA8)
};
static_assert(sizeof(C_IdleState) == 0xA8, "C_IdleState must be 0xA8");

}  // namespace wh::entitymodule
