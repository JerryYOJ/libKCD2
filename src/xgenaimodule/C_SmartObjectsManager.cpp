#include "xgenaimodule/C_SmartObjectsManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_SmartObjectsManager* C_SmartObjectsManager::GetInstance()
{
    static REL::Relocation<C_SmartObjectsManager**> instance{ REL::ID(1269055) }; // qword_185493D30
    return *instance;
}

}  // namespace wh::xgenaimodule
