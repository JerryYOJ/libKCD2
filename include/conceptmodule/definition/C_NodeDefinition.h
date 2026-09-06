#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../C_BaseAsset.h"
#include "../C_Node.h"
#include "I_NodeDefinition_S_PropertyDef.h"

namespace wh::conceptmodule::definition {

class C_NodeDefinition : public I_NodeDefinition {
public:
    explicit C_NodeDefinition(_smart_ptr<C_Node> node);       // 0x180691704
    ~C_NodeDefinition() override;                             // [0] 0x182627354
    void GetPortDefinitions(
        PortDefinitionSink sink, bool includeAll) override;   // [1] 0x182628108
    bool Validate() const override;                           // [2] 0x1826283F8
    std::shared_ptr<I_NodeDefinition> Clone() const override; // [3] 0x182627568
    CryStringT<char> const& GetName() const override;         // [4] 0x181A72EC0
    CryStringT<char> const& GetDescription() const override;  // [5] 0x181A72EB0
    CryStringT<char> const& GetCategory() const override;     // [6] 0x181A73160
    E_NodeStyle GetStyle() const override;                    // [7] 0x180836120
    bool SupportsAutoTrigger() const override;                // [8] 0x181A72E80
    bool AffectsGameSave() const override;                    // [9] 0x181AABEF0
    rttr::variant GetPropertyValue(
        CryStringT<char> const& name) const override;         // [10] 0x182627B30
    std::shared_ptr<C_BaseAsset> FindAsset(
        CryStringT<char> const& name) const override;         // [11] 0x18087CD94
    RTTR_ENABLE(I_NodeDefinition)                             // [12..14]

    std::vector<std::shared_ptr<I_PortDefinition>> GetPorts() const; // 0x182627AEC
    void SetPorts(std::vector<std::shared_ptr<I_PortDefinition>> value); // 0x18262771C
    CryStringT<char> GetTypeName() const;                     // 0x182627D88
    void SetTypeName(CryStringT<char> value);                 // 0x182627710

    _smart_ptr<C_Node> m_node;                                // +0x08
    CryStringT<char> m_name;                                  // +0x10 RTTR "Name"
    CryStringT<char> m_description;                           // +0x18 RTTR "Description"
    CryStringT<char> m_category;                              // +0x20 RTTR "Category"
    E_NodeStyle m_style;                                      // +0x28 RTTR "Style"
    std::uint8_t _pad2C[4]; // +0x2C
    std::vector<I_NodeDefinition::S_PropertyDef> m_properties; // +0x30 RTTR "Properties"
    std::vector<std::shared_ptr<C_BaseAsset>> m_assets;       // +0x48 RTTR "Assets"
    bool m_autoTriggerSupport;                                // +0x60 RTTR "AutoTriggerSupport"
    bool m_affectsGameSave;                                  // +0x61 RTTR "AffectsGameSave"
    std::uint8_t _pad62[6]; // +0x62
};

static_assert(offsetof(C_NodeDefinition, m_node) == 0x08,
              "C_NodeDefinition::m_node offset mismatch");
static_assert(offsetof(C_NodeDefinition, m_name) == 0x10,
              "C_NodeDefinition::m_name offset mismatch");
static_assert(offsetof(C_NodeDefinition, m_style) == 0x28,
              "C_NodeDefinition::m_style offset mismatch");
static_assert(offsetof(C_NodeDefinition, m_properties) == 0x30,
              "C_NodeDefinition::m_properties offset mismatch");
static_assert(offsetof(C_NodeDefinition, m_assets) == 0x48,
              "C_NodeDefinition::m_assets offset mismatch");
static_assert(offsetof(C_NodeDefinition, m_autoTriggerSupport) == 0x60,
              "C_NodeDefinition::m_autoTriggerSupport offset mismatch");
static_assert(sizeof(C_NodeDefinition) == 0x68,
              "C_NodeDefinition size mismatch");

}  // namespace wh::conceptmodule::definition
