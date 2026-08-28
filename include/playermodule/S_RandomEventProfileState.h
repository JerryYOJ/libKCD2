#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::playermodule {

struct S_RandomEventProfileState {
    void* m_profile;                  // +0x00, owned polymorphic profile; exact type unresolved
    bool m_loaded;                    // +0x08
    std::uint8_t m_padding09[7];
};

static_assert(sizeof(S_RandomEventProfileState) == 0x10,
              "S_RandomEventProfileState size mismatch");
static_assert(offsetof(S_RandomEventProfileState, m_loaded) == 0x08,
              "S_RandomEventProfileState loaded offset mismatch");

} // namespace wh::playermodule
