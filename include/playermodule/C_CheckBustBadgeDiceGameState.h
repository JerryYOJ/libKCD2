#pragma once
#include <cstddef>
#include "I_DiceGameModelState.h"

namespace wh::playermodule {

class C_CheckBustBadgeDiceGameState : public I_DiceGameModelState {
public:
    explicit C_CheckBustBadgeDiceGameState(C_DiceGameModel* model);
    const char* GetStateName() const override;                  // [1]
    void OnEnter(I_DiceGameModelDelegate* delegate) override; // [5]
    bool AdvanceState(I_DiceGameModelDelegate* delegate) override; // [7]
    bool ContinueAfterBustProtection(I_DiceGameModelDelegate* delegate) override; // [14]
    bool Pass(I_DiceGameModelDelegate* delegate, bool fromBadge) override; // [22]
    bool ApplyBadgeEffect(I_DiceGameModelDelegate* delegate) override; // [27]
    bool IsCheckBustBadgeState() override; // [41]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]
};

static_assert(sizeof(C_CheckBustBadgeDiceGameState) == 0x20,
              "C_CheckBustBadgeDiceGameState size mismatch");

} // namespace wh::playermodule
