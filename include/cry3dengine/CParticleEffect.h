#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/CryArray.h"
#include "../CryEngine/CryCommon/smartptr.h"
#include "../Offsets/vtables/IParticleEffect.h"
#include "Cry3DEngineBase.h"

// -----------------------------------------------
// CParticleEffect : IParticleEffect -- named particle asset (KCD2 WHGame.dll 1.5.6).
// sizeof 0x40.
// -----------------------------------------------
// RTTI .?AVCParticleEffect@@.  vtable 0x183A562C8 (28 slots). ctor sub_18080A794
// (alloc 0x40 in CreateEffect/LoadEffect). Also : _i_multithread_reference_target
// (refcount @+0x08) and an intrusive list node @+0x10 (head qword_1854968E0).
// Cry3DEngineBase is EBO at +0x10.

struct ParticleParams;   // KCD2 sizeof 0x4A8 -- stock SDK ParticleParams.h layout does NOT match; never include it

class CParticleEffect : public Offsets::IParticleEffect, public Cry3DEngineBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CParticleEffect;
    int              m_nRefCounter;     // +0x08
    void*            m_pListNext;       // +0x10  intrusive list: stores peer NODE addresses (peer+0x10), not CParticleEffect* (same idiom as CMatInfo)
    void*            m_pListPrev;       // +0x18
    CryStringT<char> m_name;            // +0x20
    ParticleParams*  m_pParams;         // +0x28  owned (XML "Params", alloc 0x4A8); null -> manager default
    CParticleEffect* m_pParent;         // +0x30  nulled in each child by the parent's dtor
    DynArray<_smart_ptr<CParticleEffect>> m_children; // +0x38  SetParent inserts; dtor Releases each
};
static_assert(sizeof(CParticleEffect) == 0x40, "CParticleEffect alloc is 0x40");
static_assert(offsetof(CParticleEffect, m_name) == 0x20, "name at +0x20");
static_assert(offsetof(CParticleEffect, m_pParams) == 0x28, "params at +0x28");
