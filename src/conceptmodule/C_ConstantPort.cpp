#include "conceptmodule/C_ConstantPort.h"
#include "Offsets/Offsets.h"

namespace wh::conceptmodule {

_smart_ptr<C_ConstantPort> CreateConstantPort(
    CryStringT<char> const& name, std::string const& value)
{
    _smart_ptr<C_ConstantPort> result;
    using Fn = _smart_ptr<C_ConstantPort>*(__fastcall*)(
        _smart_ptr<C_ConstantPort>*, CryStringT<char> const&,
        std::string const&);
    static REL::Relocation<Fn> fn{ REL::ID(37412) };
    fn(&result, name, value);
    return result;
}

}  // namespace wh::conceptmodule
