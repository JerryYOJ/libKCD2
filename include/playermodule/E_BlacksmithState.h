#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_BlacksmithState {
    enum Type : std::uint8_t {
        None                  = 0,
        RecipeSelection       = 1,
        RecipeSelected        = 2,
        RecipeNotSelected     = 3,
        GrabWorkpiece         = 4,
        TransitionToForge     = 5,
        TransitionToAnvil     = 6,
        TransitionToHardening = 7,
        ForgeIdle             = 8,
        ForgeInspection       = 9,
        StopForgeInspection   = 10,
        AnvilIdle             = 11,
        FlippingWorkpiece     = 12,
        FlippingWorkpieceBack = 13,
        StrokeStart           = 14,
        StrokeHit             = 15,
        StrokeFinish          = 16,
        PerfectStroke         = 17,
        BrokenWorkpiece       = 18,
        FinishedReturnHammer  = 19,
        FinishedIdle          = 20,
        Finished              = 21,
        Ended                 = 22,
    };
};
static_assert(sizeof(E_BlacksmithState::Type) == 1, "E_BlacksmithState::Type size mismatch");

}  // namespace wh::playermodule
