#pragma once
#include <cstddef>
#include "C_StaticSoulPool.h"

namespace wh::rpgmodule {

class C_SingleSoulPool : public C_StaticSoulPool {
public:
    ~C_SingleSoulPool() override;
    RTTR_ENABLE(C_StaticSoulPool)
};

static_assert(sizeof(C_SingleSoulPool) == 0x30,
              "C_SingleSoulPool size mismatch");

}  // namespace wh::rpgmodule
