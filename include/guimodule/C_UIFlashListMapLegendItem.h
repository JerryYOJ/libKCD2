#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "guimodule/C_UIFlashObject.h"

// -----------------------------------------------
// wh::guimodule::C_UIFlashListMapLegendItem -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x40 (ALLOC-PROVEN).
// -----------------------------------------------
// C_UIFlashObject serialization record (flash_leaves.md §1). Creator sub_1815B9A60
// N=80 (ctor 0x1815B9B38). FillUIArgs override 0x1818AA90C. Names descriptive
// (UNVERIFIED); the +0x21 tail is ctor-only.

namespace wh::guimodule {

class C_UIFlashListMapLegendUniqueItem;   // RTTI .?AVC_UIFlashListMapLegendUniqueItem@guimodule@wh@@

class C_UIFlashListMapLegendItem : public C_UIFlashObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIFlashListMapLegendItem;
    void FillUIArgs(void* pArgs) const override;   // [1] 0x1818AA90C

    int32_t m_type;         // +0x18
    int32_t m_int1C;        // +0x1C
    bool    m_bool20;       // +0x20
    uint8_t _pad21[7];      // +0x21  alignment padding (ctor never writes +0x21..+0x27)
    std::vector<std::shared_ptr<C_UIFlashListMapLegendUniqueItem>> m_items;   // +0x28  (0x18) unique legend entries; shared_ptr built per POI by sub_1818994CC, emplaced when mark type==48
};
static_assert(sizeof(C_UIFlashListMapLegendItem) == 0x40, "C_UIFlashListMapLegendItem must be 0x40 (creator sub_1815B9A60)");

}  // namespace wh::guimodule
