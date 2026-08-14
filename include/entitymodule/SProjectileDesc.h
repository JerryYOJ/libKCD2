#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IEntity.h"
#include "../framework/WUID.h"

namespace wh::entitymodule {

struct SProjectileDesc {
    SProjectileDesc();                    // 0x182894158

    EntityId ownerId;                     // +0x00
    std::uint32_t _pad04;                 // +0x04
    wh::framework::WUID sourceWuid;        // +0x08
    bool aimedShot;                        // +0x10
    std::uint8_t _pad11[7];               // +0x11
    CryStringT<char> objectName;           // +0x18
    bool applyAspectProfile;               // +0x20
    bool automaticTrailEffect;             // +0x21
    std::uint8_t _pad22[6];               // +0x22
};
static_assert(sizeof(SProjectileDesc) == 0x28,
              "SProjectileDesc must be 0x28");
static_assert(offsetof(SProjectileDesc, sourceWuid) == 0x08,
              "projectile source WUID must be at 0x08");
static_assert(offsetof(SProjectileDesc, objectName) == 0x18,
              "projectile object name must be at 0x18");

}  // namespace wh::entitymodule
