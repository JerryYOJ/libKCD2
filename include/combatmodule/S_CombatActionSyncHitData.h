#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include "C_CombatActionData.h"
#include "C_CombatActionTypeData.h"
#include "E_CombatActionType.h"
#include "../animationmodule/S_CaseInsensitiveHashedString.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::combatmodule::S_CombatActionSyncHitData -- KCD2 WHGame.dll 1.5.6. sizeof 0x218.
// -----------------------------------------------
// Typed combat_action_sync_hit definition. Converter sub_180933AB0 materializes each
// raw 0x158-byte DB row; C_CombatActionData base construction starts at sub_180931A98.

namespace wh::entitymodule { struct S_WeaponClass; }

namespace wh::combatmodule {

struct S_CombatActionSyncHitDataDBData;
class C_CombatWeaponGroupData;
class C_CombatGuardTypeData;
class C_CombatGuardStanceData;
class C_CombatZoneData;
class C_CombatAttackTypeData;
class C_CombatSideData;

#pragma pack(push, 4)
class S_CombatActionSyncHitData
    : public C_CombatActionData<S_CombatActionSyncHitData, S_CombatActionSyncHitDataDBData> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_CombatActionSyncHitData;
    bool          m_mounted;            // +0x040  mounted
    std::uint8_t  _pad041[3];           // +0x041
    std::uint32_t m_actorClassHash;     // +0x044  actor_class_hash
    bool          m_player;             // +0x048  player
    std::uint8_t  _pad049[7];           // +0x049
    std::int64_t  m_timestamp;          // +0x050  timestamp
    wh::animationmodule::S_CaseInsensitiveHashedString m_mnFragmentId; // +0x058  mn_fragment_id
    wh::animationmodule::S_CaseInsensitiveHashedString m_mnTags;       // +0x068  mn_tags
    std::int32_t  m_mnOptionIndex;      // +0x078  mn_option_index
    CryGUID       m_mnFragmentGuid;     // +0x07C  mn_fragment_guid
    float         m_animationDuration;  // +0x08C  animation_duration
    bool          m_isFullBody;         // +0x090  isfullbody
    bool          m_isOneShot;          // +0x091  isOneShot
    bool          m_hasAlignProcclip;   // +0x092  hasAlignProcclip
    std::uint8_t  _pad093;              // +0x093
    QuatT         m_initAlign0;         // +0x094  init_align0
    QuatT         m_initAlign1;         // +0x0B0  init_align1
    QuatT         m_initSecondaryAlign0;// +0x0CC  init_sec_align0
    QuatT         m_initSecondaryAlign1;// +0x0E8  init_sec_align1
    float         m_fadeIn;             // +0x104  fade_in
    bool          m_hasRagdoll;         // +0x108  hasRagdoll
    std::uint8_t  _pad109[3];           // +0x109
    std::uint32_t m_oppActorClassHash;  // +0x10C  opp_actor_class_hash
    std::map<std::int32_t, CryStringT<char>> m_oppActorClasses; // +0x110  resolved opp_actor_classes
    bool          m_oppMounted;         // +0x120  opp_mounted
    std::uint8_t  _pad121[7];           // +0x121
    C_CombatActionTypeData* m_pActionType; // +0x128  action_type_id
    std::int32_t  m_oppSpec;            // +0x130  opp_spec
    std::uint32_t _pad134;              // +0x134
    wh::entitymodule::S_WeaponClass* m_pRWeaponClass;    // +0x138  r_weapon_class_id
    wh::entitymodule::S_WeaponClass* m_pLWeaponClass;    // +0x140  l_weapon_class_id
    C_CombatWeaponGroupData* m_pRWeaponGroup;            // +0x148  r_weapon_group_id
    C_CombatWeaponGroupData* m_pLWeaponGroup;            // +0x150  l_weapon_group_id
    wh::entitymodule::S_WeaponClass* m_pOppRWeaponClass; // +0x158  opp_r_weapon_class_id
    wh::entitymodule::S_WeaponClass* m_pOppLWeaponClass; // +0x160  opp_l_weapon_class_id
    C_CombatWeaponGroupData* m_pOppRWeaponGroup;         // +0x168  opp_r_weapon_group_id
    C_CombatWeaponGroupData* m_pOppLWeaponGroup;         // +0x170  opp_l_weapon_group_id
    C_CombatGuardTypeData*   m_pGuardType;               // +0x178  guard_type_id
    C_CombatGuardStanceData* m_pGuardStance;             // +0x180  guard_stance_id
    C_CombatGuardStanceData* m_pOppGuardStance;          // +0x188  opp_guard_stance_id
    C_CombatZoneData*        m_pGuardZone;               // +0x190  guard_zone_id
    C_CombatGuardTypeData*   m_pEndGuardType;            // +0x198  end_guard_type_id
    C_CombatZoneData*        m_pEndGuardZone;            // +0x1A0  end_guard_zone_id
    C_CombatGuardStanceData* m_pEndGuardStance;          // +0x1A8  end_guard_stance_id
    std::int32_t             m_blockingHand;             // +0x1B0  blocking_hand
    bool                     m_virtualWeapon;            // +0x1B4  virtual_weapon
    std::uint8_t             _pad1B5[3];                 // +0x1B5
    C_CombatZoneData*        m_pBlockZone;               // +0x1B8  block_zone_id
    C_CombatAttackTypeData*  m_pOppAttackType;           // +0x1C0  opp_attack_type_id
    std::int32_t             m_comboStep;                // +0x1C8  combo_step
    float                    m_dropWeapons;              // +0x1CC  drop_weapons
    C_CombatSideData*        m_pCombatSide;              // +0x1D0  combat_side_id
    C_CombatZoneData*        m_pOppGuardZone;            // +0x1D8  opp_guard_zone_id
    wh::animationmodule::S_CaseInsensitiveHashedString m_comboId;          // +0x1E0  combo_id
    wh::animationmodule::S_CaseInsensitiveHashedString m_animationVariant; // +0x1F0  animation_variant
    Vec3                     m_minPoint;                 // +0x200  min_point
    Vec3                     m_maxPoint;                 // +0x20C  max_point

    E_CombatActionType GetActionTypeId() const {
        return m_pActionType
            ? static_cast<E_CombatActionType>(m_pActionType->combat_action_type_id)
            : E_CombatActionType::Invalid;
    }
};
#pragma pack(pop)

static_assert(sizeof(S_CombatActionSyncHitData) == 0x218);
static_assert(offsetof(S_CombatActionSyncHitData, m_mnFragmentGuid) == 0x07C);
static_assert(offsetof(S_CombatActionSyncHitData, m_pActionType) == 0x128);
static_assert(offsetof(S_CombatActionSyncHitData, m_pOppGuardZone) == 0x1D8);
static_assert(offsetof(S_CombatActionSyncHitData, m_minPoint) == 0x200);

}  // namespace wh::combatmodule
