#pragma once
#include <cstddef>
#include "../../rttr/property.h"
#include "../../rttr/rttr_enable.h"
#include "../I_PortDefinition.h"

namespace wh::conceptmodule::definition {

class C_CompileTimePortDefinition : public I_PortDefinition {
public:
    explicit C_CompileTimePortDefinition(
        rttr::property const& property);                       // 0x180C82738
    ~C_CompileTimePortDefinition() override;                  // [0] 0x180515DE0
    CryStringT<char> GetName() const override;                // [1] 0x1804F74A4
    std::int32_t GetValueOriginConstraint() const override;   // [2] 0x1806924A0
    E_PortDirection GetDirection() const override;            // [3] 0x1806999B4
    E_PortVisibility GetVisibility() const override;          // [4] 0x180C82914
    E_PortConnectionType GetConnectionType() const override;  // [5] 0x182627928
    rttr::type GetValueType() const override;                 // [6] 0x180692848
    E_TemplateTypename GetTemplate() const override;          // [7] 0x18069AAA0
    rttr::variant GetDefaultValue() const override;           // [8] 0x1806B1198
    bool IsHidden() const override;                            // [9] 0x182627DC0
    bool unk_10() const override;                              // [10] 0x181E2AE20
    bool IsVariadic() const override;                          // [11] 0x180D16160
    bool IsSequential() const override;                        // [12] 0x182627E88
    bool IsOptional() const override;                          // [13] 0x1806B1200
    bool unk_14() const override;                              // [14] 0x182627E24
    bool IsAutoTriggerable() const override;                   // [15] 0x180FB53C0
    bool IsTriggerableWhenHibernated() const override;         // [16] 0x182627EEC
    bool IsInterface() const override;                         // [17] 0x180C828FC
    std::vector<CryStringT<char>>
        GetLinkedTriggerPorts() const override;                // [18] 0x1826279D4
    std::vector<CryStringT<char>> unk_19() const override;     // [19] 0x181E2AC90
    std::shared_ptr<I_PortDefinition> unk_20() const override; // [20] 0x182627548
    RTTR_ENABLE(I_PortDefinition)                              // [21..23]

    rttr::property m_property;                                // +0x08 reflected property adapter
};

static_assert(offsetof(C_CompileTimePortDefinition, m_property) == 0x08,
              "C_CompileTimePortDefinition::m_property offset mismatch");
static_assert(sizeof(C_CompileTimePortDefinition) == 0x10,
              "C_CompileTimePortDefinition size mismatch");

}  // namespace wh::conceptmodule::definition
