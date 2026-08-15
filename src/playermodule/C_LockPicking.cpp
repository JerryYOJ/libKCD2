#include "playermodule/C_LockPicking.h"
#include "Offsets/Offsets.h"

namespace wh::playermodule {

bool C_LockPicking::Start(uint32_t entityId)
{
    using Fn = char (__fastcall*)(C_LockPicking*, uint32_t);
    static REL::Relocation<Fn> fn{ REL::ID(47148) };  // 0x1808986A4
    return fn(this, entityId) != 0;
}

void C_LockPicking::CommitResult(bool success, bool skipLeave, void* rpgScratch)
{
    using Fn = void (__fastcall*)(C_LockPicking*, uint8_t, char, void*);
    static REL::Relocation<Fn> fn{ REL::ID(47176) };  // 0x180899568
    fn(this, success ? 1 : 0, skipLeave ? 1 : 0, rpgScratch);
}

}  // namespace wh::playermodule
