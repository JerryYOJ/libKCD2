#pragma once
#include <cstdint>
#include "guimodule/E_ConfirmationId.h"
#include "framework/C_LocalizedString.h"

// -----------------------------------------------
// wh::guimodule::C_UIMenuConfirmation -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xC8 (ALLOC-PROVEN).
// -----------------------------------------------
// rttr-reflected data class, element type of C_MenuConfirmationDatabase
// ("menu_confirmations" tree DB). vtable 0x183A980D0 = RTTR trio ONLY, no virtual dtor.
// Creator sub_182BA41E8 (operator new 200, memset 0xC8); default ctor sub_180D2A15C,
// copy ctor sub_180D2A080.
// rttr props: int, C_LocalizedString (x3), E_ConfirmationId::Type. Member names inferred
// from types.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class C_UIMenuConfirmation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIMenuConfirmation;
    // RTTR_ENABLE() trio -- the WHOLE vtable ([0..2]); no virtual dtor.
    virtual rttr::type get_type() const;                     // [0]
    virtual void* get_ptr();                                 // [1] 0x1805F5DA0
    virtual rttr::detail::derived_info get_derived_info();   // [2]

    E_ConfirmationId::Type m_confirmationId;   // +0x08  identity key (DefaultKeyExtractor)
    uint8_t _pad09[7];                         // +0x09
    wh::framework::C_LocalizedString m_textA;  // +0x10  localized text [name INFERRED]
    wh::framework::C_LocalizedString m_textB;  // +0x20  localized text [name INFERRED]
    wh::framework::C_LocalizedString m_textC;  // +0x30  localized text [name INFERRED]
    int32_t m_int40;                           // +0x40  rttr int prop, ctor default 0 [name UNVERIFIED]
    int32_t m_int44;                           // +0x44  rttr int prop, ctor default 1 [name UNVERIFIED]
    uint8_t m_confirmHolder[0x40];             // +0x48  move-managed small-object holder (mgr ptr @+0x80; sub_18042DC90) -- runtime callback [layout UNVERIFIED]
    uint8_t m_cancelHolder[0x40];              // +0x88  move-managed small-object holder (mgr ptr @+0xC0) -- runtime callback [layout/role UNVERIFIED]
};
static_assert(sizeof(C_UIMenuConfirmation) == 0xC8, "C_UIMenuConfirmation must be 0xC8 (creator sub_182BA41E8)");
static_assert(offsetof(C_UIMenuConfirmation, m_confirmHolder) == 0x48, "first holder at 0x48");

}  // namespace wh::guimodule
