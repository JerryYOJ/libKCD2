#pragma once
#include <cstdint>
#include "C_Perk.h"

// -----------------------------------------------
// wh::rpgmodule::C_BuffPerk -- perk that applies a buff (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI .?AVC_BuffPerk@rpgmodule@wh@@ (TD 0x184D53D78)  vtable 0x183A391B8.
// sizeof 0x48 (PROVEN: factory sub_180471308 operator new(72)).
// Extra fields init: +0x30 = 16-byte constant xmmword_183A391A0 (invalid buff id), +0x40 = 0.

namespace wh::rpgmodule {

class C_BuffPerk : public C_Perk {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_BuffPerk;
    uint64_t m_buffId[2];   // +0x30  16-byte buff id; ctor = the invalid constant
                            //        (buff GUID candidate -- interior typing UNVERIFIED)
    void*    m_pUnk40;      // +0x40  ctor 0 [role UNVERIFIED]
};
static_assert(sizeof(C_BuffPerk) == 0x48, "C_BuffPerk must be 0x48 (operator new(72))");

}  // namespace wh::rpgmodule
