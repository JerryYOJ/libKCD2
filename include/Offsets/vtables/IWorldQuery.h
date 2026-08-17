#pragma once
#include <cstddef>
#include "IGameObjectExtension.h"
#include "../../CryEngine/CryCommon/Cry_Math.h"

typedef unsigned int EntityId;
struct IPhysicalEntity;
struct ray_hit;

namespace Offsets {

class IWorldQuery : public IGameObjectExtension {
public:
    virtual IEntity* GetEntityInFrontOf() = 0; // [29]
    virtual const EntityId* ProximityQuery(int& count) = 0; // [30]
    virtual const Vec3& GetPos() const = 0; // [31]
    virtual const Vec3& GetDir() const = 0; // [32]
    virtual EntityId GetLookAtEntityId(bool ignoreGlass = false) = 0; // [33]
    virtual const ray_hit* GetLookAtPoint(float maxDistance = 0.0f,
                                          bool ignoreGlass = false) = 0; // [34]
    virtual const ray_hit* GetBehindPoint(float maxDistance = 0.0f) = 0; // [35]
    virtual const EntityId* GetEntitiesAround(int& count) = 0; // [36]
    virtual ::IPhysicalEntity* const* GetPhysicalEntitiesAround(
        int& count) = 0; // [37]
    virtual ::IPhysicalEntity* GetPhysicalEntityInFrontOf() = 0; // [38]
};
static_assert(sizeof(IWorldQuery) == 0x40,
              "IWorldQuery must preserve the 0x40 extension prefix");

}  // namespace Offsets
