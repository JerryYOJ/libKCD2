#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::E_SubBrainType -- native subbrain descriptor/runtime kind.
// KCD2 WHGame.dll 1.5.6 (kd7u), underlying int32.
// -----------------------------------------------
// The concrete descriptor type virtuals and descriptor parser/factory prove values
// 0..5 and 7..10. No recovered descriptor, runtime subtype, parser branch, or factory
// entry uses value 6; the native domain therefore retains that hole.

namespace wh::xgenaimodule {

struct E_SubBrainType {
    enum Type : std::int32_t {
        BehaviorTree = 0,
        Situation = 1,
        Switching = 2,
        Dialog = 3,
        SmartArea = 4,
        SmartObject = 5,
        Default = 7,
        DogCompanion = 8,
        Scheduler = 9,
        Action = 10,
    };
};

}  // namespace wh::xgenaimodule
