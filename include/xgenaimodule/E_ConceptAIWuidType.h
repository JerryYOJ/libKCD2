#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

struct E_ConceptAIWuidType {
    enum Type : std::uint8_t {
        LinkableObject = 0,
        Soul           = 1,
        SmartEntity    = 2,
        SmartArea      = 3,
        SmartObject    = 4,
        TriggerArea    = 5,
        AreaUnion      = 6,
        IArea          = 7,
        Item           = 8,
    };
};
static_assert(sizeof(E_ConceptAIWuidType::Type) == 1, "E_ConceptAIWuidType::Type size mismatch");

}  // namespace wh::xgenaimodule
