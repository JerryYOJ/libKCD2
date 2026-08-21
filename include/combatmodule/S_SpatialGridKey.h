#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::combatmodule {

struct S_SpatialGridKey {
    std::uint32_t m_entityId; // +0x00
    std::int32_t  m_variant;  // +0x04

    bool operator==(const S_SpatialGridKey& rhs) const noexcept {
        return m_entityId == rhs.m_entityId && m_variant == rhs.m_variant;
    }
};
static_assert(sizeof(S_SpatialGridKey) == 0x08);
static_assert(offsetof(S_SpatialGridKey, m_entityId) == 0x00);
static_assert(offsetof(S_SpatialGridKey, m_variant) == 0x04);

}  // namespace wh::combatmodule
