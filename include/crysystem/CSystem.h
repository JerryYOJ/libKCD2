#pragma once
#include <cstdint>
#include <vector>
#include "../Offsets/vtables/ISystem.h"
#include "CCamera.h"

// forward decls for not-yet-RE'd pointee types (stage-2 auto)
namespace Offsets { class ILocalizationManager; }

// -----------------------------------------------
// CSystem — CrySystem main engine object (KCD2)
// -----------------------------------------------
// Target: WHGame.dll 1.5.6, base 0x180000000, build "release_1_5_1308617_856"
// RTTI:   .?AVCSystem@@
// primary vtable:      0x183dc2858  (Offsets::ISystem, 239 slots)
// constructor:         0x180a52d9c   Init: sub_18079ffd4
// scalar-deleting dtor:0x182458548  -> operator delete(this, 0x2BF8)   => sizeof VERIFIED
// base dtor (~CSystem):0x182456ee0
//
// Multiple inheritance (vptr layout, from the dtor's vftable restores):
//   Offsets::ISystem                    +0x00   (primary, 239 slots)
//   Offsets::ILoadConfigurationEntrySink+0x08
//   Offsets::ISystemEventListener       +0x10
//   Offsets::IWindowMessageHandler      +0x18
//
// Layout recovered from ctor/Init/dtor/shutdown member stores + vtable getter/setter
// fingerprints (t1_022 dossier, adversarially verified). m_unkNN members have a proven
// width/writer but an unrecovered source name; _padNN regions have no writer at all.

struct SSystemGlobalEnvironment;   // the +0x20 pointer targets the global gEnv (0x18492D800)
class CSystemEventDispatcher;      // 0x68-byte alloc, ctor sub_180A53908
class CXmlUtils;                   // 0x30-byte alloc, ctor sub_180A53D80 (embeds CReadWriteXMLSink)
namespace Serialization { class CArchiveHost; }  // ctor sub_180A53844

// forward decls for not-yet-RE'd pointee types (stage-2 auto)
class CTestSystemLegacy;           // 0x38-byte alloc, ctor sub_180A53ACC
class CThreadTaskManager;          // 0x108-byte alloc, ctor sub_180A53EC0
class CResourceManager;            // 0x1F0-byte alloc, ctor sub_180A541AC (embeds CAsyncPakManager)
namespace wh { class C_LoadingMonitor;      // +0x2B18 ctor sub_18194F228, alloc 0x50
               class C_ReadinessService;    // +0x2B20 ctor sub_18180AE64, alloc 0xB8
               class C_DurationProfiler;    // +0x2B28 ctor sub_1819B7F38, alloc 0x78
               class C_ConsoleModeProvider; }  // +0x2B38 8-byte vtable wrapper
class CBudgetingSystem;            // +0x9F8  ctor sub_18183C6D4, alloc 0x60 ("sys_budget_*" cvars)
class CZLibCompressor;             // +0xA00  ctor sub_1819EDB94, 8-byte vtable wrapper
class CZLibDecompressor;           // +0xA08  ctor sub_1819EDB84
class CLZ4Decompressor;            // +0xA10  ctor sub_1819EDBA4
class CCPUInfo;                    // +0x5F0  ctor sub_1819C8D0C, alloc 0xC8
namespace Cry::System { class CDriveInfo; } // +0x5F8 lazy-alloc by ISystem slot 26 (0x1819B9D04)
class CCryMemoryManager;           // +0x6B8  static singleton 0x18492DD48
class CDownloadManager;            // +0x2A78 ctor sub_1819C2988, alloc 0x20
class CCmdLine;                    // +0x2AF0 ctor sub_1816D0564, alloc 0x28
class CImeManager;                 // +0x2BC8 ctor sub_180DA4534, alloc 0x10
class CWindowsConsole;             // +0x2B40 ctor sub_1817D8D90, alloc 0x210
struct IValidator;                 // CryCommon/IValidator.h
struct SDefaultValidator;          // .?AUSDefaultValidator@@, ctor sub_1819EC7E4
struct ISystemUserCallback;        // CryCommon/ISystem.h
struct IOutputPrintSink;           // crysystem/CXConsole.h
struct ICVar;

