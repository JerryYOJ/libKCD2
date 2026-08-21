#pragma once
#include <cstddef>
#include "E_WeaponKind.h"
#include "../entitymodule/E_HandSlot.h"

namespace wh::entitymodule {
struct S_WeaponClass;
}

namespace wh::combatmodule {

class I_CombatActorWeapons {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_CombatActorWeapons;
    virtual ~I_CombatActorWeapons() = default; // [0]
    virtual const wh::entitymodule::S_WeaponClass* GetEffectiveWeaponClass() const = 0; // [1]
    virtual const wh::entitymodule::S_WeaponClass* GetWeaponClass(
        wh::entitymodule::E_HandSlot hand) const = 0; // [2]
    virtual E_WeaponKind::Type GetWeaponKind() const = 0; // [3]
    virtual bool HasEffectiveWeapon() const = 0; // [4]
    virtual bool HasWeaponClassPair_12_11() const = 0; // [5], data labels unresolved
    virtual bool HasUsableEquipmentAttachment() const = 0; // [6]
};
static_assert(sizeof(I_CombatActorWeapons) == 0x08);

}  // namespace wh::combatmodule
