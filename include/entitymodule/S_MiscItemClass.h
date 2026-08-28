#pragma once

#include <cstddef>
#include <cstdint>

#include "S_DivisibleItemClass.h"
#include "S_TypedItemClass.h"

namespace wh::entitymodule {

class S_MiscItemClass
    : public S_DivisibleItemClass,
      public S_TypedItemClass {
public:
    int32_t m_manipulationType;                                          // +0xD8 RTTR "ManipulationType"
    std::uint8_t m_paddingDC[4];                                         // +0xDC
};

static_assert(offsetof(S_MiscItemClass, m_manipulationType) == 0xD8,
              "S_MiscItemClass::m_manipulationType offset mismatch");
static_assert(sizeof(S_MiscItemClass) == 0xE0,
              "S_MiscItemClass size mismatch");

} // namespace wh::entitymodule
