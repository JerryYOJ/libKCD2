#pragma once
#include <cstdint>
#include <cstddef>
#include "REL/ID.h"

// -----------------------------------------------
// SSystemGlobalEnvironment (gEnv) -- KCD2 binary layout
// -----------------------------------------------
// Address: WHGame+0x492D800 (.data). REBASED 2026-09-01 (t1_002): the old header sat
// 8 bytes early (0x492D7F8, a zero-xref qword); CSystem ctor 0x180A52DC1 lea's
// 0x18492D800 and stores it to CSystem+0x20 (m_env), so every old offset shifted -0x08.
// Size: ctor memsets 0x440 bytes (0x180A53156/0x180A53163); next address-taken global
// off_18492DC40 = base+0x440.
// Non-polymorphic; no vtable. Coordinates now match Offsets/vtables/ISystem.h
// "gEnv->+0xNN" notes and CSystem.h's m_env.
// Slot names: VERIFIED = live-traced earlier; [RTTI]/[STRING]/[INFERRED] per
// t1_002 dossier + adversarial verdict (analysis/re_quality/dossiers/track1/).

namespace Offsets {
    struct IScriptSystem; struct IPhysicalWorld; struct IInput; struct ITimer;
    struct IGame; struct IEntitySystem; struct IConsole; struct ISystem;
    struct ILog; struct IRenderer; struct IFlashUI; struct I3DEngine;
    struct IHardwareMouse; struct ICharacterManager; struct ICryPak;
    struct IParticleManager;
}

// Engine interfaces at global scope (CryCommon definitions where present in-tree).
struct IDialogSystem; struct INetwork; struct ICryLobby; struct IFlowSystem;
struct IFileChangeMonitor; struct IProfileLogSystem; class IOpticsManager;
struct IFrameProfileSystem; struct ICryFont; struct ILocalMemoryUsage;
struct IAudioSystem; struct IAISystem; struct ICodeCheckpointMgr;
struct IMovieSystem; struct INameTable; struct IVisualLog; struct IRenderAuxGeom;
struct IMaterialEffects; struct IOverloadSceneManager; struct IServiceNetwork;
struct IRemoteCommandManager; struct IThreadManager; struct IScaleformHelper;
struct IFModAudio; class I_VideoPlayer;
namespace Telemetry { struct ITelemetrySystem; }
namespace JobManager { struct IJobManager; }
namespace DRS { struct IDynamicResponseSystem; }
namespace LiveCreate { struct IManager; struct IHost; }
namespace Cry::PluginManager { struct ISystem; }
namespace wh::game { struct S_GameContext; }

