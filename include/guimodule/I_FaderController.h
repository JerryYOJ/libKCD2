#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::I_FaderController -- KCD2 WHGame.dll 1.5.6 (kd7u).  Pure interface, 8 slots.
// -----------------------------------------------
// RTTI .?AVI_FaderController@guimodule@wh@@ (TD 0x184CB0BA0). Screen-fade facade,
// implemented by C_FaderController (@+0x00, vtable 0x183A97220). Fade requests are
// keyed by a 64-bit FNV-1a id. Impl addrs: [1] 0x180C08E84 (fade helper, appends the
// default duration), [2] RequestFade 0x180C09498, [3] 0x180C09488, [4] CancelFade
// 0x180C09710. Method names [2]/[4] behavior-coined; [1]/[3] roles UNVERIFIED.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class I_FaderController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_FaderController;
    virtual ~I_FaderController();                            // [0]
    virtual void _vf1() = 0;                                 // [1] fade helper [role UNVERIFIED]
    virtual void RequestFade(uint64_t fadeId, int a3) = 0;   // [2] name coined; moves the id into the active-fade map
    virtual void _vf3() = 0;                                 // [3] role UNVERIFIED
    virtual void CancelFade(uint64_t fadeId) = 0;            // [4] name coined; removes the id from the active-fade map
    // RTTR_ENABLE() expansion.
    virtual rttr::type get_type() const;                     // [5] 0x182B3EB7C
    virtual void* get_ptr();                                 // [6] 0x1805F5DA0
    virtual rttr::detail::derived_info get_derived_info();   // [7] 0x182B3E650
};
static_assert(sizeof(I_FaderController) == 8);

}  // namespace wh::guimodule
