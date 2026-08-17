#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IActor.h"
#include "../Offsets/vtables/IGameFramework.h"
#include "../Offsets/vtables/IInventory.h"
#include "../Offsets/vtables/IInventoryListener.h"
#include "../Offsets/vtables/IItem.h"
#include "SInventoryStats.h"

struct IEntityClass;

class CInventory
    : public Offsets::CGameObjectExtensionHelper<
          CInventory,
          Offsets::IInventory,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CInventory;

    CInventory();
    ~CInventory() override; // [0]
    void ProcessEvent(SEntityEvent& event) override; // [1]
    bool _vf2() override; // [2]
    int GetEventPriority(int eventId) override; // [3]
    void _vf4() override; // [4]
    Offsets::IEntity* GetEntity() override; // [5]
    void GetMemoryUsage(ICrySizer* sizer) const override; // [6]
    bool Init(Offsets::IGameObject* gameObject) override; // [7]
    void PostInit(Offsets::IGameObject* gameObject) override; // [8]
    void InitClient(int channelId) override; // [9]
    void PostInitClient(int channelId) override; // [10]
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11]
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12]
    bool GetEntityPoolSignature(TSerialize signature) override; // [13]
    void Release() override; // [14]
    void FullSerialize(TSerialize serializer) override; // [15]
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override; // [16]
    bool _vf17() override; // [17]
    NetworkAspectType GetNetSerializeAspects() override; // [18]
    void PostSerialize() override; // [19]
    void SerializeSpawnInfo(TSerialize serializer) override; // [20]
    ISerializableInfoPtr GetSpawnInfo() override; // [21]
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22]
    void HandleEvent(const SGameObjectEvent& event) override; // [23]
    void SetChannelId(std::uint16_t id) override; // [24]
    void SetAuthority(bool authoritative) override; // [25]
    const void* GetRMIBase() const override; // [26]
    void PostUpdate(float frameTime) override; // [27]
    void PostRemoteSpawn() override; // [28]

    bool AddItem(EntityId id) override; // [29]
    bool RemoveItem(EntityId id) override; // [30]
    void RemoveAllItems(bool force) override; // [31]
    bool AddAccessory(IEntityClass* itemClass) override; // [32]
    void Destroy() override; // [33]
    void Clear(bool force) override; // [34]
    void RMIReqToServer_RemoveAllItems() const override; // [35]
    void RMIReqToServer_AddItem(const char* itemClass) const override; // [36]
    void RMIReqToServer_RemoveItem(const char* itemClass) const override; // [37]
    void RMIReqToServer_SetAmmoCount(const char* ammoClass,
                                     std::int32_t amount) const override; // [38]
    void RMIReqToServer_AddEquipmentPack(const char* equipmentPack,
                                         bool add,
                                         bool primary) const override; // [39]
    std::int32_t GetCapacity() const override; // [40]
    std::int32_t GetCount() const override; // [41]
    std::int32_t GetCountOfClass(const char* className) const override; // [42]
    std::int32_t GetCountOfCategory(const char* categoryName) const override; // [43]
    std::int32_t GetCountOfUniqueId(std::uint8_t uniqueId) const override; // [44]
    std::int32_t GetSlotCount(std::int32_t slotId) const override; // [45]
    EntityId GetItem(std::int32_t slotId) const override; // [46]
    const char* GetItemString(std::int32_t slotId) const override; // [47]
    EntityId GetItemByClass(IEntityClass* itemClass,
                            Offsets::IItem* ignoreItem) const override; // [48]
    Offsets::IItem* GetItemByName(const char* name) const override; // [49]
    std::int32_t GetAccessoryCount() const override; // [50]
    const char* GetAccessory(std::int32_t slotId) const override; // [51]
    const IEntityClass* GetAccessoryClass(std::int32_t slotId) const override; // [52]
    bool HasAccessory(IEntityClass* itemClass) const override; // [53]
    std::int32_t FindItem(EntityId itemId) const override; // [54]
    std::int32_t FindNext(IEntityClass* itemClass,
                          const char* category,
                          std::int32_t firstSlot,
                          bool wrap) const override; // [55]
    std::int32_t FindPrev(IEntityClass* itemClass,
                          const char* category,
                          std::int32_t firstSlot,
                          bool wrap) const override; // [56]
    EntityId GetCurrentItem() const override; // [57]
    EntityId GetHolsteredItem() const override; // [58]
    void SetCurrentItem(EntityId itemId) override; // [59]
    void SetHolsteredItem(EntityId itemId) override; // [60]
    void SetLastItem(EntityId itemId) override; // [61]
    EntityId GetLastItem() const override; // [62]
    EntityId GetLastSelectedInSlot(
        Offsets::IInventory::EInventorySlots slotId) const override; // [63]
    void HolsterItem(bool holster) override; // [64]
    void SerializeInventoryForLevelChange(TSerialize serializer) override; // [65]
    bool IsSerializingForLevelChange() const override; // [66]
    std::int32_t GetAmmoTypesCount() const override; // [67]
    IEntityClass* GetAmmoType(std::int32_t index) const override; // [68]
    void SetAmmoCount(IEntityClass* ammoType,
                      std::int32_t count) override; // [69]
    std::int32_t GetAmmoCount(IEntityClass* ammoType) const override; // [70]
    void SetAmmoCapacity(IEntityClass* ammoType,
                         std::int32_t capacity) override; // [71]
    std::int32_t GetAmmoCapacity(IEntityClass* ammoType) const override; // [72]
    void ResetAmmo() override; // [73]
    void AddAmmoUser(IEntityClass* ammoType) override; // [74]
    void RemoveAmmoUser(IEntityClass* ammoType) override; // [75]
    std::int32_t GetNumberOfUsersForAmmo(
        IEntityClass* ammoType) const override; // [76]
    Offsets::IActor* GetActor() override; // [77]
    void SetInventorySlotCapacity(
        Offsets::IInventory::EInventorySlots slotId,
        std::uint32_t capacity) override; // [78]
    void AssociateItemCategoryToSlot(
        const char* itemCategory,
        Offsets::IInventory::EInventorySlots slotId) override; // [79]
    bool IsAvailableSlotForItemClass(const char* itemClass) const override; // [80]
    bool IsAvailableSlotForItemCategory(const char* category) const override; // [81]
    bool AreItemsInSameSlot(const char* itemClass1,
                            const char* itemClass2) const override; // [82]
    Offsets::IInventory::EInventorySlots GetSlotForItemCategory(
        const char* category) const override; // [83]
    void AddListener(Offsets::IInventoryListener* listener) override; // [84]
    void RemoveListener(Offsets::IInventoryListener* listener) override; // [85]
    void IgnoreNextClear() override; // [86]
    virtual void RemoveItemFromCategorySlot(EntityId entityId); // [87]

    SInventoryStats m_stats; // +0x040
    SInventoryStats m_editorStats; // +0x0D8, role/name inferred
    std::vector<Offsets::IInventoryListener*> m_listeners; // +0x170, borrowed elements
    Offsets::IGameFramework* m_pGameFramework; // +0x188, borrowed
    Offsets::IActor* m_pActor; // +0x190, borrowed
    bool m_serializingForLevelChange; // +0x198
    bool m_iteratingListeners; // +0x199
    bool m_ignoreNextClear; // +0x19A
    std::byte _pad19B[5]; // +0x19B
};
static_assert(sizeof(CInventory) == 0x1A0,
              "CInventory must be 0x1A0");
static_assert(offsetof(CInventory, m_stats) == 0x40,
              "inventory runtime stats must be at 0x40");
static_assert(offsetof(CInventory, m_editorStats) == 0xD8,
              "inventory secondary stats must be at 0xD8");
static_assert(offsetof(CInventory, m_listeners) == 0x170,
              "inventory listeners must be at 0x170");
static_assert(offsetof(CInventory, m_pGameFramework) == 0x188,
              "inventory framework pointer must be at 0x188");
static_assert(offsetof(CInventory, m_pActor) == 0x190,
              "inventory actor pointer must be at 0x190");
static_assert(offsetof(CInventory, m_serializingForLevelChange) == 0x198,
              "inventory level-change state must be at 0x198");
