#pragma once
#include <cstdint>
#include "C_CombatAutomationAction.h"
#include "../CryEngine/CryCommon/smartptr.h"

// -----------------------------------------------
// wh::combatmodule::C_CombatAutomationAttack : C_CombatAutomationAction -- KCD2 1.5.6 (kd7u).  sizeof 0xB0.
// -----------------------------------------------
// Embedded by value at C_CombatAutomation+0x168 (ctor sub_1810EEDD8; vtable 0x183B09FD0; debug dump
// sub_182767DF8 "ATTACK: ..."). The uint64 RNG states advance with the MSVC LCG
// (214013*x + 2531011, take >>16).

namespace wh::combatmodule {

// Generated/override attack parameters (0x14, heap; owned by m_pOverride, freed with size 20).
struct S_AttackOverride {
    float   staminaLimit;   // +0x00
    float   aktCenter;      // +0x04
    float   aktRange;       // +0x08
    int32_t inputClass;     // +0x0C
    uint32_t _u10;          // +0x10  (meaning unverified)
};
static_assert(sizeof(S_AttackOverride) == 0x14, "S_AttackOverride must be 0x14");

class C_CombatAutomationAttack : public C_CombatAutomationAction {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatAutomationAttack;
    const char* GetName() const override { return "AutomationAttack"; }   // [3] 0x181A7E170
    int GetActionKind() const override { return 10; }                     // [10] 0x181A74D20

    CTimeValue m_retryTimer;          // +0x30  init -100000 (timer helpers sub_180731070/sub_1809D6A34)
    S_AttackOverride* m_pOverride;    // +0x38  owned raw ptr (dtor frees 20B); null = none
    CTimeValue m_delayTimer;          // +0x40  "Delay %.2f"
    CTimeValue m_timer48;             // +0x48  init -100000 (role unresolved)
    CTimeValue m_timer50;             // +0x50  init -100000 (role unresolved)
    uint64_t   m_zoneSelectRng;       // +0x58  LCG state; picks the zone index
    int32_t    m_selectedZone;        // +0x60  "Selected zone %d"
    int32_t    m_inputClass;          // +0x64  "input %d"
    int32_t    m_zoneType;            // +0x68  init -1 (part of the 16B zone entry; medium confidence)
    float      m_weight;              // +0x6C  init 1.0; "weight %.2f"
    uint64_t   m_atkGenRng;           // +0x70  LCG state; re-rolled in sub_18072E784
    float      m_atkGenRoll;          // +0x78  [0,1) roll; "AtkGen: %.2f"
    bool       m_staminaLimitFlagA;   // +0x7C
    bool       m_staminaLimitFlagB;   // +0x7D
    uint8_t    _pad7E[2];             // +0x7E
    CTimeValue m_aktWindow;           // +0x80  "Akt %.2f"
    CTimeValue m_huntTimer;           // +0x88  "Hunt %.2f"
    void*      m_pOwnedA;             // +0x90  OWNED (_smart_ptr semantics: dtor releases via vfunc+0x10); pointee class unresolved
    void*      m_pThreatTarget;       // +0x98  weak polymorphic ptr (GetName via vfunc+56); "Threat %s"
    bool       m_confirmed;           // +0xA0  "Confirmed: %s"
    bool       m_retryFlag;           // +0xA1  read/cleared by sub_18072E784
    uint8_t    _padA2[2];             // +0xA2
    int32_t    m_stateCounter;        // +0xA4  guard in sub_18072E784
    void*      m_pOwnedB;             // +0xA8  OWNED (released via vfunc+0x10); pointee class unresolved
};
static_assert(sizeof(C_CombatAutomationAttack) == 0xB0, "C_CombatAutomationAttack must be 0xB0");

}  // namespace wh::combatmodule
