#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::E_DogObjective::Type
// (KCD2 WHGame.dll 1.5.6). Underlying uint8_t. 26 values 0..0x19.
// -----------------------------------------------
// Nested Type of struct E_DogObjective (RTTR "E_DogObjective", wrapper count $0BK = 26).
// String parser 0x18330327C (name -> byte). GetType is C_DogObjective slot [17]
// (vf+0x88); pack registrar 0x1809F5F2C inserts GetType() -> this* into the pack map.

namespace wh::xgenaimodule::activitysystem {

struct E_DogObjective {
    enum Type : uint8_t {
        Wait        = 0,
        Mark        = 1,
        Bark        = 2,
        Dig         = 3,
        Follow      = 4,
        FollowHeel  = 5,
        FollowRider = 6,
        Search      = 7,
        MeleeCombat = 8,
        Fetch       = 9,
        Hunt        = 10,
        Runaway     = 11,
        Alarm       = 12,
        Fail        = 13,
        Move        = 14,
        FunMove     = 15,
        FunOnSo     = 16,
        FunOnPoint  = 17,
        Chase       = 18,
        Eat         = 19,
        ShakeOut    = 20,
        Distract    = 21,
        Pet         = 22,
        SearchItem  = 23,
        Teleport    = 24,
        Invalid     = 25,
    };
};

}  // namespace wh::xgenaimodule::activitysystem
