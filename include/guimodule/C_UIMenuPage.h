#pragma once
#include <cstdint>
#include "guimodule/E_MenuPage.h"
#include "framework/C_LocalizedString.h"

// -----------------------------------------------
// wh::guimodule::C_UIMenuPage -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x30 (ALLOC-PROVEN).
// -----------------------------------------------
// rttr-reflected data class, element type of C_MenuPageDatabase ("menu_pages" tree DB).
// vtable 0x183BF57D0 = RTTR trio ONLY, no virtual dtor. Creator sub_182BA428C (operator
// new 48); default ctor sub_1816D9514, copy ctor sub_1816D947C.
// rttr props: int (x4), C_LocalizedString, E_MenuPage::Type. The int defaults
// (1500/370/8/196) read like page layout coordinates -- name mapping UNVERIFIED.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class C_UIMenuPage {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIMenuPage;
    // RTTR_ENABLE() trio -- the WHOLE vtable ([0..2]); no virtual dtor.
    virtual rttr::type get_type() const;                     // [0]
    virtual void* get_ptr();                                 // [1] 0x1805F5DA0
    virtual rttr::detail::derived_info get_derived_info();   // [2]

    E_MenuPage::Type m_pageId;                 // +0x08  identity key (DefaultKeyExtractor), ctor 0
    uint8_t _pad09[7];                         // +0x09
    wh::framework::C_LocalizedString m_text;   // +0x10  localized text [name INFERRED]
    int32_t m_int20;                           // +0x20  rttr int prop, default 1500 [name UNVERIFIED]
    int32_t m_int24;                           // +0x24  rttr int prop, default 370  [name UNVERIFIED]
    int32_t m_int28;                           // +0x28  rttr int prop, default 8    [name UNVERIFIED]
    int32_t m_int2C;                           // +0x2C  rttr int prop, default 196  [name UNVERIFIED]
};
static_assert(sizeof(C_UIMenuPage) == 0x30, "C_UIMenuPage must be 0x30 (creator sub_182BA428C)");

}  // namespace wh::guimodule
