#include "conceptmodule/C_Node.h"
#include "conceptmodule/I_Port.h"
#include "Offsets/Offsets.h"

namespace wh::conceptmodule {

_smart_ptr<I_Port> C_Node::FindPortByName(CryStringT<char> const& name)
{
    using Ret = _smart_ptr<I_Port>;
    using Fn = Ret*(__fastcall*)(C_Node*, Ret*, CryStringT<char> const&);
    static REL::Relocation<Fn> fn{ REL::ID(36673) };
    Ret result;
    fn(this, &result, name);
    return result;
}

_smart_ptr<I_Port> C_Node::GetOrCreatePort(CryStringT<char> const& name)
{
    using Ret = _smart_ptr<I_Port>;
    using Fn = Ret*(__fastcall*)(C_Node*, Ret*, CryStringT<char> const&);
    static REL::Relocation<Fn> fn{ REL::ID(36672) };
    Ret result;
    fn(this, &result, name);
    return result;
}

bool C_Node::AddPort(_smart_ptr<I_Port> port)
{
    using Fn = bool(__fastcall*)(C_Node*, _smart_ptr<I_Port>);
    static REL::Relocation<Fn> fn{ REL::ID(36606) };
    return fn(this, port);
}

void ConnectPorts(_smart_ptr<I_Port> source, _smart_ptr<I_Port> target)
{
    using Fn = void(__fastcall*)(_smart_ptr<I_Port>, _smart_ptr<I_Port>);
    static REL::Relocation<Fn> fn{ REL::ID(36639) };
    fn(source, target);
}

void WakeGraph(C_Node* root, E_NodeWakeReason reason)
{
    using Fn = void(__fastcall*)(C_Node*, E_NodeWakeReason);
    static REL::Relocation<Fn> fn{ REL::ID(36528) };
    fn(root, reason);
}

void HibernateGraph(C_Node* root, E_NodeHibernateReason reason)
{
    using Fn = void(__fastcall*)(C_Node*, E_NodeHibernateReason);
    static REL::Relocation<Fn> fn{ REL::ID(58513) };
    fn(root, reason);
}

}  // namespace wh::conceptmodule
