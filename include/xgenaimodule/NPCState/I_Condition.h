#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::I_Condition -- NPC-state condition interface
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08; vtable 0x183A446A8 (9 slots).
// -----------------------------------------------
// No C++ bases. Slot 1 is a clone (C_ChangeEquipmentCondition alloc 0x10).
// Slot 2's argument type is not encoded. Slot 5 is a sret uint16
// (ChangeEquipment writes 0x104).

namespace wh::xgenaimodule::NPCState {

class I_Condition {
public:
    virtual ~I_Condition();                               // [0] 0x18067A930
    virtual I_Condition* unk_01() = 0;                    // [1] clone
    virtual bool unk_02(void* arg) = 0;                   // [2] predicate; arg type unverified
    virtual bool unk_03(void* arg) = 0;                   // [3] some overrides ignore arg
    virtual bool unk_04(void* arg) = 0;                   // [4] HandContent reads a2; return-true thunks ignore it
    virtual std::uint16_t unk_05() = 0;                   // [5] sret uint16
    RTTR_ENABLE()                                         // [6..8]
};

static_assert(sizeof(I_Condition) == 0x08,
              "I_Condition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
