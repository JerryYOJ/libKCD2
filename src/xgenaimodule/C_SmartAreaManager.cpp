#include "xgenaimodule/C_SmartAreaManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_SmartAreaManager* C_SmartAreaManager::GetInstance()
{
    static REL::Relocation<C_SmartAreaManager**> instance{ REL::ID(1269001) }; // qword_185493BB0
    return *instance;
}

}  // namespace wh::xgenaimodule
