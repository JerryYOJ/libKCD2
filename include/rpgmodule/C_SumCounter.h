#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Counter.h"

namespace wh::rpgmodule {

template <typename T>
class C_SumCounter : public C_Counter {
public:
    ~C_SumCounter() override;
    double unk_07() override;
    void unk_15() override;
    void unk_19() override;
    RTTR_ENABLE(C_Counter)
    T m_value;                                            // +0x20
};

static_assert(sizeof(C_SumCounter<int>) == 0x28, "C_SumCounter<int> size mismatch");
static_assert(sizeof(C_SumCounter<double>) == 0x28, "C_SumCounter<double> size mismatch");

}  // namespace wh::rpgmodule
