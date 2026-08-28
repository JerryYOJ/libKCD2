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
    bool unk_07(void* context) override;                        // [7]
    bool unk_08(const void* value) const override;              // [8]
    bool unk_12(
        void* context,
        std::uint32_t value,
        bool flag) override;                                   // [12]
    bool unk_15(void* context) override;                        // [15]
    bool unk_16(void* context) override;                        // [16]
    bool unk_18(void* context) override;                        // [18]
    bool unk_19(void* context) override;                        // [19]
    bool unk_22(void* context, bool flag) override;             // [22]
    bool unk_25(void* context) override;                        // [25]
    bool unk_26(void* context) override;                        // [26]
    bool unk_27(void* context) override;                        // [27]
    bool unk_31() override;                                    // [31]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]

    float m_runtimeValue;                                      // +0x20
    std::uint8_t m_padding24[4];                              // +0x24
};

static_assert(sizeof(C_PlayerTurnDiceGameState) == 0x28,
              "C_PlayerTurnDiceGameState size mismatch");
static_assert(offsetof(C_PlayerTurnDiceGameState, m_runtimeValue) == 0x20,
              "C_PlayerTurnDiceGameState value offset mismatch");

} // namespace wh::playermodule
