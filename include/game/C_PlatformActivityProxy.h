#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::game::C_PlatformActivityProxy
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------

namespace wh::game {

class C_PlatformActivityProxy {
public:
    CryStringT<char> m_id;                                // +0x00 RTTR "Id"
};

static_assert(offsetof(C_PlatformActivityProxy, m_id) == 0x00,
              "C_PlatformActivityProxy::m_id offset mismatch");
static_assert(sizeof(C_PlatformActivityProxy) == 0x08,
              "C_PlatformActivityProxy size mismatch");

}  // namespace wh::game
