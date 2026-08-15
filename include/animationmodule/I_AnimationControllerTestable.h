#pragma once
#include <cstdint>
#include <functional>
#include "../Offsets/Offsets_RTTI.h"

namespace wh::animationmodule {

// Native vptr-only test interface. It has no virtual destructor in the KCD2 table.
class I_AnimationControllerTestable {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_AnimationControllerTestable;

    virtual bool IsEnabled() const = 0; // [0] 0x1821392E0, thunk to LOD slot 12
    virtual void EnumerateAnimations(
        std::function<void(std::int32_t, const char*)> callback) = 0; // [1] 0x1827D2574, by value/callee-destroy
    virtual bool _vf2() const = 0; // [2] false stub
};
static_assert(sizeof(I_AnimationControllerTestable) == 0x08,
              "I_AnimationControllerTestable must be vptr-only");

}  // namespace wh::animationmodule
