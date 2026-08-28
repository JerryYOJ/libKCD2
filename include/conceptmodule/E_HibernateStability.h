#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

struct E_HibernateStability {
    enum Type : std::uint8_t {
        KeepAll        = 0,
        KeepPersistent = 1,
        RemoveAll      = 2,
        SameAsParent   = 3,
    };
};
static_assert(sizeof(E_HibernateStability::Type) == 1, "E_HibernateStability::Type size mismatch");

}  // namespace wh::conceptmodule
