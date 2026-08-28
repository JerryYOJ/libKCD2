#pragma once

#include "S_CharacterComponentCacheKey.h"

namespace wh::entitymodule::clothing {

struct S_CharacterComponentCacheKeyEqual {
    bool operator()(
        const S_CharacterComponentCacheKey& lhs,
        const S_CharacterComponentCacheKey& rhs) const noexcept;
};

} // namespace wh::entitymodule::clothing
