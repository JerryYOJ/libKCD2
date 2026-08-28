#include "xgenaimodule/navigation/S_PathFindingRequestDefault.h"
#include "Offsets/Offsets.h"
#include "rttr/detail/derived_info.h"
#include "rttr/type.h"

namespace wh::xgenaimodule::navigation {

rttr::type S_PathFindingRequest::get_type() const
{
    using Fn = rttr::type*(__fastcall*)(const S_PathFindingRequest*, rttr::type*);
    static REL::Relocation<Fn> fn{ REL::ID(346667) };  // 0x1829F4040
    rttr::type result;
    fn(this, &result);
    return result;
}

void* S_PathFindingRequest::get_ptr()
{
    using Fn = void*(__fastcall*)(S_PathFindingRequest*);
    static REL::Relocation<Fn> fn{ REL::ID(16) };  // 0x1805F5DA0
    return fn(this);
}

rttr::detail::derived_info S_PathFindingRequest::get_derived_info()
{
    using Fn = rttr::detail::derived_info*(__fastcall*)(
        S_PathFindingRequest*, rttr::detail::derived_info*);
    static REL::Relocation<Fn> fn{ REL::ID(346662) };  // 0x1829F3FB0
    rttr::detail::derived_info result;
    fn(this, &result);
    return result;
}

rttr::type S_PathFindingRequestDefault::get_type() const
{
    using Fn = rttr::type*(__fastcall*)(
        const S_PathFindingRequestDefault*, rttr::type*);
    static REL::Relocation<Fn> fn{ REL::ID(124249) };  // 0x1815B92D8
    rttr::type result;
    fn(this, &result);
    return result;
}

void* S_PathFindingRequestDefault::get_ptr()
{
    using Fn = void*(__fastcall*)(S_PathFindingRequestDefault*);
    static REL::Relocation<Fn> fn{ REL::ID(16) };  // 0x1805F5DA0
    return fn(this);
}

rttr::detail::derived_info S_PathFindingRequestDefault::get_derived_info()
{
    using Fn = rttr::detail::derived_info*(__fastcall*)(
        S_PathFindingRequestDefault*, rttr::detail::derived_info*);
    static REL::Relocation<Fn> fn{ REL::ID(117126) };  // 0x181496D3C
    rttr::detail::derived_info result;
    fn(this, &result);
    return result;
}

S_PathFindingRequestDefault::S_PathFindingRequestDefault()
{
    // 0x18087A060 -- leaf ctor (vptr 0x183A597C8 + base ctor).  Overwrites the
    // MSVC-emitted vptr with the game's so FindPath dispatches game virtuals.
    using Fn = S_PathFindingRequestDefault*(__fastcall*)(S_PathFindingRequestDefault*);
    static REL::Relocation<Fn> fn{ REL::ID(46454) };
    fn(this);
}

}  // namespace wh::xgenaimodule::navigation
