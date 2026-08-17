#pragma once
#include <cstddef>
#include <cstdint>

typedef unsigned int EntityId;

struct SInventorySlotInfo {
    std::uint32_t count;       // +0x00
    std::uint32_t maxCapacity; // +0x04
    EntityId lastSelected;     // +0x08
};
static_assert(sizeof(SInventorySlotInfo) == 0x0C,
              "SInventorySlotInfo must be 0x0C");
