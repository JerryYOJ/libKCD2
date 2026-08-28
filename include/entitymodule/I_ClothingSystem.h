#pragma once

#include <cstddef>

namespace wh::entitymodule {

class I_ClothingSystem {
public:
    virtual ~I_ClothingSystem();                            // [0] 0x1829174CC
    virtual void unk_01() = 0;                             // [1]
    virtual void unk_02() = 0;                             // [2]
};

static_assert(sizeof(I_ClothingSystem) == 0x08,
              "I_ClothingSystem size mismatch");

}  // namespace wh::entitymodule
