#pragma once

#include <vector>
#include "CryEngine/CryCommon/Cry_Math.h"

bool QueryWorldPath(const Vec3& start, const Vec3& target, std::vector<Vec3>& outNodes);
