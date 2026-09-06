#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../../rttr/rttr_enable.h"
#include "../I_PortDefinition.h"

namespace wh::conceptmodule::definition {

class C_RunTimePortDefinition : public I_PortDefinition {
public:
    enum E_Flag : std::uint8_t {
        Flag_Hidden                      = 1u << 0,
        Flag_Metadata5                   = 1u << 1,
        Flag_Optional                    = 1u << 2,
        Flag_Variadic                    = 1u << 3,
        Flag_Sequential                  = 1u << 4,
        Flag_Metadata6                   = 1u << 5,
        Flag_AutoTriggerable             = 1u << 6,
        Flag_TriggerableWhenHibernated   = 1u << 7,
    };

    C_RunTimePortDefinition();                               // 0x1804FABC0
    C_RunTimePortDefinition(C_RunTimePortDefinition const& other); // 0x1826264D8
    ~C_RunTimePortDefinition() override;                     // [0] 0x1826273F0
    CryStringT<char> GetName() const override;               // [1] 0x1804FCC68
    std::int32_t GetValueOriginConstraint() const override;  // [2] +0x10
    E_PortDirection GetDirection() const override;           // [3] +0x14
    E_PortVisibility GetVisibility() const override;         // [4] +0x18
    E_PortConnectionType GetConnectionType() const override; // [5] +0x1C
    rttr::type GetValueType() const override;                // [6] +0x20
    E_TemplateTypename GetTemplate() const override;         // [7] +0x58
    rttr::variant GetDefaultValue() const override;          // [8] +0x60
    bool IsHidden() const override;                           // [9] bit 0
    bool IsDeprecated() const override; // [10] bit 1
    bool IsVariadic() const override;                         // [11] bit 3
    bool IsSequential() const override;                       // [12] bit 4
    bool IsOptional() const override;                         // [13] bit 2
    bool IsInternal() const override; // [14] bit 5
    bool IsAutoTriggerable() const override;                  // [15] bit 6
    bool IsTriggerableWhenHibernated() const override;        // [16] bit 7
    bool IsInterface() const override;                        // [17] visibility Internal/External
    std::vector<CryStringT<char>>
        GetLinkedTriggerPorts() const override;               // [18] +0x28
    std::vector<CryStringT<char>> GetValueOriginConstraints() const override; // [19] +0x40
    std::shared_ptr<I_PortDefinition> GetRuntimeDefinition() const override; // [20] copied shared definition
    RTTR_ENABLE(I_PortDefinition)                             // [21..23]

    CryStringT<char> m_name;                                 // +0x08
    std::int32_t m_valueOriginConstraint;                    // +0x10
    E_PortDirection m_direction;                             // +0x14
    E_PortVisibility m_visibility;                           // +0x18
    E_PortConnectionType m_connectionType;                   // +0x1C
    rttr::type m_type;                                       // +0x20
    std::vector<CryStringT<char>> m_linkedTriggerPorts;      // +0x28
    std::vector<CryStringT<char>> m_valueOriginConstraints; // +0x40 metadata key 16
    E_TemplateTypename m_template;                           // +0x58
    std::uint8_t m_flags;                                    // +0x5C E_Flag
    std::uint8_t _pad5D[3]; // +0x5D
    rttr::variant m_defaultValue;                            // +0x60
};

static_assert(offsetof(C_RunTimePortDefinition, m_name) == 0x08,
              "C_RunTimePortDefinition::m_name offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_valueOriginConstraint) == 0x10,
              "C_RunTimePortDefinition::m_valueOriginConstraint offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_type) == 0x20,
              "C_RunTimePortDefinition::m_type offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_linkedTriggerPorts) == 0x28,
              "C_RunTimePortDefinition::m_linkedTriggerPorts offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_valueOriginConstraints) == 0x40,
              "C_RunTimePortDefinition::m_valueOriginConstraints offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_template) == 0x58,
              "C_RunTimePortDefinition::m_template offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_flags) == 0x5C,
              "C_RunTimePortDefinition::m_flags offset mismatch");
static_assert(offsetof(C_RunTimePortDefinition, m_defaultValue) == 0x60,
              "C_RunTimePortDefinition::m_defaultValue offset mismatch");
static_assert(sizeof(C_RunTimePortDefinition) == 0x78,
              "C_RunTimePortDefinition size mismatch");

}  // namespace wh::conceptmodule::definition
