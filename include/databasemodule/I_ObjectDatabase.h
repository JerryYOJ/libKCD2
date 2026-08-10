#pragma once
#include <cstdint>

// wh::databasemodule::I_ObjectDatabase -- three-slot object-database interface.

namespace wh::databasemodule {

class I_ObjectDatabase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ObjectDatabase;

    virtual ~I_ObjectDatabase();                    // [0] 0x182743DB4
    virtual int32_t unk_01() const;                 // [1] returns 1; meaning OPEN
    virtual const char* GetTableName() const = 0;   // [2]
};
static_assert(sizeof(I_ObjectDatabase) == 0x08,
              "I_ObjectDatabase must contain one vtable pointer");

}  // namespace wh::databasemodule
