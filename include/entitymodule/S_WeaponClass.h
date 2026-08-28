#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rpgmodule/E_SoulSkill.h"
#include "../rttr/rttr_enable.h"
#include "E_WeaponEquipSlot.h"

namespace wh::entitymodule {

class S_WeaponClass {
public:
    virtual ~S_WeaponClass();                               // [0]
    RTTR_ENABLE()                                           // [1..3]

    int m_id;                                               // +0x08 RTTR "id"
    std::uint8_t _pad0C[4];                                 // +0x0C
    CryStringT<char> m_name;                                // +0x10 RTTR "name"
    wh::rpgmodule::E_SoulSkill m_skill;                     // +0x18 RTTR "skill"
    int m_attachmentSlotId;                                 // +0x1C RTTR "attachment_slot_id"
    E_WeaponEquipSlot m_equipSlot;                          // +0x20 RTTR "equip_slot"
    bool m_isTwohanded;                                     // +0x24 RTTR "is_twohanded"
    bool m_inRightHand;                                     // +0x25 RTTR "in_right_hand"
    std::uint8_t _pad26[2];                                 // +0x26
    int m_holsterSlotId;                                    // +0x28 RTTR "holster_slot_id"
    std::uint8_t m_genderId;                                // +0x2C RTTR "gender_id"
    std::uint8_t _pad2D[3];                                 // +0x2D
    int m_itemManipulationType;                             // +0x30 RTTR "item_manipulation_type"
    int m_primaryAttackTypeId;                              // +0x34 RTTR "primary_attack_type_id"
    int m_secondaryAttackTypeId;                            // +0x38 RTTR "secondary_attack_type_id"
    float m_attackDistance;                                 // +0x3C RTTR "attack_distance"
    bool m_isBlocking;                                      // +0x40 RTTR "is_blocking"
    std::uint8_t _pad41[3];                                 // +0x41
    float m_syncGuardDistance;                              // +0x44 RTTR "sync_guard_distance"
    int m_syncGuardPriority;                                // +0x48 RTTR "sync_guard_priority"
    float m_maxAttackDistance;                              // +0x4C RTTR "max_attack_distance"
    int m_collisionMode;                                    // +0x50 RTTR "collision_mode"
    int m_animCollisionMode;                                // +0x54 RTTR "anim_collision_mode"
    int m_combatPriority;                                   // +0x58 RTTR "combat_priority"
    float m_horsePullDownDistance;                          // +0x5C RTTR "horse_pull_down_distance"
    float m_horsePullDownMaxSpeed;                          // +0x60 RTTR "horse_pull_down_max_speed"
    float m_horsePullDownZTolerance;                        // +0x64 RTTR "horse_pull_down_z_tolerance"
    float m_huntAttackDistance;                             // +0x68 RTTR "hunt_attack_distance"
    float m_zoneChangeTimeoutCoef;                          // +0x6C RTTR "zone_change_timeout_coef"
    CryGUID m_drawBuffId;                                   // +0x70 RTTR "draw_buff_id"
    CryGUID m_alternativeDrawBuffId;                        // +0x80 RTTR "alternative_draw_buff_id"
    int m_sharpeningZoneCount;                              // +0x90 RTTR "sharpening_zone_count"
    std::uint8_t _pad94[4];                                 // +0x94
};

static_assert(offsetof(S_WeaponClass, m_name) == 0x10,
              "S_WeaponClass::m_name offset mismatch");
static_assert(offsetof(S_WeaponClass, m_equipSlot) == 0x20,
              "S_WeaponClass::m_equipSlot offset mismatch");
static_assert(offsetof(S_WeaponClass, m_attackDistance) == 0x3C,
              "S_WeaponClass::m_attackDistance offset mismatch");
static_assert(offsetof(S_WeaponClass, m_drawBuffId) == 0x70,
              "S_WeaponClass::m_drawBuffId offset mismatch");
static_assert(offsetof(S_WeaponClass, m_sharpeningZoneCount) == 0x90,
              "S_WeaponClass::m_sharpeningZoneCount offset mismatch");
static_assert(sizeof(S_WeaponClass) == 0x98,
              "S_WeaponClass size mismatch");

}  // namespace wh::entitymodule
