#pragma once
#include <boost/container/flat_map.hpp>
#include <cstddef>
#include <map>
#include <string>
#include <unordered_map>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class C_AssociativeContainersExample {
public:
    virtual ~C_AssociativeContainersExample();             // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::map<std::string, int> m_stdMapStringToInt;         // +0x08 RTTR "StdMapStringToInt"
    std::unordered_map<std::string, int> m_stdUnorderedMapStringToInt; // +0x18 RTTR "StdUnorderedMapStringToInt"
    boost::container::flat_map<std::string, int> m_boostFlatMapStringToInt; // +0x58 RTTR "BoostFlatMapStringToInt"
};

static_assert(offsetof(C_AssociativeContainersExample, m_stdMapStringToInt) == 0x08,
              "C_AssociativeContainersExample::m_stdMapStringToInt offset mismatch");
static_assert(offsetof(C_AssociativeContainersExample, m_stdUnorderedMapStringToInt) == 0x18,
              "C_AssociativeContainersExample::m_stdUnorderedMapStringToInt offset mismatch");
static_assert(offsetof(C_AssociativeContainersExample, m_boostFlatMapStringToInt) == 0x58,
              "C_AssociativeContainersExample::m_boostFlatMapStringToInt offset mismatch");
static_assert(sizeof(C_AssociativeContainersExample) == 0x70,
              "C_AssociativeContainersExample size mismatch");

}  // namespace wh::framework
