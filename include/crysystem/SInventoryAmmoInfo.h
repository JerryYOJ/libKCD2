#pragma once
#include <cstddef>
#include <cstdint>

struct SInventoryAmmoInfo {
    std::int32_t count;    // +0x00
    std::int32_t users;    // +0x04
    std::int32_t capacity; // +0x08
};
static_assert(sizeof(SInventoryAmmoInfo) == 0x0C,
              "SInventoryAmmoInfo must be 0x0C");
