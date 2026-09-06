#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"
#include "../rttr/variant.h"
#include "C_SharedResource.h"

namespace wh::conceptmodule {

class C_BaseAsset {
public:
    C_BaseAsset();
    virtual ~C_BaseAsset();                                      // [0] 0x181220028
    virtual rttr::variant Resolve(_smart_ptr<C_SharedResource> resource); // [1] 0x1804C48D4
    RTTR_ENABLE()                                                // [2..4]

    CryStringT<char> m_name;                                     // +0x08 RTTR "Name"
    CryStringT<char> m_target;                                   // +0x10 RTTR "Target"
};

static_assert(offsetof(C_BaseAsset, m_name) == 0x08,
              "C_BaseAsset::m_name offset mismatch");
static_assert(offsetof(C_BaseAsset, m_target) == 0x10,
              "C_BaseAsset::m_target offset mismatch");
static_assert(sizeof(C_BaseAsset) == 0x18,
              "C_BaseAsset size mismatch");

}  // namespace wh::conceptmodule
