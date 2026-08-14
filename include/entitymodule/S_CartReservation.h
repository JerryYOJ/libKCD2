#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryAction/GameObjectTypes.h"

namespace wh::entitymodule {

// Source-reconstructed name; exact EntityId/reference-count record.
struct S_CartReservation {
    EntityId m_entityId;                 // +0x00
    std::uint32_t m_referenceCount;      // +0x04
};

static_assert(sizeof(S_CartReservation) == 0x08,
              "S_CartReservation must be 0x08");

}  // namespace wh::entitymodule
