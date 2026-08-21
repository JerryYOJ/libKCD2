#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_PickableItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_PlayerItemClass -- UI presentation view (KCD2 1.5.6).
// sizeof 0xB0.  E_ItemType::Player (25).
// -----------------------------------------------
// Vtable 0x183A4F018, ctor sub_180754BD8, copy-ctor sub_180D28F48, Clone alloc 0xB0.
// RTTR registrar sub_180FC9FDC ("wh::entitymodule::PlayerItem").

namespace wh::entitymodule {

class S_PlayerItemClass : public S_PickableItemClass {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_PlayerItemClass;

    CryStringT<char> m_iconId;                   // +0x90  RTTR "IconId"
    CryStringT<char> m_uiInfo;                   // +0x98  RTTR "UIInfo"
    CryStringT<char> m_uiName;                   // +0xA0  RTTR "UIName"
    bool             m_isQuestItem;              // +0xA8  RTTR "IsQuestItem"  ctor 0
    bool             m_pickpocketInPouch;        // +0xA9  RTTR "PickpocketInPouch"  ctor 0
    bool             m_displayInShop;            // +0xAA  RTTR "DisplayInShop"  ctor 1
    std::uint8_t     _padAB[5];                  // +0xAB
};
static_assert(sizeof(S_PlayerItemClass) == 0xB0, "S_PlayerItemClass must be 0xB0");
static_assert(offsetof(S_PlayerItemClass, m_iconId) == 0x90);
static_assert(offsetof(S_PlayerItemClass, m_uiName) == 0xA0);

}  // namespace wh::entitymodule
