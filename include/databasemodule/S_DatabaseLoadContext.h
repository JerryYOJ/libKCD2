#pragma once
#include <cstdint>

// wh::databasemodule::S_DatabaseLoadContext -- module-owned load diagnostics state.
// sizeof 0x10; allocated by C_DatabaseModule's constructor. [SYNTHETIC NAME]

namespace wh::databasemodule {

class C_DatabaseModule;

struct S_DatabaseLoadContext {
    C_DatabaseModule* m_pModule;       // +0x00
    int32_t           m_errorCount;    // +0x08
    uint32_t          _pad0C;          // +0x0C
};
static_assert(sizeof(S_DatabaseLoadContext) == 0x10, "S_DatabaseLoadContext must be 0x10");

}  // namespace wh::databasemodule
