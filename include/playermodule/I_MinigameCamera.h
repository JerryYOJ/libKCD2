#pragma once

// -----------------------------------------------
// wh::playermodule::I_MinigameCamera -- minigame camera-control interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08, six slots.
// -----------------------------------------------
// C_Minigame's secondary vtable 0x183A6A530 proves six slots and no destructor.
// Signatures are constrained by the shared constant/default implementations; semantic
// names remain open, so callers should not use the unk slots directly.

namespace wh::playermodule {

class I_MinigameCamera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_MinigameCamera;

    virtual bool  camera_unk_00() const = 0; // [0] default false
    virtual bool  camera_unk_01() const = 0; // [1] default false
    virtual void  camera_unk_02() = 0;       // [2] nullsub
    virtual bool  camera_unk_03() const = 0; // [3] default false
    virtual float camera_unk_04() const = 0; // [4] default 1.0f
    virtual bool  camera_unk_05() const = 0; // [5] default true
};
static_assert(sizeof(I_MinigameCamera) == 0x08,
              "I_MinigameCamera is a vptr-only six-slot interface");

}  // namespace wh::playermodule
