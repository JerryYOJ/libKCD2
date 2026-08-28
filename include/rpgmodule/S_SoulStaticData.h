#pragma once
#include <cstddef>
#include <cstdint>
#include "S_CharacterBodyDescription.h"

namespace wh::rpgmodule {

struct S_SoulStaticData {
    S_SoulStaticData();
    ~S_SoulStaticData();

    std::uint8_t m_runtime00[0xF0];                         // +0x00
    S_CharacterBodyDescription m_characterBodyDescription; // +0xF0
    std::uint8_t m_runtime118[0x158 - 0x118];               // +0x118
};

static_assert(offsetof(S_SoulStaticData, m_characterBodyDescription) == 0xF0,
              "S_SoulStaticData body-description offset mismatch");
static_assert(sizeof(S_SoulStaticData) == 0x158,
              "S_SoulStaticData size mismatch");

} // namespace wh::rpgmodule
