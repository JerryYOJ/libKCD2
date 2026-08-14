#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_ItemHolderType -- concrete C_ItemHolder domain.
// -----------------------------------------------
// [SOURCE-RECONSTRUCTED TYPE NAME] One-byte return width and values 0..8 are
// proved by the concrete holder vtables. The original C++ enum name is not emitted.

namespace wh::entitymodule {

enum class E_ItemHolderType : std::uint8_t {
    Inventory            = 0,
    ItemSlot             = 1,
    WorldInventory       = 2,
    ItemVectorHolder     = 3,
    ItemVectorBorrower   = 4,
    ItemWrapper          = 5,
    ActorActionCarryItem = 6,
    SpawnedItemsHolder   = 7,
    QuestItemManager     = 8,
};
static_assert(sizeof(E_ItemHolderType) == 0x01,
              "item-holder type must remain one byte");

}  // namespace wh::entitymodule
