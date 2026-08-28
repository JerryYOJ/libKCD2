#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Vector3.h"

// -----------------------------------------------
// wh::entitymodule::S_ItemTransformation
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18. No vtable.
// -----------------------------------------------

namespace wh::entitymodule {

struct S_ItemTransformation {
    Vec3 m_position;                                      // +0x00 RTTR "Position"
    Ang3 m_rotation;                                      // +0x0C RTTR "Rotation"
};

static_assert(offsetof(S_ItemTransformation, m_position) == 0x00,
              "S_ItemTransformation::m_position offset mismatch");
static_assert(offsetof(S_ItemTransformation, m_rotation) == 0x0C,
              "S_ItemTransformation::m_rotation offset mismatch");
static_assert(sizeof(S_ItemTransformation) == 0x18,
              "S_ItemTransformation size mismatch");

}  // namespace wh::entitymodule
