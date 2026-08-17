#pragma once

#include <vector>
#include "CryEngine/CryCommon/Cry_Math.h"

class PathParticles {
public:
    static void Sync(const std::vector<Vec3>& nodes);
    static void Clear();
    static void Tick();
};
