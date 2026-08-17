#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/SmartScriptTable.h"

struct IEntityClass;

struct SEntityRespawnData {
    Offsets::SmartScriptTable properties; // +0x00, retained handle
    Vec3 position;                        // +0x08
    Quat rotation;                        // +0x14
    Vec3 scale;                           // +0x24
    std::int32_t flags;                   // +0x30
    std::byte _pad34[0x04];               // +0x34
    IEntityClass* pClass;                 // +0x38, borrowed
};
static_assert(sizeof(SEntityRespawnData) == 0x40,
              "SEntityRespawnData must be 0x40");
static_assert(offsetof(SEntityRespawnData, pClass) == 0x38,
              "respawn entity class must be at 0x38");
