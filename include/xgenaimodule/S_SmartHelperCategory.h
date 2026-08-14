#pragma once
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

class C_SmartHelper;

// Source name is not emitted; helpers are borrowed from the owning class definition.
struct S_SmartHelperCategory {
    CryStringT<char> m_name;                // +0x00
    std::vector<C_SmartHelper*> m_helpers;  // +0x08
};
static_assert(sizeof(S_SmartHelperCategory) == 0x20,
              "S_SmartHelperCategory must be 0x20");

}  // namespace wh::xgenaimodule
