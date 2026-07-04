#pragma once
#include "C_PerceptibleRefPoint.h"

// -----------------------------------------------
// wh::xgenaimodule::C_OrientedPerceptibleRefPoint : C_PerceptibleRefPoint --
// reference point with an orientation (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof NOT
// proven -> no size assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4C6B0; vtable 0x183A98948, 3 slots (overrides only):
// [0] sub_1815D6144, [1] sub_18115556C, [2] sub_181A72EB0.

namespace wh::xgenaimodule {

class C_OrientedPerceptibleRefPoint : public C_PerceptibleRefPoint {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_OrientedPerceptibleRefPoint;
    ~C_OrientedPerceptibleRefPoint() override;   // [0] sub_1815D6144
    bool _vf1() override;                        // [1] sub_18115556C [U role]
    void _vf2() override;                        // [2] sub_181A72EB0 [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
