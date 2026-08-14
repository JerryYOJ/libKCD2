#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::rpgmodule {

class C_Soul;

struct S_SoulMailboxSub {
    C_Soul* m_pOwner;       // +0x00, borrowed
    std::int32_t m_msgId;   // +0x08
    std::uint8_t m_flag0C;  // +0x0C
    std::uint8_t _pad0D[3]; // +0x0D
};
static_assert(sizeof(S_SoulMailboxSub) == 0x10,
              "S_SoulMailboxSub must be 0x10");

}  // namespace wh::rpgmodule
