#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::combatmodule::E_CombatGuardType -- KCD2 1.5.6 (kd7u).  4-byte enum.
// -----------------------------------------------
// combat_guard_type row id. Same table-id recipe as E_CombatInputClass: the DLL
// registers name→id resolvers (e.g. "main" → dword_185320CD4); numeric values
// come from Libs/Tables/combat/combat_guard_type.xml. Id 3 is unused.

namespace wh::combatmodule {

enum class E_CombatGuardType : int32_t {
    None                       = -1,  // "none"
    Main                       = 0,   // "main"
    PreBlock                   = 1,   // "preBlock"
    AttackReady                = 2,   // "attackReady"
    Clinch                     = 4,   // "clinch"
    StealthStand               = 5,   // "stealthStand"
    StealthSitting             = 6,   // "stealthSitting"
    StealthSittingGround       = 7,   // "stealthSittingGround"
    StealthLyingBenchLeft      = 8,   // "stealthLyingBenchLeft"
    StealthLyingBenchRight     = 9,   // "stealthLyingBenchRight"
    StealthLyingGroundLeft     = 10,  // "stealthLyingGroundLeft"
    StealthLyingGroundRight    = 11,  // "stealthLyingGroundRight"
    StealthGrab                = 12,  // "stealthGrab"
    CarryCorpse                = 13,  // "carryCorpse"
    KnockedOut                 = 14,  // "knockedOut"
    EndCombatMode              = 15,  // "endCombatMode"
    FreeBlock                  = 16,  // "freeBlock"
    Death                      = 17,  // "death"
    EndCombatModeCanContinue   = 18,  // "endCombatModeCanContinue"
    FreeBlockShieldUp          = 19,  // "freeBlockShieldUp"
    StealthLyingBedLeft        = 20,  // "stealthLyingBedLeft"
    StealthLyingBedRight       = 21,  // "stealthLyingBedRight"
    StealthKneelingChest       = 22,  // "stealthKneelingChest"
    FreeGuard                  = 23,  // "freeGuard"
    Clinch1                    = 24,  // "clinch1"
    Clinch2                    = 25,  // "clinch2"
    AnyGuard                   = 26,  // "anyGuard"
    StealthSittingTable        = 27,  // "stealthSittingTable"
};

}  // namespace wh::combatmodule
