#pragma once
#include <cstdint>
#include "guimodule/E_ChoiceName.h"
#include "framework/C_LocalizedString.h"

// -----------------------------------------------
// wh::guimodule::C_UIMenuChoice -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x20 (ALLOC-PROVEN).
// -----------------------------------------------
// rttr-reflected data class, element type of C_MenuChoiceDatabase ("menu_choices" tree DB).
// vtable 0x183BF13C8 = RTTR trio ONLY, no virtual dtor. Creator sub_182B8525C (operator
// new 32); default ctor sub_1816B6FF4, copy ctor sub_1816B6F84.
// rttr props: C_LocalizedString, E_ChoiceName::Type. Member names inferred from types.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class C_UIMenuChoice {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIMenuChoice;
    // RTTR_ENABLE() trio -- the WHOLE vtable ([0..2]); no virtual dtor.
    virtual rttr::type get_type() const;                     // [0]
    virtual void* get_ptr();                                 // [1] 0x1805F5DA0
    virtual rttr::detail::derived_info get_derived_info();   // [2]

    E_ChoiceName::Type m_choiceName;           // +0x08  identity key (DefaultKeyExtractor)
    uint8_t _pad09[7];                         // +0x09
    wh::framework::C_LocalizedString m_text;   // +0x10  localized text [name INFERRED]
};
static_assert(sizeof(C_UIMenuChoice) == 0x20, "C_UIMenuChoice must be 0x20 (creator sub_182B8525C)");

}  // namespace wh::guimodule
