#pragma once
#include <cstddef>

#include "S_ResourceRef.h"

// wh::conceptmodule::S_ProjectEdgeRecord -- one grouped project-edge descriptor
// (descriptive type/member names; original names were not emitted).  sizeof 0x28.

namespace wh::conceptmodule {

struct S_ProjectEdgeRecord {
    S_ResourceRef m_firstNode;       // +0x00
    S_ResourceRef m_secondNode;      // +0x08
    CryStringT<char> m_firstPort;    // +0x10
    CryStringT<char> m_secondPort;   // +0x18
    bool m_mode;                     // +0x20, semantics unverified
    std::byte _pad21[7];             // +0x21
};
static_assert(sizeof(S_ProjectEdgeRecord) == 0x28);
static_assert(offsetof(S_ProjectEdgeRecord, m_firstPort) == 0x10);
static_assert(offsetof(S_ProjectEdgeRecord, m_mode) == 0x20);

}  // namespace wh::conceptmodule
