#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PresetItemBase.h"

namespace wh::entitymodule {

class C_WeaponPresetRef : public C_PresetItemBase {
public:
    ~C_WeaponPresetRef() override;
    RTTR_ENABLE(C_PresetItemBase)
    std::uint8_t m_unknown18[8];                          // +0x18
};

static_assert(sizeof(C_WeaponPresetRef) == 0x20,
              "C_WeaponPresetRef size mismatch");

}  // namespace wh::entitymodule
