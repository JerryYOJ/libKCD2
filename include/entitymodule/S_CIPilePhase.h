#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule {

struct S_CIPilePhase {
    std::int32_t m_itemCountThreshold; // +0x00, semantic name reconstructed
    std::uint32_t _pad04;              // +0x04
    CryStringT<char> m_model;           // +0x08
};
static_assert(sizeof(S_CIPilePhase) == 0x10, "S_CIPilePhase must be 0x10");
static_assert(offsetof(S_CIPilePhase, m_model) == 0x08,
              "phase model must be at 0x08");

}  // namespace wh::entitymodule
