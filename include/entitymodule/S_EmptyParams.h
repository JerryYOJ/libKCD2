#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class S_EmptyParams {
public:
    RTTR_ENABLE()                                         // [0..2]
};

static_assert(sizeof(S_EmptyParams) == 0x08,
              "S_EmptyParams size mismatch");

}  // namespace wh::entitymodule
