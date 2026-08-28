#pragma once
#include <cstddef>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "S_BaseExampleNode.h"

namespace wh::framework {

class C_PolymorphicRawPointers {
public:
    virtual ~C_PolymorphicRawPointers();                    // [0]
    RTTR_ENABLE()                                           // [1..3]

    S_BaseExampleNode* m_rawPtr;                            // +0x08 RTTR "RawPtr"
    S_BaseExampleNode* m_rawPtrNull;                        // +0x10 RTTR "RawPtrNull"
    S_BaseExampleNode* m_rawPtrWithDerivedInstance;         // +0x18 RTTR "RawPtrWithDerivedInstance"
    std::vector<S_BaseExampleNode*> m_rawPtrVector;         // +0x20 RTTR "RawPtrVector"
};

static_assert(offsetof(C_PolymorphicRawPointers, m_rawPtr) == 0x08,
              "C_PolymorphicRawPointers::m_rawPtr offset mismatch");
static_assert(offsetof(C_PolymorphicRawPointers, m_rawPtrVector) == 0x20,
              "C_PolymorphicRawPointers::m_rawPtrVector offset mismatch");
static_assert(sizeof(C_PolymorphicRawPointers) == 0x38,
              "C_PolymorphicRawPointers size mismatch");

}  // namespace wh::framework
