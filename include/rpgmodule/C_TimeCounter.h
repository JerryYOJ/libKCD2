#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Counter.h"
#include "T_GameTimePolicy.h"
#include "T_WorldTimePolicy.h"

namespace wh::rpgmodule {

template <typename TPolicy>
class C_TimeCounter : public C_Counter {
public:
    ~C_TimeCounter() override;
    double unk_07() override;
    void unk_15() override;
    void unk_19() override;
    RTTR_ENABLE(C_Counter)
    std::uint8_t m_unknown20[0x18];                       // +0x20
};

static_assert(sizeof(C_TimeCounter<T_GameTimePolicy>) == 0x38,
              "C_TimeCounter<T_GameTimePolicy> size mismatch");
static_assert(sizeof(C_TimeCounter<T_WorldTimePolicy>) == 0x38,
              "C_TimeCounter<T_WorldTimePolicy> size mismatch");

}  // namespace wh::rpgmodule
