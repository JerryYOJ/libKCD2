#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/Offsets_RTTI.h"
#include "../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::playermodule::I_AlchemyRecipeStep -- reflected recipe-step interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08.
// -----------------------------------------------
// C_AlchemyRecipeStep is the direct concrete implementation. Its certified
// seven-slot table places the destructor after the three authored accessors.

namespace wh::framework {
class C_EEExpression;
}

namespace wh::playermodule {

class I_AlchemyRecipeStep {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_AlchemyRecipeStep;

    virtual CryStringT<char> GetUIText() const = 0;                     // [0] 0x18039956C
    virtual std::int32_t GetStepId() const = 0;                        // [1] 0x181A72970
    virtual framework::C_EEExpression* GetCompiledCondition() const = 0; // [2] 0x1819A2A90
    virtual ~I_AlchemyRecipeStep() = default;                          // [3] 0x180780568

    RTTR_ENABLE()                                                       // [4..6]
};
static_assert(sizeof(I_AlchemyRecipeStep) == 0x08,
              "I_AlchemyRecipeStep must contain only its vptr");

}  // namespace wh::playermodule
