#pragma once
#include <cstdint>
#include "guimodule/E_ButtonId.h"
#include "framework/C_LocalizedString.h"

// -----------------------------------------------
// wh::guimodule::C_UIMenuButton -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x78 (ALLOC-PROVEN).
// -----------------------------------------------
// rttr-reflected data class, element type of C_MenuButtonDatabase ("menu_buttons" tree DB,
// deserialized from XML by class name -- NOT a table row). vtable 0x183AB1A70 = RTTR trio
// ONLY, no virtual dtor. Creator sub_182B851BC (operator new 120); batch ctor sub_180DC1400
// (memset 0x78); default ctor sub_180DC1444, copy ctor sub_180DC1488, get_type sub_181A6CB10.
// rttr props: int, C_LocalizedString (x2, one wrapper TD), E_ButtonId::Type. Member NAMES
// are inferred from the property types/semantics (registrar strings not located -- G4d §UNVERIFIED).

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class C_UIMenuButton {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIMenuButton;
    // RTTR_ENABLE() trio -- the WHOLE vtable ([0..2]); no virtual dtor.
    virtual rttr::type get_type() const;                     // [0] sub_181A6CB10
    virtual void* get_ptr();                                 // [1] 0x1805F5DA0
    virtual rttr::detail::derived_info get_derived_info();   // [2]

    E_ButtonId::Type m_buttonId;               // +0x08  identity key (DefaultKeyExtractor)
    uint8_t _pad09[7];                         // +0x09
    wh::framework::C_LocalizedString m_textA;  // +0x10  localized text [name INFERRED]
    wh::framework::C_LocalizedString m_textB;  // +0x20  localized text [name INFERRED]
    int32_t m_int30;                           // +0x30  rttr int prop [name UNVERIFIED]
    uint8_t _pad34[4];                         // +0x34
    uint8_t m_actionHolder[0x40];              // +0x38  move-managed small-object holder (buffer +0x38..+0x70, manager ptr @+0x70; relocated by sub_18042DC90) -- runtime button callback, NOT an rttr prop [internal layout UNVERIFIED]
};
static_assert(sizeof(C_UIMenuButton) == 0x78, "C_UIMenuButton must be 0x78 (creator sub_182B851BC)");
static_assert(offsetof(C_UIMenuButton, m_actionHolder) == 0x38, "action holder at 0x38");

}  // namespace wh::guimodule
