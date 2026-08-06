#include "conceptmodule/C_Project.h"
#include "Offsets/Offsets.h"

namespace wh::conceptmodule {

_smart_ptr<C_Project> CreateProject(const char* name)
{
    _smart_ptr<C_Project> result;
    using Fn = _smart_ptr<C_Project>*(__fastcall*)(
        _smart_ptr<C_Project>*, const char*);
    static REL::Relocation<Fn> fn{ REL::ID(63017) };
    fn(&result, name);
    return result;
}

}  // namespace wh::conceptmodule
