#pragma once
#include <cstddef>
#include "C_ModuleBase.h"

namespace wh::conceptmodule {

class C_Level : public C_ModuleBase {
public:
    C_Level();                                               // default RTTR construction path 0x18008DF10
    RTTR_ENABLE(C_ModuleBase)                                // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x180EF6C58
    void GetPortDefinitions(
        definition::PortDefinitionSink sink,
        bool includeAll) override;                           // [28] 0x18138818C
    void OnLifecycleEvent(std::int32_t event) override;      // [34] 0x1819575C0
    std::int32_t MapEventToPhase(std::int32_t event) override; // [35] 0x18184687C
    E_HibernateMode::Type GetHibernateMode() const override; // [43] Auto
    std::uint8_t GetModuleKind() const override;             // [44] kind 1
    bool GetVoiceNamespace() const override;                 // [45] 0x1817951D8, defaults true
    void* ResolveScope() override;                           // [47] 0x180A6D628, resolves LevelHolder context
    bool HasScope() override;                                // [48] 0x180A6D46C
    bool IsScopeActive(void* host) override;                 // [49] 0x180A6BF20
};

static_assert(sizeof(C_Level) == 0xA0,
              "C_Level size mismatch");

}  // namespace wh::conceptmodule
