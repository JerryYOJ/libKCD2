#pragma once
#include <cstddef>
#include <cstdint>
#include "C_BaseAsset.h"

// -----------------------------------------------
// wh::conceptmodule::C_SoulAsset : C_BaseAsset
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x30, 5-slot vtable.
// -----------------------------------------------
// Extra 0x18 bytes after C_BaseAsset are accessor-backed; member offset
// is not proven by RTTR member_object_ptr. Left as an unknown region.

namespace wh::conceptmodule {

class C_SoulAsset : public C_BaseAsset {
public:
    ~C_SoulAsset() override;                                   // [0]
    RTTR_ENABLE(C_BaseAsset)                              // [2..4]
    std::uint8_t m_unknown18[0x18];                       // +0x18 SharedSoulGuids accessor-backed; offset unproven
};

static_assert(offsetof(C_SoulAsset, m_unknown18) == 0x18,
              "C_SoulAsset::m_unknown18 offset mismatch");
static_assert(sizeof(C_SoulAsset) == 0x30,
              "C_SoulAsset size mismatch");

}  // namespace wh::conceptmodule
