#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_SkirmishListener.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class I_SkirmishHandle;
class I_SkirmishHandleProvider;

class C_AreInSameSkirmish
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public I_SkirmishListener {
public:
    C_AreInSameSkirmish();
    ~C_AreInSameSkirmish() override;                              // primary [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // primary [27]
    void OnEffectActivate() override;                             // primary [43]
    void OnEffectDeactivate() override;                           // primary [44]

    void OnSkirmishStarted(
        I_SkirmishHandleProvider* skirmish,
        std::uint32_t matchFlag) override;                        // secondary [1]
    void OnSkirmishEnded() override;                              // secondary [2]

    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul1;          // +0xB8
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul2;          // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_skirmishStarted;          // +0x138
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_skirmishEnded;            // +0x178
    I_Soul* m_resolvedSoul1;                                     // +0x1B8
    I_Soul* m_resolvedSoul2;                                     // +0x1C0
    bool m_listenerRegistered;                                  // +0x1C8
    std::uint8_t m_padding1C9[7];                               // +0x1C9
    I_SkirmishHandle* m_skirmishHandle;                          // +0x1D0
};

static_assert(sizeof(C_AreInSameSkirmish) == 0x1D8,
              "C_AreInSameSkirmish size mismatch");
static_assert(offsetof(C_AreInSameSkirmish, m_soul1) == 0xB8,
              "C_AreInSameSkirmish Soul1 offset mismatch");
static_assert(offsetof(C_AreInSameSkirmish, m_skirmishStarted) == 0x138,
              "C_AreInSameSkirmish started output offset mismatch");
static_assert(offsetof(C_AreInSameSkirmish, m_resolvedSoul1) == 0x1B8,
              "C_AreInSameSkirmish resolved Soul1 offset mismatch");
static_assert(offsetof(C_AreInSameSkirmish, m_skirmishHandle) == 0x1D0,
              "C_AreInSameSkirmish handle offset mismatch");

} // namespace wh::rpgmodule
