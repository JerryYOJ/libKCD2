#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {

class I_ValueComparatorSelector : public I_Selector {
public:
    ~I_ValueComparatorSelector() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::int32_t m_min;                                   // +0x08 RTTR "min"
    std::int32_t m_max;                                   // +0x0C RTTR "max"
    std::uint8_t m_unknown10[8];                          // +0x10
};

static_assert(offsetof(I_ValueComparatorSelector, m_min) == 0x08,
              "I_ValueComparatorSelector::m_min offset mismatch");
static_assert(sizeof(I_ValueComparatorSelector) == 0x18,
              "I_ValueComparatorSelector size mismatch");

}  // namespace wh::rpgmodule::storm
