#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::framework {

class C_GameplayManager {
public:
    std::uint8_t m_unknown00[0x18];
};

static_assert(sizeof(C_GameplayManager) == 0x18,
              "C_GameplayManager size mismatch");

}  // namespace wh::framework
