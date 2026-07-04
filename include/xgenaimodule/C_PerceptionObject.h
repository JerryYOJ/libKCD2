#pragma once

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptionObject -- root of the perception-object hierarchy
// (perceptor/perceptible records tracked by C_PerceptionManager).  KCD2 WHGame.dll
// 1.5.6, kd7u.  Abstract; sizeof of the base NOT proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F49E40; vtable 0x183A332A8, 2 slots: [0] sub_1832AE9D0,
// [1] _purecall.  ROOT class (no bases).  Derived: C_PerceptibleObject,
// C_PerceptorObject.

namespace wh::xgenaimodule {

class C_PerceptionObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptionObject;
    virtual ~C_PerceptionObject();   // [0] sub_1832AE9D0 [U -- dtor placement unverified]
    virtual void _vf1() = 0;         // [1] _purecall here [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
