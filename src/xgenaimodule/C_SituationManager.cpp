#include "xgenaimodule/C_SituationManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_SituationManager* C_SituationManager::GetInstance()
{
    static REL::Relocation<C_SituationManager**> instance{ REL::ID(1268923) }; // qword_185493960
    return *instance;
}

C_Situation* C_SituationManager::FindByWuid(const framework::WUID& wuid)
{
    const auto it = m_situationsByWuid.find(wuid);
    return it != m_situationsByWuid.end() ? it->second : nullptr;
}

}  // namespace wh::xgenaimodule
