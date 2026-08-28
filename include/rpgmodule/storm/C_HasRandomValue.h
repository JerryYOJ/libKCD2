#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasRandomValue : public I_Selector {
public:
    ~C_HasRandomValue() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    double m_min;  // +0x8 RTTR "min"
    double m_max;  // +0x10 RTTR "max"
};

static_assert(offsetof(C_HasRandomValue, m_max) == 0x10, "C_HasRandomValue::m_max offset mismatch");
static_assert(offsetof(C_HasRandomValue, m_min) == 0x8, "C_HasRandomValue::m_min offset mismatch");
static_assert(sizeof(C_HasRandomValue) == 0x18, "C_HasRandomValue size mismatch");

}  // namespace wh::rpgmodule::storm
