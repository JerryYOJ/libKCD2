#pragma once

#include <cstdint>
#include <vector>
#include "../Offsets/vtables/IGameFramework.h"
#include "../CryEngine/CryCommon/smartptr.h"   // _smart_ptr

// forward decls for not-yet-RE'd pointee types (stage-2 auto)
class CActionGame;
class CallbackTimer;
struct I3DEngine;
struct ILog;
struct ICVar;
class CAIDebugRenderer;
class CAIProxyManager;
class CAnimationGraphCVars;
class CCooperativeAnimationManager;
class CCustomActionManager;
class CCustomEventManager;
class CDevMode;
class CDialogSystem;
class CEffectSystem;
class CFlowSystem;
class CGameQueryListener;
class CGameRulesSystem;
class CGameSerialize;
class CGameStatistics;
class CGameTokenSystem;
class CGameVolumesManager;
class CGameplayAnalyst;
class CGameplayRecorder;
class CItemSystem;
class CMannequinInterface;
class CMaterialEffects;
class CNetMessageDistpatcher;
class CPersistantDebug;
class CPlayerProfileManager;
class CScriptRMI;
class CSharedParamsManager;
class CSubtitleManager;
class CTimeDemoRecorder;
class CVisualLog;
class C_FrameStatsWH;
class IBreakEventListener;
class IEntitySystem;
class ILanQueryListener;
class INetwork;
class IScriptSystem;
class ITimer;
class SLocalAllocs;
class CRuntimeAreaManager;
class CScriptBind_Action;
class CScriptBind_ItemSystem;
class CScriptBind_ActorSystem;
class CScriptBind_Network;
class CScriptBind_ActionMapManager;
class CScriptBind_Inventory;
class CScriptBind_MaterialEffects;
class CScriptBind_UIAction;
class CTimeOfDayScheduler;
class CAINetworkDebugRenderer;
class CNetworkCVars;
class CCryActionCVars;
class CNetworkStallTickerThread;
class CMaterialEffectsCVars;
class CCryActionPhysicQueues;

// -----------------------------------------------------------------------------
// CCryAction - CryAction game-framework implementation (KCD2)
// -----------------------------------------------------------------------------
// RTTI:  .?AVCCryAction@@   (global namespace; not a wh:: class)
// Target: WHGame.dll 1.5.6, image base 0x180000000 (IDA instance "kd7u").
//
// vtable:              0x1840472d0  (143 slots, see Offsets::IGameFramework)
// constructor:         0x181865c3a  (zero-init ctor; subsystem ptrs are filled in Init())
// base destructor:     0x18355fce8
// scalar deleting dtor:vtable slot [5] (0x183560d0c) -> operator delete(this, 1984)
//
// SIZE: sizeof == 0x7C0 (1984), recovered two independent ways:
//   (1) scalar-deleting dtor passes 1984 to operator delete (sub_181AB5160(this,1984));
//   (2) CCryAction is a STATIC global at 0x18562EF50 and the next data symbol
//       (dword_18562F710) sits exactly 0x7C0 bytes later; the ctor's last store is
//       a qword at +0x7B8 (ends 0x7C0).
//
// Singleton access (KCD2 globals):
//   IGameFramework*  qword_18549D328   (returned by the framework accessor)
//   CCryAction*      qword_185497F70   (set at the tail of the ctor)
//
// Data members below are recovered from the ctor stores and from the vtable accessor
// fingerprints (getter `mov rax,[rcx+OFF]` / setter `mov [rcx+OFF],dl`). Members marked
// VERIFIED are pinned by a dedicated accessor; those marked /* tentative */ are inferred
// from KCD1 accessor semantics + the drifted offset and want a decompile pass. Everything
// else is an owned pointer/qword whose pointee type is not yet identified (void*), padded
// with _padXX where the ctor left a gap. Offsets are absolute within CCryAction.
// -----------------------------------------------------------------------------

// CryEngine SDK subsystem interfaces (SDK declares these as struct; pointees live
// behind their Get* accessors — full vtable replicas not yet RE'd).
struct ILevelSystem;
struct IActorSystem;
struct IActionMapManager;
struct IViewSystem;
struct IGameObjectSystem;
struct IUIDraw;
struct IGameStatistics;
struct IGameSessionHandler;
struct IGameFrameworkListener;

// stock CryAction.h class-local support types (declared file-scope here)
enum ESaveGameMethod { eSGM_NoSave = 0, eSGM_QuickSave, eSGM_Save };
enum ESaveGameReason { eSGR_LevelStart = 0, eSGR_FlowGraph, eSGR_Command, eSGR_QuickSave };
struct SGameFrameworkListener {
    IGameFrameworkListener* pListener;   // +0x00
    CryStringT<char>        name;        // +0x08
    int                     eFrameworkListenerPriority; // +0x10
    uint8_t                 _pad14[4];   // +0x14
};

