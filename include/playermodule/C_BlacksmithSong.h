#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "C_BlacksmithTempo.h"

namespace wh::playermodule {

class C_BlacksmithSong {
public:
    RTTR_ENABLE()                                           // [0..2]

    bool m_usesBreath;                                      // +0x08 setter backing "Id"
    std::uint8_t _pad09[7];                                 // +0x09
    CryStringT<char> m_id;                                  // +0x10 accessor backing "Id"
    std::vector<C_BlacksmithTempo> m_tempos;                // +0x18 RTTR "Tempos"
};

static_assert(offsetof(C_BlacksmithSong, m_usesBreath) == 0x08,
              "C_BlacksmithSong::m_usesBreath offset mismatch");
static_assert(offsetof(C_BlacksmithSong, m_id) == 0x10,
              "C_BlacksmithSong::m_id offset mismatch");
static_assert(offsetof(C_BlacksmithSong, m_tempos) == 0x18,
              "C_BlacksmithSong::m_tempos offset mismatch");
static_assert(sizeof(C_BlacksmithSong) == 0x30,
              "C_BlacksmithSong size mismatch");

}  // namespace wh::playermodule
