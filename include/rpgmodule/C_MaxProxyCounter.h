#pragma once
#include "C_ProxyCounter.h"

namespace wh::rpgmodule {

struct S_Statistic;

template <typename T>
class C_MaxProxyCounter : public C_ProxyCounter<T> {
public:
    explicit C_MaxProxyCounter(S_Statistic const& statistic);
    ~C_MaxProxyCounter() override;                         // [0], int 0x182D4D5E4
    RTTR_ENABLE(C_ProxyCounter<T>)                         // [12..14]
    void unk_15() override;                               // [15], int 0x181561980
    void unk_16() override;                               // [16], int 0x1819EDE7C
    void unk_17() override;                               // [17], int 0x181561938
    void unk_23() override;                               // [23], int 0x180E7AD28
};

static_assert(sizeof(C_MaxProxyCounter<int>) == 0x68,
              "C_MaxProxyCounter<int> size mismatch");

}  // namespace wh::rpgmodule
