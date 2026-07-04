#pragma once

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptibleRefPoint -- perceivable reference point (a bare
// position a perceptor can notice).  KCD2 WHGame.dll 1.5.6, kd7u.  sizeof NOT
// proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4C838; vtable 0x183A33368, 3 slots: [0] sub_1803ECBE0,
// [1] sub_18041A6A0 (return 1), [2] sub_1832AED04.  ROOT class (not part of the
// C_PerceptionObject hierarchy).  Derived: C_OrientedPerceptibleRefPoint.

namespace wh::xgenaimodule {

class C_PerceptibleRefPoint {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptibleRefPoint;
    virtual ~C_PerceptibleRefPoint();   // [0] sub_1803ECBE0 [U -- dtor placement unverified]
    virtual bool _vf1();                // [1] sub_18041A6A0 -- return 1 [U role]
    virtual void _vf2();                // [2] sub_1832AED04 [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
