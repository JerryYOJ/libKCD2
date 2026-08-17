#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::entitymodule {

// Runtime-prefab auto-phase schedule record; canonical native name OPEN.
struct S_RuntimePrefabAutoPhaseEntry {
    std::int64_t m_timeOfDayMs; // +0x00, constrained to one 86,400,000 ms day
    CryGUID m_prefabGuid;       // +0x08, resolved from category and phase number
};
static_assert(sizeof(S_RuntimePrefabAutoPhaseEntry) == 0x18,
              "S_RuntimePrefabAutoPhaseEntry must be 0x18");
static_assert(offsetof(S_RuntimePrefabAutoPhaseEntry, m_timeOfDayMs) == 0x00,
              "time of day must be at 0x00");
static_assert(offsetof(S_RuntimePrefabAutoPhaseEntry, m_prefabGuid) == 0x08,
              "prefab GUID must be at 0x08");

}  // namespace wh::entitymodule
