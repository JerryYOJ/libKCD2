#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::databasemodule {

class T_TableString {
public:
    CryStringT<char> m_value;                               // +0x00 table-authored string
};

static_assert(offsetof(T_TableString, m_value) == 0x00,
              "T_TableString::m_value offset mismatch");
static_assert(sizeof(T_TableString) == 0x08,
              "T_TableString size mismatch");

}  // namespace wh::databasemodule
