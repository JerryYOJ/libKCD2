#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorObject.h"
#include "../entitymodule/C_ItemWrapper.h"
#include "../entitymodule/E_HandSlot.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorVirtualWeapon final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorVirtualWeapon;
    explicit C_CombatActorVirtualWeapon(C_CombatActor* pOwner);
    ~C_CombatActorVirtualWeapon() override;

    void Reset() override;
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::VIRTUAL_WEAPON;
    }
    const char* GetName() const override { return "VIRTUAL_WEAPON"; }

    wh::entitymodule::C_ItemWrapper* m_pItemWrapper; // +0x10, owned
    wh::entitymodule::E_HandSlot     m_handSlot;     // +0x18
    std::uint32_t                    _pad1C;          // +0x1C
};
static_assert(sizeof(C_CombatActorVirtualWeapon) == 0x20);
static_assert(offsetof(C_CombatActorVirtualWeapon, m_pItemWrapper) == 0x10);
static_assert(offsetof(C_CombatActorVirtualWeapon, m_handSlot) == 0x18);

}  // namespace wh::combatmodule
