#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"
#include "I_CombatActorWeapons.h"
#include "S_QueuedWeaponChange.h"
#include "../CryEngine/CryCommon/CryArray.h"

namespace wh::combatmodule {

class C_CombatActor;

// The retail primary vtable has literal nullptr entries for Reset and inactive
// phases. Reset therefore remains inherited-pure here rather than being invented.
class C_CombatActorWeapons final
    : public C_CombatActorUpdatedObject
    , public I_CombatActorWeapons {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorWeapons;
    explicit C_CombatActorWeapons(C_CombatActor* pOwner);
    ~C_CombatActorWeapons() override;

    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::WEAPONS;
    }
    const char* GetName() const override { return "Weapons"; }
    void UpdatePhase3() override;

    const wh::entitymodule::S_WeaponClass* GetEffectiveWeaponClass() const override;
    const wh::entitymodule::S_WeaponClass* GetWeaponClass(
        wh::entitymodule::E_HandSlot hand) const override;
    E_WeaponKind::Type GetWeaponKind() const override;
    bool HasEffectiveWeapon() const override;
    bool HasWeaponClassPair_12_11() const override;
    bool HasUsableEquipmentAttachment() const override;

    DynArray<S_QueuedWeaponChange> m_queuedWeaponChanges; // +0x20, owned
    bool         m_equipmentListenerRegistered;          // +0x28
    std::uint8_t _pad29[7];                              // +0x29
};
static_assert(sizeof(C_CombatActorWeapons) == 0x30);
static_assert(offsetof(C_CombatActorWeapons, m_queuedWeaponChanges) == 0x20);
static_assert(offsetof(C_CombatActorWeapons, m_equipmentListenerRegistered) == 0x28);

}  // namespace wh::combatmodule
