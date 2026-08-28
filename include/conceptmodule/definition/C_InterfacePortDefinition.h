#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"
#include "../I_PortDefinition.h"

namespace wh::conceptmodule::definition {

class C_InterfacePortDefinition : public I_PortDefinition {
public:
    explicit C_InterfacePortDefinition(rttr::type const& type); // object construction in 0x1806A6010
    ~C_InterfacePortDefinition() override;                     // [0] 0x181009318
    CryStringT<char> GetName() const override;                 // [1] 0x181437814, empty
    std::int32_t GetValueOriginConstraint() const override;    // [2] zero
    E_PortDirection GetDirection() const override;             // [3] Bi
    E_PortVisibility GetVisibility() const override;           // [4] Interface
    E_PortConnectionType GetConnectionType() const override;   // [5] Any
    rttr::type GetValueType() const override;                  // [6] +0x08
    E_TemplateTypename GetTemplate() const override;           // [7] None
    rttr::variant GetDefaultValue() const override;            // [8] invalid
    bool IsHidden() const override;                             // [9] false
    bool unk_10() const override;                               // [10] false
    bool IsVariadic() const override;                           // [11] false
    bool IsSequential() const override;                         // [12] false
    bool IsOptional() const override;                           // [13] false
    bool unk_14() const override;                               // [14] false
    bool IsAutoTriggerable() const override;                    // [15] false
    bool IsTriggerableWhenHibernated() const override;          // [16] false
    bool IsInterface() const override;                          // [17] true
    std::vector<CryStringT<char>>
        GetLinkedTriggerPorts() const override;                 // [18] empty
    std::vector<CryStringT<char>> unk_19() const override;      // [19] empty
    std::shared_ptr<I_PortDefinition> unk_20() const override;  // [20] null
    RTTR_ENABLE(I_PortDefinition)                               // [21..23]

    rttr::type m_type;                                         // +0x08
};

static_assert(offsetof(C_InterfacePortDefinition, m_type) == 0x08,
              "C_InterfacePortDefinition::m_type offset mismatch");
static_assert(sizeof(C_InterfacePortDefinition) == 0x10,
              "C_InterfacePortDefinition size mismatch");

}  // namespace wh::conceptmodule::definition
