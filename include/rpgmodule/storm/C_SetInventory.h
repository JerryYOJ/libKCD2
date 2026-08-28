#pragma once
#include <cstddef>
#include "C_InventoryOperator.h"

namespace wh::rpgmodule::storm {

class C_SetInventory : public C_InventoryOperator {
public:
    ~C_SetInventory() override;
    void unk_08(C_Soul* soul, C_Rule* rule) override;
    RTTR_ENABLE(C_InventoryOperator)
};

static_assert(sizeof(C_SetInventory) == 0x10, "C_SetInventory size mismatch");

}  // namespace wh::rpgmodule::storm
