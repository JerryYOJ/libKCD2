#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::rpgmodule::I_Counter -- statistic-counter interface
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08; vtable 0x183F4D388 (15 slots).
// -----------------------------------------------
// Signatures for [1..11] are taken from C_Counter overrides. Slot 7 is invoked
// as double from C_Counter slot 21 (vtable+0x38). Source names are not encoded.

namespace wh::rpgmodule {

class I_Counter {
public:
    virtual ~I_Counter();                                 // [0] 0x182D4DC58
    virtual std::uint32_t unk_01() = 0;                   // [1]
    virtual void* unk_02() = 0;                           // [2] name-ish pointer
    virtual void* unk_03() = 0;                           // [3]
    virtual void* unk_04() = 0;                           // [4]
    virtual std::uint32_t unk_05() = 0;                   // [5]
    virtual std::uint32_t unk_06() = 0;                   // [6]
    virtual double unk_07() = 0;                          // [7] value
    virtual double unk_08() = 0;                          // [8]
    virtual bool unk_09() = 0;                            // [9]
    virtual void unk_10(void* pair) = 0;                  // [10] 16-byte notify insert
    virtual void unk_11(void* pair) = 0;                  // [11] 16-byte notify remove
    RTTR_ENABLE()                                         // [12..14]
};

static_assert(sizeof(I_Counter) == 0x08,
              "I_Counter size mismatch");

}  // namespace wh::rpgmodule
