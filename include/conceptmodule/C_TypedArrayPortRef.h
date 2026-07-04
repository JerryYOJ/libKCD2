#pragma once
#include <cstdint>
#include "C_PortRef.h"

// -----------------------------------------------
// wh::conceptmodule::C_TypedArrayPortRef<T> -- typed array port reference
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Instantiation seen: <std::vector<rpgmodule::I_Soul*>> (target-souls port @+0x88 of
// C_BuffEffect and C_TemporaryFactionEffect).  Same 0x40 embedded stride and ctor behavior
// as C_TypedPortRef.

namespace wh::conceptmodule {

template <typename T>
class C_TypedArrayPortRef : public C_PortRef {
public:
    uint64_t m_unk38;   // +0x38  never written by the ctor [UNVERIFIED]
};

}  // namespace wh::conceptmodule
