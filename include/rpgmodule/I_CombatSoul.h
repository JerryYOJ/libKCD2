#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../framework/C_Signal.h"

namespace Offsets { struct IEntity; }
namespace wh::combatmodule {
struct S_HitInfo;
struct S_MeleeHitDetails;
}

namespace wh::entitymodule {
class C_BodyPartData;
class S_WeaponClass;
}

namespace wh::rpgmodule {

class C_CombatSoulModel;
class I_Soul;
struct S_DealDamageParams;
struct S_SkirmishStatistics;

// -----------------------------------------------
// wh::rpgmodule::I_CombatSoul -- combat facet of a soul (KCD2 WHGame.dll 1.5.6)
// -----------------------------------------------
// Pure interface, 49 own slots, no virtual dtor; sole implementor C_CombatSoul
// (vtable 0x183F45670, embedded at C_Soul+0xF0). Slot names/signatures per t1_007
// dossier + verdict; signal heads at C_CombatSoul +0x08..+0x68 (see signal map there).

class I_CombatSoul {
public:
    using Delegate = wh::shared::S_Delegate<>;   // 0x10 {instance, invoke}; per-family Args below where proven

    virtual void ConnectSignal08(const Delegate& slot) = 0;        // [0]  Args OPEN (no public emit)
    virtual void DisconnectSignal08(const Delegate& slot) = 0;     // [1]
    virtual void ConnectSignal18(const Delegate& slot) = 0;        // [2]  Args OPEN
    virtual void DisconnectSignal18(const Delegate& slot) = 0;     // [3]
    virtual void ConnectSignal28(const Delegate& slot) = 0;        // [4]  Args OPEN
    virtual void DisconnectSignal28(const Delegate& slot) = 0;     // [5]
    virtual void ConnectSignal38(
        const wh::shared::S_Delegate<void*>& slot) = 0;            // [6]  1-pointer family (emit [38]); pointee OPEN
    virtual void DisconnectSignal38(
        const wh::shared::S_Delegate<void*>& slot) = 0;            // [7]
    virtual void ConnectSignal48(
        const wh::shared::S_Delegate<void*>& slot) = 0;            // [8]  1-pointer family (emit [39])
    virtual void DisconnectSignal48(
        const wh::shared::S_Delegate<void*>& slot) = 0;            // [9]
    virtual void ConnectFireData(const Delegate& slot) = 0;        // [10] Args OPEN: 16-byte key (not proven CryGUID); emit [40]
    virtual void DisconnectFireData(const Delegate& slot) = 0;     // [11]
    virtual void ConnectHit(
        const wh::shared::S_Delegate<I_Soul*,
                                     wh::combatmodule::S_HitInfo*,
                                     wh::combatmodule::S_MeleeHitDetails*>& slot) = 0; // [12] emit [41]
    virtual void DisconnectHit(
        const wh::shared::S_Delegate<I_Soul*,
                                     wh::combatmodule::S_HitInfo*,
                                     wh::combatmodule::S_MeleeHitDetails*>& slot) = 0; // [13]
    virtual void Unk14() = 0;                                     // [14] GetArmourLoad-like (Alo remap clamped [0,1]) but hidden 4-byte dest, NOT xmm0 float -- ABI OPEN
    virtual bool Unk15() const = 0;                               // [15] level>0 && GetDerivedStat(Coc)!=0; Coc meaning OPEN
    virtual bool Unk16() const = 0;                               // [16] any skirmish-situation entry passes vtbl+0x1D0->+0x78; inner type OPEN
    virtual void SetCombatActive(bool active) = 0;                 // [17] creates/releases the owned combat buff at +0x80
    virtual bool IsSoulCharged() const = 0;                        // [18]
    virtual bool IsUnarmed() const = 0;                            // [19]
    virtual bool IsUnarmedOrHasWeaponClassPair_12_11() const = 0;  // [20] unarmed OR no hand item OR weapon-class pair {12,11}
    virtual bool HasMeleeWeapon() const = 0;                       // [21]
    virtual bool HasOversizedWeapon() const = 0;                   // [22] E_WeaponKind::oversized (3)
    virtual bool HasMissileWeapon() const = 0;                     // [23]
    virtual bool HasWeaponInHand(
        const wh::entitymodule::S_WeaponClass& weaponClass) const = 0; // [24]
    virtual bool HasCombatHistoryWithSoul(
        I_Soul* soul,
        float expirationTime) const = 0;                           // [25]
    virtual bool HasCombatHistoryWithSoulInternal(
        I_Soul* soul,
        float expirationTime) const = 0;                           // [26]
    virtual void TakeDamage(
        float staminaDamage,
        float healthDamage,
        I_Soul* source,
        bool notify,
        const wh::entitymodule::C_BodyPartData& bodyPartData) = 0; // [27]
    virtual void TakeDamageInternal(const S_DealDamageParams& params) = 0; // [28]
    virtual void TakeDamageDefault(
        I_Soul* source,
        bool notify,
        const wh::entitymodule::C_BodyPartData& bodyPartData) = 0; // [29] binary overload of TakeDamage, de-overloaded (slot 28 separates the pair; MSVC would regroup); health taken from owner+0x708 (semantics OPEN)
    virtual void NotifyCombo(
        Offsets::IEntity* other,
        std::uint8_t mode) = 0;                                    // [30] posts S_HitInfo hitTypeId=Combo(10); mode 0/1/2 -> hitStrength 2/5/6
    virtual std::uint64_t GetAttackersCount() const = 0;           // [31]
    virtual std::shared_ptr<S_SkirmishStatistics>
        GetSkirmishStatistics() const = 0;                         // [32]
    virtual I_Soul* GetTarget() const = 0;                         // [33]
    virtual bool Unk34() const = 0;                               // [34] skirmish walk + entity side-effect 0x37; both OPEN
    virtual void VisitCombatHistory(void* visitor) = 0;            // [35] walks the +0xA0 history tree; visitor type OPEN
    virtual C_CombatSoulModel* GetModel() const = 0;               // [37] same body as [36] (ICF fold); MSVC reverses adjacent overloads -> const declared first
    virtual C_CombatSoulModel* GetModel() = 0;                     // [36]
    virtual void EmitSignal38(void* arg) = 0;                      // [38] public emit of m_signal38
    virtual void EmitSignal48(void* arg) = 0;                      // [39]
    virtual void NotifyFireData(const void* fireData, float charge) = 0; // [40] emits 16-byte key on m_signal58; charge is log-only
    virtual void NotifyHit(
        I_Soul* otherSoul,
        wh::combatmodule::S_HitInfo* hitInfo,
        wh::combatmodule::S_MeleeHitDetails* details) = 0;         // [41] emit of m_signal68 (C_CombatActor::NotifyHit)
    virtual void* OnMeleeHit(
        void* resultSlot,
        const void* meleeHitDesc) = 0;                             // [42]
    virtual void* OnMissileHit(
        void* resultSlot,
        const void* missileHitDesc) = 0;                           // [43]
    virtual void* OnCollisionHit(
        void* resultSlot,
        const void* collisionDesc) = 0;                            // [44]
    virtual void* OnScriptedHit(
        void* resultSlot,
        const void* scriptedDesc) = 0;                             // [45]
    virtual Vec3 GetWeaponAttackDamage(
        void* attackerCtx, void* item) const = 0;                  // [46] AttackMod xyz * perk-stat modifiers; arg types OPEN
    virtual Vec3 GetUnarmedAttackDamage(unsigned classId) const = 0; // [47] uniform xyz from unarmed skill + uat perk stat
    virtual bool Unk48(void* other) const = 0;                     // [48] true unless owner m_flagsCF0 bit3; else other->vtbl+0xA8
};

static_assert(sizeof(I_CombatSoul) == 0x08,
              "I_CombatSoul size mismatch");

} // namespace wh::rpgmodule
