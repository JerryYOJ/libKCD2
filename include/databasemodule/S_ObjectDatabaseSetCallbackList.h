#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryArray.h"
#include "S_ObjectDatabaseSetCallback.h"

// DynArray-backed callback channel at C_ObjectDatabaseManager+0x20. [SYNTHETIC NAME]

namespace wh::databasemodule {

struct S_ObjectDatabaseSetCallbackList {
    DynArray<S_ObjectDatabaseSetCallback> m_entries;  // +0x00
    int16_t m_state08;                                // +0x08, initialized -1
    int16_t m_state0A;                                // +0x0A, initialized -1
};
static_assert(sizeof(S_ObjectDatabaseSetCallbackList) == 0x10,
              "S_ObjectDatabaseSetCallbackList must be 0x10");
static_assert(offsetof(S_ObjectDatabaseSetCallbackList, m_state08) == 0x08,
              "database-set callback state at 0x08");

}  // namespace wh::databasemodule
