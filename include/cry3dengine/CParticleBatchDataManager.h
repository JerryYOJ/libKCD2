#pragma once
#include <cstdint>
#include <cstddef>
#include "../Offsets/vtables/IParticleManager.h"
#include "Cry3DEngineBase.h"

// -----------------------------------------------
// CParticleBatchDataManager : IParticleManager -- update-batch storage
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x168.
// -----------------------------------------------
// RTTI mdisp 8 of CParticleManager. ctor sub_180D24D4C writes vtable
// 0x183A96A80 then constructs 4 elements of stride 0x58 at +0x08.
// IParticleManager `this` IS this object (gEnv->pParticleManager).

class CParticleBatchDataManager : public Offsets::IParticleManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CParticleBatchDataManager;
    uint8_t m_batches[4][0x58];   // +0x08  four 0x58 batch slots [interior UNVERIFIED]
};
static_assert(sizeof(CParticleBatchDataManager) == 0x168, "4*0x58 + vptr = 0x168");
static_assert(offsetof(CParticleBatchDataManager, m_batches) == 0x08, "batch array at +0x08");
