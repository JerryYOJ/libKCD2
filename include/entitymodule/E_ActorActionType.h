#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_ActorActionType -- string table sub_180855C38.
// -----------------------------------------------
// I_Action::GetActionTypeId. Rider returns 1.

namespace wh::entitymodule {

struct E_ActorActionType {
    enum Type : int32_t {
        idle = 0,
        rider = 1,
        riderAnim = 2,
        riderIdle = 3,
        horseAnim = 4,
        cryanim = 5,
        transitionToCombat = 6,
        fall = 7,
        ragdoll = 8,
        jump = 9,
        land = 10,
        standup = 11,
        combat = 12,
        hit = 13,
        unconscious = 14,
        dead = 15,
        ai = 16,
        dogAnimAction = 17,
        dogSynchroAnimAction = 18,
        animSlave = 19,
        wiggleAction = 20,
        globalTagAction = 21,
        trackview = 22,
        minigame = 23,
        actorAnimAction = 24,
        actorAdditiveAnimAction = 25,
        crouch = 26,
        shooting = 27,
        ledge = 28,
        carryItem = 29,
        follow = 30,
        horseInCart = 31,
        cart = 32,
        cartAnim = 33,
        ladder = 34,
        carryCorpse = 35,
        carried = 36,
        interactiveScene = 37,
        skipTime = 38,
        fastTravel = 39,
        tenseCircumstance = 40,
        mount = 41,
        mountSlave = 42,
        dismount = 43,
        dismountSlave = 44,
        syncAnimMaster = 45,
        syncAnimSlave = 46,
        riderSyncAnimMaster = 47,
        dogSyncAnimMaster = 48,
        horseSyncAnimSlave = 49,
        dropItem = 50,
        pickUpItem = 51,
        placeItem = 52,
        drawWeapons = 53,
        holsterWeapons = 54,
        swapWeapons = 55,
        butchering = 56,
    };
};

}  // namespace wh::entitymodule
