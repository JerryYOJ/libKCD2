#include "xgenaimodule/C_ParticleEffectManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_ParticleEffectManager* C_ParticleEffectManager::GetInstance()
{
    using Fn = C_ParticleEffectManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(87412) }; // sub_180FF2EB8
    return fn();
}

C_ParticleEffect* C_ParticleEffectManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_ParticleEffect* (__fastcall*)(C_ParticleEffectManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(403531) }; // sub_1832A9480
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
