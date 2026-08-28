#pragma once
#include <cstddef>
#include <cstdint>
#include "C_BaseAsset.h"

// -----------------------------------------------
// wh::conceptmodule::C_ProfileAsset : C_BaseAsset
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x38, 5-slot vtable.
// -----------------------------------------------
// IsDynamic is an exact RTTR member_object_ptr at +0x30. AssetProfiles is
// accessor-backed (no offset). +0x18..+0x2F remains an unknown region.

namespace wh::conceptmodule {

class C_ProfileAsset : public C_BaseAsset {
public:
    ~C_ProfileAsset() override;                           // [0]
    RTTR_ENABLE(C_BaseAsset)                              // [2..4]
    std::uint8_t m_unknown18[0x18];                       // +0x18 AssetProfiles accessor
    bool m_isDynamic;                                     // +0x30 RTTR "IsDynamic"
    std::uint8_t _pad31[7];                               // +0x31
};

static_assert(offsetof(C_ProfileAsset, m_unknown18) == 0x18,
              "C_ProfileAsset::m_unknown18 offset mismatch");
static_assert(offsetof(C_ProfileAsset, m_isDynamic) == 0x30,
              "C_ProfileAsset::m_isDynamic offset mismatch");
static_assert(sizeof(C_ProfileAsset) == 0x38,
              "C_ProfileAsset size mismatch");

}  // namespace wh::conceptmodule
