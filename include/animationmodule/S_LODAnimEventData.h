#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::animationmodule {

// Source-reconstructed name; exact KCD2 animation-event payload copied by 0x180AE781C.
struct S_LODAnimEventData {
    float m_normalizedTime;                  // +0x00
    float m_normalizedEndTime;               // +0x04
    std::uint32_t m_eventNameLowercaseCRC32; // +0x08
    std::uint32_t m_flagsOrAux;              // +0x0C, role OPEN
    CryStringT<char> m_eventName;             // +0x10
    CryStringT<char> m_customParameter;       // +0x18
    std::int32_t m_boneOrAuxId;               // +0x20, role OPEN
    std::uint32_t _pad24;                     // +0x24
    CryStringT<char> m_boneName;              // +0x28, exact role/spelling OPEN
    Vec3 m_offset;                            // +0x30
    Vec3 m_direction;                         // +0x3C
    const void* m_pSourceEventData;           // +0x48, pointee type OPEN
};
static_assert(sizeof(S_LODAnimEventData) == 0x50,
              "LOD animation-event payload must be 0x50");
static_assert(offsetof(S_LODAnimEventData, m_eventName) == 0x10,
              "LOD event name must be at 0x10");
static_assert(offsetof(S_LODAnimEventData, m_offset) == 0x30,
              "LOD event offset must be at 0x30");
static_assert(offsetof(S_LODAnimEventData, m_pSourceEventData) == 0x48,
              "LOD source event pointer must be at 0x48");

}  // namespace wh::animationmodule
