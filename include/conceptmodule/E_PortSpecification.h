#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::conceptmodule::E_PortSpecification::Type -- concrete port-class
// discriminator (KCD2 WHGame.dll Steam 1.5.6, e4cp).
// -----------------------------------------------
// Identity, labels, values, and unsigned-byte underlying type are RTTR-proven.
// I_Port vslot 17 independently returns the same values with `mov al, N; ret`.

namespace wh::conceptmodule {

struct E_PortSpecification {
    enum Type : std::uint8_t {
        Unknown              = 0,
        InputDataPort        = 1,
        OutputDataPort       = 2,
        InterfaceDataPort    = 3,
        InputTriggerPort     = 4,
        OutputTriggerPort    = 5,
        InterfaceTriggerPort = 6,
    };
};
static_assert(sizeof(E_PortSpecification::Type) == 1,
              "E_PortSpecification::Type size mismatch");

}  // namespace wh::conceptmodule
