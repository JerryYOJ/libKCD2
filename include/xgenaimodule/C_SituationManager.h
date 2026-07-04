#pragma once
#include <cstdint>
#include "I_SEBehaviorConditionManager.h"
#include "../game/I_EntitySideEffectCallback.h"
#include "C_SEConditionDatabase.h"

// -----------------------------------------------
// wh::xgenaimodule::C_SituationManager : I_SEBehaviorConditionManager (@+0x0) +
// wh::game::I_EntitySideEffectCallback (@+0x8) -- global situation manager
// SINGLETON at qword_185493960 (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x120
// (create-site proven: getter sub_1807D2460: qword_18549D378(288,&v5),
// dword_1851DFB18 += 0x120, ctor sub_1806010EC(result)).
// -----------------------------------------------
// RTTI TD rva 0x4F4E308; COLs 0x4551330 (@+0) / 0x4551308 (@+8).  Primary
// vtable rva 0x3FE8708 (2 slots: [0]sub_1832B98D8 [1]dtor sub_1832B760C);
// secondary vtable rva 0x3FE86F0 (2 slots: [0]dtor thunk sub_1815FFE3C
// [1]sub_1815FFE30).  ctor registers cvars wh_ai_SituationInterruptPriority
// (+0x108, default 10), wh_ai_SituationInterruptUrgency (+0x110, default
// "Slow"), wh_ai_SituationManagerSearchBudget (+0x11C); inits the registry at
// +0x38 (sub_1805FFC9C); intrusive-list sentinel at +0xC8; registers a
// side-effect callback via qword_185494490 vtbl+256 (functor sub_1805F5DA0).

namespace wh::xgenaimodule {

class C_SituationManager
    : public I_SEBehaviorConditionManager,
      public game::I_EntitySideEffectCallback {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SituationManager;
    void BcmVf0() override;                        // primary [0] sub_1832B98D8
    ~C_SituationManager() override;                // primary [1] sub_1832B760C / secondary [0] thunk sub_1815FFE3C
    void OnEntitySideEffect(void* sideEffect) override; // secondary [1] sub_1815FFE30

    void*    m_10;                    // +0x10  ctor: 0 [U role]
    void*    m_18;                    // +0x18  ctor: 0 [U role]
    void*    m_20;                    // +0x20  ctor: 0 [U role]
    uint8_t  _unk28[8];               // +0x28  [U]
    int32_t  m_30;                    // +0x30  ctor: 0 [U role]
    uint8_t  _pad34[4];               // +0x34
    C_SEConditionDatabase m_seConditionDb; // +0x38..+0xA0  embedded situation-condition DB
                                      //   (ctor sub_1806010EC calls sub_1805FFC9C(this+0x38); G6I)
    uint8_t  m_zeroA0[0x20];          // +0xA0..+0xC0  zeroed ptrs [U roles]
    uint8_t  _unkC0[8];               // +0xC0  [U]
    void*    m_listSentinelC8;        // +0xC8  24-byte intrusive-list sentinel (self-linked; +24 WORD=257)
    uint8_t  _unkD0[8];               // +0xD0  [U]
    uint8_t  m_zeroD8[0x20];          // +0xD8..+0xF8  zeroed ptrs [U roles]
    uint8_t  _unkF8[8];               // +0xF8  [U]
    int32_t  m_100;                   // +0x100 [U role]
    int16_t  m_104;                   // +0x104 [U role]
    uint8_t  _pad106[2];              // +0x106
    int32_t  m_cvarInterruptPriority; // +0x108 cvar wh_ai_SituationInterruptPriority (default 10)
    uint8_t  _pad10C[4];              // +0x10C
    char*    m_cvarInterruptUrgency;  // +0x110 cvar wh_ai_SituationInterruptUrgency (default "Slow")
    int8_t   m_priorityByte;          // +0x118 clamped from +0x108 (if <= 0xFF)
    uint8_t  _pad119[3];              // +0x119
    int32_t  m_cvarSearchBudget;      // +0x11C cvar wh_ai_SituationManagerSearchBudget
};
static_assert(sizeof(C_SituationManager) == 0x120, "C_SituationManager must be 0x120 (alloc 288 at sub_1807D2460)");

}  // namespace wh::xgenaimodule
