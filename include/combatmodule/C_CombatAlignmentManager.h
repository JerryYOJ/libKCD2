#pragma once
#include <cstddef>
#include <cstdint>
#include <set>
#include <vector>
#include "C_CombatActorUpdatedObject.h"
#include "S_CombatAlignmentPrep.h"
#include "S_CombatAppliedAlignment.h"
#include "S_RecursiveSRWLock.h"

class IProceduralClip;

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatAlignmentManager final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatAlignmentManager;
    explicit C_CombatAlignmentManager(C_CombatActor* pOwner);
    ~C_CombatAlignmentManager() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::ALIGNMENT;
    }
    const char* GetName() const override { return "Alignment"; }
    S_CombatActorObjectDebugLine GetDebugLabel() override;
    void UpdatePhase1() override;
    void UpdatePhase2() override;

    std::int32_t                          m_cachedActionAlignment; // +0x18
    std::uint32_t                         _pad1C;                   // +0x1C
    S_RecursiveSRWLock                    m_lock;                   // +0x20
    std::vector<S_CombatAlignmentPrep>    m_prepQueue;              // +0x30
    std::set<IProceduralClip*>            m_stopClips;              // +0x48
    std::vector<S_CombatAppliedAlignment> m_appliedAlignments;      // +0x58
    std::uint32_t                         m_currentActionTypeId;    // +0x70
    std::uint32_t                         m_opponentActionTypeId;   // +0x74
};
static_assert(sizeof(C_CombatAlignmentManager) == 0x78);
static_assert(offsetof(C_CombatAlignmentManager, m_cachedActionAlignment) == 0x18);
static_assert(offsetof(C_CombatAlignmentManager, m_lock) == 0x20);
static_assert(offsetof(C_CombatAlignmentManager, m_prepQueue) == 0x30);
static_assert(offsetof(C_CombatAlignmentManager, m_stopClips) == 0x48);
static_assert(offsetof(C_CombatAlignmentManager, m_appliedAlignments) == 0x58);
static_assert(offsetof(C_CombatAlignmentManager, m_currentActionTypeId) == 0x70);
static_assert(offsetof(C_CombatAlignmentManager, m_opponentActionTypeId) == 0x74);

}  // namespace wh::combatmodule
