#pragma once
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../xgenaimodule/I_Area.h"
#include "I_TagPoint.h"
#include "S_ItemClassGUID.h"

// -----------------------------------------------
// wh::entitymodule::C_SniffableItem : conceptmodule::C_Effect
// (KCD2 WHGame.dll 1.5.6). sizeof 0x148.
// -----------------------------------------------
// Factory new(0x148) 0x181331DDC, ctor 0x181331E94. Leaf ports start at +0x88.
// OnEffectActivate Inserts into C_SniffableItemManager; OnEffectDeactivate Erases.

namespace wh::entitymodule {

class C_SniffableItem : public wh::conceptmodule::C_Effect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SniffableItem;

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::xgenaimodule::I_Area*>> m_areas;         // +0x88  "Areas"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_TagPoint*>> m_targetPoints;                // +0xC8  "TargetPoints"
    wh::conceptmodule::C_TypedPortRef<S_ItemClassGUID> m_itemClass; // +0x108 "ItemClass"
};
static_assert(sizeof(C_SniffableItem) == 0x148,
              "C_SniffableItem is C_Effect 0x88 + three 0x40 ports");
static_assert(offsetof(C_SniffableItem, m_areas) == 0x88,
              "leaf ports start at +0x88");
static_assert(offsetof(C_SniffableItem, m_targetPoints) == 0xC8,
              "TargetPoints at +0xC8");
static_assert(offsetof(C_SniffableItem, m_itemClass) == 0x108,
              "ItemClass at +0x108");

}  // namespace wh::entitymodule
