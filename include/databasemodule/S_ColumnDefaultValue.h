#pragma once
#include <cstddef>
#include <cstdint>

// Inline 16-byte descriptor default store. [SYNTHETIC NAME]

namespace wh::databasemodule {

union alignas(8) S_ColumnDefaultValue {
    std::byte raw[0x10];
    int32_t intValue;
    int64_t int64Value;
    float floatValue;
    CryGUID guidValue;
    bool boolValue;
    const char* stringValue;
    Vec3 vec3Value;
    Quat quatValue;
};
static_assert(sizeof(S_ColumnDefaultValue) == 0x10,
              "S_ColumnDefaultValue must be 0x10");
static_assert(alignof(S_ColumnDefaultValue) == 0x08,
              "S_ColumnDefaultValue must be 8-byte aligned");

}  // namespace wh::databasemodule