class CSystem : public Offsets::ISystem,                     // +0x00
                public Offsets::ILoadConfigurationEntrySink, // +0x08
                public Offsets::ISystemEventListener,        // +0x10
                public Offsets::IWindowMessageHandler        // +0x18
{
public:
    // ---- Global environment ------------------------------------------------
    SSystemGlobalEnvironment* m_env;                 // +0x020  = &gEnv (0x18492D800); GetGlobalEnvironment() slot 3
    uint8_t   m_Timer[0x260];                        // +0x028  embedded CTimer (ctor sub_180A53C48, vtable 0x183A6CCD0, ITimer base); own header pending

    // ---- Cameras -----------------------------------------------------------
    CCamera   m_ViewCamera;                          // +0x288  ctor names it "CSystem::m_ViewCamera" (0x180A52E09); GetViewCamera slot 135
    bool      m_bQuit;                               // +0x598  Quit() slot 32
    uint8_t   _pad599[7];                            // +0x599  alignment before CryString
    CryStringT<char> m_unk5A0;                       // +0x5A0  ctor empty-string 0x180A52E15; dtor releases a1+0xB4; name OPEN
    bool      m_bFatalError;                         // +0x5A8  set 1 @0x18245A318 before "*ERROR" log; slot 33 getter
    bool      m_bDedicatedServer;                    // +0x5A9  Init copies SSystemInitParams+0x125F; slot 34 getter
    bool      m_unk5AA;                              // +0x5AA  slot 38 getter; store 0x18245E949
    uint8_t   _pad5AB;                               // +0x5AB
    uint32_t  m_unk5AC;                              // +0x5AC  slot 35 dword setter / slot 36 getter
    bool      m_unk5B0;                              // +0x5B0  Init copies init-params+0x1251 (bEditor candidate, unproven); slot 139 getter
    bool      m_unk5B1;                              // +0x5B1  shutdown gates r_Width/r_Height/r_ColorBits restore on it
    bool      m_unk5B2;                              // +0x5B2  Init copies init-params+0x126A
    bool      m_unk5B3;                              // +0x5B3  Init zeroes before registering "sys_no_crash_dialog"
    bool      m_unk5B4;                              // +0x5B4  init-params+0x1260; slots 205-214/218 are the getters of this bool block
    bool      m_unk5B5;                              // +0x5B5  init-params+0x1262
    bool      m_unk5B6;                              // +0x5B6  init-params+0x1263
    bool      m_unk5B7;                              // +0x5B7  init-params+0x1268
    bool      m_unk5B8;                              // +0x5B8  init-params+0x1269
    bool      m_unk5B9;                              // +0x5B9  init-params+0x126C
    bool      m_unk5BA;                              // +0x5BA  init-params+0x1264
    bool      m_unk5BB;                              // +0x5BB  init-params+0x1265
    bool      m_unk5BC;                              // +0x5BC  init-params+0x1266
    bool      m_unk5BD;                              // +0x5BD  ctor-zeroed only (not an init-params copy)
    bool      m_unk5BE;                              // +0x5BE  init-params+0x1267
    bool      m_unk5BF;                              // +0x5BF  init-params+0x1250
    bool      m_unk5C0;                              // +0x5C0  init-params+0x1254; slot 49 getter
    bool      m_bDedicatedArbitrator;                // +0x5C1  init-params+0x1252; forced 1 on cmdline "dedicatedarbitrator" (0x183DC8360)
    bool      m_bNoRender;                           // +0x5C2  slot 136 setter; RenderBegin/End (slots 10/11) skip when set
    uint8_t   _pad5C3[5];                            // +0x5C3
    IValidator* m_pValidator;                        // +0x5C8  slot 63 getter; may alias m_pDefaultValidator (shutdown nulls this first when equal)
    bool      m_unk5D0;                              // +0x5D0  slot 124 setter / slot 125 getter
    bool      m_unk5D1;                              // +0x5D1  slot 126 getter
    bool      m_unk5D2;                              // +0x5D2  slot 124 clears it when arg!=0
    uint8_t   _pad5D3[5];                            // +0x5D3
    SDefaultValidator* m_pDefaultValidator;          // +0x5D8  Init constructs when init-params+0x40 null; shutdown virtual-deletes
    int32_t   m_unk5E0;                              // +0x5E0  ctor 1000
    uint8_t   _pad5E4[4];                            // +0x5E4
    CryStringT<char> m_unk5E8;                       // +0x5E8  ctor empty-string; dtor releases a1+0xBD; name OPEN
    CCPUInfo* m_pCPUInfo;                            // +0x5F0  slot 24 reads +0xB8 feature bits, slot 25 returns +0xB0 count
    Cry::System::CDriveInfo* m_pDriveInfo;           // +0x5F8  slot 26 lazy-allocs (lock cmpxchg), vtable 0x1846A6230
    uint8_t   _pad600[8];                            // +0x600  no member store (vtable-scan +0x600 hits are foreign vfunc calls)
    CryStringT<char> m_sCmdLine;                     // +0x608  Init copies init-params+0x50 (the "Cmdline: '%s'" buffer)
    uint8_t   _pad610[8];                            // +0x610  inside ctor memset(this+0x618-0x08..)? no writer found
    void*     m_dllHandles[16];                      // +0x618  HMODULEs; ctor memset 0x80; dtor FreeLibrary loop 0x182456F6B.. (NOT smart_ptrs)
    uint8_t   _tree698[0x10];                        // +0x698  std::_Tree {_Myhead,_Mysize}; dtor sub_181AD7810; Key/T OPEN
    void*     m_unk6A8;                              // +0x6A8  slot 67 getter; shutdown calls pointee vfunc +0x70(1); pointee OPEN
    void*     m_unk6B0;                              // +0x6B0  slot 137 setter / slot 138 getter; pointee OPEN
    CCryMemoryManager* m_pMemoryManager;             // +0x6B8  GetIMemoryManager slot 73; static singleton, "MTSafeHeap"
    void*     m_unk6C0;                              // +0x6C0  slots 64/65 getters (+8 interface adjust); shutdown virtual-deletes; class OPEN
    CCamera   m_PhysRendererCamera;                  // +0x6C8  ctor names it "CSystem::m_PhysRendererCamera" (0x180584004)
    uint8_t   _pad9D8[8];                            // +0x9D8  hole after CCamera; no access in ctor/Init/dtor/239 virtuals
    void*     m_pUnk9E0;                             // +0x9E0  ctor 0; type UNVERIFIED

    // ---- Subsystem/manager pointers ----------------------------------------
    CSystemEventDispatcher* m_pSystemEventDispatcher; // +0x9E8  ctor sub_180A53908 installs CSystemEventDispatcher vtable on 0x68-byte alloc; slot 85 getter
    void*     m_unk9F0;                              // +0x9F0  ctor 0; no other writer; pointee OPEN
    CBudgetingSystem* m_pBudgetingSystem;            // +0x9F8  slot 59; construction skipped for dedicated server
    CZLibCompressor* m_pZLibCompressor;              // +0xA00  slot 50 (old GetIRenderer_unk label was wrong)
    CZLibDecompressor* m_pZLibDecompressor;          // +0xA08  slot 51
    CLZ4Decompressor* m_pLZ4Decompressor;            // +0xA10  slot 52
    uint8_t   _padA18[0x8];                          // +0xA18  hole; no producer
    CXmlUtils* m_pXmlUtils;                          // +0xA20  ctor sub_180A53D80 installs CXmlUtils vtable on 0x30-byte alloc (embeds CReadWriteXMLSink); slot 132
    Serialization::CArchiveHost* m_pArchiveHost;     // +0xA28  ctor sub_180A53844 returns Serialization::CArchiveHost; slot 133
    bool      m_unkA30;                              // +0xA30  ctor byte store 0x180A52EA7; sole writer
    uint8_t   _padA31[7];                            // +0xA31  alignment to CryString
    CryStringT<char> m_rootFolder;                   // +0xA38  GetRootFolder() slot 4; dtor decrefs via CryStringT dtor helper (a1+327)
    int32_t   m_iApplicationInstance[2];             // +0xA40  ctor -1/-1; 0x1817901C8 claims a free index via CreateMutexA "%s2"/"(%d)"
    int32_t   m_iHeight;                             // +0xA48  shutdown writes it back to cvar "r_Height"
    int32_t   m_iWidth;                              // +0xA4C  shutdown writes it back to cvar "r_Width"
    int32_t   m_iColorBits;                          // +0xA50  shutdown writes it back to cvar "r_ColorBits"
    uint8_t   _padA54[0x1C];                         // +0xA54
    void*     m_unkA70;                              // +0xA70  ctor 0 only
    uint8_t   _padA78[0x28];                         // +0xA78
    void*     m_unkAA0;                              // +0xAA0  ctor 0; has reads
    ICVar*    m_cvarsAA8[7];                         // +0xAA8..+0xD8  shutdown Releases (vfunc +8) then zeros; individual cvar names OPEN
    uint8_t   _padAE0[0x28];                         // +0xAE0
    ICVar*    m_cvarB08;                             // +0xB08
    uint8_t   _padB10[0x50];                         // +0xB10
    void*     m_unkB60;                              // +0xB60  vtable object: shutdown vfunc +0x10 (uint) then Release +8; NOT an ICVar
    uint8_t   _padB68[0x18];                         // +0xB68
    ICVar*    m_cvarsB80[3];                         // +0xB80/+0xB88/+0xB90
    uint8_t   _padB98[0x18];                         // +0xB98
    ICVar*    m_cvarsBB0[20];                        // +0xBB0..+0xC48  consecutive Release run
    uint8_t   _padC50[8];                            // +0xC50
    ICVar*    m_cvarC58;                             // +0xC58  used by slot 158
    ICVar*    m_cvarC60;                             // +0xC60  shutdown sets it to "0" (vfunc +0x48) before Release
    ICVar*    m_cvarC68;                             // +0xC68
    uint8_t   _padC70[0x10];                         // +0xC70
    ICVar*    m_cvarsC80[3];                         // +0xC80/+0xC88/+0xC90
    uint8_t   _padC98[0x20];                         // +0xC98
    CryStringT<char> m_unkCB8;                       // +0xCB8  ctor empty-string; dtor releases a1+0x197; name OPEN
    ISystemUserCallback* m_pUserCallback;            // +0xCC0  Init stores init-params+0x28; if null+arbitrator, CWindowsConsole+0x10 subobject
    void*     m_hWnd;                                // +0xCC8  WIN_HWND from init-params+0x08; slot 88 getter; slot 6 IsWindow()
    void*     m_hInst;                               // +0xCD0  WIN_HINSTANCE from init-params+0x00
    void*     m_unkCD8;                              // +0xCD8  shutdown sub_182458778 then zeros; pointee OPEN
    void*     m_unkCE0;                              // +0xCE0  shutdown virtual-deletes; pointee OPEN

    // ---- Embedded subsystems (own vtables set in ctor) ---------------------
    uint8_t   m_FrameProfileSystem[0x68];            // +0xCE8  CFrameProfileSystem vtable (GetIProfileSystem slot 62; incl ptr@0xD48 alloc 0x9F8 slot 156)  /* size tentative */
    Offsets::ILocalizationManager* m_pLocalizationManager; // +0xD50  GetLocalizationManager slot 173; allocated as CLocalizedStringsManager
    uint8_t   m_nameTable[0xC8];                     // +0xD58  CNameTable vtable (folds fields 0xDF0/0xE08/0xE10)  /* size tentative */
    uint8_t   m_ProfilingSystem[0x1C08];             // +0xE20  CProfilingSystem (GetIProfilingSystem slot 84) + folded state up to 0x2A28  /* size tentative */

    // ---- Tail state --------------------------------------------------------
    uint32_t  m_nProfileCount;                       // +0x2A28  slot 187 indexes 0x38-byte records at this+0xE28 by it
    bool      m_unk2A2C;                             // +0x2A2C  Update stores; slot 172 getter
    bool      m_unk2A2D;                             // +0x2A2D  slot 199 or's it
    bool      m_unk2A2E;                             // +0x2A2E  slot 7 tests before clearing NeedDoWork
    bool      m_unk2A2F;                             // +0x2A2F  slot 104 getter
    uint64_t  m_unk2A30;                             // +0x2A30  counter: Update increments (0x180667B28); slot 178 getter; not a pointer
    uint8_t   _pad2A38[8];                           // +0x2A38
    uint8_t   m_unk2A40[0x38];                       // +0x2A40  ctor xmm-zeros + byte +0x2A70; slot 28 lea's it; typed producer OPEN
    CDownloadManager* m_pDownloadManager;            // +0x2A78  pointee stores this at +8
    uint8_t   _pad2A80[0x48];                        // +0x2A80  no ctor store until +0x2AC8
    std::vector<IOutputPrintSink*> m_errorSinks;     // +0x2AC8  fatal-error path 0x18245A46C walks it, calls sink vfunc +0x10 with the message
    uint32_t  m_unk2AE0;                             // +0x2AE0  slot 197 getter
    uint8_t   _pad2AE4[4];                           // +0x2AE4
    void*     m_unk2AE8;                             // +0x2AE8  slot 105 setter / slot 106 getter; pointee OPEN
    CCmdLine* m_pCmdLine;                            // +0x2AF0  slot 68 getter; tokenises init-params cmdline
    CTestSystemLegacy* m_pTestSystemLegacy;          // +0x2AF8  ctor sub_180A53ACC installs CTestSystemLegacy vtable on 0x38-byte alloc; slot 193
    void*     m_unk2B00;                             // +0x2B00  owning ptr, dtor sub_182458644 destroys {CryString; 16B vector; 8B vector}; class OPEN
    CThreadTaskManager* m_pThreadTaskManager;        // +0x2B08  ctor sub_180A53EC0 installs CThreadTaskManager vtable on 0x108-byte alloc; slot 83
    CResourceManager* m_pResourceManager;            // +0x2B10  ctor sub_180A541AC installs CResourceManager vtable on 0x1F0-byte alloc (embeds CAsyncPakManager @+0x150); slot 82
    wh::C_LoadingMonitor* m_pLoadingMonitor;         // +0x2B18  slot 98 getter; dtor via vfunc +0x38(1)
    wh::C_ReadinessService* m_pReadinessService;     // +0x2B20  slot 99 getter; dtor via vfunc +0x48
    wh::C_DurationProfiler* m_pDurationProfiler;     // +0x2B28  slot 100 getter
    void*     m_unk2B30;                             // +0x2B30  owning ptr, pointee dtor sub_18245751C {CryString@+0x10; two vectors}; class OPEN
    wh::C_ConsoleModeProvider* m_pConsoleModeProvider; // +0x2B38  slot 103 getter; 8-byte vtable wrapper
    CWindowsConsole* m_pTextModeConsole;             // +0x2B40  ITextModeConsole; +0x10 subobject doubles as ISystemUserCallback
    void*     m_unk2B48;                             // +0x2B48  slot 55 getter; Init zeros it near "nodevmode" check; no constructing producer
    CryStringT<char> m_unk2B50;                      // +0x2B50  Init assigns init-params+0x1150; name OPEN
    CryStringT<char> m_unk2B58;                      // +0x2B58  slot 23 getter; name OPEN
    CryStringT<char> m_unk2B60;                      // +0x2B60  name OPEN
    CryStringT<char> m_versionString;                // +0x2B68  build version "release_1_5_1308617_856"; slot 152
    uint8_t   _vec2B70[0x18];                        // +0x2B70  std::vector of 16-byte records (dtor 0x1823C9A10); element type OPEN; slot 195 aggregates float@+8 per record
    int32_t   m_unk2B88;                             // +0x2B88  ctor -1; slot 196 lea's it (index/head, not a pointer)
    uint8_t   _pad2B8C[4];                           // +0x2B8C
    uint8_t   _list2B90[0x10];                       // +0x2B90  {node* head; qword} 2-link self-sentinel list (ctor sub_1806AA234, dtor sub_182456678); T OPEN
    uint8_t   m_unk2BA0;                             // +0x2BA0  ctor word-zero covers +0x2BA0/+0x2BA1
    bool      m_bNeedDoWorkDuringOcclusionChecks;    // +0x2BA1  slot 8 getter, slot 7 clears, Update sets
    uint8_t   _pad2BA2[2];                           // +0x2BA2
    uint32_t  m_unk2BA4;                             // +0x2BA4  ctor 0x22; slot 37 predicate on {0x13,0x22,0x14}
    bool      m_unk2BA8;                             // +0x2BA8  slots 183/185 get/set
    uint8_t   _pad2BA9[3];                           // +0x2BA9
    uint32_t  m_unk2BAC;                             // +0x2BAC  slots 202/203 get/set
    std::vector<Offsets::IWindowMessageHandler*> m_windowMessageHandlers; // +0x2BB0  ctor pushes own +0x18 subobject
    CImeManager* m_pImeManager;                      // +0x2BC8  slot 230 uses it
    int32_t   m_refCount;                            // +0x2BD0  AddRef/DecRef slots 220/221 (lock inc/dec)
    uint8_t   _pad2BD4[4];                           // +0x2BD4
    void*     m_hWndAlt;                             // +0x2BD8  second WIN_HWND from init-params+0x10 (NOT ILog*): slot 6 IsWindow, slot 222 DestroyWindow, slot 223 getter
    bool      m_unk2BE0;                             // +0x2BE0  ctor 1; Init overwrites
    bool      m_unk2BE1;                             // +0x2BE1  slots 216/217 set/get
    uint8_t   _pad2BE2[6];                           // +0x2BE2
    CryStringT<char> m_unk2BE8;                      // +0x2BE8  name OPEN
    int32_t   m_unk2BF0;                             // +0x2BF0  ctor 0
    uint8_t   _pad2BF4[4];                           // +0x2BF4  tail padding to sizeof
};
static_assert(sizeof(CSystem) == 0x2BF8);
static_assert(offsetof(CSystem, m_ViewCamera) == 0x288);
static_assert(offsetof(CSystem, m_bQuit) == 0x598);
static_assert(offsetof(CSystem, m_pValidator) == 0x5C8);
static_assert(offsetof(CSystem, m_sCmdLine) == 0x608);
static_assert(offsetof(CSystem, m_dllHandles) == 0x618);
static_assert(offsetof(CSystem, m_pMemoryManager) == 0x6B8);
static_assert(offsetof(CSystem, m_PhysRendererCamera) == 0x6C8);
static_assert(offsetof(CSystem, m_pUnk9E0) == 0x9E0);
static_assert(offsetof(CSystem, m_pSystemEventDispatcher) == 0x9E8);
static_assert(offsetof(CSystem, m_rootFolder) == 0xA38);
static_assert(offsetof(CSystem, m_iHeight) == 0xA48);
static_assert(offsetof(CSystem, m_cvarsAA8) == 0xAA8);
static_assert(offsetof(CSystem, m_unkCB8) == 0xCB8);
static_assert(offsetof(CSystem, m_hWnd) == 0xCC8);
static_assert(offsetof(CSystem, m_FrameProfileSystem) == 0xCE8);
static_assert(offsetof(CSystem, m_pLocalizationManager) == 0xD50);
static_assert(offsetof(CSystem, m_nProfileCount) == 0x2A28);
static_assert(offsetof(CSystem, m_errorSinks) == 0x2AC8);
static_assert(offsetof(CSystem, m_pCmdLine) == 0x2AF0);
static_assert(offsetof(CSystem, m_versionString) == 0x2B68);
static_assert(offsetof(CSystem, m_windowMessageHandlers) == 0x2BB0);
static_assert(offsetof(CSystem, m_refCount) == 0x2BD0);
static_assert(offsetof(CSystem, m_hWndAlt) == 0x2BD8);
