#include "conceptmodule/C_PortRef.h"

#include "REL.h"

namespace wh::conceptmodule {

_smart_ptr<I_Port> C_PortRef::Resolve()
{
    // Member this-first-then-sret ABI: RCX=this, RDX=out (stored on every
    // path -- the cache short-circuit and the cold lookup both construct it).
    using Ret = _smart_ptr<I_Port>;
    using Fn = Ret*(__fastcall*)(C_PortRef*, Ret*);
    static REL::Relocation<Fn> fn{ REL::ID(37348) };  // 0x1806B1118
    Ret result;
    fn(this, &result);
    return result;
}

}  // namespace wh::conceptmodule
