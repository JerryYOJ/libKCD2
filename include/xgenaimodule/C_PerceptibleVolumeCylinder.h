#pragma once
#include <cstdint>
#include "C_PerceptibleVolume.h"

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptibleVolumeCylinder : C_PerceptibleVolume -- the
// cylinder-shaped concrete perceptible volume (KCD2 WHGame.dll 1.5.6, kd7u).
// sizeof NOT create-site proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4C5E0; primary vtable 0x183A98730, 25 slots; I_RWLocked
// subobject vtable @+0x20 = 0x183A98710; IEntityEventListener subobject @+0x60,
// vtable 0x183A986F8 ([0] dtor thunk sub_18213D52C, [1] OnEntityEvent
// sub_1832AF6BC -- same body as the base).  Implements all four base purecalls
// ([19] sub_180D45EAC, [20] sub_180D4664C, [23] sub_1832AED84, [24] sub_181007C90)
// and overrides [21]/[22]; slots [2..18] inherited spine values.

namespace wh::xgenaimodule {

class C_PerceptibleVolumeCylinder : public C_PerceptibleVolume {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptibleVolumeCylinder;
    ~C_PerceptibleVolumeCylinder() override;   // [0]  deleting dtor sub_1811FBF0C
    uint32_t GetTypeMask() override;           // [1]  sub_1810DCB00
    void _vf19() override;                     // [19] sub_180D45EAC [U role]
    void _vf20() override;                     // [20] sub_180D4664C [U role]
    void _vf21() override;                     // [21] sub_1832AFA84 [U role]
    void _vf22() override;                     // [22] sub_1832AF168 [U role]
    void _vf23() override;                     // [23] sub_1832AED84 [U role]
    void _vf24() override;                     // [24] sub_181007C90 [U role]
};
// cylinder shape params (radius/height/etc.) unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
