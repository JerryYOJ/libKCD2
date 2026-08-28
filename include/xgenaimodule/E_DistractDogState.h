#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::E_DistractDogState
// (KCD2 WHGame.dll 1.5.6). uint8_t. Nested-only RTTI (no standalone TypeDescriptor, no string
// parser, no RTTR name table) -- enumerator spellings below are INFERRED from control flow in
// C_DistractDogObjective plus RPG param names, not from a source name table.
// -----------------------------------------------

namespace wh::xgenaimodule::activitysystem {

struct E_DistractDogState {
    enum Type : uint8_t {
        Wait = 0,  // EnterWait: timer = DogDistractInitialWaitTime
        Bark = 1,  // EnterBark: timer = DogDistractBarkTime
        Flee = 2,  // EnterFlee: path radius = DogDistractFleeDistance
    };
};

}  // namespace wh::xgenaimodule::activitysystem
