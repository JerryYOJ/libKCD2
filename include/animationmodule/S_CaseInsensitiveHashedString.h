#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::animationmodule::S_CaseInsensitiveHashedString -- KCD2 WHGame.dll 1.5.6. sizeof 0x10.
// -----------------------------------------------
// Source-reconstructed name. Factory sub_18078B038 stores the CryString and its
// ASCII-case-insensitive CRC32; ctor sub_18094239C initializes the cached CRC to zero.

namespace wh::animationmodule {

class S_CaseInsensitiveHashedString {
public:
    CryStringT<char> m_value;  // +0x00
    std::uint32_t    m_crc;    // +0x08
    std::uint32_t    _pad0C;   // +0x0C
};
static_assert(sizeof(S_CaseInsensitiveHashedString) == 0x10);
static_assert(offsetof(S_CaseInsensitiveHashedString, m_crc) == 0x08);

}  // namespace wh::animationmodule
