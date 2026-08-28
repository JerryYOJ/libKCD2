#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "S_BaseExampleNode.h"

namespace wh::framework {

class C_PolymorphicSharedPointers {
public:
    virtual ~C_PolymorphicSharedPointers();                 // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::shared_ptr<S_BaseExampleNode> m_sharedPtr;         // +0x08 RTTR "SharedPtr"
    std::shared_ptr<S_BaseExampleNode> m_sharedPtrEmpty;    // +0x18 RTTR "SharedPtrEmpty"
    std::shared_ptr<S_BaseExampleNode> m_sharedPtrWithDerivedInstance; // +0x28 RTTR "SharedPtrWithDerivedInstance"
    std::vector<std::shared_ptr<S_BaseExampleNode>> m_sharedPtrVector; // +0x38 RTTR "SharedPtrVector"
};

static_assert(offsetof(C_PolymorphicSharedPointers, m_sharedPtr) == 0x08,
              "C_PolymorphicSharedPointers::m_sharedPtr offset mismatch");
static_assert(offsetof(C_PolymorphicSharedPointers, m_sharedPtrVector) == 0x38,
              "C_PolymorphicSharedPointers::m_sharedPtrVector offset mismatch");
static_assert(sizeof(C_PolymorphicSharedPointers) == 0x50,
              "C_PolymorphicSharedPointers size mismatch");

}  // namespace wh::framework
