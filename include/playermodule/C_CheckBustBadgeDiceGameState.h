#pragma once
#include <cstddef>
#include "I_DiceGameModelState.h"

namespace wh::playermodule {

class C_CheckBustBadgeDiceGameState : public I_DiceGameModelState {
public:
    explicit C_CheckBustBadgeDiceGameState(C_DiceGameModel* model);
    const char* GetStateName() const override;                  // [1]
    void unk_05(void* context) override;                        // [5]
    bool unk_07(void* context) override;                        // [7]
    bool unk_14(void* context) override;                        // [14]
    bool unk_22(void* context, bool flag) override;             // [22]
    bool unk_27(void* context) override;                        // [27]
    bool unk_41() override;                                    // [41]
    RTTR_ENABLE(I_DiceGameModelState) // [48..50]
};

static_assert(sizeof(C_CheckBustBadgeDiceGameState) == 0x20,
              "C_CheckBustBadgeDiceGameState size mismatch");

} // namespace wh::playermodule
