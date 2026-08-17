#pragma once
#include "IRenderNode.h"
#include "../../cry3dengine/S_ParticleSpawnParams.h"

// -----------------------------------------------
// IParticleEmitter : IRenderNode -- CryEngine particle emitter, KCD2 binary
// slot order (impl CParticleEmitter).  94 slots (0-93; next qword is not .text).
// -----------------------------------------------
// Target: WHGame.dll 1.5.6.  CParticleEmitter vtable 0x183A55F48.
// IRenderNode owns [0..72]; this interface adds [73..93]. Interfuscated --
// SDK IParticles.h order is NOT this order. CMultiThreadRefCount is a SECOND
// base at +0x50 (not part of this vtable).

namespace Offsets {

struct IParticleEffect;
struct IEntity;

struct IParticleEmitter : public IRenderNode {
    // [73] 0x181A72470  returns 1 -- IsInstant hypothesis [UNVERIFIED]
    virtual bool IsInstant() const = 0;
    // [74] 0x1805D6014  age/end-age test
    virtual bool IsAlive() const = 0;
    // [75] 0x180422664  true = emit+self-delete when done; false = freeze emission
    virtual void Activate(bool active) = 0;
    // [76] 0x180AC09F0  instant remove (also IParticleManager::DeleteEmitter)
    virtual void Kill() = 0;
    // [77] 0x180421B20  jump to equilibrium (sentinel ages)
    virtual void Prime() = 0;
    // [78] 0x180422EBC  assign m_pEffect @+0xF0
    virtual void SetEffect(IParticleEffect* effect) = 0;
    // [79] ICF-folded getter -- GetEffect [INFERRED]
    virtual IParticleEffect* GetEffect() const = 0;
    // [80] 0x183507B28  GeomRef @+0xB0
    virtual void SetGeomRef(const void* geom) = 0;
    // [81] 0x180738FFC  copies SpawnParams into +0x110 (PulsePeriod at +0x18)
    virtual void SetSpawnParams(const S_ParticleSpawnParams& params) = 0;
    // [82] 0x1835012EC  copies +0x110 out
    virtual void GetSpawnParams(S_ParticleSpawnParams& out) const = 0;
    // [83] 0x180F56CC0  m_pEntity @+0x1E0, slot @+0x1D8
    virtual void SetEntity(IEntity* entity, int slot) = 0;
    // [84] 0x1835015BC  drop entity association
    virtual void ClearEntity() = 0;
    // [85] 0x181AADF80  sret QuatTS from +0x70
    virtual QuatTS GetLocation() const = 0;
    // [86] 0x180423E80  write QuatTS to +0x70
    virtual void SetLocation(const QuatTS& loc) = 0;
    // [87] 0x183507C60  ParticleTarget @+0x188 (0x20)
    virtual void SetTarget(const void* target) = 0;
    // [88] 0x1805D5D18  per-frame emitter tick
    virtual void Update() = 0;
    // [89] 0x183500080  programmatic emit
    virtual void EmitParticle(const void* data) = 0;
    // [90] 0x1835005DC  entity->GetId()
    virtual unsigned GetAttachedEntityId() const = 0;
    // [91] 0x181AADEF0  slot @+0x1D8
    virtual int GetAttachedEntitySlot() const = 0;
    virtual void _vf92() = 0;   // [92] 0x1835005F4
    virtual uint8_t _vf93() = 0; // [93] 0x181AADFB0  byte @+0x150
};

}  // namespace Offsets
