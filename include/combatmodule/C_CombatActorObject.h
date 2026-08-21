#pragma once
#include <cstdint>
#include "E_CombatSubsystem.h"
#include "S_CombatActorObjectDebugLine.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorObject;
    virtual ~C_CombatActorObject() = default;                         // [0]
    virtual void Reset() = 0;                                        // [1]
    virtual E_CombatSubsystem GetSubsystemId() const = 0;             // [2]
    virtual const char* GetName() const;                              // [3]
    virtual S_CombatActorObjectDebugLine GetDebugLabel();             // [4]
    virtual S_CombatActorObjectDebugLine GetDebugInfo();              // [5]

    C_CombatActor* m_pOwner;                                         // +0x08, borrowed
};
static_assert(sizeof(C_CombatActorObject) == 0x10);

}  // namespace wh::combatmodule
