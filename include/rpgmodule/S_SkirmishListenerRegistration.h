#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace wh::rpgmodule {

class I_SkirmishListener;
class I_Soul;

struct S_SkirmishListenerRegistration {
    std::vector<I_Soul*> m_souls;                                  // +0x00
    I_SkirmishListener* m_listener;                                // +0x18
    std::uint32_t m_matchFlags;                                    // +0x20
    std::uint8_t m_padding24[4];                                   // +0x24
};

static_assert(sizeof(S_SkirmishListenerRegistration) == 0x28,
              "S_SkirmishListenerRegistration size mismatch");
static_assert(offsetof(S_SkirmishListenerRegistration, m_listener) == 0x18,
              "S_SkirmishListenerRegistration listener offset mismatch");

} // namespace wh::rpgmodule
