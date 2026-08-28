#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

// Synthetic name; binary layout is an owned serialized byte buffer.
struct S_SaveExtensionData {
    std::uint8_t* m_data;     // +0x00
    std::uint32_t m_size;     // +0x08
    std::uint32_t m_padding0C;
};

static_assert(sizeof(S_SaveExtensionData) == 0x10,
              "S_SaveExtensionData size mismatch");

} // namespace wh::entitymodule
