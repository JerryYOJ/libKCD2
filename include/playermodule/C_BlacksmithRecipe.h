#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <vector>
#include "../framework/C_LocalizedString.h"
#include "../rttr/rttr_enable.h"
#include "C_BlacksmithRecipeIngredient.h"
#include "C_BlacksmithRecipeProduct.h"
#include "I_BlacksmithRecipe.h"

namespace wh::playermodule {

class C_BlacksmithWorkpiece;

class C_BlacksmithRecipe : public I_BlacksmithRecipe {
public:
    C_BlacksmithRecipe();
    C_BlacksmithRecipe(const C_BlacksmithRecipe& other);
    C_BlacksmithRecipe(C_BlacksmithRecipe&& other);
    ~C_BlacksmithRecipe();

    const CryStringT<char>& GetId() const override;             // [0]
    const CryStringT<char>& GetUIName() const override;         // [1]
    const CryStringT<char>& GetUIIcon() const override;         // [2]
    const CryStringT<char>& GetUIDescription() const override;  // [3]
    E_BlacksmithRecipeCategory GetCategory() const override;    // [4]
    void GetAverageProductQuality(
        std::int32_t& quality) const override;                  // [5]
    std::uint32_t GetCraftableCount(
        const wh::entitymodule::C_Inventory* inventory) const override; // [6]
    bool MeetsSkillRequirement(
        const wh::rpgmodule::I_Soul* soul) const override;      // [7]
    bool HasIngredients(
        const wh::entitymodule::C_Inventory* inventory) const override; // [8]
    std::uint32_t GetMinimumSkillLevel() const override;        // [9]
    void VisitIngredients(
        std::function<void(const I_BlacksmithRecipeIngredient&)>
            visitor) const override;                           // [10]
    void VisitProducts(
        std::function<void(const I_BlacksmithRecipeProduct&)>
            visitor) const override;                           // [11]
    CryGUID GetPerkId() const override;                         // [12]
    std::int32_t GetDlcId() const override;                     // [13]
    RTTR_ENABLE() // [14..16]

    CryStringT<char> GetWorkpieceId() const;
    void SetWorkpieceId(CryStringT<char> id);

    CryStringT<char> m_id;                                     // +0x08
    wh::framework::C_LocalizedString m_uiName;                 // +0x10
    CryStringT<char> m_uiIcon;                                 // +0x20
    wh::framework::C_LocalizedString m_uiDescription;          // +0x28
    E_BlacksmithRecipeCategory m_category;                     // +0x38
    std::uint32_t m_minSkillLevel;                             // +0x3C
    CryGUID m_perkId;                                          // +0x40
    float m_completionGainMod;                                 // +0x50
    float m_qualityLossMod;                                    // +0x54
    std::vector<C_BlacksmithRecipeIngredient> m_ingredients;   // +0x58
    C_BlacksmithWorkpiece* m_workpiece;                        // +0x70
    std::vector<C_BlacksmithRecipeProduct> m_products;         // +0x78
    std::int32_t m_dlcId;                                      // +0x90
    std::uint8_t m_padding94[4];                              // +0x94
};

static_assert(sizeof(C_BlacksmithRecipe) == 0x98,
              "C_BlacksmithRecipe size mismatch");
static_assert(offsetof(C_BlacksmithRecipe, m_id) == 0x08,
              "C_BlacksmithRecipe id offset mismatch");
static_assert(offsetof(C_BlacksmithRecipe, m_ingredients) == 0x58,
              "C_BlacksmithRecipe ingredients offset mismatch");
static_assert(offsetof(C_BlacksmithRecipe, m_workpiece) == 0x70,
              "C_BlacksmithRecipe workpiece offset mismatch");
static_assert(offsetof(C_BlacksmithRecipe, m_products) == 0x78,
              "C_BlacksmithRecipe products offset mismatch");
static_assert(offsetof(C_BlacksmithRecipe, m_dlcId) == 0x90,
              "C_BlacksmithRecipe DLC offset mismatch");

} // namespace wh::playermodule
