#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "../../rttr/type.h"
#include "../S_TypeConstraint.h"
#include "../S_TypeConversion.h"
#include "E_TypeClass.h"
#include "S_Enumeration.h"

namespace wh::conceptmodule::definition {

class C_TypeDefinition {
public:
    struct S_TemplateType;

    RTTR_ENABLE()                                             // [0..2]

    std::vector<S_TemplateType> GetTemplateTypes() const;     // 0x182627C30
    void SetTemplateTypes(std::vector<S_TemplateType> value); // 0x182627724, consumes value only

    rttr::type m_type;                                        // +0x08 RTTR "Type"
    CryStringT<char> m_typeName;                              // +0x10 RTTR "TypeName"
    E_TypeClass m_typeClass;                                  // +0x18 RTTR "TypeClass"
    bool m_isEditable;                                        // +0x1C RTTR "IsEditable"
    std::uint8_t m_unknown1D[3];                              // +0x1D
    std::vector<S_TypeConstraint> m_constraints;              // +0x20 RTTR "Constraints"
    std::vector<S_TypeConversion> m_conversions;              // +0x38 RTTR "Conversions"
    std::vector<S_Enumeration> m_enums;                        // +0x50 RTTR "Enums"
};

static_assert(offsetof(C_TypeDefinition, m_type) == 0x08,
              "C_TypeDefinition::m_type offset mismatch");
static_assert(offsetof(C_TypeDefinition, m_typeName) == 0x10,
              "C_TypeDefinition::m_typeName offset mismatch");
static_assert(offsetof(C_TypeDefinition, m_typeClass) == 0x18,
              "C_TypeDefinition::m_typeClass offset mismatch");
static_assert(offsetof(C_TypeDefinition, m_constraints) == 0x20,
              "C_TypeDefinition::m_constraints offset mismatch");
static_assert(offsetof(C_TypeDefinition, m_conversions) == 0x38,
              "C_TypeDefinition::m_conversions offset mismatch");
static_assert(offsetof(C_TypeDefinition, m_enums) == 0x50,
              "C_TypeDefinition::m_enums offset mismatch");
static_assert(sizeof(C_TypeDefinition) == 0x68,
              "C_TypeDefinition size mismatch");

}  // namespace wh::conceptmodule::definition
