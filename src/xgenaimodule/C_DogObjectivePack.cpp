#include "xgenaimodule/C_DogObjectivePack.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule::activitysystem {

C_DogObjective* C_DogObjectivePack::FindByType(E_DogObjective::Type type)
{
    using Fn = C_DogObjective* (__fastcall*)(C_DogObjectivePack*, E_DogObjective::Type);
    static REL::Relocation<Fn> fn{ REL::ID(54719) };  // 0x1809F6B90
    return fn(this, type);
}

}  // namespace wh::xgenaimodule::activitysystem
