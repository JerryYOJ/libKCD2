#pragma once
#include <cstddef>
#include <cstdint>
#include <set>
#include "../rttr/rttr_enable.h"
#include "C_Address.h"

namespace wh::musicmodule {

class C_MusicMatrix {
public:
    RTTR_ENABLE()                                           // [0..2]

    C_Address m_playerAddress;                              // +0x08 accessor backing "PlayerAddress"
    C_Address m_unknown20;                                  // +0x20 embedded address, purpose unresolved
    std::set<std::uint32_t> m_playlist;                     // +0x38 accessor backing "Playlist"
    std::set<std::uint32_t> m_unknown48;                    // +0x48 purpose unresolved
};

static_assert(offsetof(C_MusicMatrix, m_playerAddress) == 0x08,
              "C_MusicMatrix::m_playerAddress offset mismatch");
static_assert(offsetof(C_MusicMatrix, m_unknown20) == 0x20,
              "C_MusicMatrix::m_unknown20 offset mismatch");
static_assert(offsetof(C_MusicMatrix, m_playlist) == 0x38,
              "C_MusicMatrix::m_playlist offset mismatch");
static_assert(offsetof(C_MusicMatrix, m_unknown48) == 0x48,
              "C_MusicMatrix::m_unknown48 offset mismatch");
static_assert(sizeof(C_MusicMatrix) == 0x58,
              "C_MusicMatrix size mismatch");

}  // namespace wh::musicmodule
