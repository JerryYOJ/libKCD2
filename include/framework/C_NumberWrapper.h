#pragma once
#include <type_traits>
#include "NumberWrapperPolicy/Clamp.h"
#include "NumberWrapperPolicy/LowerBounded.h"

namespace wh::framework {

template <typename TPolicy>
class C_NumberWrapper {
public:
    using value_type = typename TPolicy::value_type;

    value_type m_value; // +0x00
};

static_assert(sizeof(C_NumberWrapper<NumberWrapperPolicy::Clamp<
                  0, 1, float, std::false_type, std::true_type>>) == 0x04,
              "C_NumberWrapper<Clamp<false,true>> size mismatch");
static_assert(sizeof(C_NumberWrapper<NumberWrapperPolicy::Clamp<
                  0, 1, float, std::true_type, std::true_type>>) == 0x04,
              "C_NumberWrapper<Clamp<true,true>> size mismatch");
static_assert(sizeof(C_NumberWrapper<NumberWrapperPolicy::LowerBounded<
                  0, float, std::false_type, std::true_type,
                  std::true_type>>) == 0x04,
              "C_NumberWrapper<LowerBounded> size mismatch");

}  // namespace wh::framework
