#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_StateProxy.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../questmodule/S_Tracker.h"

namespace wh::entitymodule {

class C_CarryItemPile;
using C_CarryItemTargetBase =
    wh::conceptmodule::C_StateProxy<wh::conceptmodule::C_Effect>;

class C_CarryItemTarget : public C_CarryItemTargetBase {
public:
    C_CarryItemTarget();                                               // 0x1810D5924
    ~C_CarryItemTarget() override;                                     // [0] 0x1816E4158
    RTTR_ENABLE(C_CarryItemTargetBase)                                 // [5..7], vtable 0x183B069A8
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x1816E89B8
    void OnEffectActivate() override;                                 // [43] 0x180D7AF44
    void OnEffectDeactivate() override;                               // [44] 0x180D7A794

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_CarryItemPile*>> m_ciPiles;                      // +0x90 RTTR "CIPiles"
    std::vector<C_CarryItemPile*> m_resolvedPiles;                     // +0xD0 activation-time source set
    wh::conceptmodule::C_TypedPortRef<
        wh::questmodule::S_Tracker> m_depositTracker;                  // +0xE8 RTTR "DepositTracker"
    wh::questmodule::S_Tracker m_tracker;                              // +0x128 current deposited / total capacity
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onFilled;                      // +0x138 RTTR "OnFilled"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onItemDeposited;               // +0x178 RTTR "OnItemDeposited"
    std::uint32_t m_filledPileCount;                                  // +0x1B8
    std::uint32_t m_padding1BC;                                       // +0x1BC
};

static_assert(offsetof(C_CarryItemTarget, m_ciPiles) == 0x90,
              "C_CarryItemTarget::m_ciPiles offset mismatch");
static_assert(offsetof(C_CarryItemTarget, m_resolvedPiles) == 0xD0,
              "C_CarryItemTarget::m_resolvedPiles offset mismatch");
static_assert(offsetof(C_CarryItemTarget, m_depositTracker) == 0xE8,
              "C_CarryItemTarget::m_depositTracker offset mismatch");
static_assert(offsetof(C_CarryItemTarget, m_tracker) == 0x128,
              "C_CarryItemTarget::m_tracker offset mismatch");
static_assert(offsetof(C_CarryItemTarget, m_onFilled) == 0x138,
              "C_CarryItemTarget::m_onFilled offset mismatch");
static_assert(offsetof(C_CarryItemTarget, m_onItemDeposited) == 0x178,
              "C_CarryItemTarget::m_onItemDeposited offset mismatch");
static_assert(offsetof(C_CarryItemTarget, m_filledPileCount) == 0x1B8,
              "C_CarryItemTarget::m_filledPileCount offset mismatch");
static_assert(sizeof(C_CarryItemTarget) == 0x1C0,
              "C_CarryItemTarget size mismatch");

} // namespace wh::entitymodule
