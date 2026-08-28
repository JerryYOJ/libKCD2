#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "E_BlacksmithRecipeCategory.h"

namespace wh::entitymodule { class C_Inventory; }
namespace wh::rpgmodule { class I_Soul; }

namespace wh::playermodule {

class I_BlacksmithRecipeIngredient;
class I_BlacksmithRecipeProduct;

class I_BlacksmithRecipe {
public:
    virtual const CryStringT<char>& GetId() const = 0;          // [0]
    virtual const CryStringT<char>& GetUIName() const = 0;      // [1]
    virtual const CryStringT<char>& GetUIIcon() const = 0;      // [2]
    virtual const CryStringT<char>& GetUIDescription() const = 0; // [3]
    virtual E_BlacksmithRecipeCategory GetCategory() const = 0; // [4]
    virtual void GetAverageProductQuality(
        std::int32_t& quality) const = 0;                       // [5]
    virtual std::uint32_t GetCraftableCount(
        const wh::entitymodule::C_Inventory* inventory) const = 0; // [6]
    virtual bool MeetsSkillRequirement(
        const wh::rpgmodule::I_Soul* soul) const = 0;           // [7]
    virtual bool HasIngredients(
        const wh::entitymodule::C_Inventory* inventory) const = 0; // [8]
    virtual std::uint32_t GetMinimumSkillLevel() const = 0;     // [9]
    virtual void VisitIngredients(
        std::function<void(const I_BlacksmithRecipeIngredient&)>
            visitor) const = 0;                                // [10]
    virtual void VisitProducts(
        std::function<void(const I_BlacksmithRecipeProduct&)>
            visitor) const = 0;                                // [11]
    virtual CryGUID GetPerkId() const = 0;                      // [12]
    virtual std::int32_t GetDlcId() const = 0;                  // [13]
};

static_assert(sizeof(I_BlacksmithRecipe) == 0x08,
              "I_BlacksmithRecipe size mismatch");

} // namespace wh::playermodule
