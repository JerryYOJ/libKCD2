#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::framework {

struct S_TimeOfDay {
    std::int64_t m_milliseconds; // +0x00
};

static_assert(offsetof(S_TimeOfDay, m_milliseconds) == 0x00,
              "S_TimeOfDay::m_milliseconds offset mismatch");
static_assert(sizeof(S_TimeOfDay) == 0x08,
              "S_TimeOfDay size mismatch");

}  // namespace wh::framework
