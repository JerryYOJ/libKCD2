#include "xgenaimodule/C_DogObjective.h"
#include "xgenaimodule/C_DogObjectivePack.h"
#include "xgenaimodule/I_DogObjectiveContext.h"

namespace wh::xgenaimodule::activitysystem {

C_DogObjective* C_DogObjective::FindByType(E_DogObjective::Type type) const
{
    auto* pack = m_pContext ? m_pContext->GetObjectivePack() : nullptr;
    return pack ? pack->FindByType(type) : nullptr;
}

}  // namespace wh::xgenaimodule::activitysystem
