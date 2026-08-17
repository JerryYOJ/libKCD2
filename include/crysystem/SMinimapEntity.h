#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IEntity.h"

struct SMinimapEntity {
    EntityId entityId;       // +0x00
    std::int32_t type;       // +0x04
    float lifetime;          // +0x08, zero means non-expiring
};
static_assert(sizeof(SMinimapEntity) == 0x0C,
              "SMinimapEntity must be 0x0C");
