#pragma once
#include <cstddef>
#include "I_DiceGameModelState.h"

namespace wh::playermodule {

class C_BadgeDiceSelectingDiceGameState : public I_DiceGameModelState {
public:
    explicit C_BadgeDiceSelectingDiceGameState(C_DiceGameModel* model);
    const char* GetStateName() const override;                  // [1]
    bool AdvanceState(I_DiceGameModelDelegate* delegate) override; // [7]
    bool IsForPlayerModel(const C_DiceGamePlayerModel* model) const override; // [8]
    bool HoldDie(I_DiceGameModelDelegate* delegate, std::uint32_t dieId, bool hold) override; // [12]
    bool ApplyBadgeEffect(I_DiceGameModelDelegate* delegate) override; // [27]
    bool ExitBadgeEffect(I_DiceGameModelDelegate* delegate) override; // [28]
    bool IsBadgeDiceSelectingState() override; // [42]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]
};

static_assert(sizeof(C_BadgeDiceSelectingDiceGameState) == 0x20,
              "C_BadgeDiceSelectingDiceGameState size mismatch");

} // namespace wh::playermodule
