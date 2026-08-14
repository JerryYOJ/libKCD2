#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_CatWaypointDefinition.h"
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::entitymodule {

// Source-reconstructed name; exact packed 0xA8 embedded layout.
#pragma pack(push, 4)
struct S_CatHolderPathState {
    std::uint64_t m_state00;                              // +0x00, role OPEN
    std::uint16_t m_state08;                              // +0x08, role OPEN
    std::uint8_t m_state0A;                               // +0x0A, role OPEN
    std::uint8_t _pad0B;                                  // +0x0B
    Vec3 m_axis0C;                                        // +0x0C, init {1,0,0}
    Vec3 m_current18;                                     // +0x18
    Vec3 m_direction24;                                   // +0x24, init {0,1,0}
    std::uint32_t m_state30;                              // +0x30, role OPEN
    std::uint8_t _pad34[4];                               // +0x34
    std::vector<S_CatWaypointDefinition> m_waypoints;     // +0x38
    std::uint64_t m_state50;                              // +0x50, role OPEN
    std::uint32_t m_state58;                              // +0x58, role OPEN
    float m_scale5C;                                      // +0x5C, init 1.0f
    Vec3 m_vector60;                                      // +0x60
    std::uint32_t m_state6C;                              // +0x6C, role OPEN
    std::uint8_t m_opaque70[4];                           // +0x70
    Vec3 m_vector74;                                      // +0x74
    std::uint8_t m_state80;                               // +0x80, role OPEN
    std::uint8_t _pad81[3];                               // +0x81
    std::uint64_t m_state84;                              // +0x84, role OPEN
    std::uint32_t m_state8C;                              // +0x8C, role OPEN
    float m_scale90;                                      // +0x90, init 1.0f
    Vec3 m_vector94;                                      // +0x94
    std::uint64_t m_stateA0;                              // +0xA0, role OPEN
};
#pragma pack(pop)

static_assert(sizeof(S_CatHolderPathState) == 0xA8,
              "S_CatHolderPathState must be 0xA8");
static_assert(offsetof(S_CatHolderPathState, m_waypoints) == 0x38,
              "cat holder waypoint vector must be at 0x38");
static_assert(offsetof(S_CatHolderPathState, m_state84) == 0x84,
              "cat holder packed state must be at 0x84");

}  // namespace wh::entitymodule
