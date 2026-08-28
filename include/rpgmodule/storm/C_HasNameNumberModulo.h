#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasNameNumberModulo : public I_Selector {
public:
    ~C_HasNameNumberModulo() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::int32_t m_divisor;  // +0x8 RTTR "divisor"
    std::int32_t m_result;  // +0xC RTTR "result"
};

static_assert(offsetof(C_HasNameNumberModulo, m_result) == 0xc, "C_HasNameNumberModulo::m_result offset mismatch");
static_assert(offsetof(C_HasNameNumberModulo, m_divisor) == 0x8, "C_HasNameNumberModulo::m_divisor offset mismatch");
static_assert(sizeof(C_HasNameNumberModulo) == 0x10, "C_HasNameNumberModulo size mismatch");

}  // namespace wh::rpgmodule::storm
