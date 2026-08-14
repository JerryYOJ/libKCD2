#pragma once
#include <type_traits>
#include "S_PickableAreaRespawnRecord.h"

// Binary-equivalent equality policy for C_RespawnManager's respawn-record set. [SYNTHETIC NAME]

namespace wh::environmentmodule {

struct S_PickableAreaRespawnRecordEqual {
    bool operator()(const S_PickableAreaRespawnRecord& lhs,
                    const S_PickableAreaRespawnRecord& rhs) const noexcept {
        constexpr float positionToleranceSquared = 1.42108547e-14f;
        const float dx = lhs.position.x - rhs.position.x;
        const float dy = lhs.position.y - rhs.position.y;
        const float dz = lhs.position.z - rhs.position.z;

        return dx * dx + dy * dy + dz * dz <= positionToleranceSquared
            && lhs.radius == rhs.radius
            && lhs.pickable_area_id == rhs.pickable_area_id;
    }
};
static_assert(std::is_empty<S_PickableAreaRespawnRecordEqual>::value,
              "respawn-record equality policy must remain empty");

}  // namespace wh::environmentmodule
