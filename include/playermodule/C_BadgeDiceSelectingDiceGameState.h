#pragma once
#include <cstddef>
#include "I_DiceGameModelState.h"

namespace wh::playermodule {

class C_BadgeDiceSelectingDiceGameState : public I_DiceGameModelState {
public:
    explicit C_BadgeDiceSelectingDiceGameState(C_DiceGameModel* model);
    const char* GetStateName() const override;                  // [1]
    bool unk_07(void* context) override;                        // [7]
    bool unk_08(const void* value) const override;              // [8]
    bool unk_12(
        void* context,
        std::uint32_t value,
        bool flag) override;                                   // [12]
    bool unk_27(void* context) override;                        // [27]
    bool unk_28(void* context) override;                        // [28]
    bool unk_42() override;                                    // [42]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]
};

static_assert(sizeof(C_BadgeDiceSelectingDiceGameState) == 0x20,
              "C_BadgeDiceSelectingDiceGameState size mismatch");

} // namespace wh::playermodule
