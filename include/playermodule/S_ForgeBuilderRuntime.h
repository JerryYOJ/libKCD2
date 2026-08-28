#pragma once
#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::playermodule {

class C_ForgeBuilder;

struct S_ForgeBuilderRuntime {
    void* m_handleData;                       // +0x00
    std::int32_t m_handleIndex;               // +0x08, ctor -1
    std::uint32_t m_padding0C;
    Vec3 m_anchor;                            // +0x10, ctor {-1,-1,-1}
    float m_unknown1C;                        // +0x1C, ctor 1.0
    float m_unknown20;                        // +0x20, ctor -1.0
    Vec3 m_points[4];                         // +0x24
    Matrix34 m_transformA;                    // +0x54, identity
    Matrix34 m_transformB;                    // +0x84, identity
    Vec3 m_samples[12];                       // +0xB4
    std::uint8_t m_padding144[4];
    C_ForgeBuilder* m_owner;                  // +0x148
};

static_assert(sizeof(S_ForgeBuilderRuntime) == 0x150,
              "S_ForgeBuilderRuntime size mismatch");
static_assert(offsetof(S_ForgeBuilderRuntime, m_anchor) == 0x10,
              "S_ForgeBuilderRuntime anchor offset mismatch");
static_assert(offsetof(S_ForgeBuilderRuntime, m_transformA) == 0x54,
              "S_ForgeBuilderRuntime transform A offset mismatch");
static_assert(offsetof(S_ForgeBuilderRuntime, m_transformB) == 0x84,
              "S_ForgeBuilderRuntime transform B offset mismatch");
static_assert(offsetof(S_ForgeBuilderRuntime, m_samples) == 0xB4,
              "S_ForgeBuilderRuntime samples offset mismatch");
static_assert(offsetof(S_ForgeBuilderRuntime, m_owner) == 0x148,
              "S_ForgeBuilderRuntime owner offset mismatch");

} // namespace wh::playermodule
