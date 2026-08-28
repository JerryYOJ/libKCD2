#pragma once

namespace wh::rpgmodule {

class I_RPGShop {
public:
    virtual ~I_RPGShop() = default;                          // [0] 0x18259A7F0
    virtual float unk_01(void* context) const = 0;            // [1]
    virtual float unk_02(void* context) const = 0;            // [2]
};

static_assert(sizeof(I_RPGShop) == 0x08,
              "I_RPGShop size mismatch");

}  // namespace wh::rpgmodule
