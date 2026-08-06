#include "conceptmodule/C_ModuleBase.h"
#include "Offsets/Offsets.h"

namespace wh::conceptmodule {

void AttachChild(_smart_ptr<C_Node> child, _smart_ptr<C_ModuleBase> parent)
{
    using Fn = void(__fastcall*)(
        void*, _smart_ptr<C_Node>, _smart_ptr<C_ModuleBase>);
    static REL::Relocation<Fn> fn{ REL::ID(65014) };
    fn(nullptr, child, parent);
}

void EraseChild(std::vector<_smart_ptr<C_Node>>& nodes,
                _smart_ptr<C_Node> const& child)
{
    using Fn = void(__fastcall*)(
        std::vector<_smart_ptr<C_Node>>&, _smart_ptr<C_Node> const&);
    static REL::Relocation<Fn> fn{ REL::ID(48287) };
    fn(nodes, child);
}

void SetParent(C_Node* child, _smart_ptr<C_ModuleBase> parent)
{
    using Fn = void(__fastcall*)(C_Node*, _smart_ptr<C_ModuleBase>);
    static REL::Relocation<Fn> fn{ REL::ID(327113) };
    fn(child, parent);
}

void StartGraph(C_ModuleBase* module)
{
    using Fn = void(__fastcall*)(C_ModuleBase*);
    static REL::Relocation<Fn> fn{ REL::ID(58536) };
    fn(module);
}

}  // namespace wh::conceptmodule
