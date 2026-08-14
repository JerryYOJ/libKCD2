#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

class C_SmartHelper;

// Source name is not emitted; this record shape is constructor/reader proven.
struct S_SmartHelperLink {
    CryStringT<char> m_name;   // +0x00
    C_SmartHelper* m_pTarget;  // +0x08, borrowed
};
static_assert(sizeof(S_SmartHelperLink) == 0x10,
              "S_SmartHelperLink must be 0x10");

}  // namespace wh::xgenaimodule
