#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "C_CombatActorObject.h"

// -----------------------------------------------
// wh::combatmodule::C_WeaponSolver : C_CombatActorObject
// (KCD2 WHGame.dll 1.5.6). sizeof 0x50.
// -----------------------------------------------
// RTTI verifies the sole base. C_CombatActorCollisions owns an instance allocated as 0x50.
// Ctor 0x181481D80; Activate sub_180D4FC58; Deactivate sub_180D50AD0; Tick sub_180A7EA18;
// subsystem id 14; diagnostic name "WeaponSolver2". Member split per t1_036 dossier.

namespace wh::combatmodule {

struct S_WeaponSolverState;   // non-polymorphic, sizeof 0x418 (make_shared alloc 0x428); ctor sub_180D50230; own RE pending

class C_WeaponSolver : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_WeaponSolver;
    ~C_WeaponSolver() override = default;
    E_CombatSubsystem GetSubsystemId() const override { return static_cast<E_CombatSubsystem>(14); }
    const char* GetName() const override { return "WeaponSolver2"; }

    bool      m_isActive;               // +0x10  Activate sets word 0x101 (both bytes); Deactivate clears only this byte
    bool      m_unk11;                  // +0x11  Tick skips Deactivate when set; not cleared by Deactivate
    uint8_t   _pad12[6];                // +0x12
    std::shared_ptr<S_WeaponSolverState> m_state; // +0x18  Activate make_shared (0x180D4FF80, _Ref_count_obj2 vtable 0x183A99F58); Deactivate passes "WeaponSolver::End"
    void*     m_unk28;                  // +0x28  owned 0x20 heap helper (ctor sub_180D5004C, destroy sub_180D50BB0); no RTTI
    uint8_t   m_unk30[0x10];            // +0x30  ctor memset 16
    uint8_t   m_unk40[0xC];             // +0x40  ctor memset 12
    bool      m_unk4C;                  // +0x4C  ctor + Activate zero it
    uint8_t   _pad4D[3];                // +0x4D  tail padding to sizeof
};
static_assert(sizeof(C_WeaponSolver) == 0x50, "C_WeaponSolver must be 0x50");
static_assert(offsetof(C_WeaponSolver, m_isActive) == 0x10);
static_assert(offsetof(C_WeaponSolver, m_state) == 0x18);
static_assert(offsetof(C_WeaponSolver, m_unk4C) == 0x4C);

}  // namespace wh::combatmodule
