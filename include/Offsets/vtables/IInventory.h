#pragma once
#include <cstddef>
#include <cstdint>
#include "IGameObjectExtension.h"

typedef unsigned int EntityId;
struct IEntityClass;

namespace Offsets {

class IActor;
class IInventoryListener;
class IItem;

class IInventory : public IGameObjectExtension {
public:
    enum class EInventorySlots : std::int32_t {
        Weapon = 0,
        Explosives = 1,
        Grenades = 2,
        Special = 3,
        Last = 4,
    };

    virtual bool AddItem(EntityId id) = 0; // [29]
    virtual bool RemoveItem(EntityId id) = 0; // [30]
    virtual void RemoveAllItems(bool force) = 0; // [31]
    virtual bool AddAccessory(IEntityClass* itemClass) = 0; // [32]
    virtual void Destroy() = 0; // [33]
    virtual void Clear(bool force) = 0; // [34]
    virtual void RMIReqToServer_RemoveAllItems() const = 0; // [35]
    virtual void RMIReqToServer_AddItem(const char* itemClass) const = 0; // [36]
    virtual void RMIReqToServer_RemoveItem(const char* itemClass) const = 0; // [37]
    virtual void RMIReqToServer_SetAmmoCount(const char* ammoClass,
                                             std::int32_t amount) const = 0; // [38]
    virtual void RMIReqToServer_AddEquipmentPack(const char* equipmentPack,
                                                 bool add,
                                                 bool primary) const = 0; // [39]
    virtual std::int32_t GetCapacity() const = 0; // [40]
    virtual std::int32_t GetCount() const = 0; // [41]
    virtual std::int32_t GetCountOfClass(const char* className) const = 0; // [42]
    virtual std::int32_t GetCountOfCategory(const char* categoryName) const = 0; // [43]
    virtual std::int32_t GetCountOfUniqueId(std::uint8_t uniqueId) const = 0; // [44]
    virtual std::int32_t GetSlotCount(std::int32_t slotId) const = 0; // [45]
    virtual EntityId GetItem(std::int32_t slotId) const = 0; // [46]
    virtual const char* GetItemString(std::int32_t slotId) const = 0; // [47]
    virtual EntityId GetItemByClass(IEntityClass* itemClass,
                                    IItem* ignoreItem) const = 0; // [48]
    virtual IItem* GetItemByName(const char* name) const = 0; // [49]
    virtual std::int32_t GetAccessoryCount() const = 0; // [50]
    virtual const char* GetAccessory(std::int32_t slotId) const = 0; // [51]
    virtual const IEntityClass* GetAccessoryClass(std::int32_t slotId) const = 0; // [52]
    virtual bool HasAccessory(IEntityClass* itemClass) const = 0; // [53]
    virtual std::int32_t FindItem(EntityId itemId) const = 0; // [54]
    virtual std::int32_t FindNext(IEntityClass* itemClass,
                                  const char* category,
                                  std::int32_t firstSlot,
                                  bool wrap) const = 0; // [55]
    virtual std::int32_t FindPrev(IEntityClass* itemClass,
                                  const char* category,
                                  std::int32_t firstSlot,
                                  bool wrap) const = 0; // [56]
    virtual EntityId GetCurrentItem() const = 0; // [57]
    virtual EntityId GetHolsteredItem() const = 0; // [58]
    virtual void SetCurrentItem(EntityId itemId) = 0; // [59]
    virtual void SetHolsteredItem(EntityId itemId) = 0; // [60]
    virtual void SetLastItem(EntityId itemId) = 0; // [61]
    virtual EntityId GetLastItem() const = 0; // [62]
    virtual EntityId GetLastSelectedInSlot(EInventorySlots slotId) const = 0; // [63]
    virtual void HolsterItem(bool holster) = 0; // [64]
    virtual void SerializeInventoryForLevelChange(TSerialize serializer) = 0; // [65]
    virtual bool IsSerializingForLevelChange() const = 0; // [66]
    virtual std::int32_t GetAmmoTypesCount() const = 0; // [67]
    virtual IEntityClass* GetAmmoType(std::int32_t index) const = 0; // [68]
    virtual void SetAmmoCount(IEntityClass* ammoType,
                              std::int32_t count) = 0; // [69]
    virtual std::int32_t GetAmmoCount(IEntityClass* ammoType) const = 0; // [70]
    virtual void SetAmmoCapacity(IEntityClass* ammoType,
                                 std::int32_t capacity) = 0; // [71]
    virtual std::int32_t GetAmmoCapacity(IEntityClass* ammoType) const = 0; // [72]
    virtual void ResetAmmo() = 0; // [73]
    virtual void AddAmmoUser(IEntityClass* ammoType) = 0; // [74]
    virtual void RemoveAmmoUser(IEntityClass* ammoType) = 0; // [75]
    virtual std::int32_t GetNumberOfUsersForAmmo(
        IEntityClass* ammoType) const = 0; // [76]
    virtual IActor* GetActor() = 0; // [77]
    virtual void SetInventorySlotCapacity(EInventorySlots slotId,
                                          std::uint32_t capacity) = 0; // [78]
    virtual void AssociateItemCategoryToSlot(const char* itemCategory,
                                             EInventorySlots slotId) = 0; // [79]
    virtual bool IsAvailableSlotForItemClass(const char* itemClass) const = 0; // [80]
    virtual bool IsAvailableSlotForItemCategory(const char* category) const = 0; // [81]
    virtual bool AreItemsInSameSlot(const char* itemClass1,
                                    const char* itemClass2) const = 0; // [82]
    virtual EInventorySlots GetSlotForItemCategory(
        const char* category) const = 0; // [83]
    virtual void AddListener(IInventoryListener* listener) = 0; // [84]
    virtual void RemoveListener(IInventoryListener* listener) = 0; // [85]
    virtual void IgnoreNextClear() = 0; // [86]
};
static_assert(sizeof(IInventory) == 0x40,
              "IInventory must preserve the 0x40 extension prefix");

}  // namespace Offsets
