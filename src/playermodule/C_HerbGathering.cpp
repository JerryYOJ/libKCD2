#include "playermodule/C_HerbGathering.h"
#include "REL/Relocation.h"

namespace wh::playermodule {

void C_HerbGathering::Start(uint32_t pickableAreaEntityId)
{
    using Fn = void(__fastcall*)(C_HerbGathering*, uint32_t);
    static REL::Relocation<Fn> fn{ REL::ID(378607) };
    fn(this, pickableAreaEntityId);
}

}  // namespace wh::playermodule
