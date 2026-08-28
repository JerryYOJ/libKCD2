#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <utility>

#include "S_CharacterComponentCacheKey.h"
#include "S_CharacterComponentCacheKeyEqual.h"
#include "S_CharacterComponentCacheKeyHash.h"

namespace wh::entitymodule::clothing {

struct S_CharacterComponentQueryCache {
    using value_type = std::pair<std::int32_t, std::int32_t>;
    using map_type = std::unordered_map<
        S_CharacterComponentCacheKey,
        value_type,
        S_CharacterComponentCacheKeyHash,
        S_CharacterComponentCacheKeyEqual>;

    S_CharacterComponentCacheKey m_defaultKey; // +0x00
    map_type m_entries;                         // +0x20
    std::int32_t m_frameId;                     // +0x60, initialized -1
    std::uint32_t m_padding64;                  // +0x64
};

static_assert(offsetof(S_CharacterComponentQueryCache, m_entries) == 0x20,
              "S_CharacterComponentQueryCache::m_entries offset mismatch");
static_assert(offsetof(S_CharacterComponentQueryCache, m_frameId) == 0x60,
              "S_CharacterComponentQueryCache::m_frameId offset mismatch");
static_assert(sizeof(S_CharacterComponentQueryCache) == 0x68,
              "S_CharacterComponentQueryCache size mismatch");

} // namespace wh::entitymodule::clothing
