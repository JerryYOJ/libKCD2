#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::entitymodule::S_ItemInstanceData -- item-instance create/save blob (KCD2 1.5.6, kd7u).
// sizeof 0xF8.  [SYNTHETIC NAME -- no RTTI/RTTR exists for this type; do NOT treat the
// spelling as source-recovered.]
// -----------------------------------------------
// Non-polymorphic (init memsets from +0x00; no vptr). THE parameter of S_ItemClass vf[16..20]
// (Diff 0x180B56DA4 / Patch 0x180B5B134 / Fill 0x180B56CA8 / InitItemInstance 0x180468B70 /
// InitItemDefaults 0x180467FFC) and of the item factory 0x180466018 (class-GUID lookup at
// +0x50 in db 0x185325820). Init 0x1804533E4, copy 0x180516368, dtor 0x180453BEC.
// Embedded by S_DeactivatedItem (0x100 = vptr + blob) and S_ActiveQuestItem (0x108 = 0x10 +
// blob); a 0x100 variant (ctor 0x182A67608) appends one CryStringT at +0xF8.
// Patch tags (vf[17], word at pkt+8): 0 amount add-clamp>=0; 1 health add clamp[0,1];
// 2 flags OR; 3 flags AND-NOT; 5 -> +0x30 (8B) + +0x00 (16B); 6 expiry 8B; 0xA quality add;
// 0x12 -> +0x20 (16B).
// InitItemDefaults: flags &= 0xFFE7FFFE (clears bit0 equipped + bits 19/20); amount=1 if
// !IsDivisible; quality/health from the quality curve or {1, 1.0f}.

namespace wh::entitymodule {

struct S_ItemInstanceData {
    std::uint8_t        _unk00[0x10];            // +0x00  zero-init; patch tag 5 writes 16B here; role UNVERIFIED
    wh::framework::WUID m_owner;                 // +0x10  Fill <- C_Item+0x68
    wh::framework::WUID m_stolenFrom;            // +0x18  Fill <- C_Item+0x70; Diff vs BSS 0x185324E70
    std::uint8_t        _unk20[0x10];            // +0x20  zero-init; patch tag 0x12 target; role UNVERIFIED
    std::int64_t        m_ownerSetWorldTime;     // +0x30  Fill <- C_Item+0x78 (init 0)
    std::int64_t        m_expiryWorldTime;       // +0x38  Fill <- C_Item+0x80 (init INT64_MAX)
    CryGUID             m_instanceGuid;          // +0x40  factory vs zero sentinel 0x183A2DA58
    CryGUID             m_classGuid;             // +0x50  item-class registry key (db 0x185325820)
    std::uint32_t       _unk60;                  // +0x60  init 0x25 (variant path writes 0x20); role UNVERIFIED
    std::int32_t        m_amount;                // +0x64  Fill <- C_Item+0x50
    float               m_health;                // +0x68  Fill <- C_Item+0x54  [0,1]
    std::uint32_t       m_flags;                 // +0x6C  Fill <- C_Item+0x60
    std::uint32_t       _unk70;                  // +0x70  copy-copied dword; role UNVERIFIED
    std::uint8_t        _unk74[0x10];            // +0x74  zero-init; role UNVERIFIED
    std::uint8_t        _unk84[0xC];             // +0x84  zero-init; role UNVERIFIED
    std::int32_t        m_quality;               // +0x90  Fill <- C_Item::GetQuality 0x180469A70
    float               _unk94;                  // +0x94  init 1.0f; role UNVERIFIED
    void*               m_treeHead;              // +0x98  MSVC std::_Tree head (dummy node 0x30, ctor 0x180452BA4)
    std::size_t         m_treeSize;              // +0xA0  _Tree size; key/value types UNVERIFIED
    std::uint8_t        _unkA8[0x10];            // +0xA8  zero-init; role UNVERIFIED
    std::uint8_t        _unkB8[0x10];            // +0xB8  zero-init; role UNVERIFIED
    std::uint32_t       _unkC8;                  // +0xC8  role UNVERIFIED
    std::uint32_t       _unkCC;                  // +0xCC  role UNVERIFIED
    std::uint64_t       _unkD0;                  // +0xD0  role UNVERIFIED
    CryStringT<char>    m_strings[4];            // +0xD8  four empty-init strings; names UNVERIFIED
};
static_assert(sizeof(S_ItemInstanceData) == 0xF8, "S_ItemInstanceData must be 0xF8");
static_assert(offsetof(S_ItemInstanceData, m_owner) == 0x10, "owner WUID at 0x10");
static_assert(offsetof(S_ItemInstanceData, m_stolenFrom) == 0x18, "stolenFrom WUID at 0x18");
static_assert(offsetof(S_ItemInstanceData, m_classGuid) == 0x50, "class GUID at 0x50 (factory key)");
static_assert(offsetof(S_ItemInstanceData, m_amount) == 0x64, "amount at 0x64");
static_assert(offsetof(S_ItemInstanceData, m_quality) == 0x90, "quality at 0x90");
static_assert(offsetof(S_ItemInstanceData, m_strings) == 0xD8, "string tail at 0xD8");

}  // namespace wh::entitymodule
