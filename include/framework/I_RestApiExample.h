#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class I_RestApiExample {
public:
    virtual ~I_RestApiExample() = default;                  // [0]
    RTTR_ENABLE()                                           // [1..3]
};

static_assert(sizeof(I_RestApiExample) == 0x08,
              "I_RestApiExample size mismatch");

}  // namespace wh::framework
