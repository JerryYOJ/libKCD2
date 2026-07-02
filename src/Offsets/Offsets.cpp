#include "Offsets/Offsets.h"

uintptr_t Offsets::GetBase() {
    return REL::Module::get().base();
}

Offsets::IGameFramework* Offsets::GetCCryAction() {
    static REL::Relocation<IGameFramework**> p{ REL::Offset(0x549D328) };
    return *p;
}
