#pragma once
#include <cstdint>

// wh::databasemodule::I_DynamicEnum -- five-slot 32-bit enum provider.
// The interface has no virtual destructor; concrete owners destroy providers manually.

namespace wh::databasemodule {

class I_DynamicEnum {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_DynamicEnum;

    virtual uint32_t GetCount() const = 0;                         // [0]
    virtual uint32_t GetValue(uint32_t index) const = 0;           // [1]
    virtual const char* GetName(uint32_t index) const = 0;         // [2]
    virtual uint32_t GetValueByName(const char* name) const = 0;   // [3]
    virtual const char* GetNameByValue(uint32_t value) const = 0;  // [4]
};
static_assert(sizeof(I_DynamicEnum) == 0x08,
              "I_DynamicEnum must contain one vtable pointer");

}  // namespace wh::databasemodule
