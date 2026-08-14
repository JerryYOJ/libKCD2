#pragma once
#include <cstddef>

namespace wh::xgenaimodule {

class S_IntelligentObjectEntry {
public:
    CryStringT<char> m_name;  // +0x00
    void* m_pValue;           // +0x08, exact pointee role OPEN
};
static_assert(sizeof(S_IntelligentObjectEntry) == 0x10,
              "S_IntelligentObjectEntry must be 0x10");

}  // namespace wh::xgenaimodule
