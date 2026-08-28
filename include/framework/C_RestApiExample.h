#pragma once
#include <cstddef>
#include "C_AssociativeContainersExample.h"
#include "C_MethodsExample.h"
#include "C_PolymorphicRawPointers.h"
#include "C_PolymorphicSharedPointers.h"
#include "C_SequentialContainersExample.h"
#include "C_SimpleTypesExample.h"
#include "C_WrappersExample.h"
#include "I_RestApiExample.h"

namespace wh::framework {

class C_RestApiExample : public I_RestApiExample {
public:
    ~C_RestApiExample() override;                           // [0]
    RTTR_ENABLE(I_RestApiExample)                           // [1..3]

    C_SimpleTypesExample m_simpleTypes;                     // +0x08 RTTR "SimpleTypes"
    C_PolymorphicRawPointers m_polymorphicRawPointers;      // +0x70 RTTR "PolymorphicRawPoniters"
    C_PolymorphicSharedPointers m_polymorphicSharedPointers; // +0xA8 RTTR "PolymorphicSharedPoniters"
    C_WrappersExample m_wrappers;                           // +0xF8 RTTR "Wrappers"
    C_SequentialContainersExample m_sequentialContainers;   // +0x158 RTTR "SequentialContainers"
    C_AssociativeContainersExample m_associativeContainers; // +0x1B8 RTTR "AssociativeContainers"
    C_MethodsExample m_methods;                             // +0x228 RTTR "Methods"
};

static_assert(offsetof(C_RestApiExample, m_simpleTypes) == 0x08,
              "C_RestApiExample::m_simpleTypes offset mismatch");
static_assert(offsetof(C_RestApiExample, m_polymorphicRawPointers) == 0x70,
              "C_RestApiExample::m_polymorphicRawPointers offset mismatch");
static_assert(offsetof(C_RestApiExample, m_polymorphicSharedPointers) == 0xA8,
              "C_RestApiExample::m_polymorphicSharedPointers offset mismatch");
static_assert(offsetof(C_RestApiExample, m_wrappers) == 0xF8,
              "C_RestApiExample::m_wrappers offset mismatch");
static_assert(offsetof(C_RestApiExample, m_sequentialContainers) == 0x158,
              "C_RestApiExample::m_sequentialContainers offset mismatch");
static_assert(offsetof(C_RestApiExample, m_associativeContainers) == 0x1B8,
              "C_RestApiExample::m_associativeContainers offset mismatch");
static_assert(offsetof(C_RestApiExample, m_methods) == 0x228,
              "C_RestApiExample::m_methods offset mismatch");
static_assert(sizeof(C_RestApiExample) == 0x230,
              "C_RestApiExample size mismatch");

}  // namespace wh::framework
