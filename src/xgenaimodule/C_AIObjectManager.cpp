#include "xgenaimodule/C_AIObjectManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_AIObjectManager* C_AIObjectManager::GetInstance()
{
    using Fn = C_AIObjectManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(170585) }; // sub_181A9DC40
    return fn();
}

C_AIObject* C_AIObjectManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_AIObject* (__fastcall*)(C_AIObjectManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(27380) }; // sub_18047C1F8
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
