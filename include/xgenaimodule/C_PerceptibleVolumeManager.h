#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptibleVolumeManager -- spatial registry of perceptible
// volumes, embedded at +0x120 of C_PerceptionManager (KCD2 WHGame.dll 1.5.6,
// kd7u).  sizeof 0x60 (ctor-proven: sub_180FB7764(PM+0x120), spans PM+0x120..
// +0x180).
// -----------------------------------------------
// RTTI TD rva 0x4F4C7F0; vtable 0x183FE6D98, 2 slots: [0] sub_1832AE970,
// [1] sub_1832AEFA0.  ROOT class (no bases).  +0x08 grid = sub_180FB7E5C(40, 40):
// a 40x40 C_RegularGrid spatial hash of perceptible volumes (alloc 376).

namespace wh::xgenaimodule {

class C_PerceptibleVolumeManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptibleVolumeManager;
    virtual ~C_PerceptibleVolumeManager();   // [0] sub_1832AE970 [U -- dtor placement unverified]
    virtual void _vf1();                     // [1] sub_1832AEFA0 [U role]

    void*    m_grid;        // +0x08  40x40 C_RegularGrid spatial hash (sub_180FB7E5C, alloc 376) [V]
    uint64_t m_unk10[10];   // +0x10..+0x58  ctor: 0 (vectors/lists) [U roles]
};
static_assert(sizeof(C_PerceptibleVolumeManager) == 0x60, "C_PerceptibleVolumeManager must be 0x60 (PM+0x120..+0x180)");

}  // namespace wh::xgenaimodule
