#pragma once
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::I_Interactor -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x10.
// -----------------------------------------------
// RTTI .?AVI_Interactor@entitymodule@wh@@; vtable 0x183D15AE0, 6 slots.
// This Warhorse interface is unrelated to CryEngine's global IInteractor.

namespace wh::entitymodule {

class C_Player;

class I_Interactor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_Interactor;
    virtual ~I_Interactor() = default;                  // [0] sub_1829FD7B8
    virtual void Initialize(C_Player* pPlayer);         // [1] sub_1816DBC70: stores pPlayer at +0x08
    virtual void unk_02();                              // [2] nullsub_1; role OPEN
    virtual void ResetInteractionState() = 0;           // [3] pure; C_PlayerInteractor sub_1808E9300
    virtual void unk_04();                              // [4] nullsub_1; role OPEN
    virtual void Update();                              // [5] base nullsub; C_PlayerInteractor sub_1807F2DD4

    C_Player* m_pPlayer;                                // +0x08
};

static_assert(sizeof(I_Interactor) == 0x10, "I_Interactor must be 0x10");
static_assert(offsetof(I_Interactor, m_pPlayer) == 0x08, "m_pPlayer must be at 0x08");

}  // namespace wh::entitymodule
