#include "xgenaimodule/C_SearchItemDogObjective.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule::activitysystem {

int64_t C_SearchItemDogObjective::CommitDestination(const Vec3& pos)
{
    using Fn = int64_t (__fastcall*)(C_SearchItemDogObjective*, const Vec3*);
    static REL::Relocation<Fn> fn{ REL::ID(406224) };  // 0x18330EF7C
    return fn(this, &pos);
}

int64_t C_SearchItemDogObjective::Fail()
{
    using Fn = int64_t (__fastcall*)(C_SearchItemDogObjective*);
    static REL::Relocation<Fn> fn{ REL::ID(406136) };  // 0x18330B484
    return fn(this);
}

}  // namespace wh::xgenaimodule::activitysystem
