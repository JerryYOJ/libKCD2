#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

struct E_ElementType {
    enum Type : std::uint8_t {
        Stance                = 0,
        LeftHand              = 1,
        RightHand             = 2,
        Unstance              = 3,
        ChangeEquipment       = 4,
        Minigame              = 5,
        MandatoryElementCount = 6,
        ChangeBehaviorState   = 7,
        AddLink               = 8,
        ChangeAreaLabel       = 9,
        ItemSetAside          = 10,
        EnableBehaviorForNPC  = 11,
        AddContext            = 12,
        EnableRoleOnHub       = 13,
        HorseUsage            = 14,
        AddMetarole           = 15,
        AddBuff               = 16,
        ItemsToReturn         = 17,
        OpenShop              = 18,
        CombatAutomations     = 19,
    };
};
static_assert(sizeof(E_ElementType::Type) == 1, "E_ElementType::Type size mismatch");

}  // namespace wh::xgenaimodule::NPCState
