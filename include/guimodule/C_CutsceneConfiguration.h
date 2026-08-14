#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule {
class C_CutsceneHolder;
}

namespace wh::guimodule {

class I_Cutscene;

// Non-polymorphic playback configuration built from a CutsceneHolder name.
class C_CutsceneConfiguration {
public:
    entitymodule::C_CutsceneHolder* m_pHolder; // +0x00, borrowed
    std::int32_t m_state;                      // +0x08, initialized -1; exact type/role OPEN
    bool m_flag0C;                             // +0x0C, exact role OPEN
    std::uint8_t _pad0D[3];                    // +0x0D
    bool m_flag10;                             // +0x10, constructor argument; role OPEN
    bool m_flag11;                             // +0x11, constructor argument; role OPEN
    CryStringT<char> m_cutsceneName;           // +0x18, owned copy
    I_Cutscene* m_pCutscene;                   // +0x20, borrowed from database shared_ptr
};
static_assert(sizeof(C_CutsceneConfiguration) == 0x28,
              "C_CutsceneConfiguration must be 0x28");
static_assert(offsetof(C_CutsceneConfiguration, m_flag10) == 0x10,
              "configuration flags must begin at 0x10");
static_assert(offsetof(C_CutsceneConfiguration, m_cutsceneName) == 0x18,
              "copied cutscene name must be at 0x18");
static_assert(offsetof(C_CutsceneConfiguration, m_pCutscene) == 0x20,
              "borrowed cutscene pointer must be at 0x20");

}  // namespace wh::guimodule
