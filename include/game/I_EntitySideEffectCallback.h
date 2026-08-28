#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::game::I_EntitySideEffectCallback -- KCD2 WHGame.dll 1.5.6.
// -----------------------------------------------
// Two real notification slots and no virtual destructor. The dispatcher passes
// the side-effect ID in RDX and the affected entity WUID in R8. C_SkirmishManager
// consumes both; C_RecognizingThresholdManager independently consumes the R8
// WUID in 0x1808ACF2C/0x1808AC6F4.

namespace wh::game {

class I_EntitySideEffectCallback {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_EntitySideEffectCallback;
    virtual void OnEntitySideEffectAdded(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) = 0;                       // [0]
    virtual void OnEntitySideEffectRemoved(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) = 0;                       // [1]
};

static_assert(sizeof(I_EntitySideEffectCallback) == 0x08,
              "I_EntitySideEffectCallback size mismatch");

} // namespace wh::game
