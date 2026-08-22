#pragma once
#include <cstdint>
#include <vector>
#include "C_Perk.h"

// -----------------------------------------------
// wh::rpgmodule::C_PerkList -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x70.
// -----------------------------------------------
// RTTI .?AVC_PerkList@rpgmodule@wh@@ (TD 0x184D539B0; COL @vtable-8 = 0x184129BF0; vtable 0x183A49FA0).
// Single-inheritance from wh::rpgmodule::I_EventListener (CHD both mdisp 0 -> one vtable).
// Embedded at S_SoulStatBlock+0x1F8 (live sheet @C_Soul+0x758).  Ctor inlined in
// S_SoulStatBlock::ctor sub_18070F3E8 @+504; dtor sub_180966C0C.
//
// Three MSVC std::vector (24B each): +0x10 trivial 8-byte elems (dtor frees only);
// +0x28 and +0x40 OWNED C_Perk* (deleting-dtor per slot via sub_18046C388).
// Learn/HasPerk use +0x40 (insert sub_18046B634(list+0x40); walk sub_1804686E8).
// +0x28 is a second owned store (sub_1804687E8 inserts here) -- role UNRESOLVED;
// native HasPerk does not search it.

namespace wh::rpgmodule {

class C_Soul;

class I_EventListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_EventListener;
    virtual ~I_EventListener() = default;
};

class C_PerkList : public I_EventListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerkList;

    C_Soul*                m_pOwner;      // +0x08  owner soul (stat-block ctor stores a2)
    std::vector<void*>     m_unk10;       // +0x10  8-byte trivial elems (dtor sub_181AB5490 only) [UNRESOLVED]
    std::vector<C_Perk*>   m_auxPerks;    // +0x28  owned C_Perk*; wiped without Deactivate (sub_18047059C).  Not in the HasPerk walk.  [role UNRESOLVED]
    std::vector<C_Perk*>   m_perks;       // +0x40  owned live C_Perk* -- Learn inserts here; HasPerk walks this then each perk's GetChildPerks()
    void*                  m_pStatCache;  // +0x58  owned 0x70-byte cache (alloc sub_180C3F09C; reset sub_1811240E8; freed sub_181AB5160)
    uint8_t                m_flags;       // +0x60  ctor &=0xF8; bit1 skips Deactivate on reset; bit2 listener registered
    uint8_t                _pad61[3];     // +0x61
    int32_t                m_counter;     // +0x68  ctor 0
    uint32_t               _pad6C;        // +0x6C
};
static_assert(sizeof(C_PerkList) == 0x70, "C_PerkList must be 0x70");
static_assert(offsetof(C_PerkList, m_auxPerks) == 0x28, "aux perks at 0x28");
static_assert(offsetof(C_PerkList, m_perks) == 0x40, "live perks at 0x40");

}  // namespace wh::rpgmodule
