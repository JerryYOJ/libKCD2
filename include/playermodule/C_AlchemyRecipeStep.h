#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/C_EEExpression.h"
#include "I_AlchemyRecipeStep.h"

// -----------------------------------------------
// wh::playermodule::C_AlchemyRecipeStep -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x38.
// -----------------------------------------------
// RTTI hierarchy: C_AlchemyRecipeStep -> I_AlchemyRecipeStep. The certified
// seven-slot vtable is {GetUIText, GetStepId, GetCompiledCondition, dtor,
// RTTR trio}. The recipe-row stride is independently observed as 0x38.
// Condition is stored as source text at +0x10 and compiled into the expression
// at +0x20 by its reflected setter. StepType is a row name, not a native enum.

namespace wh::playermodule {

class C_AlchemyRecipeStep : public I_AlchemyRecipeStep {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AlchemyRecipeStep;

    CryStringT<char> GetUIText() const override;                       // [0] 0x18039956C
    std::int32_t GetStepId() const override;                          // [1] 0x181A72970
    framework::C_EEExpression* GetCompiledCondition() const override; // [2] 0x1819A2A90
    ~C_AlchemyRecipeStep() override;                                  // [3] 0x180780568

    RTTR_ENABLE(I_AlchemyRecipeStep)                                   // [4..6]

    std::int32_t m_stepId;                         // +0x08, RTTR "StepId"
    std::uint32_t _pad0C;                          // +0x0C
    CryStringT<char> m_condition;                  // +0x10, source Condition DSL
    CryStringT<char> m_uiText;                     // +0x18, localized UI text
    framework::C_EEExpression* m_pCompiledCondition; // +0x20, borrowed compiled condition
    std::int32_t m_feedbackPriority;               // +0x28
    std::uint32_t _pad2C;                          // +0x2C
    CryStringT<char> m_stepType;                   // +0x30, Trivial/Easy/Hard row name
};
static_assert(sizeof(C_AlchemyRecipeStep) == 0x38,
              "C_AlchemyRecipeStep must be 0x38");
static_assert(offsetof(C_AlchemyRecipeStep, m_pCompiledCondition) == 0x20,
              "compiled condition must be at 0x20");
static_assert(offsetof(C_AlchemyRecipeStep, m_stepType) == 0x30,
              "step type must be at 0x30");

}  // namespace wh::playermodule
