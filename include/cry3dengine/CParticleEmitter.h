#pragma once
#include <cstdint>
#include <cstddef>
#include "../Offsets/vtables/IParticleEmitter.h"
#include "../CryEngine/CryCommon/smartptr.h"   // CMultiThreadRefCount
#include "CParticleEffect.h"
#include "S_ParticleSpawnParams.h"
#include "Cry3DEngineBase.h"

// -----------------------------------------------
// CParticleEmitter : IParticleEmitter, CMultiThreadRefCount
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x260.
// -----------------------------------------------
// RTTI .?AVCParticleEmitter@@.  Primary vtable 0x183A55F48 (94 slots),
// CMultiThreadRefCount vtable 0x183A55F30 @+0x50. ctor sub_180422B18,
// pool stride 0x260 (qword_185503230). Further RTTI mixins (CParticleSource /
// STimeState @+0x64 / SMoveState @+0x70 / GeomRef @+0xB0) are modeled as
// members -- their empty/overlapping bases are EBO'd.

class CParticleEmitter : public Offsets::IParticleEmitter, public CMultiThreadRefCount {
public:
    uint32_t               m_sourcePad60;     // +0x60  _plain_reference_target
    float                  m_fAge;            // +0x64  STimeState
    float                  m_fEndAge;         // +0x68  far-future 0x4E6E6B28; Kill writes 0xCE6E6B28
    float                  m_fStopAge;        // +0x6C
    QuatTS                 m_loc;             // +0x70  SMoveState (SetLocation / GetLocation)
    uint8_t                _pad90[0x20];      // +0x90
    void*                  m_pStatObj;        // +0xB0  GeomRef
    void*                  m_pChar;           // +0xB8
    void*                  m_pPhysEnt;        // +0xC0
    uint8_t                _padC8[0x28];      // +0xC8  intrusive lists @+0xD0/+0xE0
    CParticleEffect*       m_pEffect;         // +0xF0  _smart_ptr
    void*                  m_unkF8;           // +0xF8
    uint32_t               m_unk100;          // +0x100
    uint32_t               _pad104;           // +0x104
    uint64_t               m_lastTimer;       // +0x108
    S_ParticleSpawnParams  m_spawnParams;     // +0x110
    float                  m_unk158;          // +0x158  ctor 1.0
    float                  m_unk15C;          // +0x15C  ctor 1.0
    void*                  m_pContainer;      // +0x160
    void*                  m_unk168;          // +0x168
    uint32_t               m_unk170;          // +0x170
    uint32_t               m_emitterFlags;    // +0x178  ePEF_* plus WH bits
    uint8_t                _pad17C[0xC];      // +0x17C
    uint8_t                m_target[0x20];    // +0x188  ParticleTarget
    uint8_t                _pad1A8[0x18];     // +0x1A8
    void*                  m_unk1C0;          // +0x1C0
    float                  m_unk1C8;          // +0x1C8  ctor 5.0
    uint32_t               m_unk1CC;          // +0x1CC
    float                  m_fKillAge;        // +0x1D0  Kill() writes 0xCE6E6B28
    uint32_t               _pad1D4;           // +0x1D4
    int                    m_entitySlot;      // +0x1D8  ctor -1
    uint32_t               _pad1DC;           // +0x1DC
    Offsets::IEntity*      m_pEntity;         // +0x1E0
    uint32_t               m_stateFlags;      // +0x1E8  bit 0x200 = has entity
    uint32_t               _pad1EC;           // +0x1EC
    uint8_t                _pad1F0[0x40];     // +0x1F0  subobject ctor sub_180422D0C
    uint8_t                m_locDirty;        // +0x230
    uint8_t                _pad231[0x2F];     // +0x231
};
static_assert(sizeof(CParticleEmitter) == 0x260, "CParticleEmitter pool stride is 0x260");
static_assert(offsetof(CParticleEmitter, m_loc) == 0x70, "location at +0x70");
static_assert(offsetof(CParticleEmitter, m_pEffect) == 0xF0, "effect at +0xF0");
static_assert(offsetof(CParticleEmitter, m_spawnParams) == 0x110, "spawn params at +0x110");
static_assert(offsetof(CParticleEmitter, m_pEntity) == 0x1E0, "entity at +0x1E0");
