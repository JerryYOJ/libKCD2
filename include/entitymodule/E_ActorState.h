#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_ActorState {
    enum Type : std::uint8_t {
        idle                 = 0,
        jump                 = 1,
        ledge                = 2,
        ladder               = 3,
        minigame             = 4,
        itemInteraction      = 5,
        dogInteraction       = 6,
        shooting             = 7,
        ragdoll              = 8,
        unconscious          = 9,
        hit                  = 10,
        carryCorpse          = 11,
        carried              = 12,
        carryItem            = 13,
        stoneThrowing        = 14,
        battleArcheryPlayer  = 15,
        battleArcheryNpc     = 16,
        blacksmithing        = 17,
        fall                 = 18,
        land                 = 19,
        standingUp           = 20,
        dying                = 21,
        dead                 = 22,
        trackview            = 23,
        holdingDecoy         = 24,
        combat               = 25,
        follow               = 26,
        cart                 = 27,
        sprinting            = 28,
        inAir                = 29,
        interactiveScene     = 30,
        dialogue             = 31,
        skipTime             = 32,
        fastTravel           = 33,
        cutscene             = 34,
        tenseCircumstance    = 35,
        crouch               = 36,
        horse                = 37,
        onBed                = 38,
        actorAnim            = 39,
        butchering           = 40,
        reading              = 41,
        readingFromInventory = 42,
        rear                 = 43,
        none                 = 44,
    };
};
static_assert(sizeof(E_ActorState::Type) == 1, "E_ActorState::Type size mismatch");

}  // namespace wh::entitymodule
