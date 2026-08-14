#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::xgenaimodule {

// The binary proves returned addresses; original pointer/reference spelling remains open.
class I_PositionAndOrientation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_PositionAndOrientation;
    virtual Vec3* GetPosition() = 0;      // [0] returns inline position
    virtual Quat* GetOrientation() = 0;   // [1] returns inline orientation
    virtual ~I_PositionAndOrientation() = default; // [2]
};
static_assert(sizeof(I_PositionAndOrientation) == 0x08,
              "I_PositionAndOrientation must be 0x08");

}  // namespace wh::xgenaimodule
