#pragma once
#include <cstddef>

struct SEntityRemovalData {
    float timer;             // +0x00
    float time;              // +0x04
    bool visibility;         // +0x08
    std::byte _pad09[0x03];  // +0x09
};
static_assert(sizeof(SEntityRemovalData) == 0x0C,
              "SEntityRemovalData must be 0x0C");

using SScheduledRemoval = SEntityRemovalData;
