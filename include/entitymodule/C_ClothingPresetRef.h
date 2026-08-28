#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PresetItemBase.h"

namespace wh::entitymodule {

class C_ClothingPresetRef : public C_PresetItemBase {
public:
    ~C_ClothingPresetRef() override;
    RTTR_ENABLE(C_PresetItemBase)
    std::uint8_t m_unknown18[8];                          // +0x18
};

static_assert(sizeof(C_ClothingPresetRef) == 0x20,
              "C_ClothingPresetRef size mismatch");

}  // namespace wh::entitymodule
