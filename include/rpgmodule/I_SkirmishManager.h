#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

namespace wh::rpgmodule {

class I_SkirmishHandle;
class I_SkirmishListener;
class I_SkirmishSituation;
class I_SkirmishTargetingStrategy;
class I_Soul;

class I_SkirmishManager {
public:
    virtual ~I_SkirmishManager() = default;                         // [0]
    virtual bool CanStartSkirmish(
        I_Soul* soul,
        I_Soul* target,
        bool initialTarget) = 0;                                   // [1]
    virtual bool StartSkirmish(
        I_Soul* soul,
        I_Soul* target,
        bool initialTarget) = 0;                                   // [2]
    virtual void RemoveSoul(I_Soul* soul) = 0;                      // [3]
    virtual bool SetTargetingStrategy(
        I_Soul* soul,
        std::shared_ptr<I_SkirmishTargetingStrategy> strategy) = 0; // [4]
    virtual bool ClearTargetingStrategy(I_Soul* soul) = 0;          // [5]
    virtual bool ArmAgainst(I_Soul* soul, I_Soul* target) = 0;      // [6]
    virtual std::uint8_t EvaluateTarget(
        I_Soul* soul,
        I_Soul* target,
        const void* targetingContext) = 0;                          // [7]
    virtual bool HasSkirmishPair(I_Soul* soul, I_Soul* target) = 0; // [8]
    virtual I_SkirmishHandle* CreateHandle(I_Soul* soul) = 0;      // [9]
    virtual void RegisterListener(
        const std::vector<I_Soul*>& souls,
        I_SkirmishListener* listener,
        std::uint32_t matchFlags) = 0;                              // [10]
    virtual void UnregisterListener(I_SkirmishListener* listener) = 0; // [11]
    virtual I_SkirmishSituation* GetSituation() = 0;                // [12]
    virtual bool IsInSkirmish(I_Soul* soul) = 0;                    // [13]
    virtual bool unk_14(I_Soul* soul) = 0;                          // [14]
    virtual bool unk_15(I_Soul* soul) = 0;                          // [15]
    virtual bool CanEnterCombat(I_Soul* soul) = 0;                  // [16]
    virtual bool HandleTargetEscaped(I_Soul* soul, I_Soul* target) = 0; // [17]
    virtual void UpdateParticipantState(
        I_Soul* soul,
        std::int32_t state,
        bool enabled) = 0;                                         // [18]
    virtual void DebugTriggerEvent() = 0;                           // [19]
    virtual void Clear() = 0;                                      // [20]
    virtual void Update() = 0;                                     // [21]
};

static_assert(sizeof(I_SkirmishManager) == 0x08,
              "I_SkirmishManager size mismatch");

} // namespace wh::rpgmodule
