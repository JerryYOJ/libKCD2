#pragma once
#include <cstdint>
#include "../Offsets/Offsets_RTTI.h"

class IAction;

namespace wh::animationmodule {

class I_AnimationControllerTestable;
class I_LODAnimationController;

class I_AnimationController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_AnimationController;

    virtual ~I_AnimationController() = default; // [0] secondary deleting-destructor thunk
    // Source name and pointer/reference form OPEN. XMM2 proves the second argument is float.
    virtual bool QueueAction(IAction& action, float time,
                             bool restartInstalled) = 0; // [1] 0x1827D225C
    virtual I_LODAnimationController* GetLODAnimationController() = 0; // [2] 0x181A73320
    virtual I_AnimationControllerTestable* GetTestable() = 0;          // [3] 0x181A749E0
    virtual void _vf4() = 0;                                           // [4] nullsub
    virtual void SetSuspended(std::int32_t mode) = 0;                  // [5] 0x181E5A720, mode spelling/domain OPEN
};
static_assert(sizeof(I_AnimationController) == 0x08,
              "I_AnimationController must be vptr-only");

}  // namespace wh::animationmodule
