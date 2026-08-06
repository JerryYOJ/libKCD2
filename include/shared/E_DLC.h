#pragma once
#include <cstdint>

// wh::shared::E_DLC -- content package identifier.
// Values are from RTTR registration 0x18005DD90.

namespace wh::shared {

struct E_DLC {
    enum Type : uint8_t {
        Invalid              = 0,
        QuestForValor        = 1,
        Barber               = 2,
        HorseRacing          = 3,
        HardcoreMode         = 4,
        ForgeTycoon          = 5,
        TouristMode          = 6,
        MysteriaEcclesiae    = 7,
        Unpublished          = 8,
        BanditCamps          = 9,
        SeasonPassShields    = 10,
        GoldEditionHuntsman  = 11,
        Last                 = 12,
    };
};

}  // namespace wh::shared
