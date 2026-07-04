#pragma once
#include <cstdint>
#include <vector>

// -----------------------------------------------
// wh::xgenaimodule::C_LODAgent -- abstract LOD agent base (NOT a singleton)
// (KCD2 WHGame.dll 1.5.6, kd7u).  Size folded into the derived classes
// (C_LODAgentNPC TD 0x4F6E490, C_PerceptibleVolume TD 0x4F4C560) -- NO
// static_assert.  Base ctor sub_180BDA08C(this, char initFlag) writes only the
// vptr (+ mem tracking if initFlag & 1).
// -----------------------------------------------
// RTTI TD rva 0x4EFF2D0 (root, numBase=1).  Vtable rva 0x3A82FE8, COL
// 0x40DC5F8 -- 12 slots: [0] dtor sub_183320CB4, [1][2][4][9] _purecall,
// [3]sub_181A74A40, [5][8]sub_180838AE0 (shared body), [6][10][11] nullsub,
// [7]sub_1833220F0.  Member hint from dtor sub_1832A8774: std::vector @+0x18
// (elem stride 0x10); +0x08..+0x18 not attributed [U].

namespace wh::xgenaimodule {

class C_LODAgent {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LODAgent;
    virtual ~C_LODAgent();     // [0]  dtor sub_183320CB4
    virtual void _vf1() = 0;   // [1]  [U role]
    virtual void _vf2() = 0;   // [2]  [U role]
    virtual void _vf3();       // [3]  sub_181A74A40 [U role]
    virtual void _vf4() = 0;   // [4]  [U role]
    virtual void _vf5();       // [5]  sub_180838AE0 (shared) [U role]
    virtual void _vf6();       // [6]  nullsub [U role]
    virtual void _vf7();       // [7]  sub_1833220F0 [U role]
    virtual void _vf8();       // [8]  sub_180838AE0 (shared) [U role]
    virtual void _vf9() = 0;   // [9]  [U role]
    virtual void _vf10();      // [10] nullsub [U role]
    virtual void _vf11();      // [11] nullsub [U role]

    uint8_t            _unk08[0x10];  // +0x08..+0x18  [U]
    std::vector<void*> m_vec18;       // +0x18  elem stride 0x10 in dtor free [U elem type]
};
// abstract; full size folded into derived -- no static_assert.

}  // namespace wh::xgenaimodule
