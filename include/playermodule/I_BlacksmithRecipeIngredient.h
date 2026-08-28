#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::playermodule {

class I_BlacksmithRecipeIngredient {
public:
    virtual const CryGUID& GetItemClassId() const = 0;          // [0]
    virtual std::uint32_t GetAmount() const = 0;                // [1]
};

static_assert(sizeof(I_BlacksmithRecipeIngredient) == 0x08,
              "I_BlacksmithRecipeIngredient size mismatch");

} // namespace wh::playermodule
