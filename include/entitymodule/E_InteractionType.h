#pragma once
#include <cstdint>

// Native reflected enum wh::entitymodule::InteractionType.
namespace wh::entitymodule {

enum class E_InteractionType : std::int32_t {
    Press = 0,
    Hold = 1,
};

}  // namespace wh::entitymodule