struct SSystemGlobalEnvironment {
    IDialogSystem*                  pDialogSystem;          // +0x00  [INFERRED] CCryAction+0x598 -> CSystem setter slot 110 (0x181A71804 mov [rax],rdx); "DialogSystem" save section 0x18477C778
    Offsets::I3DEngine*             p3DEngine;              // +0x08  VERIFIED live I3DEngine* (e_TimeOfDay dispatch; abs 0x18492D808, 833 refs)
    INetwork*                       pNetwork;               // +0x10  [RTTI] CEngineModule_CryNetwork::Initialize stores CNetwork @0x180B6B3D6; "Error creating Network System!"
    void*                           _unk18;                 // +0x18  OPEN: zero xrefs to 0x18492D818; stock-order candidate IOnline* (unproven)
    ICryLobby*                      pLobby;                 // +0x20  [STRING] getter 0x180669540 reads 0x18492D820; "Error running pLobby->ProcessEvents (%d)" 0x184086448
    Offsets::IScriptSystem*         pScriptSystem;          // +0x28  VERIFIED: GetGlobalValue/ExecuteBuffer
    Offsets::IPhysicalWorld*        pPhysicalWorld;         // +0x30  VERIFIED: RayWorldIntersection
    IFlowSystem*                    pFlowSystem;            // +0x38  [RTTI] CSystem setter slot 109 0x181A717E4; CFlowSystem vtable 0x184049628
    Offsets::IInput*                pInput;                 // +0x40  VERIFIED: AddEventListener("C_Keybinds")
    void*                           _unk48;                 // +0x48  OPEN: Init zeroes it; only null-test readers 0x18066C953/0x183732543; candidate IStatoscope* (unproven)
    Offsets::ICryPak*               pCryPak;                // +0x50  VERIFIED: FindFirst/FindNext wildcard loop on abs 0x18492D850 matches CCryPak vtable 0x183A97328 [63]/[64]; most-referenced slot (681 reads)
    IFileChangeMonitor*             pFileChangeMonitor;     // +0x58  [INFERRED] setter slot 114 0x181A73774; IFileChangeListener registrations 0x180BC363E/0x180BC3660
    IProfileLogSystem*              pProfileLogSystem;      // +0x60  [RTTI] Init stores @0x1807A086E; CProfileLogSystem vtable 0x183C62F50
    Offsets::IParticleManager*      pParticleManager;       // +0x68  VERIFIED: FindEffect this-adjust -8; abs 0x18492D868
    IOpticsManager*                 pOpticsManager;         // +0x70  [RTTI] setter slot 113 0x181A717B4; COpticsManager vtable 0x183A96A28
    IFrameProfileSystem*            pFrameProfileSystem;    // +0x78  [RTTI] ctor 0x180A531AF publishes embedded CSystem+0xCE8; vtable 0x183DC2668
    Offsets::ITimer*                pTimer;                 // +0x80  VERIFIED: GetCurrTime
    ICryFont*                       pCryFont;               // +0x88  [RTTI] "EngineModule_CryFont" loader checks it @0x1812DC063; CCryFont vtable 0x184078630
    Offsets::IGame*                 pGame;                  // +0x90  VERIFIED: GetIGameFramework chain
    ILocalMemoryUsage*              pLocalMemoryUsage;      // +0x98  [INFERRED] OnRender/OnUpdate/DeleteGlobalData 3-slot protocol 0x18043F1CE/0x180667C6D/0x1805F9E81 matches ILocalMemoryUsage.h
    Offsets::IEntitySystem*         pEntitySystem;          // +0xA0  VERIFIED: GetEntity(entityId)
    Offsets::IConsole*              pConsole;               // +0xA8  VERIFIED: GetCVar/RegisterVariable
    Telemetry::ITelemetrySystem*    pTelemetrySystem;       // +0xB0  [RTTI] Init stores @0x1807A1496; "Failed to initialize telemetry system!"
    IAudioSystem*                   pAudioSystem;           // +0xB8  [RTTI] CryEngine audio iface (NOT the FMOD wrapper, see +0x170); NULL fallback CNULLAudioSystem stored @0x1807A1344
    Offsets::ISystem*               pSystem;                // +0xC0  VERIFIED: == CSystem self (ctor 0x180A53183)
    Offsets::ISystem*               _unkC8;                 // +0xC8  same CSystem* stored again (ctor 0x180A5318E); ISystem-dispatched (GetViewCamera 0x180935700); source name unknown
    Offsets::ICharacterManager*     pCharacterManager;      // +0xD0  VERIFIED: CryAnimation module stores manager (sub_18099B504 @0x18099B672)
    IAISystem*                      pAISystem;              // +0xD8  [RTTI] "EngineModule_CryAISystem" loader checks it; "Cannot create AI System!"; CAISystem vtable 0x183F934A8
    Offsets::ILog*                  pLog;                   // +0xE0  VERIFIED: Log/LogError
    ICodeCheckpointMgr*             pCodeCheckpointMgr;     // +0xE8  [INFERRED] ../USER/CodeCheckpointList.txt pipeline reads 0x18492D8E8 (submit 0x1839D47CD, lookup 0x1839D4C28)
    IMovieSystem*                   pMovieSystem;           // +0xF0  [RTTI] "EngineModule_CryMovie" loader; CMovieSystem vtable 0x18407E648
    INameTable*                     pNameTable;             // +0xF8  [RTTI] ctor 0x180A531A4 publishes embedded CSystem+0xD58; CNameTable vtable 0x183DC3F20
    IVisualLog*                     pVisualLog;             // +0x100 [RTTI] setter slot 115 0x181A71794; CVisualLog vtable 0x183C42640
    Offsets::IRenderer*             pRenderer;              // +0x108 VERIFIED: renderer vtable calls
    IRenderAuxGeom*                 pAuxGeomRenderer;       // +0x110 [RTTI] writer 0x1809A7EAF publishes thread-local CAuxGeomCB (vtable 0x183BE6808)
    Offsets::IHardwareMouse*        pHardwareMouse;         // +0x118 VERIFIED: writer 0x1807A110F stores (CHardwareMouse*)+8 subobject; abs 0x18492D918
    IMaterialEffects*               pMaterialEffects;       // +0x120 [RTTI] setter slot 111 0x181A717C4; CMaterialEffects vtable 0x184056C88
    JobManager::IJobManager*        pJobManager;            // +0x128 [RTTI] ctor 0x180A5379D stores &qword_1855CD110 (runtime-filled with CJobManager, vtable 0x183DBE290)
    IOverloadSceneManager*          pOverloadSceneManager;  // +0x130 [RTTI] Init stores @0x1807A0FDE; COverloadSceneManager vtable 0x183C339F0
    Offsets::IFlashUI*              pFlashUI;               // +0x138 VERIFIED: abs 0x18492D938 = CFlashUI self-singleton; Shutdown zeroes it @0x1835C1265
    void*                           _unk140;                // +0x140 OPEN: setter slot 118 0x181A73794; UI layout service (creates "layout", applies "CE_NoAutoUpdate") -- no RTTI/producer identity
    IServiceNetwork*                pServiceNetwork;        // +0x148 [RTTI] Init stores @0x1807A1667; CServiceNetwork vtable 0x183C333F8
    IRemoteCommandManager*          pRemoteCommandManager;  // +0x150 [RTTI] Init stores @0x1807A168F; CRemoteCommandManager vtable 0x183C42F58
    DRS::IDynamicResponseSystem*    pDynamicResponseSystem; // +0x158 [RTTI] "EngineModule_CryDynamicResponseSystem"; NULL fallback stored @0x1807A1B5F
    IThreadManager*                 pThreadManager;         // +0x160 [RTTI] ctor 0x180A53261 stores sub_180BBA838 result; CThreadManager vtable 0x183DCEF00
    IScaleformHelper*               pScaleformHelper;       // +0x168 [RTTI] CEngineModule_ScaleformHelper::Initialize stores @0x1819DEB2A; vtable 0x1846A75C0
    IFModAudio*                     pFmodAudio;             // +0x170 [INFERRED] WH FMOD wrapper (was mislabeled pAudioSystem): CB_FmodStudioWrapper ctor publishes this @0x180E3D06C; runtime object is CWh_FmodStudioWrapper
    Cry::PluginManager::ISystem*    pPluginManager;         // +0x178 [RTTI] "PluginManager initialization"; stored @0x181736277; vtable 0x183DBBDE0
    wh::game::S_GameContext*        pGameContext;           // +0x180 [INFERRED] ctor 0x180A5320A calls S_GameContext::Instance_1809155C8, stores @0x180A53213
    void*                           _unk188;                // +0x188 OPEN (HARD_OPENS C5): 0x128-byte lock-pool, 2 elements stride 0x90, acquire helper sub_1803D47D8 (Mtx_trylock); no RTTI
    I_VideoPlayer*                  pVideoPlayer;           // +0x190 [RTTI] setter slot 117 0x181A71774; C_BinkVideoPlayer vtable 0x183DBA4A8
    LiveCreate::IManager*           pLiveCreateManager;     // +0x198 [STRING] "LiveCreateManager not created, using NULL implementation." @0x1819B1357
    LiveCreate::IHost*              pLiveCreateHost;        // +0x1A0 [STRING] "LiveCreateHost not created, using NULL implementation." @0x1819B12DA
    uint32_t                        mMainThreadId;          // +0x1A8 VERIFIED: GetCurrentThreadId cached at init (0x1807A0038 mov cs:dword_18492D9A8, eax)
    uint32_t                        nMainFrameID;           // +0x1AC [INFERRED] renderer frame id, dword writers 0x18052EA5D mov / 0x18052EAAF inc (was _pad1B4)
    const char*                     szCmdLine;              // +0x1B0 [INFERRED] Init publishes CryStringT buffer ptr @0x1807A011A; logged as "Cmdline: '%s'"
    uint8_t                         _tail1B8[0x288];        // +0x1B8 unresolved tail (outside t1_002 scope): ctor writes byte +0x1B8, +0x238..+0x252, +0x3CC, +0x3D1/+0x3D3/+0x3D4; ISystem slot 184 tests byte +0x250

    static SSystemGlobalEnvironment* GetInstance()
    {
        // id 1181143 = RVA 0x492D800, the pointer CSystem ctor stores to m_env.
        // (Old id 1300 = 0x492D7F8 was one qword early -- the pre-rebase phantom base.)
        return reinterpret_cast<SSystemGlobalEnvironment*>(REL::ID(1181143).address());
    }
};
static_assert(sizeof(SSystemGlobalEnvironment) == 0x440);   // ctor memset span 0x180A53156; next address-taken global off_18492DC40 = base+0x440
static_assert(offsetof(SSystemGlobalEnvironment, pConsole) == 0xA8);
static_assert(offsetof(SSystemGlobalEnvironment, pLog) == 0xE0);
static_assert(offsetof(SSystemGlobalEnvironment, pGameContext) == 0x180);
static_assert(offsetof(SSystemGlobalEnvironment, mMainThreadId) == 0x1A8);
