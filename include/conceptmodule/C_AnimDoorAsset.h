#pragma once
#include <cstddef>
#include "C_BaseAsset.h"

// -----------------------------------------------
// wh::conceptmodule::C_AnimDoorAsset : C_BaseAsset
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18, 5-slot vtable.
// -----------------------------------------------
// Empty RTTR leaf: inherits C_BaseAsset at mdisp=0, overrides the trio,
// keeps C_BaseAsset slot 1. No extra members.

namespace wh::conceptmodule {

class C_AnimDoorAsset : public C_BaseAsset {
public:
    ~C_AnimDoorAsset() override;                                   // [0]
    RTTR_ENABLE(C_BaseAsset)                              // [2..4]
};

static_assert(sizeof(C_AnimDoorAsset) == 0x18,
              "C_AnimDoorAsset size mismatch");

}  // namespace wh::conceptmodule
