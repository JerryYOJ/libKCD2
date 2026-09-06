#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// Offsets::ICryPak -- KCD2 CCryPak (gEnv+0x58), PARTIAL interface.
// -----------------------------------------------
// Target: WHGame.dll 1.5.6 (kd7u). CCryPak RTTI 0x184a42130, primary vtable
// 0x183a97328 (COL 0x184176b58, subobject +0).
//
// The SDK ICryPak declaration order SURVIVES with a uniform +2 slot shift
// (two WH-inserted slots ahead of the file API); MSVC reverses each pair of
// adjacent overloads (FOpen, FGetSize, OpenPack, OpenPacks), same rule as
// IFlashPlayer::Set/GetVariable.
//
// VERIFIED anchors (decompiled bodies / in-binary consumer):
//   [36] FOpen(name,mode,nFlags)      0x180461240  full CryEngine mode-char parser
//                                                  ('r','w','b','t','x','+','S','R','D','N','C','T')
//   [39] FReadRawAll(data,size,f)     0x18051DF98  fseek(f,0,SEEK_SET) + whole-file read
//                                                  (in-memory pak entry copy short-circuit)
//   [46] FGetSize(FILE*)              0x1804609A8  handle-table entry size, fstat64 fallback
//   [55] FClose(FILE*)                0x180460770  1-based handle-slot release / real fclose
//   [63] FindFirst(wild,fd,flags,fs)  0x18096C4E8  consumer: IActorSystem::Scan 0x180E46CE8
//                                                  ("<dir>/*.*" loop on gEnv+0x58); ret -1 = none
//   [64] FindNext(handle,fd)          0x18041D3E0  same consumer; ret <0 = done
//   [65] FindClose(handle)            0x18096CCCC  find-handle refcount release
//
// FILE* handles are CryPak pseudo-handles (1-based indices into an internal
// table, real CRT FILE* for loose files) -- only pass them back into CryPak.
// Unnamed _vfN slots are real functions whose role is UNVERIFIED -- do not call.

