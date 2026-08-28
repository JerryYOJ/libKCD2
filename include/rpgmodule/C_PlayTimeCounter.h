#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Counter.h"

namespace wh::rpgmodule {

class C_PlayTimeCounter : public C_Counter {
public:
    ~C_PlayTimeCounter() override;
    double unk_07() override;
    void unk_15() override;
    void unk_19() override;
    RTTR_ENABLE(C_Counter)
    std::uint8_t m_unknown20[0x20];                       // +0x20
};

static_assert(sizeof(C_PlayTimeCounter) == 0x40,
              "C_PlayTimeCounter size mismatch");

}  // namespace wh::rpgmodule