// Concrete CryAction singleton. Single inheritance: the only base is IGameFramework,
// so the whole object is [vtable][members]. Offsets::IGameFramework supplies the 143-slot
// vtable base; the members here start at +0x08 (right after the vtable pointer).
class CCryAction : public Offsets::IGameFramework
{
public:
    // The engine-owned singleton: cached framework-pointer global qword_18549D328 (REL::ID
    // 2356); the object itself is the static CCryAction @0x18562EF50.  Single inheritance,
    // so the cached IGameFramework* IS the CCryAction*.  (src/crysystem/CCryAction.cpp)
    static CCryAction* GetInstance();

    // ---- Pause bookkeeping ----
    int32_t     m_pauseSourceRefCounts[15];      // +0x08  per-source pause refcounts: 0x180A55696 inc [this+8+4*src]; 0x180A558A8 clears 15; slot 14 tests >0

    // ---- Save/load + engine handle ----
    bool        m_bLoadingSaveGame;              // +0x44  IsLoadingSaveGame / SetLoadingSaveGame   VERIFIED
    uint8_t _pad45[3]; // +0x45
    ISystem*    m_pSystem;                        // +0x48  (GetISystem 0x180856CF0 = return *(this+0x48))  VERIFIED
    INetwork* m_pNetwork; // +0x50
    I3DEngine* m_p3DEngine; // +0x58
    IScriptSystem* m_pScriptSystem; // +0x60
    IEntitySystem* m_pEntitySystem; // +0x68
    ITimer* m_pTimer; // +0x70
    ILog* m_pLog; // +0x78
    void* m_systemDll; // +0x80 HMODULE (windows.h not included here)
    _smart_ptr<CActionGame> m_pGame; // +0x88  game/network context; heavily used     /* tentative (CActionGame*) */
    char        m_unk90[0x200];                   // +0x90  ctor NUL-terminates only; no KCD2 reader of the tail (stock m_editorLevelName UNPROVEN)
    char        m_unk290[0x200];                  // +0x290 ctor NUL-terminates only (stock m_editorLevelFolder UNPROVEN)

    // ---- Game GUID string buffer (GetGameGUID; ctor seeds "{000...-000}") ----
    char        m_gameGUID[0x80];                 // +0x490                                          VERIFIED

