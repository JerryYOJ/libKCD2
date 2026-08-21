#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseRoadPoint -- KCD2 WHGame.dll.
// -----------------------------------------------
// [SYNTHETIC] road-graph vertex consumed by sub_180A0A124 / sub_180A0B38C.
// No TypeDescriptor. Pointers stored on S_HorseMagnetismSample +0x18/+0x20.
// m_id == -1 means unresolved; lookup is (m_lookupKey, m_lookupIdx).

namespace wh::entitymodule {

struct S_HorseRoadPoint {
    Vec3     m_pos;        // +0x00  12-byte subtract in 0x180A0A124
    float    m_w;          // +0x0C  sits before the handle (unread here)
    uint64_t m_lookupKey;  // +0x10  arg0 of 0x1834169B4
    uint64_t m_q18;        // +0x18  unread in magnetism tick
    uint32_t m_lookupIdx;  // +0x20  arg1 of 0x1834169B4
    uint32_t _pad24;       // +0x24
    int32_t  m_id;         // +0x28  pushed into path vector; -1 = unresolved
};
static_assert(offsetof(S_HorseRoadPoint, m_lookupKey) == 0x10, "lookup key");
static_assert(offsetof(S_HorseRoadPoint, m_lookupIdx) == 0x20, "lookup idx");
static_assert(offsetof(S_HorseRoadPoint, m_id) == 0x28, "id");

}  // namespace wh::entitymodule
