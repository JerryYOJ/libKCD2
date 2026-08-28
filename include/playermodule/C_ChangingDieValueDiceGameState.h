#pragma once
#include <cstddef>
#include <cstdint>
#include "I_DiceGameModelState.h"

namespace wh::playermodule {

class C_ChangingDieValueDiceGameState : public I_DiceGameModelState {
public:
    explicit C_ChangingDieValueDiceGameState(C_DiceGameModel* model);
    ~C_ChangingDieValueDiceGameState() override;                // [0]
    const char* GetStateName() const override;                  // [1]
    void unk_05(void* context) override;                        // [5]
    bool unk_07(void* context) override;                        // [7]
    bool unk_43() override;                                    // [43]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]

    std::uint8_t m_runtime20[8];                               // +0x20
};

static_assert(sizeof(C_ChangingDieValueDiceGameState) == 0x28,
              "C_ChangingDieValueDiceGameState size mismatch");
static_assert(offsetof(C_ChangingDieValueDiceGameState, m_runtime20) == 0x20,
              "C_ChangingDieValueDiceGameState tail offset mismatch");

} // namespace wh::playermodule
