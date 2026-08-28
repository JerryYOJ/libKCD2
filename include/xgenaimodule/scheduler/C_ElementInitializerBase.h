#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::xgenaimodule::scheduler::C_ElementInitializerBase
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18; vtable 0x183A4F8C8 (8 slots).
// -----------------------------------------------
// No C++ bases. Clone of a 0x20 derived copies a word at +0x08 and a qword at
// +0x10. Role/TargetGuid are accessor-backed (no RTTR member offset). Dtor
// 0x180EA1C80 does not tear down members.

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerBase {
public:
    virtual ~C_ElementInitializerBase();                  // [0] 0x180EA1C80
    virtual void unk_01() = 0;                            // [1]
    virtual void unk_02() = 0;                            // [2]
    virtual void unk_03() = 0;                            // [3]
    virtual bool unk_04();                                // [4] 0x180838AE0 false
    RTTR_ENABLE()                                         // [5..7]

    std::uint16_t m_unknown08;                            // +0x08 copied by derived clone
    std::uint8_t _pad0A[6];                               // +0x0A
    std::uint64_t m_targetGuid;                           // +0x10 TargetGuid accessor width
};

static_assert(offsetof(C_ElementInitializerBase, m_unknown08) == 0x08,
              "C_ElementInitializerBase::m_unknown08 offset mismatch");
static_assert(offsetof(C_ElementInitializerBase, m_targetGuid) == 0x10,
              "C_ElementInitializerBase::m_targetGuid offset mismatch");
static_assert(sizeof(C_ElementInitializerBase) == 0x18,
              "C_ElementInitializerBase size mismatch");

}  // namespace wh::xgenaimodule::scheduler
