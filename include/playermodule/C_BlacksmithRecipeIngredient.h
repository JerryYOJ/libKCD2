#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "I_BlacksmithRecipeIngredient.h"

namespace wh::playermodule {

class C_BlacksmithRecipeIngredient : public I_BlacksmithRecipeIngredient {
public:
    C_BlacksmithRecipeIngredient();
    ~C_BlacksmithRecipeIngredient();
    const CryGUID& GetItemClassId() const override;             // [0]
    std::uint32_t GetAmount() const override;                   // [1]
    RTTR_ENABLE() // [2..4]

    CryGUID m_itemClassId;                                      // +0x08
    std::uint32_t m_amount;                                    // +0x18
    std::uint8_t m_padding1C[4];                              // +0x1C
};

static_assert(sizeof(C_BlacksmithRecipeIngredient) == 0x20,
              "C_BlacksmithRecipeIngredient size mismatch");
static_assert(offsetof(C_BlacksmithRecipeIngredient, m_itemClassId) == 0x08,
              "C_BlacksmithRecipeIngredient item id offset mismatch");
static_assert(offsetof(C_BlacksmithRecipeIngredient, m_amount) == 0x18,
              "C_BlacksmithRecipeIngredient amount offset mismatch");

} // namespace wh::playermodule
