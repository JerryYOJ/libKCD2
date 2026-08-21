#pragma once
#include <cstdint>

namespace wh::combatmodule::E_SignalSource {

enum Type : std::int32_t {
    This     = 0,
    Opponent = 1,
    Other    = 2,
};

}  // namespace wh::combatmodule::E_SignalSource
