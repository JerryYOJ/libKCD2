#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::playermodule {

class I_BlacksmithRecipeProduct {
public:
    virtual const CryGUID& GetItemClassId() const = 0;          // [0]
    virtual std::uint32_t GetMinimalQuality() const = 0;        // [1]
};

static_assert(sizeof(I_BlacksmithRecipeProduct) == 0x08,
              "I_BlacksmithRecipeProduct size mismatch");

} // namespace wh::playermodule
