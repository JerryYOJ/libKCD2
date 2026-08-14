#include "shopmodule/C_ShopRegistry.h"
#include "Offsets/Offsets.h"

namespace wh::shopmodule {

C_Shop* C_ShopRegistry::FindByWuid(framework::WUID wuid)
{
    using Fn = C_Shop* (__fastcall*)(C_ShopRegistry*, framework::WUID);
    static REL::Relocation<Fn> fn{ REL::ID(65845) }; // sub_180C4865C
    return fn(this, wuid);
}

}  // namespace wh::shopmodule
