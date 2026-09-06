#pragma once
#include <cstddef>
#include <cstdint>
#include "I_DiceGameModelState.h"

namespace wh::playermodule {

class C_PlayerTurnDiceGameState : public I_DiceGameModelState {
public:
    explicit C_PlayerTurnDiceGameState(C_DiceGameModel* model);
    ~C_PlayerTurnDiceGameState() override;                      // [0]
    const char* GetStateName() const override;                  // [1]
    bool AdvanceState(I_DiceGameModelDelegate* delegate) override; // [7]
    bool IsForPlayerModel(const C_DiceGamePlayerModel* model) const override; // [8]
    bool HoldDie(I_DiceGameModelDelegate* delegate, std::uint32_t dieId, bool hold) override; // [12]
    bool UseExtraRollBadge(I_DiceGameModelDelegate* delegate) override; // [15]
    bool UseRerollBadge(I_DiceGameModelDelegate* delegate) override; // [16]
    bool CanScore(I_DiceGameModelDelegate* delegate, C_DiceGamePlayerModel* model) override; // [18]
    bool Score(I_DiceGameModelDelegate* delegate) override; // [19]
    bool Pass(I_DiceGameModelDelegate* delegate, bool fromBadge) override; // [22]
    bool unk_25(void* context) override;                        // [25]
    bool BeginBadgeDiceSelection(I_DiceGameModelDelegate* delegate) override; // [26]
    bool ApplyBadgeEffect(I_DiceGameModelDelegate* delegate) override; // [27]
    bool IsPlayerTurnState() override; // [31]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]

    float m_runtimeValue;                                      // +0x20
    std::uint8_t m_padding24[4];                              // +0x24
};

static_assert(sizeof(C_PlayerTurnDiceGameState) == 0x28,
              "C_PlayerTurnDiceGameState size mismatch");
static_assert(offsetof(C_PlayerTurnDiceGameState, m_runtimeValue) == 0x20,
              "C_PlayerTurnDiceGameState value offset mismatch");

} // namespace wh::playermodule
