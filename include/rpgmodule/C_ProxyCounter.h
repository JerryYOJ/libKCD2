#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Counter.h"

namespace wh::rpgmodule {

template <typename T>
class C_ProxyCounter : public C_Counter {
public:
    ~C_ProxyCounter() override;
    double unk_07() override;
    RTTR_ENABLE(C_Counter)
    void unk_15() override;                               // [15], int 0x181561820
    void unk_18() override;                               // [18], int 0x1819DE264
    void unk_19() override;                               // [19], int 0x1819D4C4C
    virtual void unk_22();                                // [22]
    virtual void unk_23();                                // [23]
    std::uint8_t m_unknown20[0x48];                       // +0x20
};

static_assert(sizeof(C_ProxyCounter<int>) == 0x68,
              "C_ProxyCounter<int> size mismatch");
static_assert(sizeof(C_ProxyCounter<double>) == 0x68,
              "C_ProxyCounter<double> size mismatch");

}  // namespace wh::rpgmodule
