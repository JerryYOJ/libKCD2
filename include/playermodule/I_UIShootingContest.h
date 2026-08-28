#pragma once
#include <cstddef>
#include <cstdint>
#include "CryEngine/CryCommon/CryString.h"

namespace wh::playermodule {

class I_UIShootingContest {
public:
    virtual ~I_UIShootingContest();
    virtual void HideShootingContestTable() = 0; // [1]
    virtual void UpdateShootingContestTable(
        std::int32_t value0, std::int32_t value1,
        std::int32_t value2, std::int32_t value3,
        std::int32_t value4, std::int32_t value5) = 0; // [2]
    virtual void ShowShootingHit(float x, float y) = 0; // [3]
    virtual void ShowHorseShootingContestTable(
        CryStringT<char> const& name,
        CryStringT<char> const& horse,
        std::int32_t value, std::int32_t state,
        CryStringT<char> const& score) = 0; // [4]
    virtual void HideHorseShootingContestTable() = 0; // [5]
    virtual void UpdateHorseShootingContestTable(std::int32_t value) = 0; // [6]
};

static_assert(sizeof(I_UIShootingContest) == 0x08,
              "I_UIShootingContest size mismatch");

}  // namespace wh::playermodule
