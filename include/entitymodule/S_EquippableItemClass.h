#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_PlayerItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_EquippableItemClass -- KCD2 1.5.6. sizeof 0xE8.
// -----------------------------------------------
// Vtable 0x183A4F1F8, ctor sub_180754B60, copy-ctor sub_180D28EA0, Clone alloc 0xE8.
// RTTR registrar sub_180FCB224 ("wh::entitymodule::EquippableItem"). Clothing is a
// 16-byte shared_ptr at +0xD0 (copy sub_18039AE88); RTTR "Clothing" is getter/setter
// (slots 64/65 = 0x180971218 / 0x18115571C) over the pointee's NAME string, not the object.
// Pointee is C_Clothing: the setter TYPE-GATES exact wh::entitymodule::clothing::C_Clothing
// (vf[12] type vs 0x1810258E8) and stores null otherwise (dual-verifier 2026-08-21).

namespace wh::entitymodule {

namespace clothing { class C_Clothing; }

class S_EquippableItemClass : public S_PlayerItemClass {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_EquippableItemClass;
    S_EquippableItemClass* GetAsEquippableItemClass() override { return this; } // [26]

    float            m_visibility;               // +0xB0  RTTR "Visibility"
    float            m_conspicuousness;          // +0xB4  RTTR "Conspicuousness"
    float            m_charisma;                 // +0xB8  RTTR "Charisma"  ctor 1.0f
    float            m_rpgBuffWeight;            // +0xBC  RTTR "RPGBuffWeight"  ctor 1.0f
    std::int32_t     m_socialClassId;            // +0xC0  RTTR "SocialClassId"
    std::int32_t     m_wealthLevel;              // +0xC4  RTTR "WealthLevel"
    CryStringT<char> m_uiSound;                  // +0xC8  RTTR "UiSound"
    std::shared_ptr<clothing::C_Clothing> m_clothing; // +0xD0  RTTR "Clothing" (exact-C_Clothing gated)
    std::uint32_t    m_maxQuality;               // +0xE0  RTTR "MaxQuality"
    std::uint8_t     _padE4[4];                  // +0xE4
};
static_assert(sizeof(S_EquippableItemClass) == 0xE8, "S_EquippableItemClass must be 0xE8");
static_assert(offsetof(S_EquippableItemClass, m_visibility) == 0xB0);
static_assert(offsetof(S_EquippableItemClass, m_clothing) == 0xD0);
static_assert(offsetof(S_EquippableItemClass, m_maxQuality) == 0xE0);

}  // namespace wh::entitymodule
