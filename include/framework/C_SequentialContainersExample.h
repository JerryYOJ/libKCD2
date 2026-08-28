#pragma once
#include <array>
#include <boost/optional.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "S_BaseExampleNode.h"

namespace wh::framework {

class C_SequentialContainersExample {
public:
    virtual ~C_SequentialContainersExample();              // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::array<int, 3> m_stdArrayOfInt;                     // +0x08 RTTR "StdArrayOfInt"
    std::uint8_t _pad14[4];                                 // +0x14
    std::vector<int> m_stdVectorOfInt;                      // +0x18 accessor backing "StdVectorOfInt"
    std::vector<S_BaseExampleNode> m_stdVectorOfNodes;      // +0x30 RTTR "StdVectorOfNodes"
    std::vector<boost::optional<int>> m_stdVectorOfBoostOptional; // +0x48 RTTR "StdVectorOfBoostOptional"
};

static_assert(offsetof(C_SequentialContainersExample, m_stdArrayOfInt) == 0x08,
              "C_SequentialContainersExample::m_stdArrayOfInt offset mismatch");
static_assert(offsetof(C_SequentialContainersExample, m_stdVectorOfInt) == 0x18,
              "C_SequentialContainersExample::m_stdVectorOfInt offset mismatch");
static_assert(offsetof(C_SequentialContainersExample, m_stdVectorOfNodes) == 0x30,
              "C_SequentialContainersExample::m_stdVectorOfNodes offset mismatch");
static_assert(sizeof(C_SequentialContainersExample) == 0x60,
              "C_SequentialContainersExample size mismatch");

}  // namespace wh::framework
