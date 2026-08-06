#include "conceptmodule/C_TemplatedNode.h"

#include <string>

#include "REL.h"

namespace wh::conceptmodule {

void C_TemplatedNode::SetTypeT(std::string name)
{
    // 0x1806A6FA4 -- type::get_by_name(name); valid -> m_typeT + OnTypeTSet(true),
    // else logs "unrecognized rttr template TypeT:'%s'" and leaves m_typeT alone.
    // std::string is BY VALUE on purpose: the callee destroys the argument at exit
    // (release @0x1806A704F), so a by-value C++ signature reproduces that ABI.
    using Fn = void (__fastcall*)(C_TemplatedNode*, std::string);
    static REL::Relocation<Fn> fn{ REL::ID(37004) };
    fn(this, std::move(name));
}

}  // namespace wh::conceptmodule
