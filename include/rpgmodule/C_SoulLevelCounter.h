#pragma once
#include <cstddef>
#include <cstdint>
#include "C_SoulPropertyCounter.h"

namespace wh::rpgmodule {

class C_SoulLevelCounter : public C_SoulPropertyCounter {
public:
    ~C_SoulLevelCounter() override;
    RTTR_ENABLE(C_SoulPropertyCounter)
    std::uint8_t m_unknown28[8];                          // +0x28
};

static_assert(sizeof(C_SoulLevelCounter) == 0x30,
              "C_SoulLevelCounter size mismatch");

}  // namespace wh::rpgmodule