    // ===================================================================
    // Subsystem pointer block (+0x510 .. +0x638). Filled during Init().
    // ===================================================================
    ILevelSystem* m_pLevelSystem;                // +0x510 CLevelSystem (GetILevelSystem 0x180B8F740 = return *(this+0x510)) VERIFIED
    IActorSystem* m_pActorSystem;                // +0x518 CActorSystem (GetIActorSystem 0x180641150 = return *(this+0x518)) VERIFIED
    CItemSystem* m_pItemSystem; // +0x520 CItemSystem         (GetIItemSystem)     VERIFIED
    CSharedParamsManager* m_pSharedParamsManager; // +0x528 subsystem ptr (accessor slot [48])
    IActionMapManager* m_pActionMapManager;      // +0x530 CActionMapManager (GetIActionMapManager slot[28] = return *(this+0x530)) VERIFIED
    IViewSystem* m_pViewSystem;                  // +0x538 CViewSystem (GetIViewSystem slot[29] = return *(this+0x538)) VERIFIED
    CGameplayRecorder* m_pGameplayRecorder; // +0x540 subsystem ptr (accessor slot [30])
    CGameRulesSystem* m_pGameRulesSystem; // +0x548 (accessor slot [31])                     /* tentative */
    CFlowSystem* m_pFlowSystem; // +0x550 (accessor slot [32])                     /* tentative */
    IGameObjectSystem* m_pGameObjectSystem;      // +0x558 CGameObjectSystem (GetIGameObjectSystem slot[23] = return *(this+0x558)) VERIFIED
    IUIDraw*    m_pUIDraw;                        // +0x560 CUIDraw (GetIUIDraw slot[21] = return *(this+0x560))         VERIFIED
    CScriptRMI* m_pScriptRMI; // +0x568
    CAnimationGraphCVars* m_pAnimationGraphCvars; // +0x570
    CMannequinInterface* m_pMannequin; // +0x578 CMannequinInterface (GetIMannequin)      VERIFIED
    CMaterialEffects* m_pMaterialEffects; // +0x580 (accessor slot [35])                     /* tentative */
    void* m_unk588; // +0x588 (accessor slot [139])                    /* tentative */
    CPlayerProfileManager* m_pPlayerProfileManager; // +0x590 subsystem ptr (accessor slot [37])
    CDialogSystem* m_pDialogSystem; // +0x598 (accessor slot [36])                     /* tentative */
    CSubtitleManager* m_pSubtitleManager; // +0x5A0 subsystem ptr (accessor slot [38])
    CGameTokenSystem* m_pGameTokenSystem; // +0x5A8 subsystem ptr (accessor slot [33])
    CEffectSystem* m_pEffectSystem; // +0x5B0 (accessor slot [34])                     /* tentative */
    CGameSerialize* m_pGameSerialize; // +0x5B8 (used by slots [3]/[4])
    CallbackTimer* m_pCallbackTimer; // +0x5C0
    CGameplayAnalyst* m_pGameplayAnalyst; // +0x5C8
    CVisualLog* m_pVisualLog; // +0x5D0 subsystem ptr (accessor slot [41])
    void* m_unk5D8; // +0x5D8 subsystem ptr (accessor slot [44])
    ILanQueryListener* m_pLanQueryListener; // +0x5E0 subsystem ptr (accessor slot [20])
    CCustomActionManager* m_pCustomActionManager; // +0x5E8 subsystem ptr (accessor slot [45])
    CCustomEventManager* m_pCustomEventManager; // +0x5F0 subsystem ptr (accessor slot [46])
    IGameStatistics* m_pGameStatsConfig;         // +0x5F8 CGameStatsConfig (GetIGameStatistics slot[142] = return *(this+0x5F8)) — config object, NOT the stats system
    CGameStatistics* m_pGameStatistics; // +0x600 subsystem ptr (accessor slot [40]; Init alloc 0x118, ctor 0x181209A58, vt 0x183B33938)
    CCooperativeAnimationManager* m_pCooperativeAnimationManager; // +0x608 subsystem ptr (accessor slot [42])
    IGameSessionHandler* m_pGameSessionHandler;  // +0x610 (SetGameSessionHandler slot[55] = *(this+0x610)=arg) VERIFIED
    CAIProxyManager* m_pAIProxyManager; // +0x618
    CGameVolumesManager* m_pGameVolumesManager; // +0x620 (accessor slot [132])
    CDevMode* m_pDevMode; // +0x628
    CTimeDemoRecorder* m_pTimeDemoRecorder; // +0x630 (accessor slot [78]; used by many slots)
    C_FrameStatsWH* m_pFrameStatsWH; // +0x638 owned polymorphic obj (released in dtor via slot 0)
    CGameQueryListener* m_pGameQueryListener; // +0x640
    CRuntimeAreaManager* m_pRuntimeAreaManager; // +0x648 CompleteInit, gated on g_enableMergedMeshRuntimeAreas
    void* m_unk650; // +0x650 0x20-byte {vector<0x48-byte records>, SRWLOCK} deferred-callback queue; name OPEN
    CScriptBind_Action* m_pScriptA; // +0x658
    CScriptBind_ItemSystem* m_pScriptIS; // +0x660
    CScriptBind_ActorSystem* m_pScriptAS; // +0x668
    CScriptBind_Network* m_pScriptNet; // +0x670
    CScriptBind_ActionMapManager* m_pScriptAMM; // +0x678
    CScriptBind_Inventory* m_pScriptInventory; // +0x680
    void* m_unk688; // +0x688 owned 0x78 polymorphic script-bind (teardown-only; no InitScriptBinds store); class OPEN
    CScriptBind_MaterialEffects* m_pScriptBindMFX; // +0x690 CompleteInit
    CScriptBind_UIAction* m_pScriptBindUIAction; // +0x698
    CTimeOfDayScheduler* m_pTimeOfDayScheduler; // +0x6A0 no surviving RTTI

    CPersistantDebug* m_pPersistantDebug; // +0x6A8 (accessor slot [97])
    CAIDebugRenderer* m_pAIDebugRenderer; // +0x6B0
    CAINetworkDebugRenderer* m_pAINetworkDebugRenderer; // +0x6B8
    CNetworkCVars* m_pNetworkCVars; // +0x6C0 ctor registers the net_* cvar family; no RTTI
    CCryActionCVars* m_pCryActionCVars; // +0x6C8 no RTTI
    CNetworkStallTickerThread* m_pNetworkStallTickerThread; // +0x6D0 vslot 130 creates ("NetStallTicker"), vslot 131 destroys at refcount 0
    uint32_t m_networkStallTickerReferences; // +0x6D8
    uint32_t _pad6DC; // +0x6DC
    CMaterialEffectsCVars* m_pMaterialEffectsCVars; // +0x6E0 owns the mfx_* cvar family; no RTTI
    CCryActionPhysicQueues* m_pPhysicsQueues; // +0x6E8 0x3E0 alloc; sole caller is level loading

