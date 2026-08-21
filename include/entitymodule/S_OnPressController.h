#pragma once
#include <cstdint>
#include <cstddef>
#include "I_MagnetismController.h"
#include "I_RiderPlayerStateMachineModifier.h"
#include "S_HorseData.h"

// -----------------------------------------------
// wh::entitymodule::S_OnPressController -- KCD2 WHGame.dll.  sizeof 0x30.
// -----------------------------------------------
// RTTI .?AVS_OnPressController@entitymodule@wh@@
//   : I_MagnetismController @0 (vt 0x183C34910)
//   : I_RiderPlayerStateMachineModifier @8 (vt 0x183C348D0)
// Factory sub_181932168 / ctor sub_1819321F8. Mode 1 of RoadMagnetism.
// a2 = S_HorseData*, a3 = C_Player* (only when actor type == 0x11).

namespace wh::entitymodule {

class C_Player;

class S_OnPressController : public I_MagnetismController, public I_RiderPlayerStateMachineModifier {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_OnPressController;
    C_Player*    m_pPlayer;          // +0x10  ctor a3; +0xB08 interactor
    S_HorseData* m_pHorseData;       // +0x18  ctor a2; heading at +0x100
    float        m_deactivateTime;   // +0x20  loaded from CVars+0x204
    float        m_reactivateTime;   // +0x24  loaded from CVars+0x208
    float        m_hintTime;         // +0x28  UI gate sub_180A25DD8
    uint8_t      m_flags;            // +0x2C  bit0 active, bit1 latched, bit3, bit4 flick
    uint8_t      _pad2D[3];          // +0x2D
};
static_assert(sizeof(S_OnPressController) == 0x30, "S_OnPressController must be 0x30");
static_assert(offsetof(S_OnPressController, m_pPlayer) == 0x10, "player");
static_assert(offsetof(S_OnPressController, m_pHorseData) == 0x18, "horse data");
static_assert(offsetof(S_OnPressController, m_flags) == 0x2C, "flags byte");

}  // namespace wh::entitymodule
