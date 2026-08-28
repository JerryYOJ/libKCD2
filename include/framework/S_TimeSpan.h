#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::framework {

struct S_TimeSpan {
    std::int64_t m_milliseconds; // +0x00
};

static_assert(offsetof(S_TimeSpan, m_milliseconds) == 0x00,
              "S_TimeSpan::m_milliseconds offset mismatch");
static_assert(sizeof(S_TimeSpan) == 0x08,
              "S_TimeSpan size mismatch");

}  // namespace wh::framework
