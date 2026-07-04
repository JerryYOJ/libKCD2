#pragma once
#include "C_PerceptionObject.h"

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptorObject : C_PerceptionObject -- a perceiving entity
// record (the NPC-side counterpart of C_PerceptibleObject).  KCD2 WHGame.dll
// 1.5.6, kd7u.  sizeof NOT proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4C5A0; vtable 0x183A332C0, 4 slots (adds [2],[3]):
// [0] sub_1803EBDEC, [1] sub_181A72470, [2] sub_1832AFD1C, [3] sub_1832AF550.

namespace wh::xgenaimodule {

class C_PerceptorObject : public C_PerceptionObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptorObject;
    ~C_PerceptorObject() override;   // [0] sub_1803EBDEC
    void _vf1() override;            // [1] sub_181A72470 [U role]
    virtual void _vf2();             // [2] sub_1832AFD1C [U role]
    virtual void _vf3();             // [3] sub_1832AF550 [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
