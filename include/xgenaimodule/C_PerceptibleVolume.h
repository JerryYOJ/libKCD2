#pragma once
#include <cstdint>
#include "C_LinkableObject.h"
#include "../crysystem/EntityEventListenerWithCleanup.h"

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptibleVolume : C_LinkableObject + IEntityEventListener
// (@+0x60) -- a perceivable volume in the linkable graph (registered in
// C_PerceptibleVolumeManager's spatial grid).  KCD2 WHGame.dll 1.5.6, kd7u.
// ABSTRACT (slots [19][20][23][24] _purecall).  sizeof >= 0x68, NOT create-site
// proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4C560; primary vtable 0x183FE6CC0, 25 slots (spine 19 + new
// [19..24]); I_RWLocked subobject vtable @+0x20 = 0x183FE6CA0 (3x nullsub);
// IEntityEventListener subobject @+0x60, vtable 0x183FE6C88 ([0] dtor thunk
// sub_18213D520, [1] OnEntityEvent sub_1832AF6BC).  IEntityEventListener comes
// from crysystem/EntityEventListenerWithCleanup.h (stock IEntitySystem.h cannot
// compile here) -- do NOT include the stock header in the same TU.
// Spine overrides: [0] deleting dtor sub_1832AE93C, [1] GetTypeMask sub_181AA5780,
// [6] sub_181A75250 (the ONLY audited class overriding the spine's return-0
// default).  Host ctor sub_180D45C38 creates the paired 16-byte
// C_PerceptibleVolumePuppet (see that header; C_AIObject+0x18 = the puppet).
// Slot indices are vtable ORDER roles, not SDK declaration order (interfuscator
// PSA) [U].

namespace wh::xgenaimodule {

class C_PerceptibleVolume : public C_LinkableObject, public IEntityEventListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptibleVolume;
    ~C_PerceptibleVolume() override;       // [0]  deleting dtor sub_1832AE93C
    uint32_t GetTypeMask() override;       // [1]  sub_181AA5780
    void* _vf6() override;                 // [6]  sub_181A75250 -- overrides the spine return-0 default [U role]
    virtual void _vf19() = 0;              // [19] _purecall (impl in C_PerceptibleVolumeCylinder)
    virtual void _vf20() = 0;              // [20] _purecall
    virtual void _vf21();                  // [21] sub_1832AF960 [U role]
    virtual void _vf22();                  // [22] sub_1832AEFEC [U role]
    virtual void _vf23() = 0;              // [23] _purecall
    virtual void _vf24() = 0;              // [24] _purecall
    // IEntityEventListener impl
    void OnEntityEvent(IEntity* pEntity, SEntityEvent& event) override;   // subobject vt [1] sub_1832AF6BC
};
// sizeof >= 0x68 (C_LinkableObject 0x60 + IEntityEventListener vptr @+0x60);
// own data past +0x68 unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
