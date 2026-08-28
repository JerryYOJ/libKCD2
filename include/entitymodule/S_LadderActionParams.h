#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_LadderActionParams {
    std::uint32_t m_ladderEntityId;                                      // +0x00 OnStart entity lookup key
    std::uint8_t m_padding04[4];                                         // +0x04
};

static_assert(offsetof(S_LadderActionParams, m_ladderEntityId) == 0x00,
              "S_LadderActionParams::m_ladderEntityId offset mismatch");
static_assert(sizeof(S_LadderActionParams) == 0x08,
              "S_LadderActionParams size mismatch");

} // namespace wh::entitymodule
