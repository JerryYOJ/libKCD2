#pragma once
#include <cstddef>
#include "I_Element.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_CombatAutomationsElement : I_Element
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18; vtable 0x183B5ABE0 (33 slots).
// -----------------------------------------------
// Same size as I_Element. Slot 2 returns E_ElementType::CombatAutomations (0x13).

namespace wh::xgenaimodule::NPCState {

class C_CombatAutomationsElement : public I_Element {
public:
    ~C_CombatAutomationsElement() override;               // [1]
    E_ElementType::Type unk_02() override;                // [2] 0x181AA68A0 returns 0x13
    I_Element* Clone() const override; // [9] 0x181301DA8 clone
    std::uint64_t GetHash() const override; // [10] 0x180AFC7BC
    bool WritePayload(void* writer) const override; // [24] 0x18041A6A0 true
    bool ReadPayload(void* reader, void* ctxA, void* ctxB, bool* ok) override; // [25] 0x18041A6A0 true
    RTTR_ENABLE(I_Element)                                // [30..32]
};

static_assert(sizeof(C_CombatAutomationsElement) == 0x18,
              "C_CombatAutomationsElement size mismatch");

}  // namespace wh::xgenaimodule::NPCState
