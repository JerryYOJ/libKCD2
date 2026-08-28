#pragma once
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class I_UIItemTransfer {
public:
    virtual ~I_UIItemTransfer();                             // [0] 0x182B8C1C8
    virtual bool unk_01(const void* parameters) = 0;         // [1]
    virtual bool unk_02(std::uint8_t reason) = 0;            // [2]
    virtual bool unk_03(const void* object) const = 0;       // [3]
    virtual void* unk_04() = 0;                              // [4]
    virtual std::uint8_t unk_05() const = 0;                 // [5]
    virtual bool unk_06() const = 0;                         // [6]
    RTTR_ENABLE()                                             // [7..9]
};

static_assert(sizeof(I_UIItemTransfer) == 0x08,
              "I_UIItemTransfer size mismatch");

}  // namespace wh::framework
