#pragma once
#include <cstddef>

// wh::databasemodule::S_DatabaseNameRange -- ABI view of the name range
// consumed by I_DatabaseModule batch load/unload methods. [SYNTHETIC NAME]

namespace wh::databasemodule {

struct S_DatabaseNameRange {
    const char* const* m_begin;  // +0x00
    const char* const* m_end;    // +0x08

    [[nodiscard]] std::size_t size() const noexcept { return static_cast<std::size_t>(m_end - m_begin); }
    [[nodiscard]] bool empty() const noexcept { return m_begin == m_end; }
};
static_assert(sizeof(S_DatabaseNameRange) == 0x10, "S_DatabaseNameRange must be 0x10");

}  // namespace wh::databasemodule
