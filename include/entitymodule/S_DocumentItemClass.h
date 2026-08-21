#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_PlayerItemClass.h"
#include "S_TypedItemClass.h"
#include "S_DocumentContent.h"

// -----------------------------------------------
// wh::entitymodule::S_DocumentItemClass -- KCD2 1.5.6. sizeof 0xF0.
// -----------------------------------------------
// E_ItemType::Document (8), CRTP S_ItemClassWrapper<S_DocumentItemClass, S_PlayerItemClass, 8>.
// Primary vtable 0x183A51C28, mixin vtable @+0xB0 0x183A51BD8, ctor sub_180784880,
// copy sub_182A1C8B0, Clone sub_182A1E644 alloc 0xF0. RTTR "wh::entitymodule::Document"
// (registrar 0x1812210D4). IsType = (type==8) || Player closed mask {21,22,25} via
// sub_1804696D4 -- compiled ancestor mask, NOT a parent-vfunc walk. Document vf[11]
// (SubType getter slot) is a constant -1 stub and does not read m_subType.

namespace wh::entitymodule {

class S_DocumentItemClass
    : public S_PlayerItemClass                   // +0x00 .. 0xB0
    , public S_TypedItemClass {                  // +0xB0 .. 0xC0
public:
    S_DocumentItemClass* GetAsDocumentItemClass() override { return this; } // [40]

    std::shared_ptr<S_DocumentContent> m_documentContent; // +0xC0  RTTR "DocumentContent"
    float            m_lengthInGameHours;        // +0xD0  RTTR "LengthInGameHours" (hours semantic UNVERIFIED)
    std::int32_t     m_recipeId;                 // +0xD4  RTTR "RecipeId" (alchemy-FK identity UNVERIFIED)
    CryStringT<char> m_blacksmithRecipeId;       // +0xD8  RTTR "BlacksmithRecipeId" -- a STRING key, not an int id
    CryStringT<char> m_rarity;                   // +0xE0  RTTR "Rarity"  ctor "Common" (S_DocumentRarity FK UNVERIFIED)
    std::int32_t     m_visualCategory;           // +0xE8  RTTR "VisualCategory"  ctor 1 (I_UIBook::SetFullBook wiring UNVERIFIED)
    std::uint8_t     _padEC[4];                  // +0xEC
};
static_assert(sizeof(S_DocumentItemClass) == 0xF0, "S_DocumentItemClass must be 0xF0 (Clone alloc)");
static_assert(offsetof(S_DocumentItemClass, m_documentContent) == 0xC0);
static_assert(offsetof(S_DocumentItemClass, m_lengthInGameHours) == 0xD0);
static_assert(offsetof(S_DocumentItemClass, m_visualCategory) == 0xE8);

}  // namespace wh::entitymodule
