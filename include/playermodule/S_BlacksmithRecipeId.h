#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {
class S_BlacksmithRecipeId {
public:
    virtual ~S_BlacksmithRecipeId();
    RTTR_ENABLE()  // [1..3]
    CryStringT<char> m_id;  // +0x08
};

static_assert(sizeof(S_BlacksmithRecipeId) == 0x10,
              "S_BlacksmithRecipeId size mismatch");

}  // namespace wh::playermodule
