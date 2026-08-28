#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#include "../../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule::clothing {

struct S_Uberlod {
    CryStringT<char> m_components;                                     // +0x00 RTTR "Components"
    std::uint64_t m_unknown08;                                         // +0x08
    std::shared_ptr<void> m_unknown10;                                 // +0x10
    std::shared_ptr<void> m_unknown20;                                 // +0x20
    std::uint32_t m_unknown30;                                         // +0x30
    std::uint8_t m_padding34[4];                                       // +0x34
};

static_assert(offsetof(S_Uberlod, m_components) == 0x00,
              "S_Uberlod::m_components offset mismatch");
static_assert(offsetof(S_Uberlod, m_unknown10) == 0x10,
              "S_Uberlod::m_unknown10 offset mismatch");
static_assert(offsetof(S_Uberlod, m_unknown20) == 0x20,
              "S_Uberlod::m_unknown20 offset mismatch");
static_assert(sizeof(S_Uberlod) == 0x38,
              "S_Uberlod size mismatch");

} // namespace wh::entitymodule::clothing
