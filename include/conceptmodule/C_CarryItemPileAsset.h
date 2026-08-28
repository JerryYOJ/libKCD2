#pragma once
#include <cstddef>
#include "C_BaseAsset.h"

// -----------------------------------------------
// wh::conceptmodule::C_CarryItemPileAsset : C_BaseAsset
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18, 5-slot vtable.
// -----------------------------------------------
// Empty RTTR leaf: inherits C_BaseAsset at mdisp=0, overrides the trio,
// keeps C_BaseAsset slot 1. No extra members.

namespace wh::conceptmodule {

class C_CarryItemPileAsset : public C_BaseAsset {
public:
    ~C_CarryItemPileAsset() override;                                   // [0]
    RTTR_ENABLE(C_BaseAsset)                              // [2..4]
};

static_assert(sizeof(C_CarryItemPileAsset) == 0x18,
              "C_CarryItemPileAsset size mismatch");

}  // namespace wh::conceptmodule
