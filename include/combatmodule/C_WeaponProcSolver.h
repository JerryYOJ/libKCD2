#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorObject.h"
#include "S_CombatCollisionDetails.h"

// -----------------------------------------------
// wh::combatmodule::C_WeaponProcSolver : C_CombatActorObject
// (KCD2 WHGame.dll 1.5.6). sizeof 0x3C8.
// -----------------------------------------------
// RTTI verifies the sole base. C_CombatActorCollisions owns an instance allocated as 0x3C8
// at its +0x88. Ctor 0x181481E18; Arm sub_1827C2AE4; Start sub_1827C2B38; subsystem id 13;
// diagnostic name "WeaponSolver". Procedural weapon-hand IK solver: member split per t1_036
// dossier (STRING names from the GetDebugInfo format at 0x1827C34E3); qword stores at
// 4-aligned offsets are spelled as byte arrays so MSVC packing keeps binary offsets.

namespace wh::combatmodule {

class C_WeaponProcSolver : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_WeaponProcSolver;
    ~C_WeaponProcSolver() override = default;
    E_CombatSubsystem GetSubsystemId() const override { return static_cast<E_CombatSubsystem>(13); }
    const char* GetName() const override { return "WeaponSolver"; }

    bool      m_isActive;               // +0x10   Start sets 1 (0x1827C2BC5); GetDebugLabel gates on it
    bool      m_isArmed;                // +0x11   Arm sets 1 (0x1827C2B12) before Start
    uint8_t   m_unk12;                  // +0x12   ctor zero only
    uint8_t   _pad13[1];                // +0x13
    QuatT     m_ikQuat[5];              // +0x14   nested ctor 0x181482058 identity-inits 5x0x1C; Start seeds from hand/weapon transforms
    uint8_t   m_unkA0[0x48];            // +0xA0   tail of the inline IK block (nested-ctor Vec3/qword runs to rel +0xD4)
    QuatT*    m_pIkQuat0;               // +0xE8   ctor stores &m_ikQuat[0] (0x181481E4F)
    int32_t   m_unkF0;                  // +0xF0
    uint8_t   m_unkF4[0x18];            // +0xF4
    uint8_t   m_unk10C[8];              // +0x10C  qword store at 4-aligned offset (uint64_t would shift layout)
    uint8_t   _pad114[4];               // +0x114
    uint16_t  m_unk118[7];              // +0x118  ctor 0xFFFF fill (bone-id defaults)
    uint8_t   m_unk126[4];              // +0x126  dword store at 2-aligned offset
    int16_t   m_handBoneId;             // +0x12A  ctor 0xFFFF; Start passes it to the bone-matrix getter (0x1827C2DFA)
    uint16_t  m_unk12C;                 // +0x12C
    uint8_t   _pad12E[2];               // +0x12E
    int32_t   m_unk130;                 // +0x130
    uint8_t   _pad134[4];               // +0x134
    uint64_t  m_unk138;                 // +0x138  ctor stores dword_1854A7764 (zero-extended) on entity vfunc +0x2A8 true path
    uint64_t  m_unk140;                 // +0x140  same path, dword_1854A7760
    int32_t   m_handSlot;               // +0x148  Arm arg; debug "HandSlot=%s": 0 -> "R", else "L"
    int32_t   m_unk14C;                 // +0x14C  ctor 1; Arm overwrites with its second int arg
    uint64_t  m_unk150;                 // +0x150
    float     m_weight;                 // +0x158  "Weight=%.2f"
    uint32_t  m_unk15C;                 // +0x15C  covered by the +0x158 qword zero; no exclusive producer
    int32_t   m_unk160;                 // +0x160
    uint8_t   m_unk164[8];              // +0x164  qword store at 4-aligned offset
    float     m_rotRecoveryBlend;       // +0x16C  "RotRecoveryBlend=%.2f"
    uint8_t   m_tree170[0x10];          // +0x170  std::_Tree head {sentinel,size} (ctor sub_181481FC0); Key/T OPEN
    uint8_t   m_tree180[0x10];          // +0x180  second tree head
    int32_t   m_unk190;                 // +0x190
    uint8_t   m_unk194[0xC];            // +0x194
    uint8_t   m_unk1A0[0x14];           // +0x1A0
    float     m_weaponRange;            // +0x1B4  "WeaponRange=%.2f"; Start computes from weapon OBB (0x1827C2D81)
    float     m_weaponRadius;           // +0x1B8  "WeaponRadius=%.2f"; 0.5*max(aabb.x,aabb.y)
    float     m_weaponHeight;           // +0x1BC  "WeaponHeight=%.2f"
    uint8_t   m_unk1C0[0xF4];           // +0x1C0  weapon OBB/transform copies + identity-scale qwords; OPEN (needs its own pass)
    bool      m_unk2B4;                 // +0x2B4
    uint8_t   _pad2B5[0x13];            // +0x2B5
    S_CombatCollisionDetails m_collisionDetails; // +0x2C8  ctor runs the same tail-defaults helper as Collisions' records (0x180D508C0)
    bool      m_unk3A0;                 // +0x3A0
    uint8_t   _pad3A1[3];               // +0x3A1
    uint8_t   m_unk3A4[8];              // +0x3A4  qword store at 4-aligned offset
    int32_t   m_unk3AC;                 // +0x3AC
    uint32_t  m_unk3B0;                 // +0x3B0  low dword of a ctor qword zero spanning +0x3B0..+0x3B7
    float     m_handBonePosDiff;        // +0x3B4  "HandBonePosDiff=%.2f"
    float     m_handBoneRDiff;          // +0x3B8  "HandBoneRDiff=%.2f"
    float     m_weaponTopPikError;      // +0x3BC  "WeaponTopPIKError=%.2f"
    float     m_handBonePikError;       // +0x3C0  "HandBonePIKError=%.2f"
    float     m_handBoneRikError;       // +0x3C4  "HandBoneRIKError=%.2f"
};
static_assert(sizeof(C_WeaponProcSolver) == 0x3C8, "C_WeaponProcSolver must be 0x3C8");
static_assert(offsetof(C_WeaponProcSolver, m_isActive) == 0x10);
static_assert(offsetof(C_WeaponProcSolver, m_ikQuat) == 0x14);
static_assert(offsetof(C_WeaponProcSolver, m_pIkQuat0) == 0xE8);
static_assert(offsetof(C_WeaponProcSolver, m_handBoneId) == 0x12A);
static_assert(offsetof(C_WeaponProcSolver, m_handSlot) == 0x148);
static_assert(offsetof(C_WeaponProcSolver, m_rotRecoveryBlend) == 0x16C);
static_assert(offsetof(C_WeaponProcSolver, m_weaponRange) == 0x1B4);
static_assert(offsetof(C_WeaponProcSolver, m_collisionDetails) == 0x2C8);
static_assert(offsetof(C_WeaponProcSolver, m_handBonePosDiff) == 0x3B4);

}  // namespace wh::combatmodule