namespace Offsets {

// CryPak find record. Filename offset +0x24 proven by the Scan consumer
// (reads fd+0x24 as the name); layout = CryCommon __finddata64_t with 32-bit
// size field.
struct SCryPakFindData {
    uint32_t attrib;         // 0x00
    int64_t  time_create;    // 0x08
    int64_t  time_access;    // 0x10
    int64_t  time_write;     // 0x18
    uint32_t size;           // 0x20
    char     name[260];      // 0x24
};
static_assert(offsetof(SCryPakFindData, name) == 0x24, "CryPak fd name @+0x24 (consumer 0x180E46CE8)");

struct ICryPak {
    virtual void _vf0() = 0;   // [0]  scalar deleting dtor
    virtual void _vf1() = 0;   // [1]
    virtual void _vf2() = 0;   // [2]
    virtual void _vf3() = 0;   // [3]
    virtual void _vf4() = 0;   // [4]
    virtual void _vf5() = 0;   // [5]
    // OpenPack overload pair (MSVC-reversed: bindRoot version first), then
    // ClosePack, then the OpenPacks pair. VERIFIED 2026-08-29; duplicate/
    // lock semantics RE'd 2026-08-30 (analysis/MCM/dispatch_trace/
    // crypak_priority.md):
    //   [6] 0x180DA1A5C adjusts BOTH names (vfunc[1] AdjustFileName, bindRoot
    //       with 0x50000) then OpenPackCommon 0x1804D45C4. THE mount lever:
    //       bindRoot is a lookup PREFIX -- FOpen walks the pak vector
    //       TAIL->begin and serves the first pak whose bindRoot prefixes the
    //       adjusted path, so pass "Data" to serve "Libs/..." requests.
    //       nFlags 0x400 inserts at the tail = wins duplicate paths
    //       (ModManager mounts every Mods/<mod>/Data/*.pak with 0x10400 in
    //       lowercased strcmp order; later mounts shadow earlier ones).
    //   [7] 0x18193CCA4 derives bindRoot = dirname(adjusted pak path)
    //       (strrchr '\\') -- WRONG ROOT for mod-style content: such a mount
    //       can never serve a "data\libs\..." lookup, it only opens a second
    //       OS handle on the file. (The earlier note here claiming this is
    //       "the same root the mod loader uses" was FALSE: the mod loader
    //       binds at GetGameFolder()="Data".)
    //   [8] ClosePack matches the STORED archive name only (path-only
    //       _stricmp after AdjustFileName; startup mod mounts store the
    //       lowercased glob form). NOT-FOUND RETURNS TRUE (silent no-op);
    //       found-but-referenced retries 10ms x200 (2s) then returns false
    //       and leaves the pak mounted. A re-OpenPack of the same
    //       path+bindRoot is a no-op that does NOT reread a replaced zip.
    //   [9] consumed in-binary by ModManager.cpp:0x115 sub_181DDCFD0
    //       ("[Mod] Opening paks in %s"): OpenPacks(bindRoot, "<dir>/*.pak",
    //       0x10400, 0) -- source of the nFlags value used below.
    virtual bool OpenPack_BindRoot(const char* szBindRoot, const char* pName,
                                   unsigned nFlags = 0x10400, void* pData = nullptr,
                                   void* pFullPath = nullptr) = 0;             // [6] 0x180DA1A5C
    virtual bool OpenPack(const char* pName, unsigned nFlags = 0x10400,
                          void* pData = nullptr,
                          void* pFullPath = nullptr) = 0;                      // [7] 0x18193CCA4
    virtual bool ClosePack(const char* pName, unsigned nFlags = 0) = 0;        // [8] 0x1804D92A8 (retries with adjusted name)
    virtual void _vf9() = 0;   // [9]  OpenPacks(szBindRoot, pWildcard, nFlags, pFullPaths) -- consumer-verified, unused here
    virtual void _vf10() = 0;  // [10] OpenPacks(pWildcard, ...) by pair order
    virtual void _vf11() = 0;  // [11] ClosePacks(pWildcard, nFlags) 0x1804D91AC -- globs DISK then ClosePack each (crypak_priority.md)
    virtual void _vf12() = 0;  // [12] is-open-by-path 0x18241BA54 -- forward _stricmp on stored archive names (crypak_priority.md)
    virtual void _vf13() = 0;  // [13]
    virtual void _vf14() = 0;  // [14]
    virtual void _vf15() = 0;  // [15]
    virtual void _vf16() = 0;  // [16]
    virtual void _vf17() = 0;  // [17]
    virtual void _vf18() = 0;  // [18]
    virtual void _vf19() = 0;  // [19]
    virtual void _vf20() = 0;  // [20]
    virtual void _vf21() = 0;  // [21]
    virtual void _vf22() = 0;  // [22]
    virtual void _vf23() = 0;  // [23]
    virtual void _vf24() = 0;  // [24]
    virtual void _vf25() = 0;  // [25]
    virtual void _vf26() = 0;  // [26]
    virtual void _vf27() = 0;  // [27]
    virtual void _vf28() = 0;  // [28]
    virtual void _vf29() = 0;  // [29]
    virtual void _vf30() = 0;  // [30]
    virtual void _vf31() = 0;  // [31]
    virtual void _vf32() = 0;  // [32]
    virtual void _vf33() = 0;  // [33]
    virtual void _vf34() = 0;  // [34]
    virtual void* FOpen_GamePath(const char* pName, const char* mode,
                                 char* szFileGamePath, int nLen) = 0;         // [35] 0x1824198A4  overload pair partner (SDK order reversed) -- tentative, prefer [36]
    virtual void* FOpen(const char* pName, const char* mode,
                        unsigned nFlags = 0) = 0;                             // [36] 0x180461240  VERIFIED (mode-char parser)
    virtual void* FOpenRaw(const char* pName, const char* mode) = 0;          // [37] 0x182419988  by SDK order -- tentative
    virtual size_t FReadRaw(void* data, size_t length, size_t elems,
                            void* handle) = 0;                                // [38] 0x1804610A4  by SDK order (sandwiched by verified [36]/[39])
    virtual size_t FReadRawAll(void* data, size_t nFileSize,
                               void* handle) = 0;                             // [39] 0x18051DF98  VERIFIED
    virtual void _vf40() = 0;  // [40] FGetCachedFileData by SDK order
    virtual void _vf41() = 0;  // [41] FWrite
    virtual void _vf42() = 0;  // [42] FPrintf
    virtual void _vf43() = 0;  // [43] FGets
    virtual void _vf44() = 0;  // [44] Getc
    virtual size_t FGetSizeByName(const char* pName,
                                  bool bAllowUseFileSystem = false) = 0;      // [45] 0x182419608  overload pair partner -- tentative
    virtual size_t FGetSize(void* handle) = 0;                                // [46] 0x1804609A8  VERIFIED (handle table / fstat64)
    virtual void _vf47() = 0;  // [47] Ungetc
    virtual void _vf48() = 0;  // [48] IsInPak
    virtual void _vf49() = 0;  // [49] RemoveFile
    virtual void _vf50() = 0;  // [50] RemoveDir
    virtual void _vf51() = 0;  // [51] IsAbsPath
    virtual void _vf52() = 0;  // [52] CopyFileOnDisk
    virtual void _vf53() = 0;  // [53] FSeek
    virtual void _vf54() = 0;  // [54] FTell
    virtual int FClose(void* handle) = 0;                                     // [55] 0x180460770  VERIFIED
    virtual void _vf56() = 0;  // [56] FEof
    virtual void _vf57() = 0;  // [57] FError
    virtual void _vf58() = 0;  // [58] FGetErrno
    virtual void _vf59() = 0;  // [59] FFlush
    virtual void _vf60() = 0;  // [60] PoolMalloc
    virtual void _vf61() = 0;  // [61] PoolFree
    virtual void _vf62() = 0;  // [62] PoolAllocMemoryBlock
    virtual intptr_t FindFirst(const char* pDir, SCryPakFindData* fd,
                               unsigned nFlags = 0,
                               bool bAllowUseFileSystem = false) = 0;         // [63] 0x18096C4E8  VERIFIED (consumer)
    virtual int FindNext(intptr_t handle, SCryPakFindData* fd) = 0;           // [64] 0x18041D3E0  VERIFIED (consumer)
    virtual int FindClose(intptr_t handle) = 0;                               // [65] 0x18096CCCC  VERIFIED
};

}  // namespace Offsets
