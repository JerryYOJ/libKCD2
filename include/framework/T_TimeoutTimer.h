#pragma once
#include <cstddef>
#include <cstdint>
#include "rttr/rttr_enable.h"

namespace wh::framework {

template <class TimePolicy>
class T_TimeoutTimer {
public:
    T_TimeoutTimer();
    ~T_TimeoutTimer();
    RTTR_ENABLE() // [0..2]

    std::uint32_t m_timerId;       // +0x08
    std::uint32_t m_padding0C;     // +0x0C
    std::uint64_t m_runtime10;     // +0x10
    std::uint64_t m_runtime18;     // +0x18
    std::uint64_t m_runtime20;     // +0x20
};

static_assert(sizeof(T_TimeoutTimer<void>) == 0x28,
              "T_TimeoutTimer size mismatch");
static_assert(offsetof(T_TimeoutTimer<void>, m_timerId) == 0x08,
              "T_TimeoutTimer timer id offset mismatch");

} // namespace wh::framework
