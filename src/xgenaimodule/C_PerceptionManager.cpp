#include "xgenaimodule/C_PerceptionManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_PerceptionManager* C_PerceptionManager::GetInstance()
{
    using Fn = C_PerceptionManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(25561) }; // sub_180418170
    return fn();
}

}  // namespace wh::xgenaimodule
