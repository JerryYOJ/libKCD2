#pragma once

#include <unordered_map>
#include "C_ParticleEffect.h"
#include "../framework/HashPrimitives.h"
#include "../framework/I_WUIDMappingProvider.h"

namespace wh::xgenaimodule {

class C_ParticleEffectManager : public framework::I_WUIDMappingProvider {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ParticleEffectManager;
    static C_ParticleEffectManager* GetInstance();
    C_ParticleEffect* FindByWuid(const framework::WUID& wuid);

    framework::WUID GetWuidForKey(const CryGUID& key) const override; // [0] sub_1832A96F0
    CryGUID GetValueForWuid(framework::WUID wuid) const override;     // [1] sub_1832A96AC

    std::unordered_map<framework::WUID, C_ParticleEffect,
                       shared::S_DefaultHash<framework::WUID>> m_effectsByWuid; // +0x08
    std::uint64_t m_unknown48;
};
static_assert(sizeof(C_ParticleEffectManager) == 0x50, "C_ParticleEffectManager must be 0x50");

}  // namespace wh::xgenaimodule
