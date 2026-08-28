#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/S_ResourceHandle.h"

namespace wh::playermodule {

class C_Blacksmithing;

struct S_BlacksmithingWorkpieceState {
    wh::framework::S_ResourceHandle m_handle; // +0x00
    std::int32_t m_unknown10;                 // +0x10, ctor -1
    std::uint32_t m_padding14;
    std::int64_t m_timestamp;                 // +0x18, ctor -100000
    std::uint64_t m_unknown20;                // +0x20
    std::uint64_t m_unknown28;                // +0x28
    CryStringT<char> m_name;                  // +0x30
    C_Blacksmithing* m_owner;                 // +0x38
};

static_assert(sizeof(S_BlacksmithingWorkpieceState) == 0x40,
              "S_BlacksmithingWorkpieceState size mismatch");
static_assert(offsetof(S_BlacksmithingWorkpieceState, m_timestamp) == 0x18,
              "S_BlacksmithingWorkpieceState timestamp offset mismatch");
static_assert(offsetof(S_BlacksmithingWorkpieceState, m_name) == 0x30,
              "S_BlacksmithingWorkpieceState name offset mismatch");

} // namespace wh::playermodule
