#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_EquippableItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_ArmorItemClass -- KCD2 1.5.6. sizeof 0x118.
// -----------------------------------------------
// E_ItemType::Armor (4). Vtable 0x183A4F418, ctor sub_180754B04, copy-ctor sub_180D28D80,
// Clone sub_180D28CFC alloc 0x118. OnRegister vf[51] sub_180970684 (shared verbatim by Helmet
// and QuickSlotContainer; Hood wraps it): refresh clothing (+0xD0), cache S_ArmorType* from
// vf[10] id (clothing m_armorTypeId, else -1 -> null), then IFF clothing != null fill the four
// head-coverage bools from C_ArmorArchetype2BodySubpartDatabase (0x1853253A0) joins:
//   A = any joined body_subpart named "head_face" (0x181EE2890)
//   B = any joined subpart whose parent body_part is named "head" (0x180C625D8 bitset, writer
//       C_BodySubpartDatabase::RebuildIndices 0x180723A3C)
// WARNING: ctor does NOT init +0x110..+0x113 -- garbage until OnRegister, and OnRegister skips
// them when clothing is null. Bool identifiers reconstructed from the predicates (no RTTR).

namespace wh::entitymodule {

struct S_ArmorType;

class S_ArmorItemClass : public S_EquippableItemClass {
public:
    S_ArmorItemClass* GetAsArmorItemClass() override { return this; } // [29]

    S_ArmorType*     m_pArmorType;              // +0xE8  non-owning cache into C_ArmorTypeDatabase 0x185325470 (ctor 0; name reconstructed)
    std::uint64_t    _unkF0;                    // +0xF0  ctor 0; role UNVERIFIED
    std::uint64_t    _unkF8;                    // +0xF8  ctor 0; role UNVERIFIED
    std::int32_t     _unk100;                   // +0x100 ctor 0; role UNVERIFIED
    std::int32_t     m_maxStatus;               // +0x104 RTTR "MaxStatus"  ctor 1
    CryStringT<char> m_factionId;               // +0x108 RTTR "FactionId" (registrar 0x180FC9C78 last property)
    bool             m_coversHeadFace;          // +0x110 predicate A on clothing ArmorArchetypeId  [spelling UNVERIFIED]
    bool             m_coversHeadFaceAlternative; // +0x111 predicate A on AlternativeArmorArchetypeId  [spelling UNVERIFIED]
    bool             m_coversHead;              // +0x112 predicate B on ArmorArchetypeId  [spelling UNVERIFIED]
    bool             m_coversHeadAlternative;   // +0x113 predicate B on AlternativeArmorArchetypeId  [spelling UNVERIFIED]
    std::uint8_t     _pad114[4];                // +0x114
};
static_assert(sizeof(S_ArmorItemClass) == 0x118, "S_ArmorItemClass must be 0x118 (Clone alloc)");
static_assert(offsetof(S_ArmorItemClass, m_pArmorType) == 0xE8);
static_assert(offsetof(S_ArmorItemClass, m_factionId) == 0x108);
static_assert(offsetof(S_ArmorItemClass, m_coversHeadFace) == 0x110);

}  // namespace wh::entitymodule
