#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/BaseTypes.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/primitives.h"
#include "../CryEngine/CryCommon/physinterface.h"

namespace wh::entitymodule {

struct S_DeferredArrowCollision {
    EventPhysCollision collision; // +0x00
    QuatT transform;              // +0xA8
};
static_assert(offsetof(S_DeferredArrowCollision, transform) == 0xA8,
              "deferred arrow transform must be at 0xA8");
static_assert(sizeof(S_DeferredArrowCollision) == 0xC8,
              "S_DeferredArrowCollision must be 0xC8");

}  // namespace wh::entitymodule
