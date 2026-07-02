#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::C_InventorySoul -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x148.
// -----------------------------------------------
// RTTI-named (ctor sub_1803F22D8 writes THREE C_InventorySoul-labelled vtables @+0x00/+0x08/+0x10
// -- multiple inheritance; the two secondary BASE IDENTITIES were not resolved, so the secondary
// vptrs are kept as raw slots below rather than invented interfaces). dtor sub_180966F00.
// Embedded in C_Soul @+0x198. owner @+0x18; interior to the byte @+0x146 UNRESOLVED (flagged).

namespace wh::rpgmodule {

class C_Soul;

class C_InventorySoul {
public:
    virtual ~C_InventorySoul() = default;   // +0x00  primary vptr
    void*    m_secondaryVptr08;             // +0x08  secondary base vptr (base identity unresolved)
    void*    m_secondaryVptr10;             // +0x10  secondary base vptr (base identity unresolved)
    C_Soul*  m_pOwner;                      // +0x18  back-ptr
    uint64_t m_unk20[36];                   // +0x20..+0x140  unresolved interior
    uint8_t  m_unk140[6];                   // +0x140..+0x146 unresolved
    uint8_t  m_flag146;                     // +0x146  (ctor writes byte @+326)
    uint8_t  _pad147;                       // +0x147
};
static_assert(sizeof(C_InventorySoul) == 0x148, "C_InventorySoul must be 0x148");

}  // namespace wh::rpgmodule
