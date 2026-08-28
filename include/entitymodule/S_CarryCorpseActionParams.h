#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_CarryCorpseActionParams {
    std::uint32_t m_targetId;                                            // +0x00 compared to carry-component +0x30
    std::uint32_t m_mode;                                                // +0x04 observed 0 or 1
    bool m_flag;                                                         // +0x08 copied into component flags bit 0x20
    std::uint8_t m_padding09[7];                                         // +0x09
};

static_assert(offsetof(S_CarryCorpseActionParams, m_targetId) == 0x00,
              "S_CarryCorpseActionParams::m_targetId offset mismatch");
static_assert(offsetof(S_CarryCorpseActionParams, m_mode) == 0x04,
              "S_CarryCorpseActionParams::m_mode offset mismatch");
static_assert(offsetof(S_CarryCorpseActionParams, m_flag) == 0x08,
              "S_CarryCorpseActionParams::m_flag offset mismatch");
static_assert(sizeof(S_CarryCorpseActionParams) == 0x10,
              "S_CarryCorpseActionParams size mismatch");

} // namespace wh::entitymodule
