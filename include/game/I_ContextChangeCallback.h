#pragma once
#include <cstddef>

namespace wh::game {

class I_ContextChangeCallback {
public:
    virtual void OnContextAdded() = 0;                          // [0]
    virtual void OnContextRemoved() = 0;                        // [1]
};

static_assert(sizeof(I_ContextChangeCallback) == 0x08,
              "I_ContextChangeCallback size mismatch");

}  // namespace wh::game
