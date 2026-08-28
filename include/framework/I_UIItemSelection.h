#pragma once
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class I_UIItemSelection {
public:
    virtual ~I_UIItemSelection();                            // [0] 0x182B8C19C
    virtual bool unk_01(const void* parameters) = 0;         // [1]
    virtual bool unk_02(std::uint8_t reason) = 0;            // [2]
    virtual std::uint8_t unk_03() const = 0;                 // [3]
    RTTR_ENABLE()                                             // [4..6]
};

static_assert(sizeof(I_UIItemSelection) == 0x08,
              "I_UIItemSelection size mismatch");

}  // namespace wh::framework
