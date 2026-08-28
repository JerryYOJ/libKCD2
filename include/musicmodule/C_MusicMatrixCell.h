#pragma once
#include <cstddef>
#include <cstdint>
#include <set>
#include "../rttr/rttr_enable.h"

namespace wh::musicmodule {

class C_MusicMatrixCell {
public:
    virtual ~C_MusicMatrixCell();                           // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::uint32_t m_worldStateToggleId;                     // +0x08 accessor backing "WorldStateToggle"
    std::uint8_t _pad0C[4];                                 // +0x0C
    std::set<std::uint32_t> m_playlist;                     // +0x10 accessor backing "Playlist"
};

static_assert(offsetof(C_MusicMatrixCell, m_worldStateToggleId) == 0x08,
              "C_MusicMatrixCell::m_worldStateToggleId offset mismatch");
static_assert(offsetof(C_MusicMatrixCell, m_playlist) == 0x10,
              "C_MusicMatrixCell::m_playlist offset mismatch");
static_assert(sizeof(C_MusicMatrixCell) == 0x20,
              "C_MusicMatrixCell size mismatch");

}  // namespace wh::musicmodule
