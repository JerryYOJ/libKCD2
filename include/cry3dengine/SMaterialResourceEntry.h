#pragma once
#include <cstddef>
#include <cstdint>

struct SMaterialResourceEntry {
    CryStringT<char> m_name;                                    // +0x00
    std::uint32_t m_value;                                      // +0x08
    std::uint32_t m_padding0C;                                  // +0x0C
};

static_assert(offsetof(SMaterialResourceEntry, m_value) == 0x08,
              "SMaterialResourceEntry value offset mismatch");
static_assert(sizeof(SMaterialResourceEntry) == 0x10,
              "SMaterialResourceEntry size mismatch");
