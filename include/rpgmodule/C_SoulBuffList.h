#pragma once
#include <cstdint>
#include <vector>

// -----------------------------------------------
// wh::rpgmodule::C_SoulBuffList -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x198 (non-polymorphic).
// -----------------------------------------------
// SYNTHETIC NAME. C_Soul's buff list/manager aggregate @C_Soul+0xAF8. ctor sub_1803F1FBC (+
// sub_1803F4268); the C_Soul dtor iterates m_buffs calling each buff's VIRTUAL dtor -- the soul
// OWNS its buff instances (C_BuffManager only keeps a global by-WUID index). This block also
// absorbs KCD1's S_SoulWaitConfig-style timing (FLT_MAX defaults). Anchors verify-confirmed;
// the two embedded sub-objects' interiors + exact extents are UNRESOLVED (tiled by anchor,
// flagged).

namespace wh::rpgmodule {

class C_BuffInstanceBase;

struct C_SoulBuffList {
    std::vector<C_BuffInstanceBase*> m_buffs;  // +0x000  OWNING (virtual-delete on soul teardown)
    uint64_t m_counters18[4];                  // +0x018..+0x038  ctor-arg-derived counters (unresolved)
    float    m_timer38;                        // +0x038  init FLT_MAX
    uint32_t m_unk3C;                          // +0x03C  (unresolved)
    uint64_t m_unk40[3];                       // +0x040..+0x058  (unresolved)
    uint64_t m_subobjA58[9];                   // +0x058..+0x0A0  sub-object (ctor sub_1803F204C; extent inferred)
    uint32_t m_unkA0;                          // +0x0A0  (unresolved)
    uint16_t m_unkA4;                          // +0x0A4  (unresolved)
    uint16_t m_wordA6;                         // +0x0A6  (sub_180FBB1D4(+0xA6, 2))
    uint64_t m_unkA8;                          // +0x0A8  (unresolved)
    uint64_t m_subobjB0[27];                   // +0x0B0..+0x188  sub-object (ctor sub_1803F2148; extent inferred)
    float    m_timer188;                       // +0x188  init FLT_MAX
    float    m_unk18C;                         // +0x18C  (unresolved)
    float    m_timer190;                       // +0x190  init FLT_MAX
    uint32_t _pad194;                          // +0x194  align to 0x198
};
static_assert(sizeof(C_SoulBuffList) == 0x198, "C_SoulBuffList must be 0x198");

}  // namespace wh::rpgmodule
