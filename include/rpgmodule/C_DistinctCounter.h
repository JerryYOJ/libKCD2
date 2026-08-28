#pragma once
#include <cstddef>
#include <unordered_set>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "C_Counter.h"

namespace wh::rpgmodule {

template <typename T>
class C_DistinctCounter : public C_Counter {
public:
    ~C_DistinctCounter() override;
    double unk_07() override;
    void unk_15() override;
    void unk_19() override;
    RTTR_ENABLE(C_Counter)
    std::unordered_set<T> m_values;                       // +0x20
};

static_assert(sizeof(std::unordered_set<CryGUID>) == 0x40,
              "unordered_set header must be 0x40");
static_assert(sizeof(C_DistinctCounter<CryGUID>) == 0x60,
              "C_DistinctCounter<CryGUID> size mismatch");
static_assert(sizeof(C_DistinctCounter<CryStringT<char>>) == 0x60,
              "C_DistinctCounter<CryStringT> size mismatch");
static_assert(sizeof(C_DistinctCounter<unsigned int>) == 0x60,
              "C_DistinctCounter<unsigned int> size mismatch");

}  // namespace wh::rpgmodule
