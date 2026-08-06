#include "conceptmodule/C_ObjectProperties.h"

#include <string>

#include "REL.h"

namespace wh::conceptmodule {

void C_ObjectProperties::SetDeclaringType(std::string name)
{
    // 0x18106FFF4 -- resolves the name (sub_1806A589C), stores it at +0x40 and
    // the derived display name at +0x48. std::string is BY VALUE for the same
    // reason as C_TemplatedNode::SetTypeT: the callee destroys the argument on
    // exit (release @0x181070082).
    using Fn = void (__fastcall*)(C_ObjectProperties*, std::string);
    static REL::Relocation<Fn> fn{ REL::ID(90074) };
    fn(this, std::move(name));
}

}  // namespace wh::conceptmodule
