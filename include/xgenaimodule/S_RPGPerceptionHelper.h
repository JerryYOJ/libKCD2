#pragma once
#include "I_RPGPerceptionHelper.h"

// -----------------------------------------------
// wh::xgenaimodule::S_RPGPerceptionHelper : I_RPGPerceptionHelper -- stateless RPG
// perception bridge (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x08 (vptr only).
// -----------------------------------------------
// RTTI TD rva 0x4FF3770 (.?AV -- class, despite the S_ prefix). Embedded by value in
// C_XGenAIModule @+0xA0 (ctor writes vtable 0x184772508 there; next member at +0xA8).
// Shared vtable, 2 slots: [0] sub_180D45B6C, [1] sub_1823CDA14 -- semantics UNRESOLVED.
// Overrides declared (not defined) so the type is concrete and embeddable.

namespace wh::xgenaimodule {

class S_RPGPerceptionHelper : public I_RPGPerceptionHelper {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_RPGPerceptionHelper;
    void _vf0() override;   // [0] sub_180D45B6C [role UNVERIFIED]
    void _vf1() override;   // [1] sub_1823CDA14 [role UNVERIFIED]
};
static_assert(sizeof(S_RPGPerceptionHelper) == 0x08, "S_RPGPerceptionHelper is vptr-only");

}  // namespace wh::xgenaimodule
