#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

enum EAttachmentBlendControlJointAxisToUse : std::int32_t {
    BlendControlJointAxisToUse_X = 0,
    BlendControlJointAxisToUse_Y = 1,
    BlendControlJointAxisToUse_Z = 2,
};
static_assert(sizeof(EAttachmentBlendControlJointAxisToUse) == 4, "EAttachmentBlendControlJointAxisToUse size mismatch");
