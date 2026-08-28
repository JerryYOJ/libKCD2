#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "E_AmmoLength.h"
#include "E_FireOnHitMode.h"
#include "E_LoadingMovement.h"
#include "S_WeaponClass.h"

namespace wh::entitymodule {

class S_MissileWeaponClass : public S_WeaponClass {
public:
    ~S_MissileWeaponClass() override;
    RTTR_ENABLE(S_WeaponClass)

    std::uint8_t m_ammoClassMask;                           // +0x98 accessor backing "ammo_class"
    bool m_autoLoad;                                        // +0x99 RTTR "auto_load"
    bool m_requiresCharging;                                // +0x9A RTTR "requires_charging"
    bool m_requiresCocking;                                 // +0x9B RTTR "requires_cocking"
    bool m_keepLoaded;                                      // +0x9C RTTR "keep_loaded"
    bool m_keepLoadedInInventory;                           // +0x9D RTTR "keep_loaded_in_inventory"
    E_FireOnHitMode::Type m_fireOnHit;                      // +0x9E RTTR "fire_on_hit"
    std::uint8_t _pad9F;                                    // +0x9F
    CryGUID m_loadingItemFirst;                             // +0xA0 RTTR "loading_item_first"
    CryGUID m_loadingItemSecond;                            // +0xB0 RTTR "loading_item_second"
    CryGUID m_firingItem;                                   // +0xC0 RTTR "firing_item"
    CryStringT<char> m_animationTag;                        // +0xD0 RTTR "animation_tag"
    CryStringT<char> m_leverAnimationTag;                   // +0xD8 RTTR "lever_animation_tag"
    bool m_attachLeverToWeapon;                             // +0xE0 RTTR "attach_lever_to_weapon"
    E_LoadingMovement::Type m_loadingMovement;              // +0xE1 RTTR "loading_movement"
    bool m_unknownE2;                                       // +0xE2 RTTR duplicate label
    E_AmmoLength::Type m_ammoLength;                        // +0xE3 RTTR "ammo_length"
    float m_battlementOffset;                               // +0xE4 RTTR "battlement_offset"
    float m_minAimPitch;                                    // +0xE8 RTTR "min_aim_pitch"
    float m_unknownEC;                                      // +0xEC RTTR duplicate label
    float m_minAimPitchMounted;                             // +0xF0 RTTR "min_aim_pitch_mounted"
    float m_unknownF4;                                      // +0xF4 RTTR duplicate label
    float m_unknownF8;                                      // +0xF8 RTTR duplicate label
    float m_maxAimYawMounted;                               // +0xFC RTTR "max_aim_yaw_mounted"
};

static_assert(offsetof(S_MissileWeaponClass, m_ammoClassMask) == 0x98,
              "S_MissileWeaponClass::m_ammoClassMask offset mismatch");
static_assert(offsetof(S_MissileWeaponClass, m_loadingItemFirst) == 0xA0,
              "S_MissileWeaponClass::m_loadingItemFirst offset mismatch");
static_assert(offsetof(S_MissileWeaponClass, m_animationTag) == 0xD0,
              "S_MissileWeaponClass::m_animationTag offset mismatch");
static_assert(offsetof(S_MissileWeaponClass, m_ammoLength) == 0xE3,
              "S_MissileWeaponClass::m_ammoLength offset mismatch");
static_assert(sizeof(S_MissileWeaponClass) == 0x100,
              "S_MissileWeaponClass size mismatch");

}  // namespace wh::entitymodule
