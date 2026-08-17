#pragma once
#include <cstddef>
#include <cstdint>

typedef unsigned int EntityId;
struct IEntityClass;

namespace Offsets {

class IInventoryListener {
public:
    virtual ~IInventoryListener() = default; // [0], destructor shape inferred
    virtual void OnAddItem(EntityId entityId) = 0; // [1]
    virtual void OnSetAmmoCount(IEntityClass* ammoType,
                                std::int32_t count) = 0; // [2]
    virtual void OnAddAccessory(IEntityClass* accessoryClass) = 0; // [3]
    virtual void OnClearInventory() = 0; // [4]
};
static_assert(sizeof(IInventoryListener) == 0x08,
              "IInventoryListener must be vptr-only");

}  // namespace Offsets
