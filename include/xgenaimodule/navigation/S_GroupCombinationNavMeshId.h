#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::xgenaimodule::navigation {

struct S_GroupCombinationNavMeshId {
    std::uint16_t m_groupId;                                // +0x00 accessor backing "GroupId"; 0xFFFF absent
    std::uint16_t m_index;                                  // +0x02 accessor backing "Index"
};

static_assert(offsetof(S_GroupCombinationNavMeshId, m_groupId) == 0x00,
              "S_GroupCombinationNavMeshId::m_groupId offset mismatch");
static_assert(offsetof(S_GroupCombinationNavMeshId, m_index) == 0x02,
              "S_GroupCombinationNavMeshId::m_index offset mismatch");
static_assert(sizeof(S_GroupCombinationNavMeshId) == 0x04,
              "S_GroupCombinationNavMeshId size mismatch");

}  // namespace wh::xgenaimodule::navigation
