#pragma once
#include <cstdint>
#include "guimodule/C_UIFlashObject.h"

// -----------------------------------------------
// wh::guimodule::C_UIFlashMapPoiMarker -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x38 (ALLOC-PROVEN).
// -----------------------------------------------
// C_UIFlashObject serialization record (flash_leaves.md §1). Creator sub_1815B9998
// N=72 (two ctor overloads 0x1815B9C20 / 0x1815B9D70). FillUIArgs override 0x18186152C.
// Names descriptive (UNVERIFIED).

namespace wh::guimodule {

class C_UIFlashMapPoiMarker : public C_UIFlashObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIFlashMapPoiMarker;
    void FillUIArgs(void* pArgs) const override;   // [1] 0x18186152C

    CryStringT<char> m_name;     // +0x18
    int32_t          m_type;     // +0x20  marker-STATE param (= S_EntityMapMark::m_param, ctor sub_1815B9D70 copies src+8), NOT E_MarkType (that lives in m_name); shared domain with C_CompassMark::m_state (2 = discovered/shown observed)
    bool             m_bool24;   // +0x24
    uint8_t          _pad25[3];  // +0x25
    int32_t          m_int28;    // +0x28
    float            m_x;        // +0x2C
    float            m_y;        // +0x30
    uint8_t          _pad34[4];  // +0x34
};
static_assert(sizeof(C_UIFlashMapPoiMarker) == 0x38, "C_UIFlashMapPoiMarker must be 0x38 (creator sub_1815B9998)");

}  // namespace wh::guimodule
