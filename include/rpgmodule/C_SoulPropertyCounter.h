#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Counter.h"

namespace wh::rpgmodule {

class C_SoulPropertyCounter : public C_Counter {
public:
    ~C_SoulPropertyCounter() override;
    double unk_07() override;
    void unk_15() override;
    void unk_19() override;
    RTTR_ENABLE(C_Counter)
    std::uint8_t m_unknown20[8];                          // +0x20
};

static_assert(sizeof(C_SoulPropertyCounter) == 0x28,
              "C_SoulPropertyCounter size mismatch");

}  // namespace wh::rpgmodule
