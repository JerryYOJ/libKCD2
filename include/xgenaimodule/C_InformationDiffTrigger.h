#pragma once

#include <cstddef>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_LinkableObject.h"
#include "E_InformationMessageStatus.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_InformationDiffTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    ~C_InformationDiffTrigger() override;                                    // [0] 0x180FBA7D0
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183AEBFF0
    void OnEffectActivate() override;                                        // [43] 0x1819DEED8
    void OnEffectDeactivate() override;                                      // [44] 0x183282C50

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_who;                                       // +0xB0 RTTR "Who"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_whoFilter;                                 // +0xF0 RTTR "WhoFilter"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_label;             // +0x130 RTTR "Label"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_labelFilter;       // +0x170 RTTR "LabelFilter"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_perceivedWuid;    // +0x1B0 RTTR "PerceivedWuid"
    wh::conceptmodule::C_TypedPortRef<
        C_LinkableObject*> m_perceivedWuidFilter;                            // +0x1F0 RTTR "PerceivedWuidFilter"
    wh::conceptmodule::C_TypedPortRef<bool> m_isCrime;                       // +0x230 RTTR "IsCrime"
    wh::conceptmodule::C_TypedPortRef<bool> m_isCrimeFilter;                 // +0x270 RTTR "IsCrimeFilter"
    wh::conceptmodule::C_TypedPortRef<
        E_InformationMessageStatus::Type> m_status;                          // +0x2B0 RTTR "Status"
    wh::conceptmodule::C_TypedPortRef<
        E_InformationMessageStatus::Type> m_statusFilter;                    // +0x2F0 RTTR "StatusFilter"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onNotification;                      // +0x330 RTTR "OnNotification"
};

static_assert(offsetof(C_InformationDiffTrigger, m_who) == 0xB0,
              "C_InformationDiffTrigger::m_who offset mismatch");
static_assert(offsetof(C_InformationDiffTrigger, m_onNotification) == 0x330,
              "C_InformationDiffTrigger::m_onNotification offset mismatch");
static_assert(sizeof(C_InformationDiffTrigger) == 0x370,
              "C_InformationDiffTrigger size mismatch");

} // namespace wh::xgenaimodule
