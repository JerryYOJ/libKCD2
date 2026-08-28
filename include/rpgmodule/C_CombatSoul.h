#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/C_Signal.h"
#include "../rttr/rttr_enable.h"
#include "I_CombatSoul.h"
#include "S_DealDamageParams.h"

// -----------------------------------------------
// wh::rpgmodule::C_CombatSoul -- KCD2 WHGame.dll 1.5.6. sizeof 0xA8.
// -----------------------------------------------
// RTTI proves I_CombatSoul as the sole primary base at +0x00. Its 49 slots are
// implemented here; C_CombatSoul adds only the RTTR trio at [49..51]. The class
// is embedded in C_Soul at +0xF0 and has no virtual-destructor slot.

namespace wh::rpgmodule {

class C_Soul;

class C_CombatSoul : public I_CombatSoul {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatSoul;

    ~C_CombatSoul();
    void Unk00(const void* delegate16) override;                   // [0] 0x1807D08B0
    void Unk01() override;                                        // [1] 0x1809048E8
    void Unk02() override;                                        // [2] 0x180A1CF20
    void Unk03() override;                                        // [3] 0x180A1C480
    void Unk04() override;                                        // [4] 0x182D260CC
    void Unk05() override;                                        // [5] 0x182D267C0
    void Unk06() override;                                        // [6] 0x1806159A4
    void Unk07() override;                                        // [7] 0x180615330
    void Unk08() override;                                        // [8] 0x18061597C
    void Unk09() override;                                        // [9] 0x1806153B4
    void Unk10() override;                                        // [10] 0x180615774
    void Unk11() override;                                        // [11] 0x1806156F0
    void Unk12() override;                                        // [12] 0x181293EB4
    void Unk13() override;                                        // [13] 0x181293E30
    void Unk14() override;                                        // [14] 0x181704280
    void Unk15() override;                                        // [15] 0x1814C8978
    void Unk16() override;                                        // [16] 0x1809D14D4
    void Unk17() override;                                        // [17] 0x182D29BF8
    bool IsSoulCharged() const override;                           // [18] 0x18046E4E4
    bool IsUnarmed() const override;                               // [19] 0x1816B1D60
    void Unk20() override;                                        // [20] 0x1816B1D10
    bool HasMeleeWeapon() const override;                          // [21] 0x18072C6FC
    void Unk22() override;                                        // [22] 0x1818364F0
    bool HasMissileWeapon() const override;                        // [23] 0x18072C098
    bool HasWeaponInHand(
        const wh::entitymodule::S_WeaponClass& weaponClass) const override; // [24] 0x181797EDC
    bool HasCombatHistoryWithSoul(
        I_Soul* soul,
        float expirationTime) const override;                      // [25] 0x1807275CC
    bool HasCombatHistoryWithSoulInternal(
        I_Soul* soul,
        float expirationTime) const override;                      // [26] 0x1807275E0
    void TakeDamage(
        float staminaDamage,
        float healthDamage,
        I_Soul* source,
        bool notify,
        const wh::entitymodule::C_BodyPartData& bodyPartData) override; // [27] 0x180EE031C
    void TakeDamageInternal(const S_DealDamageParams& params) override; // [28] 0x1807256D4
    void Unk29() override;                                        // [29] 0x182D289E4
    void Unk30() override;                                        // [30] 0x18180901C
    std::uint64_t GetAttackersCount() const override;              // [31] 0x182D27008
    std::shared_ptr<S_SkirmishStatistics>
        GetSkirmishStatistics() const override;                    // [32] 0x1817AECAC
    I_Soul* GetTarget() const override;                            // [33] 0x181772E84
    void Unk34() override;                                        // [34] 0x1815863C4
    void Unk35() override;                                        // [35] 0x182D2A4C0
    C_CombatSoulModel* Unk36() override;                           // [36] 0x181A8A560
    C_CombatSoulModel* Unk37() override;                           // [37] 0x181A8A560
    void Unk38(const void* delegate16) override;                   // [38] 0x182D28E90
    void Unk39(const void* delegate16) override;                   // [39] 0x182D28E9C
    void Unk40(const void* fireData, float charge) override;       // [40] 0x182D29108
    void Unk41() override;                                        // [41] 0x180D543A4
    void* OnMeleeHit(void* resultSlot, const void* meleeHitDesc) override; // [42]
    void* OnMissileHit(void* resultSlot, const void* missileHitDesc) override; // [43]
    void* OnCollisionHit(void* resultSlot, const void* collisionDesc) override; // [44]
    void* OnScriptedHit(void* resultSlot, const void* scriptedDesc) override; // [45]
    void Unk46() override;                                        // [46] 0x180686FDC
    void Unk47() override;                                        // [47] 0x1806875BC
    void Unk48() override;                                        // [48] 0x180728C30
    RTTR_ENABLE(I_CombatSoul) // [49..51]

    wh::shared::C_Signal<> m_signal08;                            // +0x08
    wh::shared::C_Signal<> m_signal18;                            // +0x18
    wh::shared::C_Signal<> m_signal28;                            // +0x28
    wh::shared::C_Signal<> m_signal38;                            // +0x38
    wh::shared::C_Signal<> m_signal48;                            // +0x48
    wh::shared::C_Signal<> m_signal58;                            // +0x58
    wh::shared::C_Signal<> m_signal68;                            // +0x68
    C_Soul* m_pOwner;                                             // +0x78
    std::uint64_t m_unknown80[3];                                // +0x80
    C_CombatSoulModel* m_pModel;                                 // +0x98 owned
    void* m_pTreeA0;                                              // +0xA0 owned tree
};

static_assert(sizeof(C_CombatSoul) == 0xA8,
              "C_CombatSoul size mismatch");
static_assert(offsetof(C_CombatSoul, m_signal08) == 0x08,
              "C_CombatSoul first signal offset mismatch");
static_assert(offsetof(C_CombatSoul, m_pOwner) == 0x78,
              "C_CombatSoul owner offset mismatch");
static_assert(offsetof(C_CombatSoul, m_pModel) == 0x98,
              "C_CombatSoul model offset mismatch");

} // namespace wh::rpgmodule
