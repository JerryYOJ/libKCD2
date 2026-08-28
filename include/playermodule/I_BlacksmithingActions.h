#pragma once
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"

namespace wh::playermodule {

struct S_BlacksmithingModelState;

class I_BlacksmithingActions {
public:
    virtual void TransitionToAnvil() = 0;                   // [0]
    virtual void TransitionToForge() = 0;                   // [1]
    virtual void TransitionToHardening() = 0;               // [2]
    virtual void SetForgeInspection(bool enabled) = 0;      // [3]
    virtual void unk_04(bool enabled) = 0;                  // [4]
    virtual void unk_05(void* value) = 0;                   // [5]
    virtual void FlipWorkpiece() = 0;                       // [6]
    virtual void StartStroke() = 0;                         // [7]
    virtual void FinishStroke() = 0;                        // [8]
    virtual void unk_09(std::int32_t* index) = 0;           // [9]
    virtual void SetBlacksmithActionMap(
        CryStringT<char> const& context) = 0;               // [10]
    virtual void TransitionToHardeningAlternate() = 0;      // [11]
    virtual S_BlacksmithingModelState* GetModelState() = 0; // [12]
};

static_assert(sizeof(I_BlacksmithingActions) == 0x08,
              "I_BlacksmithingActions size mismatch");

} // namespace wh::playermodule
