#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_InteractiveSceneActionParams {
    std::uint8_t m_mode;                                              // +0x00, observed values 0..3
    std::uint8_t m_padding01[7];                                      // +0x01
};

static_assert(offsetof(S_InteractiveSceneActionParams, m_mode) == 0x00,
              "S_InteractiveSceneActionParams::m_mode offset mismatch");
static_assert(sizeof(S_InteractiveSceneActionParams) == 0x08,
              "S_InteractiveSceneActionParams size mismatch");

} // namespace wh::entitymodule
