#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

// Source-reconstructed name; exact two-qword callback token.
struct S_CartDelegateToken {
    std::uintptr_t m_context; // +0x00
    std::uintptr_t m_invoke;  // +0x08, exact callback prototype OPEN
};

static_assert(sizeof(S_CartDelegateToken) == 0x10,
              "S_CartDelegateToken must be 0x10");

}  // namespace wh::entitymodule
