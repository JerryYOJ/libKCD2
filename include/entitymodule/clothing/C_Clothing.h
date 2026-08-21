#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include "C_Component.h"

// -----------------------------------------------
// wh::entitymodule::clothing::C_Clothing -- concrete clothing asset (KCD2 1.5.6, kd7u).
// sizeof 0x148.
// -----------------------------------------------
// RTTI .?AVC_Clothing@clothing@entitymodule@wh@@   vtable 0x183A4F760   ctor 0x1807551B0.
// RTTR constructor_wrapper<C_Clothing, as_std_shared_ptr> factory 0x180755108 (alloc 0x148,
// ctrl-block _Ref_count<C_Clothing> vfptr 0x183A4F7E0); clone vf[1] 0x181E96050 -> 0x181E94A70
// (_Ref_count_obj2<C_Clothing> 0x183E8B470, alloc 0x158). GetRttrType vf[12] 0x1809734B8
// returns the exact-C_Clothing type (0x181025984, size 0x148) -- the Equippable/Hood setter gate.
// Tail slot->name map dual-verifier proven from registrar 0x180107B80 + getters/setters.

namespace wh::entitymodule::clothing {

class C_Clothing : public C_Component {
public:
    // +0x120  backing store of RTTR "ArmorType" (BY-VALUE string getter 0x182917678 projects this
    // id through C_ArmorTypeDatabase 0x185325470; setter 0x180D65284 writes {id, has=1}).
    // Optional payload int32 vs enum UNVERIFIED.
    std::optional<std::int32_t> m_armorTypeId;                    // +0x120  member spelling reconstructed
    std::optional<std::int32_t> m_armorArchetypeId;               // +0x128  RTTR "ArmorArchetypeId"
    std::optional<std::int32_t> m_alternativeArmorArchetypeId;    // +0x130  RTTR "AlternativeArmorArchetypeId"
    CryStringT<char>            m_dropModel;                      // +0x138  RTTR "DropModel" (getter 0x181A834C0)
    CryStringT<char>            m_dropMaterial;                   // +0x140  RTTR "DropMaterial" (getter 0x1809CBA50)
};
static_assert(sizeof(C_Clothing) == 0x148, "C_Clothing must be 0x148 (factory 0x180755108 alloc)");
static_assert(offsetof(C_Clothing, m_armorTypeId) == 0x120);
static_assert(offsetof(C_Clothing, m_dropModel) == 0x138);
static_assert(offsetof(C_Clothing, m_dropMaterial) == 0x140);

}  // namespace wh::entitymodule::clothing
