#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>

namespace wh::entitymodule {
class C_BodyPartData;
class S_WeaponClass;
}

namespace wh::rpgmodule {

class C_CombatSoulModel;
class I_Soul;
struct S_DealDamageParams;
struct S_SkirmishStatistics;

class I_CombatSoul {
public:
    virtual void Unk00(const void* delegate16) = 0;                // [0]
    virtual void Unk01() = 0;                                     // [1]
    virtual void Unk02() = 0;                                     // [2]
    virtual void Unk03() = 0;                                     // [3]
    virtual void Unk04() = 0;                                     // [4]
    virtual void Unk05() = 0;                                     // [5]
    virtual void Unk06() = 0;                                     // [6]
    virtual void Unk07() = 0;                                     // [7]
    virtual void Unk08() = 0;                                     // [8]
    virtual void Unk09() = 0;                                     // [9]
    virtual void Unk10() = 0;                                     // [10]
    virtual void Unk11() = 0;                                     // [11]
    virtual void Unk12() = 0;                                     // [12]
    virtual void Unk13() = 0;                                     // [13]
    virtual void Unk14() = 0;                                     // [14]
    virtual void Unk15() = 0;                                     // [15]
    virtual void Unk16() = 0;                                     // [16]
    virtual void Unk17() = 0;                                     // [17]
    virtual bool IsSoulCharged() const = 0;                        // [18]
    virtual bool IsUnarmed() const = 0;                            // [19]
    virtual void Unk20() = 0;                                     // [20]
    virtual bool HasMeleeWeapon() const = 0;                       // [21]
    virtual void Unk22() = 0;                                     // [22]
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
    virtual void Unk29() = 0;                                     // [29]
    virtual void Unk30() = 0;                                     // [30]
    virtual std::uint64_t GetAttackersCount() const = 0;           // [31]
    virtual std::shared_ptr<S_SkirmishStatistics>
        GetSkirmishStatistics() const = 0;                         // [32]
    virtual I_Soul* GetTarget() const = 0;                         // [33]
    virtual void Unk34() = 0;                                     // [34]
    virtual void Unk35() = 0;                                     // [35]
    virtual C_CombatSoulModel* Unk36() = 0;                        // [36]
    virtual C_CombatSoulModel* Unk37() = 0;                        // [37]
    virtual void Unk38(const void* delegate16) = 0;                // [38]
    virtual void Unk39(const void* delegate16) = 0;                // [39]
    virtual void Unk40(const void* fireData, float charge) = 0;    // [40]
    virtual void Unk41() = 0;                                     // [41]
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
    virtual void Unk46() = 0;                                     // [46]
    virtual void Unk47() = 0;                                     // [47]
    virtual void Unk48() = 0;                                     // [48]
};

static_assert(sizeof(I_CombatSoul) == 0x08,
              "I_CombatSoul size mismatch");

} // namespace wh::rpgmodule
