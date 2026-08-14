#pragma once
#include <cstdint>
#include "E_MinigameType.h"

// -----------------------------------------------
// wh::playermodule::I_Minigame -- minigame-session interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08, 47 slots.
// -----------------------------------------------
// Slot count is certified by C_Minigame/C_HerbGathering vtables. Slot [5] is the
// virtual destructor (C_HerbGathering sub_182E98B20), not a separate teardown method.
// Only behavior/signatures with direct producer/caller proof are named.

namespace wh::playermodule {

class I_Minigame {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_Minigame;
    virtual E_MinigameType::Type GetMinigameType() const = 0; // [0]
    virtual bool unk_01() const = 0;                          // [1]
    virtual void unk_02() = 0;                               // [2]
    virtual bool unk_03() const = 0;                          // [3]
    virtual void Destroy() = 0;                              // [4] forwards to [5]
    virtual ~I_Minigame();                                   // [5]
    virtual void DestroySession() = 0;                       // [6] forwards to [5]
    virtual bool IsFinished() const = 0;                     // [7]
    virtual void unk_08() = 0;                               // [8]
    virtual void unk_09() = 0;                               // [9]
    virtual uint32_t GetPlayerId() const = 0;                // [10]
    virtual void unk_11() = 0;                               // [11]
    virtual void unk_12() = 0;                               // [12]
    virtual void unk_13() = 0;                               // [13]
    virtual void unk_14() = 0;                               // [14]
    virtual void unk_15() = 0;                               // [15]
    virtual void* unk_16() = 0;                              // [16]
    virtual void unk_17() = 0;                               // [17]
    virtual bool Begin() = 0;                                // [18] minigame setup gate
    virtual void Update(float deltaTime) = 0;                // [19] per-frame session update
    virtual void unk_20() = 0;                               // [20]
    virtual void Reset() = 0;                                // [21]
    virtual uint32_t GetUserId() const = 0;                  // [22]
    virtual void unk_23() = 0;                               // [23]
    virtual void unk_24() = 0;                               // [24]
    virtual void unk_25() = 0;                               // [25]
    virtual void unk_26() = 0;                               // [26]
    virtual void unk_27() = 0;                               // [27]
    virtual void unk_28() = 0;                               // [28]
    virtual void unk_29() = 0;                               // [29]
    virtual void unk_30() = 0;                               // [30]
    virtual void unk_31() = 0;                               // [31]
    virtual void unk_32() = 0;                               // [32]
    virtual void SelfDestruct() = 0;                         // [33] removes the session
    virtual void SetActionMapContext(CryStringT<char> context) = 0; // [34] callee-destroy by value
    virtual void UpdateExitHint() = 0;                       // [35] "minigame_exit" action/hint
    virtual void unk_36() = 0;                               // [36]
    virtual void unk_37() = 0;                               // [37]
    virtual void unk_38() = 0;                               // [38]
    virtual void unk_39() = 0;                               // [39]
    virtual void unk_40() = 0;                               // [40]
    virtual void unk_41() = 0;                               // [41]
    virtual void unk_42() = 0;                               // [42]
    virtual void unk_43() = 0;                               // [43]
    virtual void unk_44() = 0;                               // [44]
    virtual uint8_t unk_45() const = 0;                      // [45] AL-only constant overrides
    virtual void RequestExit() = 0;                          // [46] input-driven exit request
};
static_assert(sizeof(I_Minigame) == 0x08, "I_Minigame is a vptr-only interface");

}  // namespace wh::playermodule
