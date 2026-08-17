#pragma once

#include <vector>
#include "CryEngine/CryCommon/Cry_Math.h"

class Overlay {
public:
    static void PushPath(const std::vector<Vec3>& nodes);
    static void ClearPath();
    static bool CheckpointHovered();
};
