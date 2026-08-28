#pragma once
#include <cstddef>
#include "../conceptmodule/C_StateBase.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_SaveGameBase.h"
#include "E_SaveGameWithNotificationState.h"

namespace wh::playermodule {

using C_SaveGameWithNotificationStateBase =
    wh::conceptmodule::C_StateBase<
        E_SaveGameWithNotificationState::Type>;

class C_SaveGameWithNotification
    : public C_SaveGameWithNotificationStateBase,
      public C_SaveGameBase {
public:
    C_SaveGameWithNotification();
    ~C_SaveGameWithNotification() override;                     // [0] 0x1813CDE3C
    RTTR_ENABLE(C_SaveGameWithNotificationStateBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0834
    void GetPortDefinitions(
        wh::conceptmodule::definition::PortDefinitionSink sink,
        bool includeAll) override;                              // [28] 0x18163A97C
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x182DDF168
    void OnLifecycleEvent(std::int32_t event) override;         // [34] 0x18172E514
    std::int32_t MapEventToPhase(std::int32_t event) override;  // [35] 0x1817FA460

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_resetState;             // +0x150
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDone;                 // +0x190
};

static_assert(sizeof(C_SaveGameWithNotification) == 0x1D0,
              "C_SaveGameWithNotification size mismatch");
static_assert(offsetof(C_SaveGameWithNotification, m_resetState) == 0x150,
              "C_SaveGameWithNotification reset offset mismatch");
static_assert(offsetof(C_SaveGameWithNotification, m_onDone) == 0x190,
              "C_SaveGameWithNotification done offset mismatch");

} // namespace wh::playermodule
