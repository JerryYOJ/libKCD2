#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>

namespace wh::xgenaimodule {

// [SOURCE-RECONSTRUCTED TYPE NAME]
// Trivial-value C_AnimalSpawner record; field widths, roles, and defaults are
// binary-certified even though the stripped native member spellings are open.
struct S_AnimalSpawnState {
    std::uint32_t m_respawnDay{}; // +0x00, absolute day; 0 = no delay
    std::uint32_t m_pendingOperationId{
        std::numeric_limits<std::uint32_t>::max()}; // +0x04, invalid sentinel
    EntityGUID m_entityGuid{}; // +0x08, 0 = no spawned entity
};

static_assert(sizeof(S_AnimalSpawnState) == 0x10,
              "S_AnimalSpawnState must be 0x10");
static_assert(offsetof(S_AnimalSpawnState, m_pendingOperationId) == 0x04,
              "pending operation id must be at 0x04");
static_assert(offsetof(S_AnimalSpawnState, m_entityGuid) == 0x08,
              "entity GUID must be at 0x08");

}  // namespace wh::xgenaimodule
