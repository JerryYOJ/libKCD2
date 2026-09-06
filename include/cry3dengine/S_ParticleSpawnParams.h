#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Geo.h"   // EGeomType / EGeomForm
#include "EAudioObjectObstructionCalcType.h"

// -----------------------------------------------
// SpawnParams -- per-emitter overrides (KCD2 WHGame.dll 1.5.6).  sizeof 0x48.
// -----------------------------------------------
// Ctor sub_180422DA4, copy sub_1807390CC (byte-exact; skipped ranges = genuine pads).
// Lives at CParticleEmitter+0x110 and particle-entity+0x70. WH uses the CE5-style
// order (bool cluster, six floats, seed/spec/attach/audio) -- the old header carried
// the stock CE3 order at +0x00..+0x04, which was WRONG (t1_045). [STRING] names come
// from the entity/Lua/editor serializers; bools without a per-field reader are
// CE5-isomorphic [INFERRED] (ctor defaults match bit-for-bit).

struct S_ParticleSpawnParams {
    bool             m_bPrime;           // +0x00  emitter ctor/SetSpawnParams run GetEquilibriumAge when set; entity "bPrime" mirror at entity+0x6E
    bool             m_bIgnoreVisAreas;  // +0x01  [INFERRED] CE5 order; no reader
    bool             m_bRegisterByBBox;  // +0x02  "bRegisterByBBox"
    bool             m_bNowhere;         // +0x03  [INFERRED] CE5 order; no reader
    bool             m_bPlaced;          // +0x04  [INFERRED] CE5 order; no reader
    bool             m_bIgnoreTerrainLayerBlend; // +0x05  [INFERRED] default-true pair per CE5
    bool             m_bIgnoreDecalBlend;        // +0x06  [INFERRED] default-true pair per CE5
    uint8_t          _pad07;             // +0x07  copy-gap
    float            m_countScale;       // +0x08
    float            m_sizeScale;        // +0x0C
    float            m_speedScale;       // +0x10
    float            m_timeScale;        // +0x14
    float            m_pulsePeriod;      // +0x18  0 = never auto-restart ("PulsePeriod %g too low")
    float            m_strength;         // +0x1C  ctor -1.0f
    int32_t          m_nSeed;            // +0x20  ctor -1
    uint32_t         m_eSpec;            // +0x24  EParticleSpec-shaped (Default=0); no enumerator strings in binary -- kept integral
    EGeomType        m_eAttachType;      // +0x28  "esAttachType" (BoundingBox=1/Physics=2/Render=3); change triggers emitter rebuild
    EGeomForm        m_eAttachForm;      // +0x2C  "esAttachForm" (ctor GeomForm_Surface)
    bool             m_bCountPerUnit;    // +0x30  "bCountPerUnit"; emitter multiplies count by geom extent
    bool             m_bEnableAudio;     // +0x31  "bEnableAudio" (ctor true)
    uint8_t          _pad32[2];          // +0x32  copy-gap
    EAudioObjectObstructionCalcType m_obstOcclCalcType; // +0x34  "esSoundObstructionType" (ctor Ignore)
    CryStringT<char> m_sAudioRTPC;       // +0x38  "audioRTPCRtpc"/"sAudioRTPC"
    bool             m_bLODUpdateEnabled; // +0x40  "bLODUpdateEnabled" (ctor true); WH extra vs CE5
    uint8_t          _pad41[7];          // +0x41  copy-gap tail
};
static_assert(sizeof(S_ParticleSpawnParams) == 0x48, "WH SpawnParams copy is 0x48");
static_assert(offsetof(S_ParticleSpawnParams, m_pulsePeriod) == 0x18, "PulsePeriod at +0x18");
static_assert(offsetof(S_ParticleSpawnParams, m_eAttachType) == 0x28, "attach type at +0x28");
static_assert(offsetof(S_ParticleSpawnParams, m_sAudioRTPC) == 0x38, "RTPC string at +0x38");
