#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IEntity.h"

// Current callback table has no virtual destructor slot.
class SGameRulesListener {
public:
    virtual void GameOver(std::int32_t localWinner) = 0; // [0]
    virtual void EnteredGame() = 0;                      // [1]
    virtual void EndGameNear(EntityId id) = 0;           // [2]
};
static_assert(sizeof(SGameRulesListener) == 0x08,
              "SGameRulesListener must be vptr-only");
