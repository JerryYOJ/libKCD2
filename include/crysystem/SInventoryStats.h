#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../Offsets/vtables/IInventory.h"
#include "SInventoryAmmoInfo.h"
#include "SInventorySlotInfo.h"

struct IEntityClass;

struct SInventoryStats {
    std::vector<EntityId> slots; // +0x00
    std::vector<IEntityClass*> accessorySlots; // +0x18
    std::map<IEntityClass*, SInventoryAmmoInfo> ammoInfo; // +0x30
    SInventorySlotInfo slotsInfo[4]; // +0x40
    std::map<CryStringT<char>, Offsets::IInventory::EInventorySlots> categories; // +0x70
    std::map<IEntityClass*, SInventoryAmmoInfo>::iterator ammoIterator; // +0x80
    EntityId currentItemId;   // +0x88
    EntityId holsteredItemId; // +0x8C
    EntityId lastItemId;      // +0x90
    std::uint32_t _pad94;     // +0x94
};
static_assert(sizeof(SInventoryStats) == 0x98,
              "SInventoryStats must be 0x98");
static_assert(offsetof(SInventoryStats, accessorySlots) == 0x18,
              "inventory accessory slots must be at 0x18");
static_assert(offsetof(SInventoryStats, ammoInfo) == 0x30,
              "inventory ammo map must be at 0x30");
static_assert(offsetof(SInventoryStats, slotsInfo) == 0x40,
              "inventory slot records must be at 0x40");
static_assert(offsetof(SInventoryStats, categories) == 0x70,
              "inventory category map must be at 0x70");
static_assert(offsetof(SInventoryStats, ammoIterator) == 0x80,
              "inventory ammo iterator must be at 0x80");
