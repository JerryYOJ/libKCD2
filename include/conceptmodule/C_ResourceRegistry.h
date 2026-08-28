#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::conceptmodule {

class C_ResourceRegistry {
public:
    C_ResourceRegistry();                                    // 0x180BE97D8
    ~C_ResourceRegistry();
    RTTR_ENABLE()                                             // [0..2]

    std::uint8_t m_unknown08[0x40];                           // +0x08 MSVC std::unordered_map; key/value specialization is not referenced by the binary
};

static_assert(offsetof(C_ResourceRegistry, m_unknown08) == 0x08,
              "C_ResourceRegistry::m_unknown08 offset mismatch");
static_assert(sizeof(C_ResourceRegistry) == 0x48,
              "C_ResourceRegistry size mismatch");

}  // namespace wh::conceptmodule
