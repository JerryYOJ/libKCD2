#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_ShieldPaintingIngredientUIName {
    CryStringT<char> m_text;       // +0x00 RTTR "UIName"
    std::int32_t m_id;             // +0x08 RTTR "UIName"
    bool m_flag;                   // +0x0C RTTR "UIName"
    std::uint8_t m_padding0D[3];   // +0x0D
};

static_assert(offsetof(S_ShieldPaintingIngredientUIName, m_id) == 0x08,
              "S_ShieldPaintingIngredientUIName::m_id offset mismatch");
static_assert(offsetof(S_ShieldPaintingIngredientUIName, m_flag) == 0x0C,
              "S_ShieldPaintingIngredientUIName::m_flag offset mismatch");
static_assert(sizeof(S_ShieldPaintingIngredientUIName) == 0x10,
              "S_ShieldPaintingIngredientUIName size mismatch");

} // namespace wh::entitymodule
