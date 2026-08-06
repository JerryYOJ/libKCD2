#include "conceptmodule/C_SharedResource.h"
#include "Offsets/Offsets.h"

namespace wh::conceptmodule {

void C_SharedResource::AddRef()
{
    using Fn = void(__fastcall*)(C_SharedResource*);
    static REL::Relocation<Fn> fn{ REL::ID(188831) };
    fn(this);
}

void C_SharedResource::Release()
{
    using Fn = void(__fastcall*)(C_SharedResource*);
    static REL::Relocation<Fn> fn{ REL::ID(188836) };
    fn(this);
}

}  // namespace wh::conceptmodule
