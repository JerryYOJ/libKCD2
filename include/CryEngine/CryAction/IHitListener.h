#pragma once
#include <cstddef>

struct HitInfo;
struct ExplosionInfo;

class IHitListener {
public:
    virtual ~IHitListener() = default;                              // [0]
    virtual void OnHit(const HitInfo& hit) = 0;                     // [1]
    virtual void OnExplosion(const ExplosionInfo& explosion) = 0;  // [2]
    virtual void OnServerExplosion(const ExplosionInfo& explosion) = 0; // [3]
};
static_assert(sizeof(IHitListener) == 0x08,
              "IHitListener must be 0x08");
