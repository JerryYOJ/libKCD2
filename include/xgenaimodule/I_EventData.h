#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::xgenaimodule::I_EventData
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08; vtable 0x183BC4458 (8 slots).
// -----------------------------------------------

namespace wh::xgenaimodule {

class I_EventData {
public:
    virtual ~I_EventData();                               // [0] 0x18342FC48
    virtual void unk_01() = 0;                            // [1]
    virtual std::int64_t unk_02();                        // [2] 0x181A72470 returns 1
    virtual void unk_03() = 0;                            // [3]
    virtual void unk_04() = 0;                            // [4]
    RTTR_ENABLE()                                         // [5..7]
};

static_assert(sizeof(I_EventData) == 0x08,
              "I_EventData size mismatch");

}  // namespace wh::xgenaimodule
