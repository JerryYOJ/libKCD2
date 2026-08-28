#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_ItemFilterType::Type -- KCD2 1.5.6 (kd7u).
// -----------------------------------------------
// Tri-state item-descriptor filter. Enumerators from the RTTR enum registrar 0x1801552F0
// (RTTR sizeof 1). Matcher semantics (C_ItemPropertyDescriptor 0x18096F50C): Unused skips the
// test, Pass requires the predicate true, ANY other value (incl. Fail) requires it false.

namespace wh::entitymodule {

struct E_ItemFilterType {
    enum Type : std::uint8_t {
        Unused = 0,
        Pass   = 1,
        Fail   = 2,
    };
};
static_assert(sizeof(E_ItemFilterType::Type) == 1,
              "E_ItemFilterType::Type size mismatch");

}  // namespace wh::entitymodule
