#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "C_Node.h"

namespace wh::conceptmodule {

class C_StaticInstancePlaceholder : public C_Node {
public:
    C_StaticInstancePlaceholder();                          // 0x1811DF174
    ~C_StaticInstancePlaceholder() override;                // [0] 0x1813B57EC
    RTTR_ENABLE(C_Node)                                     // [5..7]
    bool unk23() override;                                  // [23] returns true

    CryStringT<char> m_definition;                          // +0x40 RTTR "Definition" (read-only)
};

static_assert(offsetof(C_StaticInstancePlaceholder, m_definition) == 0x40,
              "C_StaticInstancePlaceholder::m_definition offset mismatch");
static_assert(sizeof(C_StaticInstancePlaceholder) == 0x48,
              "C_StaticInstancePlaceholder size mismatch");

}  // namespace wh::conceptmodule
