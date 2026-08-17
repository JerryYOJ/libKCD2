#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// SpawnParams -- per-emitter overrides (KCD2 WHGame.dll 1.5.6).  sizeof 0x48.
// -----------------------------------------------
// Copied by sub_1807390CC (byte-exact through +0x40). WH-extended vs the stock
// CE3 SpawnParams (which ends earlier and has no CryStringT). fPulsePeriod is
// at +0x18 (SetSpawnParams log "PulsePeriod %g too low"). Other float roles
// follow the stock order (count/size/speed/time/strength) [INFERRED].

struct S_ParticleSpawnParams {
    uint8_t          m_attachType;      // +0x00
    uint8_t          m_attachForm;      // +0x01
    uint8_t          m_countPerUnit;    // +0x02
    uint8_t          m_enableSound;     // +0x03
    uint8_t          m_registerByBBox;  // +0x04
    uint8_t          _pad05[3];         // +0x05
    float            m_countScale;      // +0x08
    float            m_sizeScale;       // +0x0C
    float            m_speedScale;      // +0x10
    float            m_timeScale;       // +0x14
    float            m_pulsePeriod;     // +0x18  0 = never auto-restart
    float            m_strength;        // +0x1C
    uint32_t         m_unk20;           // +0x20
    uint32_t         m_unk24;           // +0x24
    uint32_t         m_unk28;           // +0x28
    uint32_t         m_unk2C;           // +0x2C
    uint8_t          m_unk30;           // +0x30
    uint8_t          m_unk31;           // +0x31
    uint8_t          _pad32[2];         // +0x32
    uint32_t         m_unk34;           // +0x34
    CryStringT<char> m_unk38;           // +0x38
    uint8_t          m_unk40;           // +0x40
    uint8_t          _pad41[7];         // +0x41
};
static_assert(sizeof(S_ParticleSpawnParams) == 0x48, "WH SpawnParams copy is 0x48");
static_assert(offsetof(S_ParticleSpawnParams, m_pulsePeriod) == 0x18, "PulsePeriod at +0x18");
