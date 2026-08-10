#pragma once
#include <cstddef>
#include "S_TableLayout.h"

// Specialized generated-layout cache entry. [SYNTHETIC NAME]

namespace wh::databasemodule {

struct S_TableLayoutCacheEntry {
    CryStringT<char> m_substitution;          // +0x00, owned
    const S_TableLayout* m_layoutTemplate;    // +0x08, borrowed
    S_TableLayout* m_specializedLayout;       // +0x10, process-lifetime allocation
};
static_assert(sizeof(S_TableLayoutCacheEntry) == 0x18,
              "S_TableLayoutCacheEntry must be 0x18");

}  // namespace wh::databasemodule
