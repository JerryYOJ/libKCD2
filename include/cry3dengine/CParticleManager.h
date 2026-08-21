#pragma once
#include <cstdint>
#include <cstddef>
#include "../Offsets/vtables/IVisAreaCallback.h"
#include "CParticleBatchDataManager.h"
#include "Cry3DEngineBase.h"

// -----------------------------------------------
// CParticleManager : IVisAreaCallback, CParticleBatchDataManager
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x430.
// -----------------------------------------------
// RTTI .?AVCParticleManager@@.  Primary vtable 0x18402AE60 (IVisAreaCallback,
// 2 slots), IParticleManager vtable 0x18402AE90 @+0x08. ctor sub_180D25160,
// alloc 0x430 (C3DEngine::Init). Published as gEnv->pParticleManager = this+8.
// Cry3DEngineBase is EBO at +0x10 (first data of the batch manager).

class CParticleManager : public Offsets::IVisAreaCallback, public CParticleBatchDataManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CParticleManager;
    uint8_t m_tail[0x2C0];   // +0x170  name map @+0x1A8, emitter lists @+0x348, etc. [interior UNVERIFIED]
};
static_assert(sizeof(CParticleManager) == 0x430, "CParticleManager alloc is 0x430");
static_assert(offsetof(CParticleManager, m_tail) == 0x170, "own members start after the 0x168 batch manager");
