#include "xgenaimodule/C_ParticleEffectPuppetManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_ParticleEffectPuppetManager* C_ParticleEffectPuppetManager::GetInstance()
{
    static REL::Relocation<C_ParticleEffectPuppetManager**> instance{ REL::ID(1270289) }; // qword_1854961A8
    return *instance;
}

C_ParticleEffectPuppet* C_ParticleEffectPuppetManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_ParticleEffectPuppet* (__fastcall*)(C_ParticleEffectPuppetManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(389603) }; // sub_1830BE94C
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
