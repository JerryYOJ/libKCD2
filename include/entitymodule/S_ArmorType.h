#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::entitymodule::S_ArmorType -- typed armor_type DB row (KCD2 1.5.6, kd7u).  sizeof 0x48.
// -----------------------------------------------
// NO standalone RTTI (.?AUS_ArmorType@ absent) -- the type survives only inside template RTTI:
// C_ObjectTableDatabase<S_ArmorType, S_ArmorTypeDBData>, IdIndexed, DynamicEnum, and
// C_ArmorTypeDatabase (instance 0x185325470, ctor 0x18192069C, primary vtable 0x183C37C08,
// table "armor_type"). Raw DBData stride 0x40 (ParseRows 0x1813ED910); typed converter
// 0x1813EDA0C + emplace 0x1813ED8AC prove this 0x48 layout. Field names = schema column
// spellings (0x18013BC10). S_ArmorItemClass caches a non-owning pointer to one of these.

namespace wh::entitymodule {

struct S_ArmorType {
    std::int32_t     m_id;                          // +0x00  col "Id" (PK)
    std::uint32_t    _pad04;                        // +0x04
    CryStringT<char> m_name;                        // +0x08  col "Name" (clothing ArmorType getter copies this)
    CryGUID          m_equipBuffId;                 // +0x10  col "EquipBuffId" (default all-zero)
    bool             m_canHealthChange;             // +0x20  col "CanHealthChange" (default true)
    std::uint8_t     _pad21[7];                     // +0x21
    CryStringT<char> m_surface;                     // +0x28  col "Surface"
    float            m_surfacePriorityMultiplier;   // +0x30  col "SurfacePriorityMultiplier" (default 1.0f)
    std::uint32_t    _pad34;                        // +0x34
    CryStringT<char> m_animationTag;                // +0x38  col "AnimationTag" (default empty)
    std::uint32_t    m_animationTagCrc;             // +0x40  case-insensitive CRC32 (0x1805AFA90); UNWRITTEN when tag empty -- value then UNVERIFIED
    std::uint32_t    _pad44;                        // +0x44
};
static_assert(sizeof(S_ArmorType) == 0x48, "S_ArmorType must be 0x48 (vector stride /0x48)");
static_assert(offsetof(S_ArmorType, m_equipBuffId) == 0x10);
static_assert(offsetof(S_ArmorType, m_animationTagCrc) == 0x40);

}  // namespace wh::entitymodule
