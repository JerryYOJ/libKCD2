#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_ButcheringActionParams {
    std::uint32_t m_unknown00;                                           // +0x00 ctor-zeroed dword
    std::uint8_t m_padding04[4];                                         // +0x04
};

static_assert(offsetof(S_ButcheringActionParams, m_unknown00) == 0x00,
              "S_ButcheringActionParams::m_unknown00 offset mismatch");
static_assert(sizeof(S_ButcheringActionParams) == 0x08,
              "S_ButcheringActionParams size mismatch");

} // namespace wh::entitymodule
