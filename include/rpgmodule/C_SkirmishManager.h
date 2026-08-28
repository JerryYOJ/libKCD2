#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>
#include "../framework/WUID.h"
#include "../game/I_EntitySideEffectCallback.h"
#include "../rttr/rttr_enable.h"
#include "I_SkirmishManager.h"
#include "S_SkirmishListenerRegistration.h"
#include "S_SkirmishPredominanceSetStorage.h"

namespace wh::rpgmodule {

class C_Skirmish;
class C_SkirmishSituation;
class I_SkirmishHandle;
class I_SkirmishListener;
class I_SkirmishSituation;
class I_SkirmishTargetingStrategy;
class I_Soul;

class C_SkirmishManager
    : public I_SkirmishManager,
      public wh::game::I_EntitySideEffectCallback {
public:
    C_SkirmishManager();
    ~C_SkirmishManager() override;                                // primary [0]
    bool CanStartSkirmish(
        I_Soul* soul,
        I_Soul* target,
        bool initialTarget) override;                             // primary [1]
    bool StartSkirmish(
        I_Soul* soul,
        I_Soul* target,
        bool initialTarget) override;                             // primary [2]
    void RemoveSoul(I_Soul* soul) override;                       // primary [3]
    bool SetTargetingStrategy(
        I_Soul* soul,
        std::shared_ptr<I_SkirmishTargetingStrategy> strategy) override; // primary [4]
    bool ClearTargetingStrategy(I_Soul* soul) override;           // primary [5]
    bool ArmAgainst(I_Soul* soul, I_Soul* target) override;       // primary [6]
    std::uint8_t EvaluateTarget(
        I_Soul* soul,
        I_Soul* target,
        const void* targetingContext) override;                   // primary [7]
    bool HasSkirmishPair(I_Soul* soul, I_Soul* target) override;  // primary [8]
    I_SkirmishHandle* CreateHandle(I_Soul* soul) override;        // primary [9]
    void RegisterListener(
        const std::vector<I_Soul*>& souls,
        I_SkirmishListener* listener,
        std::uint32_t matchFlags) override;                       // primary [10]
    void UnregisterListener(I_SkirmishListener* listener) override; // primary [11]
    I_SkirmishSituation* GetSituation() override;                 // primary [12]
    bool IsInSkirmish(I_Soul* soul) override;                     // primary [13]
    bool unk_14(I_Soul* soul) override;                           // primary [14]
    bool unk_15(I_Soul* soul) override;                           // primary [15]
    bool CanEnterCombat(I_Soul* soul) override;                   // primary [16]
    bool HandleTargetEscaped(I_Soul* soul, I_Soul* target) override; // primary [17]
    void UpdateParticipantState(
        I_Soul* soul,
        std::int32_t state,
        bool enabled) override;                                  // primary [18]
    void DebugTriggerEvent() override;                            // primary [19]
    void Clear() override;                                        // primary [20]
    void Update() override;                                       // primary [21]
    RTTR_ENABLE(I_SkirmishManager) // primary [22..24]

    void OnEntitySideEffectAdded(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) override;                 // secondary [0]
    void OnEntitySideEffectRemoved(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) override;                 // secondary [1]

    std::vector<std::unique_ptr<C_Skirmish>> m_skirmishes;       // +0x10
    std::unordered_map<
        wh::framework::WUID,
        C_Skirmish*> m_skirmishesBySoulWuid;                      // +0x28
    std::vector<
        S_SkirmishListenerRegistration> m_listenerRegistrations;  // +0x68
    std::unique_ptr<C_SkirmishSituation> m_situation;             // +0x80
    bool m_skirmishesDirty;                                      // +0x88
    bool m_listenerRegistrationsDirty;                           // +0x89
    std::uint8_t m_padding8A[6];                                // +0x8A
    std::uint8_t m_pendingTree90[0x10];                         // +0x90 MSVC tree; entry type unresolved
    std::uint8_t m_pendingSoulPairMerges[0x10];                 // +0xA0 MSVC tree; pair entry unresolved
    std::vector<
        S_SkirmishPredominanceSetStorage> m_pendingPredominanceSets; // +0xB0
    bool m_updateBlocked;                                        // +0xC8
    bool m_unknownC9;                                            // +0xC9
    std::uint8_t m_paddingCA[6];                                // +0xCA
    std::vector<std::unique_ptr<
        S_SkirmishPredominanceSetStorage>> m_externalPredominanceSets; // +0xD0
};

static_assert(sizeof(C_SkirmishManager) == 0xE8,
              "C_SkirmishManager size mismatch");
static_assert(offsetof(C_SkirmishManager, m_skirmishes) == 0x10,
              "C_SkirmishManager skirmish vector offset mismatch");
static_assert(offsetof(C_SkirmishManager, m_skirmishesBySoulWuid) == 0x28,
              "C_SkirmishManager lookup offset mismatch");
static_assert(offsetof(C_SkirmishManager, m_listenerRegistrations) == 0x68,
              "C_SkirmishManager listener registrations offset mismatch");
static_assert(offsetof(C_SkirmishManager, m_situation) == 0x80,
              "C_SkirmishManager situation offset mismatch");
static_assert(offsetof(C_SkirmishManager, m_pendingPredominanceSets) == 0xB0,
              "C_SkirmishManager pending predominance offset mismatch");
static_assert(offsetof(C_SkirmishManager, m_externalPredominanceSets) == 0xD0,
              "C_SkirmishManager external predominance offset mismatch");

} // namespace wh::rpgmodule
