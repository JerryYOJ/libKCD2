#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_CombatTutorialFeature {
    enum Type : std::uint8_t {
        PlayerBlock                                 = 0,
        PlayerPerfectBlock                          = 1,
        PlayerDodge                                 = 2,
        PlayerHeavyAttack                           = 3,
        PlayerSpecialAttack                         = 4,
        PlayerRiposte                               = 5,
        PlayerMovement                              = 6,
        PlayerClinchGuard                           = 7,
        PlayerClinchAction                          = 8,
        PlayerDrawHolsterWeapon                     = 9,
        PlayerCombatZoneUp                          = 10,
        PlayerCombatZoneDown                        = 11,
        PlayerCombatZoneLeft                        = 12,
        PlayerCombatZoneRight                       = 13,
        TutorCombatMove                             = 14,
        TutorFightState                             = 15,
        TutorAttackAutomation                       = 16,
        TutorDefenseAutomation                      = 17,
        TutorGuardAutomation                        = 18,
        TutorWeaponAutomation                       = 19,
        TutorZoneAutomation                         = 20,
        TutorClinchAutoBackoff                      = 21,
        TutorDefenseForceNoBlock                    = 22,
        TutorDefenseForceNormalBlock                = 23,
        TutorDefenseForcePerfectBlock               = 24,
        TutorDefenseForcePerfectBlockOnOpposingZone = 25,
        TutorDefenseForceMasterStrike               = 26,
        TutorComboForceNoCombo                      = 27,
        TutorComboForceNaturalCombo                 = 28,
        TutorComboForceCombo                        = 29,
        TutorSlowAttackRate                         = 30,
        TutorCombatZoneUp                           = 31,
        TutorCombatZoneDown                         = 32,
        TutorCombatZoneLeft                         = 33,
        TutorCombatZoneRight                        = 34,
        CombatUiRosetta                             = 35,
        AllCombos                                   = 36,
    };
};
static_assert(sizeof(E_CombatTutorialFeature::Type) == 1, "E_CombatTutorialFeature::Type size mismatch");

}  // namespace wh::combatmodule