    // ---- std::vector<T> (begin / end / capacity-end); freed in the dtor ----
    std::vector<void*> m_vec;   // +0x6F0  begin/end/capacity (0x18); element type unidentified
    ICVar* m_pEnableLoadingScreen; // +0x708 "g_enableloadingscreen"
    uint8_t m_unk710[8]; // +0x710 hole ("g_enableitems" registration discards its ICVar* — not this field)
    ICVar* m_pShowLanBrowserCVAR; // +0x718 "net_lanbrowser"
    ICVar* m_pDebugSignalTimers; // +0x720 "ai_DebugSignalTimers"
    ICVar* m_pDebugRangeSignaling; // +0x728 "ai_DebugRangeSignaling"
    ICVar* m_pAsyncLevelLoad; // +0x730 "g_asynclevelload"
    ICVar* m_pPauseDebug; // +0x738 "wh_game_pauseDebug"

    bool m_bShowLanBrowser; // +0x740
    bool        m_flag741;                        // +0x741 (getter slot [84])
    bool        m_flag742;                        // +0x742 (setter slot [82])
    uint8_t _pad743; // +0x743
    ESaveGameMethod m_delayedSaveGameMethod; // +0x744
    ESaveGameReason m_delayedSaveGameReason; // +0x748
    int32_t m_delayedSaveCountDown; // +0x74C
    SLocalAllocs* m_pLocalAllocs; // +0x750 (read by slot [82])
    std::vector<SGameFrameworkListener>* m_pGFListeners; // +0x758 (used by slot [101])
    IBreakEventListener* m_pBreakEventListener; // +0x760 (set/clear by slots [98]/[99])
    std::vector<bool> m_validListeners;           // +0x768..0x787 ONE vector<bool> (0x20: block-vector 0x18 + bit-count qword at +0x780); dtor 0x18355FD1C frees blocks, broadcaster bit-indexes 0x180668DC2
    int32_t m_VoiceRecordingEnabled; // +0x788 (set slot [108] / tested slot [112])
    bool        m_bAllowSave;                     // +0x78C AllowSave  (ctor = true)                 VERIFIED
    bool        m_bAllowLoad;                     // +0x78D AllowLoad  (ctor = true)                 VERIFIED
    uint8_t _pad78E[2]; // +0x78E
    CryStringT<char>* m_nextFrameCommand; // +0x790 owned obj (accessed by slots [114]-[116])
    uint8_t m_unk798[8]; // +0x798
    double      m_loadSaveDelay;                  // +0x7A0 GetLoadSaveDelay returns (float)this     /* tentative */
    double m_lastFrameTimeUI; // +0x7A8
    bool        m_pbSvEnabled;                     // +0x7B0 punkbuster server: "net_pb_sv_enable" command writes/tests it
    bool        m_pbClEnabled;                     // +0x7B1 punkbuster client: "net_pb_cl_enable"
    uint8_t _pad7B2[2]; // +0x7B2
    uint32_t    m_preUpdateTicks;                  // +0x7B4 GetPreUpdateTicks (read + reset)         /* tentative */
    CNetMessageDistpatcher* m_pNetMessageDistpatcher; // +0x7B8  (ctor's final store; ends at 0x7C0)
};
static_assert(sizeof(CCryAction) == 0x7C0, "CCryAction must be 0x7C0 (static object extent / operator delete 1984)");
static_assert(offsetof(CCryAction, m_bLoadingSaveGame) == 0x44);
static_assert(offsetof(CCryAction, m_unk90) == 0x90);
static_assert(offsetof(CCryAction, m_gameGUID) == 0x490);
static_assert(offsetof(CCryAction, m_pScriptA) == 0x658);
static_assert(offsetof(CCryAction, m_pTimeOfDayScheduler) == 0x6A0);
static_assert(offsetof(CCryAction, m_pPhysicsQueues) == 0x6E8);
static_assert(offsetof(CCryAction, m_pEnableLoadingScreen) == 0x708);
static_assert(offsetof(CCryAction, m_pPauseDebug) == 0x738);
static_assert(offsetof(CCryAction, m_bShowLanBrowser) == 0x740);
static_assert(offsetof(CCryAction, m_pbSvEnabled) == 0x7B0);
