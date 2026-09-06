#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../C_Resource.h"
#include "../definition/E_TypeClass.h"
#include "../definition/S_Enumeration.h"

namespace wh::conceptmodule::runtime {

class C_RuntimeType : public C_Resource {
public:
    C_RuntimeType();                                         // 0x181068ADC
    ~C_RuntimeType() override;                               // [0] 0x180928B30
    void OnBeforeSerialization() override; // [1] nullsub
    void OnAfterSerialization() override; // [2] nullsub
    void OnBeforeDeserialization() override; // [3] nullsub
    void OnAfterDeserialization() override; // [4] 0x181120540 registers the type name
    RTTR_ENABLE(C_Resource)                                  // [5..7]

    CryStringT<char> m_typeName;                             // +0x08 RTTR "TypeName"
    definition::E_TypeClass m_typeClass;                     // +0x10 RTTR "TypeClass"
    std::uint8_t _pad14[4]; // +0x14
    std::vector<definition::S_Enumeration> m_enums;          // +0x18 RTTR "Enums"
};

static_assert(offsetof(C_RuntimeType, m_typeName) == 0x08,
              "C_RuntimeType::m_typeName offset mismatch");
static_assert(offsetof(C_RuntimeType, m_typeClass) == 0x10,
              "C_RuntimeType::m_typeClass offset mismatch");
static_assert(offsetof(C_RuntimeType, m_enums) == 0x18,
              "C_RuntimeType::m_enums offset mismatch");
static_assert(sizeof(C_RuntimeType) == 0x30,
              "C_RuntimeType size mismatch");

}  // namespace wh::conceptmodule::runtime
