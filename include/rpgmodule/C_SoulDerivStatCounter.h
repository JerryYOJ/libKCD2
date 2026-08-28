#pragma once
#include <cstddef>
#include <cstdint>
#include "C_SoulPropertyCounter.h"

namespace wh::rpgmodule {

class C_SoulDerivStatCounter : public C_SoulPropertyCounter {
public:
    ~C_SoulDerivStatCounter() override;
    RTTR_ENABLE(C_SoulPropertyCounter)
    std::uint8_t m_unknown28[8];                          // +0x28
};

static_assert(sizeof(C_SoulDerivStatCounter) == 0x30,
              "C_SoulDerivStatCounter size mismatch");

}  // namespace wh::rpgmodule
