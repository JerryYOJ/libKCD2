#pragma once
#include <cstdint>

namespace wh::databasemodule {

// Registered-table state bits. Names remain neutral where only bit behavior is known.
enum class E_DatabaseTableFlags : uint32_t {
    None          = 0x00,
    Flag01        = 0x01,
    Flag02        = 0x02,
    NeedsLoad     = 0x08,
    Flag10        = 0x10,
    Flag20        = 0x20,
    HasPrimaryKey = 0x40,
    Flag80        = 0x80,
};

}  // namespace wh::databasemodule
