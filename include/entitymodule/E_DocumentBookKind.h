#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_DocumentBookKind -- document UI asset kind.
// -----------------------------------------------
// [SOURCE-RECONSTRUCTED TYPE NAME] The native registry at 0x180155AC0 maps
// the authored names below to 1/2, and C_DocumentItem stores the result with
// a one-byte write at +0x170. The constructor's zero state has no recovered name.

namespace wh::entitymodule {

enum class E_DocumentBookKind : std::uint8_t {
    GeneralBook = 1,
    AlchemyBook = 2,
};
static_assert(sizeof(E_DocumentBookKind) == 0x01,
              "document book kind must remain one byte");

}  // namespace wh::entitymodule
