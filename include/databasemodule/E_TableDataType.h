#pragma once
#include <cstdint>

// wh::databasemodule::E_TableDataType -- registered table column storage kind.
// Values are binary-proven; the enum name is synthetic.

namespace wh::databasemodule {

enum class E_TableDataType : int32_t {
    Invalid = -1,
    Int     = 0,
    Int64   = 1,
    Float   = 2,
    Guid    = 3,
    Bool    = 4,
    String  = 5,
    Vec3    = 6,
    Quat    = 7,
    QuatT   = 8,
    Padding = 9,
};

}  // namespace wh::databasemodule
