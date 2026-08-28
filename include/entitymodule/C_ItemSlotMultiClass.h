#pragma once

#include <cstddef>

#include "C_ItemSlot.h"

namespace wh::entitymodule {

class C_ItemSlotMultiClass : public C_ItemSlot {
public:
    C_ItemSlotMultiClass();                                              // factory 0x181EEDEC0
    ~C_ItemSlotMultiClass() override;                                    // [0] 0x18149A1B0
    RTTR_ENABLE(C_ItemSlot)                                              // [21..23], vtable 0x183EC1550
};

static_assert(sizeof(C_ItemSlotMultiClass) == 0xE0,
              "C_ItemSlotMultiClass size mismatch");

} // namespace wh::entitymodule
