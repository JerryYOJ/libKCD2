#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include "C_DatabaseCryStringEqual.h"
#include "C_DatabaseCryStringHash.h"

// XML serialization string-to-offset accumulator. [SYNTHETIC NAME]

namespace wh::databasemodule {

struct S_SerializationStringPoolBuilder {
    uint32_t m_totalBytes;  // +0x00
    uint32_t _pad04;        // +0x04
    std::unordered_map<CryStringT<char>, uint32_t,
                       C_DatabaseCryStringHash,
                       C_DatabaseCryStringEqual> m_offsets; // +0x08
};
static_assert(sizeof(S_SerializationStringPoolBuilder) == 0x48,
              "S_SerializationStringPoolBuilder must be 0x48");
static_assert(offsetof(S_SerializationStringPoolBuilder, m_offsets) == 0x08,
              "serialization string-offset map at 0x08");

}  // namespace wh::databasemodule
