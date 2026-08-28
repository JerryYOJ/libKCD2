#pragma once
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class I_UIShop {
public:
    virtual ~I_UIShop();                                     // [0] 0x182BA5CF8
    virtual void unk_01(const void* parameters) = 0;         // [1]
    virtual std::uint8_t unk_02() const = 0;                 // [2]
    virtual void* unk_03() = 0;                              // [3]
    virtual void unk_04() = 0;                               // [4]
    virtual void unk_05() = 0;                               // [5]
    virtual void unk_06(std::uint8_t state) = 0;             // [6]
    virtual void unk_07() = 0;                               // [7]
    virtual void unk_08() = 0;                               // [8]
    virtual void* unk_09() = 0;                              // [9]
    RTTR_ENABLE()                                             // [10..12]
};

static_assert(sizeof(I_UIShop) == 0x08,
              "I_UIShop size mismatch");

}  // namespace wh::framework
