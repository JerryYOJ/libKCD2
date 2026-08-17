#pragma once
#include <cstdint>
#include "../../CryEngine/CryCommon/Cry_Math.h"   // QuatTS

// -----------------------------------------------
// IParticleEffect -- CryEngine particle-effect asset, KCD2 binary slot order
// (impl CParticleEffect).  28 slots (0-27; slot 28 is the next COL).
// -----------------------------------------------
// Target: WHGame.dll 1.5.6.  CParticleEffect vtable 0x183A562C8.
// Interfuscated -- SDK IParticles.h slot order is NOT this order.

namespace Offsets {

struct IParticleEmitter;

struct IParticleEffect {
    virtual ~IParticleEffect() = default;                              // [0] 0x18080A68C
    virtual int AddRef() = 0;                                          // [1] 0x181A72640
    virtual int Release() = 0;                                         // [2] 0x1804A76F0
    virtual void _vf3() = 0;                                           // [3] 0x1825049D8
    virtual void _vf4() = 0;                                           // [4] 0x181A72470  returns 1
    virtual void _vf5() = 0;                                           // [5] 0x1834851F8
    virtual IParticleEmitter* Spawn(const QuatTS& loc, uint32_t flags) = 0;  // [6] 0x180422818
    virtual const char* SetName(const char* name) = 0;                 // [7] 0x180809AF8  writes +0x20
    virtual const char* GetName() const = 0;                           // [8] 0x1819A2A90  +0x20
    virtual void _vf9() = 0;                                           // [9] 0x1807A5F78
    virtual void _vf10() = 0;                                          // [10] 0x1808BD4A4
    virtual bool IsEnabled(unsigned flags) const = 0;                  // [11] 0x18065AC88
    virtual bool IsTemporary() const = 0;                              // [12] 0x1834856B8  name=="(Temporary)"
    virtual void _vf13() = 0;                                          // [13] 0x18348604C
    virtual void* GetParticleParams() = 0;                             // [14] 0x1804219C8  +0x28 or manager default
    virtual void _vf15() = 0;
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
};

}  // namespace Offsets
