#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/T_TableDataType.h"

namespace wh::rpgmodule {

struct S_SoulStaticDBData {
    S_SoulStaticDBData();
    ~S_SoulStaticDBData();

    std::uint8_t m_runtime00[0x4C];                            // +0x00
    wh::databasemodule::T_TableDataType<float> m_combatLevel; // +0x4C
    std::uint8_t m_runtime50[0x80 - 0x50];                    // +0x50
};

static_assert(offsetof(S_SoulStaticDBData, m_combatLevel) == 0x4C,
              "S_SoulStaticDBData combat-level offset mismatch");
static_assert(sizeof(S_SoulStaticDBData) == 0x80,
              "S_SoulStaticDBData size mismatch");

} // namespace wh::rpgmodule
