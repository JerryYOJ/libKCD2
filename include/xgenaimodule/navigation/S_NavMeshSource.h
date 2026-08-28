#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include "../../CryEngine/CryCommon/CryString.h"
#include "S_GroupCombinationNavMeshId.h"

namespace wh::xgenaimodule::navigation {

struct S_NavMeshSource {
    std::optional<CryStringT<char>> GetProfileId() const;    // 0x18341B08C
    void SetProfileId(std::optional<CryStringT<char>> value); // 0x18074CC6C
    std::optional<bool> GetIsBaseProfile() const;            // 0x18341B15C
    void SetIsBaseProfile(std::optional<bool> value);        // 0x18074BDD4

    std::uint16_t m_profileId;                               // +0x00 accessor backing; FFFF absent, FFFE base
    S_GroupCombinationNavMeshId m_groupCombinationId;        // +0x02 RTTR "GroupCombinationId"
    std::uint16_t m_unknown06;                               // +0x06
};

static_assert(offsetof(S_NavMeshSource, m_groupCombinationId) == 0x02,
              "S_NavMeshSource::m_groupCombinationId offset mismatch");
static_assert(sizeof(S_NavMeshSource) == 0x08,
              "S_NavMeshSource size mismatch");

}  // namespace wh::xgenaimodule::navigation
