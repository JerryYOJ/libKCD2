#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryArray.h"

// Physically recovered delegate channel at C_ObjectDatabaseManager+0x10; role OPEN.

namespace wh::databasemodule {

struct S_ObjectDatabaseOpaqueDelegateList {
    DynArray<std::array<std::uintptr_t, 2>> m_entries;  // +0x00
    int16_t m_state08;                                  // +0x08, initialized -1
    int16_t m_state0A;                                  // +0x0A, initialized -1
};
static_assert(sizeof(S_ObjectDatabaseOpaqueDelegateList) == 0x10,
              "S_ObjectDatabaseOpaqueDelegateList must be 0x10");
static_assert(offsetof(S_ObjectDatabaseOpaqueDelegateList, m_state08) == 0x08,
              "opaque delegate state at 0x08");

}  // namespace wh::databasemodule
