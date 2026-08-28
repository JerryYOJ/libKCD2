#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

struct E_VariableForm {
    enum Type : std::int32_t {
        Single            = 0,
        Array             = 1,
        Associative       = 2,
        CustomAssociative = 3,
    };
};
static_assert(sizeof(E_VariableForm::Type) == 4, "E_VariableForm::Type size mismatch");

}  // namespace wh::xgenaimodule
