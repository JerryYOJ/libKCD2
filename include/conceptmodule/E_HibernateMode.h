#pragma once
#include <cstdint>

// wh::conceptmodule::E_HibernateMode -- module hibernation policy.
// Values are from RTTR registration 0x18008BA90.

namespace wh::conceptmodule {

struct E_HibernateMode {
    enum Type : uint8_t {
        None         = 0,
        Auto         = 1,
        Script       = 2,
        EventPlace   = 3,
        DLC          = 4,
        ActivityType = 5,
    };
};

}  // namespace wh::conceptmodule
