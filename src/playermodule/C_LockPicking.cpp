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

void C_LockPicking::StampLockpickTime()
{
    using Fn = void (__fastcall*)(C_LockPicking*);
    static REL::Relocation<Fn> fn{ REL::ID(47103) };  // 0x180897460
    fn(this);
}

void C_LockPicking::ResetPlayFields()
{
    using Fn = void (__fastcall*)(E_LockPickingState::Type*);
    static REL::Relocation<Fn> fn{ REL::ID(378543) };  // 0x182E93B90
    fn(&m_state);
}

void C_LockPicking::SetLockAngle(float angle)
{
    using Fn = void (__fastcall*)(C_LockPicking*, float);
    static REL::Relocation<Fn> fn{ REL::ID(47212) };  // 0x18089ADB0
    fn(this, angle);
}

void C_LockPicking::RestartPlayActions()
{
    using Fn = void (__fastcall*)(C_LockPicking*);
    static REL::Relocation<Fn> fn{ REL::ID(47177) };  // 0x180899790
    fn(this);
}

}  // namespace wh::playermodule
