#pragma once
#include <boost/container/flat_map.hpp>
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Quat.h"
#include "navigation/S_NavMeshSource.h"
#include "S_SmartObjectHelperSetAnimationSerializedCheckResult.h"

namespace wh::xgenaimodule {

struct S_SmartObjectAnimation {
    boost::container::flat_map<
        navigation::S_NavMeshSource,
        S_SmartObjectHelperSetAnimationSerializedCheckResult> m_results; // +0x00 RTTR "Results"
    QuatT m_projectedTargetWorld;                            // +0x18 RTTR "ProjectedTargetWorld"
    std::uint8_t m_unknown34[4];                             // +0x34
};

static_assert(offsetof(S_SmartObjectAnimation, m_projectedTargetWorld) == 0x18,
              "S_SmartObjectAnimation::m_projectedTargetWorld offset mismatch");
static_assert(sizeof(S_SmartObjectAnimation) == 0x38,
              "S_SmartObjectAnimation size mismatch");

}  // namespace wh::xgenaimodule
