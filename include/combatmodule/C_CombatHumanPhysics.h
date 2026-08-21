#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorPhysics.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatHumanPhysics final : public C_CombatActorPhysics {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatHumanPhysics;
    explicit C_CombatHumanPhysics(C_CombatActor* pOwner) noexcept;
    ~C_CombatHumanPhysics() override;

    // Complete-size witness only. No KCD2 code initializes, reads, writes, or
    // destroys these bytes; original parent-vs-leaf ownership is undecidable.
    std::byte m_unobservedTail[0x08]; // +0x10
};
static_assert(sizeof(C_CombatHumanPhysics) == 0x18);
static_assert(offsetof(C_CombatHumanPhysics, m_unobservedTail) == 0x10);

}  // namespace wh::combatmodule
