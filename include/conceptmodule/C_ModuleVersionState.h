#pragma once
#include <cstddef>
#include <cstdint>
#include "C_StateBase.h"
#include "C_TypedPortRef.h"
#include "framework/E_GameReleaseVersion.h"

namespace wh::conceptmodule {

class C_ModuleVersionState
    : public C_StateBase<wh::framework::E_GameReleaseVersion::Type> {
public:
    C_ModuleVersionState();                                  // 0x1812EE8A0
    ~C_ModuleVersionState() override;                        // [0] 0x18268DDE4
    RTTR_ENABLE(C_StateBase<wh::framework::E_GameReleaseVersion::Type>) // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x1818440AC
    void OnLifecycleEvent(std::int32_t event) override;      // [34] 0x1818371E8
    std::int32_t MapEventToPhase(std::int32_t event) override; // [35] 0x1819A9F98

    C_TypedPortRef<wh::framework::E_GameReleaseVersion::Type>
        m_version;                                          // +0x50 RTTR "Version", Out
};

static_assert(offsetof(C_ModuleVersionState, m_version) == 0x50,
              "C_ModuleVersionState::m_version offset mismatch");
static_assert(sizeof(C_ModuleVersionState) == 0x90,
              "C_ModuleVersionState size mismatch");

}  // namespace wh::conceptmodule
