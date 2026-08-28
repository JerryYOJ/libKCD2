#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_SequenceType : std::uint8_t {
    Default                = 0,
    Skillcheck             = 1,
    CharacterCreation      = 2,
    Punishment             = 3,
    Bribe                  = 4,
    Trigger                = 5,
    Wash                   = 6,
    Return                 = 7,
    Bathmaid               = 8,
    Shop                   = 9,
    RepairShop             = 10,
    Trainer                = 12,
    FastTravel             = 16,
    ShopDenied             = 13,
    RepairShopDenied       = 14,
    Sleepover              = 15,
    QuestGiver             = 17,
    Tournament             = 25,
    DrinkingEasy           = 26,
    DrinkingMedium         = 27,
    DrinkingHard           = 28,
    Payment                = 29,
    PaymentPlumb           = 30,
    PaymentSilver          = 31,
    PaymentGold            = 32,
    DiceGame               = 33,
    PaymentPlumbBet        = 34,
    PaymentSilverBet       = 35,
    PaymentGoldBet         = 36,
    OpenShop               = 37,
    OpenRepairShop         = 38,
    Romance                = 43,
    PaymentBarber          = 44,
    DLC0                   = 45,
    DLC1_BrushesWithDeath  = 46,
    DLC2_LegacyOfTheForge  = 47,
    DLC3_MysteriaEcclesiae = 48,
    ShieldPainter          = 49,
    DLC2_smithing          = 50,
    DLC2_dice              = 51,
    DLC2_acquiringPackages = 52,
    DLC2_archery           = 53,
    DLC2_donations         = 54,
    DLC2_duels             = 55,
    DLC2_stealingPackages  = 56,
};
static_assert(sizeof(E_SequenceType) == 1, "E_SequenceType size mismatch");

}  // namespace wh::dialogmodule::data
