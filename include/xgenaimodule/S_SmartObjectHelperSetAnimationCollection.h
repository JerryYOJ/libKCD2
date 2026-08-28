#pragma once

#include <boost/container/flat_map.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

#include "S_SmartObjectHelperSetAnimation.h"

namespace wh::xgenaimodule {

struct S_SmartObjectHelperSetAnimationCollection {
    boost::container::flat_map<
        unsigned int, std::vector<S_SmartObjectHelperSetAnimation>>
        m_animationsMap;                                                     // +0x00 RTTR "AnimationsMap"
    std::uint64_t m_hashValue;                                               // +0x18 RTTR "HashValue"
    std::uint8_t m_unknown20[0x18];                                          // +0x20
};

static_assert(offsetof(S_SmartObjectHelperSetAnimationCollection, m_hashValue) ==
                  0x18,
              "S_SmartObjectHelperSetAnimationCollection::m_hashValue offset mismatch");
static_assert(sizeof(S_SmartObjectHelperSetAnimationCollection) == 0x38,
              "S_SmartObjectHelperSetAnimationCollection size mismatch");

} // namespace wh::xgenaimodule
