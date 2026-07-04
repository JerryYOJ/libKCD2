#pragma once
#include <cstdint>
#include "I_Port.h"

// -----------------------------------------------
// wh::conceptmodule::C_PortRef -- port reference (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Ctor sub_1806B2890: I_Port chain (sub_1806B28F0), own vftable, +0x30 = 0.  Embedded in
// conceptmodule::C_Effect and its subclasses as C_TypedPortRef<T>/C_TypedArrayPortRef<T>
// members with a 0x40 stride.

namespace wh::conceptmodule {

class C_PortRef : public I_Port {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PortRef;
    uint8_t m_flag30;    // +0x30  ctor 0 [role UNVERIFIED]
    uint8_t _pad31[7];   // +0x31
};
static_assert(sizeof(C_PortRef) == 0x38, "C_PortRef must be 0x38");

}  // namespace wh::conceptmodule
