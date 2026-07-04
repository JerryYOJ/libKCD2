#pragma once
#include <cstdint>
#include <vector>

// -----------------------------------------------
// wh::guimodule::S_CutsceneProfile -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x28.
// -----------------------------------------------
// RTTI TD 0x184CB04C0; vtable 0x183B89598 = RTTR trio ONLY (get_type 0x180C2A074 /
// get_ptr 0x1805F5DA0 / get_derived_info 0x182B3E750), no virtual dtor. rttr-reflected
// cutscene/fader profiling record (see wh_ui_FaderProfiler* CVars). Layout from ctor
// sub_1814398A0 (others: sub_182B23390/sub_182B24988/sub_182B352A0). Roles UNVERIFIED.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class S_CutsceneProfile {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_CutsceneProfile;
    // RTTR_ENABLE() trio -- the WHOLE vtable ([0..2]); no virtual dtor.
    virtual rttr::type get_type() const;                     // [0] 0x180C2A074
    virtual void* get_ptr();                                 // [1] 0x1805F5DA0
    virtual rttr::detail::derived_info get_derived_info();   // [2] 0x182B3E750

    std::vector<uint64_t> m_entries;   // +0x08  (0x18) element type UNVERIFIED
    CryStringT<char>      m_name;      // +0x20  ctor empty [role UNVERIFIED]
};
static_assert(sizeof(S_CutsceneProfile) == 0x28, "S_CutsceneProfile must be 0x28 (ctor sub_1814398A0)");

}  // namespace wh::guimodule
