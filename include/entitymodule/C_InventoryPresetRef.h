#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PresetItemBase.h"

namespace wh::entitymodule {

class C_InventoryPresetRef : public C_PresetItemBase {
public:
    ~C_InventoryPresetRef() override;
    RTTR_ENABLE(C_PresetItemBase)
    std::uint8_t m_unknown18[8];                          // +0x18
};

static_assert(sizeof(C_InventoryPresetRef) == 0x20,
              "C_InventoryPresetRef size mismatch");

}  // namespace wh::entitymodule
