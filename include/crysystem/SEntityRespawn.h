#pragma once
#include <cstddef>
#include <cstdint>

struct SEntityRespawn {
    bool unique;             // +0x00
    std::byte _pad01[0x03];  // +0x01
    float timer;             // +0x04
};
static_assert(sizeof(SEntityRespawn) == 0x08,
              "SEntityRespawn must be 0x08");

using SScheduledRespawn = SEntityRespawn;
