#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "I_BlacksmithRecipeProduct.h"

namespace wh::playermodule {

class C_BlacksmithRecipeProduct : public I_BlacksmithRecipeProduct {
public:
    C_BlacksmithRecipeProduct();
    ~C_BlacksmithRecipeProduct();
    const CryGUID& GetItemClassId() const override;             // [0]
    std::uint32_t GetMinimalQuality() const override;           // [1]
    RTTR_ENABLE() // [2..4]

    CryGUID m_itemClassId;                                      // +0x08
    std::uint32_t m_minimalQuality;                            // +0x18
    std::uint8_t m_padding1C[4];                              // +0x1C
};

static_assert(sizeof(C_BlacksmithRecipeProduct) == 0x20,
              "C_BlacksmithRecipeProduct size mismatch");
static_assert(offsetof(C_BlacksmithRecipeProduct, m_itemClassId) == 0x08,
              "C_BlacksmithRecipeProduct item id offset mismatch");
static_assert(offsetof(C_BlacksmithRecipeProduct, m_minimalQuality) == 0x18,
              "C_BlacksmithRecipeProduct quality offset mismatch");

} // namespace wh::playermodule
