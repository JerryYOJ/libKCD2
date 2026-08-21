#pragma once
#include <cstdint>

namespace wh::rpgmodule::E_CombatShoutType {

// Converter spellings from KCD2 1.5.6. "Recieved" is the game's spelling.
enum Type : std::int32_t {
    invalid                         = 0,
    skirmishShout                   = 1,
    actorScreamAttack               = 2,
    victimScreamReceivedHit         = 3,
    victimScreamMissedAttack        = 4,
    actorScreamClinch               = 5,
    actorScreamNoStaminaAttack      = 6,
    actorScreamNoSpaceAttack        = 7,
    actorScreamTackleAttack         = 8,
    actorScreamRecievedTackleHit    = 9,
    victimScreamStealthClinchIdle   = 10,
    victimScreamStealthSuccessHit   = 11,
    victimScreamStealthPerfectBlock = 12,
    victimScreamStealthHit          = 13,
};

}  // namespace wh::rpgmodule::E_CombatShoutType
