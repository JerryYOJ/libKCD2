#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_set>
#include "C_DatabaseCryStringEqual.h"
#include "C_DatabaseCryStringHash.h"

// Module-owned interned CryString pool. [SYNTHETIC NAME]

namespace wh::databasemodule {

class C_DatabaseStringPool {
public:
    std::unordered_set<CryStringT<char>,
                       C_DatabaseCryStringHash,
                       C_DatabaseCryStringEqual> m_strings; // +0x00
    uint32_t m_totalBytes;                                  // +0x40
    uint32_t _pad44;                                        // +0x44
};
static_assert(sizeof(C_DatabaseStringPool) == 0x48,
              "C_DatabaseStringPool must be 0x48");
static_assert(offsetof(C_DatabaseStringPool, m_totalBytes) == 0x40,
              "interned byte count at 0x40");

}  // namespace wh::databasemodule
