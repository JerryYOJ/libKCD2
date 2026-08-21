#pragma once
#include <cstddef>

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorPhysics {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorPhysics;
    virtual ~C_CombatActorPhysics(); // [0], sole virtual slot

protected:
    explicit C_CombatActorPhysics(C_CombatActor* pOwner) noexcept;

public:
    C_CombatActor* m_pOwner; // +0x08, borrowed
};
static_assert(sizeof(C_CombatActorPhysics) == 0x10);
static_assert(offsetof(C_CombatActorPhysics, m_pOwner) == 0x08);

}  // namespace wh::combatmodule
