#include "xgenaimodule/navigation/S_PathFindingRequestDefault.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule::navigation {

S_PathFindingRequestDefault::S_PathFindingRequestDefault()
{
    // 0x18087A060 -- leaf ctor (vptr 0x183A597C8 + base ctor).  Overwrites the
    // MSVC-emitted vptr with the game's so FindPath dispatches game virtuals.
    using Fn = S_PathFindingRequestDefault*(__fastcall*)(S_PathFindingRequestDefault*);
    static REL::Relocation<Fn> fn{ REL::ID(46454) };
    fn(this);
}

}  // namespace wh::xgenaimodule::navigation
