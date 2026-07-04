#pragma once
#include "C_PerceptionObject.h"

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptibleObject : C_PerceptionObject -- a perceivable
// entity record (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof NOT proven -> no size
// assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F49E80; vtable 0x183A332E8, 6 slots (adds [2..5]):
// [0] sub_1819D2600, [1] sub_18066CD10 (return 0), [2] nullsub_1, [3] nullsub_1,
// [4] sub_1832A93E4, [5] nullsub_1.

namespace wh::xgenaimodule {

class C_PerceptibleObject : public C_PerceptionObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptibleObject;
    ~C_PerceptibleObject() override;   // [0] sub_1819D2600
    void _vf1() override;              // [1] sub_18066CD10 -- return 0 [U role]
    virtual void _vf2();               // [2] nullsub_1 [U role]
    virtual void _vf3();               // [3] nullsub_1 [U role]
    virtual void _vf4();               // [4] sub_1832A93E4 [U role]
    virtual void _vf5();               // [5] nullsub_1 [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
