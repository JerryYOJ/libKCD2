#pragma once

// -----------------------------------------------
// wh::xgenaimodule::I_RPGPerceptionHelper -- RPG-side perception hook interface
// (KCD2 WHGame.dll 1.5.6, kd7u).  Pure interface, 2 slots, NO virtual dtor.
// -----------------------------------------------
// RTTI TD rva 0x4FF3730. Implemented by S_RPGPerceptionHelper (embedded in
// C_XGenAIModule @+0xA0, shared vtable 0x184772508, exactly 2 slots -- do NOT add a
// virtual dtor). Method semantics UNRESOLVED; slots mirrored for layout only.

namespace wh::xgenaimodule {

class I_RPGPerceptionHelper {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_RPGPerceptionHelper;
    virtual void _vf0() = 0;   // [0] S_RPGPerceptionHelper: sub_180D45B6C [role UNVERIFIED]
    virtual void _vf1() = 0;   // [1] S_RPGPerceptionHelper: sub_1823CDA14 [role UNVERIFIED]
};
static_assert(sizeof(I_RPGPerceptionHelper) == 0x08, "I_RPGPerceptionHelper is vptr-only");

}  // namespace wh::xgenaimodule
