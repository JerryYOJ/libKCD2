#pragma once
#include "C_PerceptibleObject.h"

// -----------------------------------------------
// wh::xgenaimodule::C_StatePerceptibleObject : C_PerceptibleObject -- perceivable
// record with per-state tracking (the "perceived states" updated by the perception
// jobs).  KCD2 WHGame.dll 1.5.6, kd7u.  sizeof NOT proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4C628; vtable 0x183A33320, 8 slots (adds [6],[7]):
// [0] sub_1803ECAB4, [1] sub_18066CD10 (inherited value), [2] sub_180ACA504,
// [3] sub_1804800C8, [4] sub_181A749E0, [5] sub_1803EBD88, [6] sub_1832AFDE0,
// [7] sub_1832AF5EC.

namespace wh::xgenaimodule {

class C_StatePerceptibleObject : public C_PerceptibleObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_StatePerceptibleObject;
    ~C_StatePerceptibleObject() override;   // [0] sub_1803ECAB4
    void _vf2() override;                   // [2] sub_180ACA504 [U role]
    void _vf3() override;                   // [3] sub_1804800C8 [U role]
    void _vf4() override;                   // [4] sub_181A749E0 [U role]
    void _vf5() override;                   // [5] sub_1803EBD88 [U role]
    virtual void _vf6();                    // [6] sub_1832AFDE0 [U role]
    virtual void _vf7();                    // [7] sub_1832AF5EC [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
