#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::entitymodule {

struct S_InteractiveObjectInteraction {
    Quat m_rotation;                    // +0x00
    Vec3 m_position;                    // +0x10
    float m_interactionRadius;          // +0x1C
    float m_interactionAngle;           // +0x20, radians after property load
    std::uint32_t m_interactionId;      // +0x24, exact source role OPEN
    CryStringT<char> m_helperName;      // +0x28, source name reconstructed
};
static_assert(sizeof(S_InteractiveObjectInteraction) == 0x30,
              "S_InteractiveObjectInteraction must be 0x30");
static_assert(offsetof(S_InteractiveObjectInteraction, m_position) == 0x10,
              "interaction position must be at 0x10");
static_assert(offsetof(S_InteractiveObjectInteraction, m_interactionRadius) == 0x1C,
              "interaction radius must be at 0x1C");
static_assert(offsetof(S_InteractiveObjectInteraction, m_interactionId) == 0x24,
              "interaction id must be at 0x24");
static_assert(offsetof(S_InteractiveObjectInteraction, m_helperName) == 0x28,
              "interaction helper name must be at 0x28");

}  // namespace wh::entitymodule
