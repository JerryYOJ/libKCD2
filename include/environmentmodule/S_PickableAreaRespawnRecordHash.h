#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include "S_PickableAreaRespawnRecord.h"
#include "../framework/HashPrimitives.h"

// Binary-equivalent hash policy for C_RespawnManager's respawn-record set. [SYNTHETIC NAME]

namespace wh::environmentmodule {

struct S_PickableAreaRespawnRecordHash {
    std::size_t operator()(const S_PickableAreaRespawnRecord& record) const noexcept {
        const auto hashFloat = [](float value) noexcept {
            const float normalized = value == 0.0f ? 0.0f : value;
            return wh::shared::fnv1a(&normalized, sizeof(normalized));
        };

        uint64_t hash = hashFloat(record.position.x) * 2;
        hash = (hash ^ hashFloat(record.position.y)) * 2;
        hash = (hash ^ hashFloat(record.position.z)) * 2;
        hash = (hash ^ hashFloat(record.radius)) * 2;
        return static_cast<std::size_t>(
            hash ^ wh::shared::fnv1a(&record.pickable_area_id,
                                     sizeof(record.pickable_area_id)));
    }
};
static_assert(std::is_empty<S_PickableAreaRespawnRecordHash>::value,
              "respawn-record hash policy must remain empty");

}  // namespace wh::environmentmodule
