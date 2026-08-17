#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

struct TRMIInventory_Item {
    CryStringT<char> m_itemClass; // +0x00, wire key "ItemClass"
};
static_assert(sizeof(TRMIInventory_Item) == 0x08,
              "TRMIInventory_Item must be 0x08");
