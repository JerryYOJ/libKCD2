#pragma once
#include <cstdint>
#include "guimodule/C_UIFlashObject.h"

// -----------------------------------------------
// wh::guimodule::C_UIFlashListReputation -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x48 (ALLOC-PROVEN).
// -----------------------------------------------
// C_UIFlashObject serialization record (flash_leaves.md §1). Creator sub_180783E20
// N=88 (ctor 0x180783EC8). FillUIArgs override 0x18154C530. Names descriptive
// (UNVERIFIED); the +0x2C tail is ctor-only.

namespace wh::guimodule {

class C_UIFlashListReputation : public C_UIFlashObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIFlashListReputation;
    void FillUIArgs(void* pArgs) const override;   // [1] 0x18154C530

    CryStringT<char> m_name;        // +0x18
    int32_t          m_int20;       // +0x20
    bool             m_bool24;      // +0x24
    uint8_t          _pad25[3];     // +0x25
    int32_t          m_int28;       // +0x28
    uint8_t          _unk2C[0x1C];  // +0x2C..+0x48  ctor tail [UNVERIFIED]
};
static_assert(sizeof(C_UIFlashListReputation) == 0x48, "C_UIFlashListReputation must be 0x48 (creator sub_180783E20)");

}  // namespace wh::guimodule
