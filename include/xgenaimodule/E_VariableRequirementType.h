#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

struct E_VariableRequirementType {
    enum Type : std::uint8_t {
        ForwardDeclaration = 0,
        In                 = 1,
        Out                = 2,
        Reference          = 3,
        ConstReference     = 4,
        None               = 5,
    };
};
static_assert(sizeof(E_VariableRequirementType::Type) == 1, "E_VariableRequirementType::Type size mismatch");

}  // namespace wh::xgenaimodule
