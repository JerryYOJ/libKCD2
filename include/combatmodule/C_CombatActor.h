#pragma once
#include <cstdint>
#include <cstddef>
#include "I_CombatActor.h"
#include "../Offsets/vtables/EntityEventListenerWithCleanup.h"

// -----------------------------------------------
// wh::combatmodule::C_CombatActor -- per-entity combat state object (KCD2 1.5.6, kd7u)
// -----------------------------------------------
// sizeof 0x448 (factory sub_1810EFEDC allocs 1096 + _InterlockedAdd 0x448; KCD2 uses a
// custom deleter qword_18549D358, not a plain operator delete).
// primary vtable 0x183E3FAC8 (217 slots)   secondary (EntityEventListenerWithCleanup @+0x08) 0x183E3FAB0 (2 slots)
// default ctor sub_1810F01A8   subsystem builder = primary slot 90 sub_180916ECC   dtor sub_1810EF698
// Reached by every plugin via C_Actor::m_pCombatActor (C_Actor+0x278, GetOrCreateCombatActor sub_18072DC90).
//
// Bases: I_CombatActor @+0x00, EntityEventListenerWithCleanup @+0x08. Members from +0x10.
//
// [FUNDAMENTAL vs KCD1] sizeof 0x780 -> 0x448; EVERY member offset moved.
// [FUNDAMENTAL vs KCD1] MI bases: KCD1 had I_CombatActor@0/I_ItemAttachmentListener@8/IEntityEventListener@0x10;
//   KCD2 has I_CombatActor@0 + EntityEventListenerWithCleanup@8 (I_ItemAttachmentListener REMOVED).
// [FUNDAMENTAL vs KCD1] Signals re-architected: ~22 x 0x10-byte signal heads from +0x38 (KCD1 had
//   ~24 x 0x30-byte C_Signal); subscription is per-signal Connect() at primary slots ~109-174.
// [MODERATE vs KCD1] primary vtable 83 -> 217 slots; GetEntity [6]->[7], GetEntityId [7]->[8].
// [UNVERIFIED] SetAction (KCD1 slot 82) and DispatchCounterAction could NOT be located statically --
//   the action/combo dispatch was reworked. Do NOT hardcode a slot; find it via a runtime vtable dump.

