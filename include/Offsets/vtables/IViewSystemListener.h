#pragma once
#include <cstddef>

struct IAnimSequence;
struct SCameraParams;

namespace Offsets {

// Current listener table omits the historical OnPlayCutSceneSound slot.
class IViewSystemListener {
public:
    virtual ~IViewSystemListener() = default; // [0]
    virtual bool OnBeginCutScene(IAnimSequence* sequence, bool resetFx) = 0; // [1]
    virtual bool OnEndCutScene(IAnimSequence* sequence) = 0; // [2]
    virtual bool OnCameraChange(const SCameraParams& cameraParams) = 0; // [3]
};
static_assert(sizeof(IViewSystemListener) == 0x08,
              "IViewSystemListener must be vptr-only");

}  // namespace Offsets
