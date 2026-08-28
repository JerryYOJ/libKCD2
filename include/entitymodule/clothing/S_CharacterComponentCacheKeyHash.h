#pragma once
#include <cstddef>

#include "S_CharacterComponentCacheKey.h"

namespace wh::entitymodule::clothing {

struct S_CharacterComponentCacheKeyHash {
    std::size_t operator()(const S_CharacterComponentCacheKey& key) const noexcept;
};

} // namespace wh::entitymodule::clothing
