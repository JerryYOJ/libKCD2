#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::combatmodule {

struct S_NextGuardRequest {
    std::int32_t m_combatGuardTypeId; // +0x00
    std::int32_t m_destinationZoneId; // +0x04
    std::int32_t m_comparisonZoneId;  // +0x08
    bool         m_forceImmediate;    // +0x0C
    bool         m_clinchMaster;      // +0x0D
    std::uint8_t _pad0E[2];           // +0x0E
};
static_assert(sizeof(S_NextGuardRequest) == 0x10);
static_assert(offsetof(S_NextGuardRequest, m_combatGuardTypeId) == 0x00);
static_assert(offsetof(S_NextGuardRequest, m_destinationZoneId) == 0x04);
static_assert(offsetof(S_NextGuardRequest, m_forceImmediate) == 0x0C);

}  // namespace wh::combatmodule
