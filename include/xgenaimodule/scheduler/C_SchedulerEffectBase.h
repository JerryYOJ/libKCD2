#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::xgenaimodule::scheduler::C_SchedulerEffectBase
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10; vtable 0x183A4FCC0 (8 slots).
// -----------------------------------------------
// Role is accessor-backed. Dtor 0x180515DE0 does not free +0x08.

namespace wh::xgenaimodule::scheduler {

class C_SchedulerEffectBase {
public:
    virtual ~C_SchedulerEffectBase();                     // [0] 0x180515DE0
    virtual void unk_01() = 0;                            // [1]
    virtual void unk_02() = 0;                            // [2]
    virtual void unk_03() = 0;                            // [3]
    virtual void unk_04() = 0;                            // [4]
    RTTR_ENABLE()                                         // [5..7]
    std::uint8_t m_unknown08[8];                          // +0x08 Role accessor; type unverified
};

static_assert(offsetof(C_SchedulerEffectBase, m_unknown08) == 0x08,
              "C_SchedulerEffectBase::m_unknown08 offset mismatch");
static_assert(sizeof(C_SchedulerEffectBase) == 0x10,
              "C_SchedulerEffectBase size mismatch");

}  // namespace wh::xgenaimodule::scheduler
