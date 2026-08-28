#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"
#include "../../CryEngine/CryCommon/CryString.h"
#include "I_Operator.h"

// -----------------------------------------------
// wh::rpgmodule::storm::C_SetCharacterComponentBase : I_Operator
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20; vtable 0x183B0FDA8 (9 slots).
// -----------------------------------------------
// Dtor 0x18178BC04 runs CryString teardown of three strings at +0x08/+0x10/+0x18
// (sub_1806906AC). DebugDraw [4] prints *(this+8) as "%s - %s". Slot 1 apply
// forwards to [8]. Slot 3 returns E_TaskClass::appearance (0x100).

namespace wh::rpgmodule::storm {

class C_SetCharacterComponentBase : public I_Operator {
public:
    ~C_SetCharacterComponentBase() override;              // [0] 0x18178BC04
    void unk_01(C_Soul* soul, C_Rule* rule) override;     // [1] 0x180973318 -> [8]
    bool unk_02() override;                               // [2] 0x18041A6A0 true
    E_TaskClass unk_03() override;                        // [3] 0x181A94E30 appearance
    void DebugDraw(wh::C_DebugDraw& draw) const override; // [4] 0x182D4E41C
    RTTR_ENABLE(I_Operator)                               // [5..7]
    virtual void unk_08(wh::rpgmodule::C_Soul* soul, C_Rule* rule) = 0;  // [8]

    CryStringT<char> m_name;                              // +0x08 DebugDraw name
    CryStringT<char> m_unknown10;                         // +0x10
    CryStringT<char> m_unknown18;                         // +0x18
};

static_assert(offsetof(C_SetCharacterComponentBase, m_name) == 0x08,
              "C_SetCharacterComponentBase::m_name offset mismatch");
static_assert(sizeof(C_SetCharacterComponentBase) == 0x20,
              "C_SetCharacterComponentBase size mismatch");

}  // namespace wh::rpgmodule::storm
