#pragma once
#include <cstdint>

namespace wh::combatmodule {

struct E_CombatAlignmentType {
    enum Type : std::uint8_t {
        CombinedPositionRotationAlignment = 0,
        CombinedParentAlignment           = 1,
        AttackerPositionAlignment         = 2,
        AttackerRotationAlignment         = 3,
        CombinedPositionAlignment         = 4,
        CombinedRotationAlignment         = 5,
        AttackerPoseAlignment             = 6,
    };
};

}  // namespace wh::combatmodule
