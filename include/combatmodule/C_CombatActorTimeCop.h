#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "C_CombatActorObject.h"
#include "E_TimeCopPhaseKind.h"
#include "S_TimeCopConfiguration.h"
#include "S_TimeCopPhaseRecord.h"
#include "S_TimeCopSynchronizationGate.h"

namespace wh::combatmodule {

class C_CombatActor;
class C_TimingSolver;

class C_CombatActorTimeCop final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorTimeCop;
    explicit C_CombatActorTimeCop(C_CombatActor* pOwner);
    ~C_CombatActorTimeCop() override;

    void Reset() override;
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::TIME_COP;
    }
    const char* GetName() const override { return "TimeCop"; }
    S_CombatActorObjectDebugLine GetDebugLabel() override;
    S_CombatActorObjectDebugLine GetDebugInfo() override;

    float m_timeScale;                                      // +0x10
    bool  m_isMaster;                                       // +0x14
    std::uint8_t _pad15[3];                                 // +0x15
    S_TimeCopConfiguration m_configuration;                 // +0x18
    std::vector<std::unique_ptr<C_TimingSolver>> m_solvers; // +0x38, owned
    float m_elapsed;                                        // +0x50
    float m_dilatedElapsed;                                 // +0x54
    std::vector<S_TimeCopPhaseRecord> m_phases;             // +0x58
    std::uint32_t m_lastProcessedFrameId;                   // +0x70
    float m_addedAnimationTime;                             // +0x74
    S_TimeCopSynchronizationGate m_gate;                    // +0x78
};
static_assert(sizeof(C_CombatActorTimeCop) == 0x98);
static_assert(offsetof(C_CombatActorTimeCop, m_timeScale) == 0x10);
static_assert(offsetof(C_CombatActorTimeCop, m_configuration) == 0x18);
static_assert(offsetof(C_CombatActorTimeCop, m_solvers) == 0x38);
static_assert(offsetof(C_CombatActorTimeCop, m_phases) == 0x58);
static_assert(offsetof(C_CombatActorTimeCop, m_gate) == 0x78);

}  // namespace wh::combatmodule
