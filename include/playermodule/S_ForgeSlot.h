#pragma once
#include <cstddef>
#include <cstdint>
#include "E_ForgeAssetScope.h"
#include "E_ForgeAssetSlot.h"

namespace wh::playermodule {

struct S_ForgeSlot {
    E_ForgeAssetSlot::Type m_slot;                        // +0x00
    std::uint8_t _pad01[3];                               // +0x01
    std::int32_t m_unknown04;                             // +0x04
    E_ForgeAssetScope::Type m_scope;                      // +0x08
    std::uint8_t _pad09[3];                               // +0x09
    float m_cameraX;                                      // +0x0C RTTR "camera_x"
    float m_cameraY;                                      // +0x10 RTTR "camera_y"
    float m_cameraScale;                                  // +0x14 RTTR "camera_scale"
};

static_assert(offsetof(S_ForgeSlot, m_cameraX) == 0x0C,
              "S_ForgeSlot::m_cameraX offset mismatch");
static_assert(sizeof(S_ForgeSlot) == 0x18,
              "S_ForgeSlot size mismatch");

}  // namespace wh::playermodule
