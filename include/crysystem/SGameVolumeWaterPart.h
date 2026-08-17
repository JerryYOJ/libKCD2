#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

struct IPhysicalEntity;
struct IWaterVolumeRenderNode;

// Water-volume render/physics pair; canonical source name remains open.
struct SGameVolumeWaterPart {
    IWaterVolumeRenderNode* m_pRenderNode; // +0x00, owned/released
    IPhysicalEntity* m_pPhysicsArea;       // +0x08, owned by physics world
    Vec3 m_physicsPosition;                // +0x10
    std::uint32_t _pad1C;                  // +0x1C
};
static_assert(sizeof(SGameVolumeWaterPart) == 0x20,
              "SGameVolumeWaterPart must be 0x20");
static_assert(offsetof(SGameVolumeWaterPart, m_physicsPosition) == 0x10,
              "water-part physics position must be at 0x10");
