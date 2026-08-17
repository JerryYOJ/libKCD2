#pragma once
#include <cstdint>

// -----------------------------------------------
// IParticleManager -- CryEngine particle manager, KCD2 binary slot order
// (impl CParticleManager+8 / CParticleBatchDataManager).  45 slots (0-44).
// -----------------------------------------------
// Target: WHGame.dll 1.5.6.  Subobject vtable 0x18402AE90.
// ACCESS: gEnv->pParticleManager (+0x70).  `this` is the +8 subobject
// (bodies do this-8 to reach CParticleManager).

namespace Offsets {

struct IParticleEffect;
struct IParticleEmitter;

struct IParticleManager {
    virtual ~IParticleManager() = default;                                 // [0] 0x18213D7F0
    virtual IParticleEffect* CreateEffect(const char* name) = 0;           // [1] 0x183507A54  alloc 0x40
    virtual void _vf2() = 0;                                               // [2] 0x181A72750
    virtual IParticleEffect* _vf3(const char* name) = 0;                   // [3] 0x1809D8E18  looked up from ctor
    virtual void _vf4() = 0;                                               // [4] 0x1834FF8D0
    virtual void DeleteEffect(IParticleEffect* effect) = 0;                // [5] 0x180809234  unregisters if unused
    virtual IParticleEffect* FindEffect(const char* name, const char* source, bool load) = 0;  // [6] 0x180807EFC
    virtual IParticleEffect* LoadEffect(const char* name, void* xml, bool load, const char* source) = 0;  // [7] 0x18080A814
    virtual void _vf8() = 0;                                               // [8] 0x1808BD478
    virtual void _vf9() = 0;                                               // [9] 0x180D9E5CC
    virtual void _vf10() = 0;                                              // [10] 0x18080AC90
    virtual void _vf11() = 0;                                              // [11] 0x1835035E4
    virtual void _vf12() = 0;                                              // [12] 0x1835035EC
    virtual void _vf13() = 0;                                              // [13] 0x1834FF93C
    virtual void DeleteEmitter(IParticleEmitter* emitter) = 0;             // [14] 0x180ABEFDC  -> emitter->Kill()
    virtual void DeleteEmitters(void* predicate) = 0;                      // [15] 0x1834FFF0C  walks list, Kill()
    virtual void _vf16() = 0;
    virtual void _vf17() = 0;
    virtual void _vf18() = 0;
    virtual void _vf19() = 0;
    virtual void _vf20() = 0;
    virtual void _vf21() = 0;
    virtual void _vf22() = 0;
    virtual void _vf23() = 0;
    virtual void _vf24() = 0;
    virtual void _vf25() = 0;
    virtual void _vf26() = 0;
    virtual void _vf27() = 0;
    virtual void _vf28() = 0;
    virtual void _vf29() = 0;
    virtual void _vf30() = 0;
    virtual void _vf31() = 0;
    virtual void _vf32() = 0;
    virtual void _vf33() = 0;
    virtual void _vf34() = 0;
    virtual void _vf35() = 0;
    virtual void _vf36() = 0;
    virtual void _vf37() = 0;
    virtual void _vf38() = 0;
    virtual void _vf39() = 0;
    virtual void _vf40() = 0;
    virtual void _vf41() = 0;
    virtual void _vf42() = 0;
    virtual void _vf43() = 0;
    virtual void _vf44() = 0;
};

}  // namespace Offsets
