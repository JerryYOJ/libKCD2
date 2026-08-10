#pragma once
#include <cstddef>
#include <vector>

// Type-erased callback invoked with a processed object-database set. [SYNTHETIC NAME]

namespace wh::databasemodule {

class C_ObjectDatabaseBase;

struct S_ObjectDatabaseSetCallback {
    using callback_type = void (*)(
        void*, const std::vector<C_ObjectDatabaseBase*>&);

    void* m_context;              // +0x00, borrowed
    callback_type m_callback;     // +0x08
};
static_assert(sizeof(S_ObjectDatabaseSetCallback) == 0x10,
              "S_ObjectDatabaseSetCallback must be 0x10");

}  // namespace wh::databasemodule
