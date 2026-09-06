#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::S_AnimEventContext -- anim-event channel payload
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. [STRING]
// -----------------------------------------------
// Channel name "AnimEventContext" at 0x183A2CEF8 (binder 0x18039B97B); layout
// matches decoder 0x18075B0CC {int32, +8 CryString}. C_AnimActionBase stores the
// first 16 bytes at +0x180 and passes it to slots 64-66.

namespace wh::xgenaimodule::NPCState {

struct S_AnimEventContext {
    std::int32_t     category;   // +0x00
    std::uint32_t    _pad04;     // +0x04
    CryStringT<char> name;       // +0x08 interned
};
static_assert(sizeof(S_AnimEventContext) == 0x10, "S_AnimEventContext size mismatch");

}  // namespace wh::xgenaimodule::NPCState
