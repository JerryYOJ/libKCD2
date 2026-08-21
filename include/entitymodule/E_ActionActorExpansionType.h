#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_ActionActorExpansionType
// -----------------------------------------------
// I_ActionActorExpansion[1] GetExpansionType return values.

namespace wh::entitymodule {

struct E_ActionActorExpansionType {
    enum Type : int32_t {
        Anims = 0,
        State = 1,
        Dog = 2,
        AnimsItemHandling = 3,
        Shooting = 4,
        Rider = 5,
        FacialAnims = 6,
    };
};

}  // namespace wh::entitymodule
