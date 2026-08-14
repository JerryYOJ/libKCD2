#pragma once
#include <cstddef>
#include "C_InteractionType.h"

// -----------------------------------------------
// wh::entitymodule::C_PlayerInteraction -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x50.
// -----------------------------------------------
// RTTI .?AVC_PlayerInteraction@entitymodule@wh@@; vtable 0x183A69D90, 22 slots.
// General player interaction strategy registered under interaction-type key 1 by
// C_PlayerInteractor; this is the strategy used by the herb/general usable path.

namespace wh::entitymodule {

class C_PlayerInteraction : public C_InteractionType {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PlayerInteraction;
    ~C_PlayerInteraction() override;                            // [0] sub_1809ECAB4
    void Initialize(C_Player* pPlayer) override;                // [1] sub_1816DBDE0
    bool IsEnabled() override;                                 // [3] sub_181A72470: true
    void RefreshInteractionBounds() override;                  // [4] sub_1816DBE5C
    float GetInteractionDistance() override;                   // [7] sub_18082CDBC

    float m_interactionDistance;           // +0x48  initialized from GetInteractionDistance()
    float m_maximumInteractionDistance;    // +0x4C  initialized to m_interactionDistance * 5.0f
};

static_assert(sizeof(C_PlayerInteraction) == 0x50, "C_PlayerInteraction must be 0x50");
static_assert(offsetof(C_PlayerInteraction, m_interactionDistance) == 0x48,
              "m_interactionDistance must be at 0x48");

}  // namespace wh::entitymodule
