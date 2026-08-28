#pragma once
#include <cstddef>
#include <cstdint>
#include "C_GameplayManager.h"

namespace wh::framework {

class C_Framework {
public:
    std::uint8_t m_unknown00[0xB8];                         // +0x00
    C_GameplayManager m_gameplayManager;                    // +0xB8 accessor "GameplayManager"
    std::uint8_t m_unknownD0[0xC0];                         // +0xD0
};

static_assert(offsetof(C_Framework, m_gameplayManager) == 0xB8,
              "C_Framework::m_gameplayManager offset mismatch");
static_assert(sizeof(C_Framework) == 0x190,
              "C_Framework size mismatch");

}  // namespace wh::framework
