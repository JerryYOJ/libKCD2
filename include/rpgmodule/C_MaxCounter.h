#pragma once
#include <cstddef>
#include "C_Counter.h"

namespace wh::rpgmodule {

template <typename T>
class C_MaxCounter : public C_Counter {
public:
    ~C_MaxCounter() override;
    double unk_07() override;
    void unk_15() override;
    void unk_19() override;
    RTTR_ENABLE(C_Counter)
    T m_value;                                            // +0x20
};

static_assert(sizeof(C_MaxCounter<double>) == 0x28,
              "C_MaxCounter<double> size mismatch");

}  // namespace wh::rpgmodule