namespace wh::combatmodule {

class C_CombatActorDirector;
class C_CombatScene;
class S_CombatActorState;
class C_CombatAutomation;
class C_CombatActorActionManager;
class C_CombatComboManager;
class C_CombatActorOpponentManager;

class C_CombatActor
    : public I_CombatActor
    , public Offsets::EntityEventListenerWithCleanup
{
public:
    // ---- I_CombatActor overrides [0]-[8] ----
    ~C_CombatActor() override = default;                                     // [0]  scalar-deleting dtor 0x1810EF51C
    void unk_1() override {}                                                 // [1]
    void unk_2() override {}                                                 // [2]
    void unk_3() override {}                                                 // [3]
    void unk_4() override {}                                                 // [4]
    void unk_5() override {}                                                 // [5]
    void unk_6() override {}                                                 // [6]
    Offsets::IEntity* GetEntity() const override { return m_pEntity; }       // [7]  0x181A739B0
    uint32_t GetEntityId() const override { return 0; }                      // [8]  0x180C57690

    // ---- C_CombatActor new virtuals [9]-[216] (extend the 217-slot primary vtable) ----
    // SetAction / DispatchCounterAction are NOT declared: their KCD2 slots are unresolved (see header note).
    virtual void unk_vf9() {}      // [9]
    virtual void unk_vf10() {}      // [10]
    virtual void unk_vf11() {}      // [11]
    virtual void unk_vf12() {}      // [12]
    virtual void unk_vf13() {}      // [13]
    virtual void unk_vf14() {}      // [14]
    virtual void unk_vf15() {}      // [15]
    virtual void unk_vf16() {}      // [16]
    virtual void unk_vf17() {}      // [17]
    virtual void unk_vf18() {}      // [18]
    virtual void unk_vf19() {}      // [19]
    virtual void unk_vf20() {}      // [20]
    virtual void unk_vf21() {}      // [21]
    virtual void unk_vf22() {}      // [22]
    virtual void unk_vf23() {}      // [23]
    virtual void unk_vf24() {}      // [24]
    virtual void unk_vf25() {}      // [25]
    virtual void unk_vf26() {}      // [26]
    virtual void unk_vf27() {}      // [27]
    virtual void unk_vf28() {}      // [28]
    virtual void unk_vf29() {}      // [29]
    virtual void unk_vf30() {}      // [30]
    virtual void unk_vf31() {}      // [31]
    virtual void unk_vf32() {}      // [32]
    virtual void unk_vf33() {}      // [33]
    virtual void unk_vf34() {}      // [34]
    virtual void unk_vf35() {}      // [35]
    virtual void unk_vf36() {}      // [36]
    virtual void unk_vf37() {}      // [37]
    virtual void unk_vf38() {}      // [38]
    virtual void unk_vf39() {}      // [39]
    virtual void unk_vf40() {}      // [40]
    virtual void unk_vf41() {}      // [41]
    virtual void unk_vf42() {}      // [42]
    virtual void unk_vf43() {}      // [43]
    virtual void unk_vf44() {}      // [44]
    virtual void unk_vf45() {}      // [45]
    virtual void unk_vf46() {}      // [46]
    virtual void unk_vf47() {}      // [47]
    virtual void unk_vf48() {}      // [48]
    virtual void unk_vf49() {}      // [49]
    virtual void unk_vf50() {}      // [50]
    virtual void unk_vf51() {}      // [51]
    virtual void unk_vf52() {}      // [52]
    virtual void unk_vf53() {}      // [53]
    virtual void unk_vf54() {}      // [54]
    virtual void unk_vf55() {}      // [55]
    virtual void unk_vf56() {}      // [56]
    virtual void unk_vf57() {}      // [57]
    virtual void unk_vf58() {}      // [58]
    virtual void unk_vf59() {}      // [59]
    virtual void unk_vf60() {}      // [60]
    virtual void unk_vf61() {}      // [61]
    virtual void unk_vf62() {}      // [62]
    virtual void unk_vf63() {}      // [63]
    virtual void unk_vf64() {}      // [64]
    virtual void unk_vf65() {}      // [65]
    virtual void unk_vf66() {}      // [66]
    virtual void unk_vf67() {}      // [67]
    virtual void unk_vf68() {}      // [68]
    virtual void unk_vf69() {}      // [69]
    virtual void unk_vf70() {}      // [70]
    virtual void unk_vf71() {}      // [71]
    virtual void unk_vf72() {}      // [72]
    virtual void unk_vf73() {}      // [73]
    virtual void unk_vf74() {}      // [74]
    virtual void unk_vf75() {}      // [75]
    virtual void unk_vf76() {}      // [76]
    virtual void unk_vf77() {}      // [77]
    virtual void unk_vf78() {}      // [78]
    virtual void unk_vf79() {}      // [79]
    virtual void unk_vf80() {}      // [80]
    virtual void unk_vf81() {}      // [81]
    virtual void unk_vf82() {}      // [82]
    virtual void unk_vf83() {}      // [83]
    virtual void unk_vf84() {}      // [84]
    virtual void unk_vf85() {}      // [85]
    virtual void unk_vf86() {}      // [86]
    virtual void unk_vf87() {}      // [87]
    virtual void unk_vf88() {}      // [88]
    virtual void unk_vf89() {}      // [89]
    virtual void BuildSubsystems() {}      // [90] 0x180916ECC  allocates & stores all subsystem pointers  VERIFIED
    virtual void unk_vf91() {}      // [91]
    virtual void unk_vf92() {}      // [92]
    virtual void unk_vf93() {}      // [93]
    virtual void unk_vf94() {}      // [94]
    virtual void unk_vf95() {}      // [95]
    virtual void unk_vf96() {}      // [96]
    virtual void unk_vf97() {}      // [97]
    virtual void unk_vf98() {}      // [98]
    virtual void unk_vf99() {}      // [99]
    virtual void unk_vf100() {}      // [100]
    virtual void unk_vf101() {}      // [101]
    virtual void unk_vf102() {}      // [102]
    virtual void unk_vf103() {}      // [103]
    virtual void unk_vf104() {}      // [104]
    virtual void unk_vf105() {}      // [105]
    virtual void unk_vf106() {}      // [106]
    virtual void unk_vf107() {}      // [107]
    virtual void unk_vf108() {}      // [108]
    virtual void unk_vf109() {}      // [109]
    virtual void unk_vf110() {}      // [110]
    virtual void unk_vf111() {}      // [111]
    virtual void unk_vf112() {}      // [112]
    virtual void unk_vf113() {}      // [113]
    virtual void unk_vf114() {}      // [114]
    virtual void unk_vf115() {}      // [115]
    virtual void unk_vf116() {}      // [116]
    virtual void unk_vf117() {}      // [117]
    virtual void unk_vf118() {}      // [118]
    virtual void unk_vf119() {}      // [119]
    virtual void unk_vf120() {}      // [120]
    virtual void unk_vf121() {}      // [121]
    virtual void unk_vf122() {}      // [122]
    virtual void unk_vf123() {}      // [123]
    virtual void unk_vf124() {}      // [124]
    virtual void unk_vf125() {}      // [125]
    virtual void unk_vf126() {}      // [126]
    virtual void unk_vf127() {}      // [127]
    virtual void unk_vf128() {}      // [128]
    virtual void unk_vf129() {}      // [129]
    virtual void unk_vf130() {}      // [130]
    virtual void unk_vf131() {}      // [131]
    virtual void unk_vf132() {}      // [132]
    virtual void unk_vf133() {}      // [133]
    virtual void unk_vf134() {}      // [134]
    virtual void unk_vf135() {}      // [135]
    virtual void unk_vf136() {}      // [136]
    virtual void unk_vf137() {}      // [137]
    virtual void unk_vf138() {}      // [138]
    virtual void unk_vf139() {}      // [139]
    virtual void unk_vf140() {}      // [140]
    virtual void unk_vf141() {}      // [141]
    virtual void unk_vf142() {}      // [142]
    virtual void unk_vf143() {}      // [143]
    virtual void unk_vf144() {}      // [144]
    virtual void unk_vf145() {}      // [145]
    virtual void unk_vf146() {}      // [146]
    virtual void unk_vf147() {}      // [147]
    virtual void unk_vf148() {}      // [148]
    virtual void unk_vf149() {}      // [149]
    virtual void unk_vf150() {}      // [150]
    virtual void unk_vf151() {}      // [151]
    virtual void unk_vf152() {}      // [152]
    virtual void unk_vf153() {}      // [153]
    virtual void unk_vf154() {}      // [154]
    virtual void unk_vf155() {}      // [155]
    virtual void unk_vf156() {}      // [156]
    virtual void unk_vf157() {}      // [157]
    virtual void unk_vf158() {}      // [158]
    virtual void unk_vf159() {}      // [159]
    virtual void unk_vf160() {}      // [160]
    virtual void unk_vf161() {}      // [161]
    virtual void unk_vf162() {}      // [162]
    virtual void unk_vf163() {}      // [163]
    virtual void unk_vf164() {}      // [164]
    virtual void unk_vf165() {}      // [165]
    virtual void unk_vf166() {}      // [166]
    virtual void unk_vf167() {}      // [167]
    virtual void unk_vf168() {}      // [168]
    virtual void unk_vf169() {}      // [169]
    virtual void unk_vf170() {}      // [170]
    virtual void unk_vf171() {}      // [171]
    virtual void unk_vf172() {}      // [172]
    virtual void unk_vf173() {}      // [173]
    virtual void unk_vf174() {}      // [174]
    virtual void unk_vf175() {}      // [175]
    virtual void unk_vf176() {}      // [176]
    virtual void unk_vf177() {}      // [177]
    virtual void unk_vf178() {}      // [178]
    virtual void unk_vf179() {}      // [179]
    virtual void unk_vf180() {}      // [180]
    virtual void unk_vf181() {}      // [181]
    virtual void unk_vf182() {}      // [182]
    virtual void unk_vf183() {}      // [183]
    virtual void unk_vf184() {}      // [184]
    virtual void unk_vf185() {}      // [185]
    virtual void unk_vf186() {}      // [186]
    virtual void unk_vf187() {}      // [187]
    virtual void unk_vf188() {}      // [188]
    virtual void unk_vf189() {}      // [189]
    virtual void unk_vf190() {}      // [190]
    virtual void unk_vf191() {}      // [191]
    virtual void unk_vf192() {}      // [192]
    virtual void unk_vf193() {}      // [193]
    virtual void unk_vf194() {}      // [194]
    virtual void unk_vf195() {}      // [195]
    virtual void unk_vf196() {}      // [196]
    virtual void unk_vf197() {}      // [197]
    virtual void unk_vf198() {}      // [198]
    virtual void unk_vf199() {}      // [199]
    virtual void unk_vf200() {}      // [200]
    virtual void unk_vf201() {}      // [201] 0x181A7D7E0  GetCombatScene? -> returns *(this+0x208)  (tentative)
    virtual void unk_vf202() {}      // [202]
    virtual void unk_vf203() {}      // [203]
    virtual void unk_vf204() {}      // [204]
    virtual void unk_vf205() {}      // [205]
    virtual void unk_vf206() {}      // [206]
    virtual void unk_vf207() {}      // [207]
    virtual void unk_vf208() {}      // [208]
    virtual void unk_vf209() {}      // [209]
    virtual void unk_vf210() {}      // [210]
    virtual void unk_vf211() {}      // [211]
    virtual void unk_vf212() {}      // [212]
    virtual void unk_vf213() {}      // [213] Deactivate/Shutdown -- tears down subsystems  (tentative; NOT SetAction)
    virtual void unk_vf214() {}      // [214]
    virtual void unk_vf215() {}      // [215]
    virtual void unk_vf216() {}      // [216]

    // ---- data members ----
    int64_t  m_field10;                                 // +0x10   (ctor inits 0)
    uint8_t  _pad18[0x20];                              // +0x18   early flags incl. update-mode byte @+0x28
    uint8_t  _signals[0x1C0];                           // +0x38   ~22 x 0x10 signal-head objects; Connect() via primary slots ~109-174
    Offsets::IEntity*              m_pEntity;           // +0x1F8  (GetEntity slot7)                          VERIFIED
    C_CombatActorDirector*         m_pDirector;         // +0x200  m_actions                                 VERIFIED
    C_CombatScene*                 m_pCombatScene;      // +0x208  (name tentative; GetCombatScene slot201)
    S_CombatActorState*            m_pState;            // +0x210  m_isInCombat/m_pOpponent/... (0xD10)      VERIFIED
    void*                          m_pSub218;           // +0x218  subsystem (0x268, ctor sub_181481B9C)
    void*                          m_pSub220;           // +0x220  subsystem (0x40,  ctor sub_180917708)
    void*                          m_pSub228;           // +0x228  subsystem (0x30,  back-ptr {this})
    void*                          m_pSub230;           // +0x230  subsystem (0x30,  ctor sub_180B1DE98)
    void*                          m_pSub238;           // +0x238  subsystem (0x50,  ctor sub_1815EA284)
    void*                          m_pSub240;           // +0x240  subsystem (0xA0,  ctor sub_18091784C)
    C_CombatAutomation*            m_pAutomation;       // +0x248  LAZY (null until GetOrCreateAutomation)   VERIFIED
    void*                          m_pSub250;           // +0x250  subsystem (0x78,  ctor sub_180917F3C)
    void*                          m_pSub258;           // +0x258  subsystem (0x20,  ctor sub_1808D40D0)
    void*                          m_pSub260;           // +0x260  subsystem (0x20,  ctor sub_180917758)
    void*                          m_pSub268;           // +0x268  subsystem (0x20,  ctor sub_1809177F8)
    void*                          m_pSub270;           // +0x270  back-ptr {this}
    int16_t  m_word278;                                 // +0x278  (init 0)
    uint8_t  _pad27A[2];                                // +0x27A
    int32_t  m_combatStateIndex;                        // +0x27C  (init -1)
    uint8_t  _pad280[1];                                // +0x280
    bool     m_flag281;                                 // +0x281  (init 0)
    uint8_t  _pad282[2];                                // +0x282
    uint8_t  m_field284[8];                             // +0x284  qword (init 0) -- byte array: offset is not 8-aligned
    uint8_t  m_stateFlags28C;                           // +0x28C  (masked &0xFC)
    uint8_t  _pad28D[3];                                // +0x28D
    float    m_timerA;                                  // +0x290  (init -1.0f)
    float    m_timerB;                                  // +0x294  (init -1.0f)
    uint8_t  _pad298[0x1C];                             // +0x298
    uint8_t  m_updateMode;                              // +0x2B4  (init 4)
    uint8_t  _pad2B5[0xCB];                             // +0x2B5
    int32_t  m_field380;                                // +0x380  (init 0)
    int16_t  m_field384;                                // +0x384  (init -1)
    uint8_t  _pad386[2];                                // +0x386
    void*                          m_pSub388;           // +0x388  subsystem (0x60,  ctor sub_1810EDB2C)
    void*                          m_pSub390;           // +0x390  back-ptr {this}
    void*                          m_pHumanPhysics;     // +0x398  C_CombatHumanPhysics (0x18, inline vtable) VERIFIED
    void*                          m_pSub3A0;           // +0x3A0  subsystem (0x20,  ctor sub_1809179E4)
    C_CombatActorActionManager*    m_pActionManager;    // +0x3A8  m_pAttackFactory->CreateAndDispatch        VERIFIED
    C_CombatComboManager*          m_pComboManager;     // +0x3B0  m_activeCombos/m_comboFireGateZone         VERIFIED
    C_CombatActorOpponentManager*  m_pOpponentManager;  // +0x3B8                                            VERIFIED
    uint8_t  _pad3C0[0x80];                             // +0x3C0  ~16 more subsystem pointers (identities unconfirmed, builder sub_180916ECC)
    void*    m_lock;                                    // +0x440  SRWLOCK (InitializeSRWLock)
};
static_assert(sizeof(C_CombatActor) == 0x448, "C_CombatActor must be 0x448");
static_assert(offsetof(C_CombatActor, m_pEntity)         == 0x1F8);
static_assert(offsetof(C_CombatActor, m_pState)          == 0x210);
static_assert(offsetof(C_CombatActor, m_pAutomation)     == 0x248);
static_assert(offsetof(C_CombatActor, m_pActionManager)  == 0x3A8);
static_assert(offsetof(C_CombatActor, m_pOpponentManager)== 0x3B8);
static_assert(offsetof(C_CombatActor, m_lock)            == 0x440);

}  // namespace wh::combatmodule
