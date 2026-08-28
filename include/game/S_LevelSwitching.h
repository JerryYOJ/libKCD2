#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::game {
class S_LevelSwitching {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
};

static_assert(offsetof(S_LevelSwitching, m_name) == 0x8, "S_LevelSwitching::m_name offset mismatch");
static_assert(sizeof(S_LevelSwitching) == 0x10, "S_LevelSwitching size mismatch");

}  // namespace wh::game
