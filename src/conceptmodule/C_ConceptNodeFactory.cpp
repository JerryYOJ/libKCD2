#include "conceptmodule/C_ConceptNodeFactory.h"
#include "Offsets/Offsets.h"

namespace wh::conceptmodule {

C_ConceptNodeFactory* C_ConceptNodeFactory::Ctor(
    C_ConceptGraphDeserializer* owner)
{
    // storage is a fresh, untyped allocation: the native ctor is invoked on
    // it directly, never through a real C++ constructor for this type (see
    // the header note on why that would double-construct member subobjects).
    void* storage = ::operator new(sizeof(C_ConceptNodeFactory));
    using Fn = void(__fastcall*)(
        C_ConceptNodeFactory*, C_ConceptGraphDeserializer*);
    static REL::Relocation<Fn> fn{ REL::ID(63053) };
    fn(static_cast<C_ConceptNodeFactory*>(storage), owner);
    return static_cast<C_ConceptNodeFactory*>(storage);
}

void C_ConceptNodeFactory::Dtor(C_ConceptNodeFactory* factory)
{
    if (!factory)
        return;
    using Fn = void(__fastcall*)(C_ConceptNodeFactory*);
    static REL::Relocation<Fn> fn{ REL::ID(63000) };
    fn(factory);
    ::operator delete(factory);
}

}  // namespace wh::conceptmodule
