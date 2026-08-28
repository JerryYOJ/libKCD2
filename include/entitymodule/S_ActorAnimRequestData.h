#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

// Source name unresolved; constructor 0x1808E2698 proves this 0x20 subobject.
struct S_ActorAnimRequestData {
    std::uint64_t m_unknown00;                              // +0x00, runtime-global default
    CryStringT<char> m_name;                                // +0x08
    std::uint64_t m_unknown10;                              // +0x10
    std::uint32_t m_unknown18;                              // +0x18
    bool m_flag1C;                                          // +0x1C
    std::uint8_t m_padding1D[3];                            // +0x1D
};

static_assert(offsetof(S_ActorAnimRequestData, m_name) == 0x08,
              "S_ActorAnimRequestData::m_name offset mismatch");
static_assert(sizeof(S_ActorAnimRequestData) == 0x20,
              "S_ActorAnimRequestData size mismatch");

}  // namespace wh::entitymodule
