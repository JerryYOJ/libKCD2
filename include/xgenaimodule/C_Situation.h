#pragma once
#include <cstdint>
#include <vector>
#include "I_Situation.h"
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::xgenaimodule::C_Situation : I_Situation -- one live situation instance
// (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x78 (create-site proven:
// sub_180E9AF04 calls sub_1804F75C0(120) -> ctor sub_180E9AFB8(this, a2,
// a3=holder, a4:int, a5=domainVec, a6=WUID)).  dtor sub_180D9D564.
// -----------------------------------------------
// RTTI TD rva 0x4F4E280, COL 0x40DFA78.  Vtable rva 0x3AA4100 (18 slots, all
// overridden): [0]sub_181A72970 [1]sub_181A7FAF0 [2]sub_181A72EB0
// [3]sub_180638480 (SHARED body with C_SituationSubsystem holder slot [0])
// [4]sub_181A727E0 [5]0x79EB80 (shared getter stub) [6]sub_181A735C0
// [7]sub_180BD7B20 [8]sub_180B28170 [9]sub_180BD7800 [10]sub_180B27FD0
// [11]nullsub_1 [12]sub_180BD6578 [13]sub_180BD7548 [14]nullsub_1
// [15]sub_1832BCBD0 [16]sub_180BD59DC [17]deleting dtor sub_180D9D3DC.
// The +0x70 WUID is (holder+168) | 0x0900000000000000 (type-nibble 9).

namespace wh::xgenaimodule {

class C_Situation : public I_Situation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Situation;
    void _vf0()  override;   // [0]  sub_181A72970
    void _vf1()  override;   // [1]  sub_181A7FAF0
    void _vf2()  override;   // [2]  sub_181A72EB0
    void _vf3()  override;   // [3]  sub_180638480 (shared body)
    void _vf4()  override;   // [4]  sub_181A727E0
    void _vf5()  override;   // [5]  shared getter stub 0x79EB80
    void _vf6()  override;   // [6]  sub_181A735C0
    void _vf7()  override;   // [7]  sub_180BD7B20
    void _vf8()  override;   // [8]  sub_180B28170
    void _vf9()  override;   // [9]  sub_180BD7800
    void _vf10() override;   // [10] sub_180B27FD0
    void _vf11() override;   // [11] nullsub_1
    void _vf12() override;   // [12] sub_180BD6578
    void _vf13() override;   // [13] sub_180BD7548
    void _vf14() override;   // [14] nullsub_1
    void _vf15() override;   // [15] sub_1832BCBD0
    void _vf16() override;   // [16] sub_180BD59DC
    ~C_Situation() override; // [17] deleting dtor sub_180D9D3DC (body sub_180D9D564)

    int32_t            m_state;             // +0x08  ctor: 0 (state/flags) [U meaning]
    uint8_t            _pad0C[4];           // +0x0C
    void*              m_holder;            // +0x10  ctor a3 (holder/context) [U pointee]
    std::vector<void*> m_domainVec;         // +0x18  copied from ctor a5 (sub_180E9B160) [U elem type]
    int32_t            m_30;                // +0x30  ctor a4
    uint8_t            _pad34[4];           // +0x34
    std::vector<void*> m_vec38;             // +0x38  elem size 16 (dtor free-mask 0xF0) [U elem type]
    uint64_t           m_participantCount;  // +0x50
    uint64_t           m_participantLimit;  // +0x58  ctor: same count (duplicate/limit) [U role]
    void*              m_60;                // +0x60  ctor a2 [U pointee]
    void*              m_node68;            // +0x68  32-byte node (qword_18549D378(32)); destroyed by sub_180A2C368 [U type]
    framework::WUID    m_wuid;              // +0x70  (holder+168) | 0x09<<56
};
static_assert(sizeof(C_Situation) == 0x78, "C_Situation must be 0x78 (alloc 120 at sub_180E9AF04)");

}  // namespace wh::xgenaimodule
