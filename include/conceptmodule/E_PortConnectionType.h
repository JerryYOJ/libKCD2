#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::conceptmodule::E_PortConnectionType -- how a pin gets its value
// (KCD2 WHGame.dll Steam 1.5.6, e4cp).
// -----------------------------------------------
// Registered RTTR enum (name string 0x183E39C68, reg sub_1800A5B00).
// Exact labels and values: Any=0, Constant=1, Edge=2. Surfaced on
// definition::I_PortDefinition as the "ConnectionType" property.

namespace wh::conceptmodule {

enum class E_PortConnectionType : std::int32_t {
    Any      = 0,
    Constant = 1,
    Edge     = 2,
};
static_assert(sizeof(E_PortConnectionType) == 4,
              "E_PortConnectionType size mismatch");

}  // namespace wh::conceptmodule
