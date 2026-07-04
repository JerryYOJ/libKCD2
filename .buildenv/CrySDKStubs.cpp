#include <Windows.h>
#include <cstddef>
#include "REL.h"

// CryEngine SDK glue the vendored CryCommon headers reference but no game module
// provides in this build. Declarations come from the kcd.h PCH (which fixes the
// extern-C linkage of the CryModule* allocators).

void CryCreateCriticalSectionInplace(void* p) { InitializeCriticalSection(static_cast<CRITICAL_SECTION*>(p)); }
void CryDeleteCriticalSectionInplace(void* p) { DeleteCriticalSection(static_cast<CRITICAL_SECTION*>(p)); }

struct IMemoryManager;
IMemoryManager* CryGetIMemoryManager() { return nullptr; }

// Forward to WHGame.dll's own ucrtbase CRT thunks (malloc/calloc/realloc/free import
// thunks, api-ms-win-crt-heap) so blocks allocated by SDK types compiled into this
// module and freed by the game -- or vice versa -- share one heap.
__declspec(dllexport) void* CryModuleMalloc(size_t size) throw()
{
    static REL::Relocation<void* (__cdecl*)(size_t)> f{ REL::Offset(0x4F7BA0) };
    return f(size);
}
__declspec(dllexport) void* CryModuleCalloc(size_t count, size_t size)
{
    static REL::Relocation<void* (__cdecl*)(size_t, size_t)> f{ REL::Offset(0x1D93F11) };
    return f(count, size);
}
__declspec(dllexport) void* CryModuleRealloc(void* p, size_t size) throw()
{
    static REL::Relocation<void* (__cdecl*)(void*, size_t)> f{ REL::Offset(0x1D93F2F) };
    return f(p, size);
}
__declspec(dllexport) void CryModuleFree(void* p) throw()
{
    static REL::Relocation<void (__cdecl*)(void*)> f{ REL::Offset(0x1D93F17) };
    f(p);
}

// Aligned pair (used by CryArray's NAlloc::StandardAlloc / StdAllocator for over-aligned
// element types).  Forward to WHGame.dll's own _aligned_malloc / _aligned_free thunks so
// aligned blocks share the game's aligned heap -- consistent with the plain pair above and
// safe to hand across the module boundary.  Note: no throw() (matches the header decls).
__declspec(dllexport) void* CryModuleMemalign(size_t size, size_t alignment)
{
    static REL::Relocation<void* (__cdecl*)(size_t, size_t)> f{ REL::Offset(0x1D93FAD) };  // _aligned_malloc
    return f(size, alignment);
}
__declspec(dllexport) void CryModuleMemalignFree(void* p)
{
    static REL::Relocation<void (__cdecl*)(void*)> f{ REL::Offset(0x1D93FB3) };             // _aligned_free
    f(p);
}

// WHGame retail-DynArray bridge (NArray::WHDynStorage, WHDynStorage.h).  Our blocks must be
// byte-identical to the game's NArray blocks, so alloc/free go straight to the game's bucket
// allocator.

void* WHDynArrayAlloc(size_t nBytes, size_t* nActualBytes)
{
    // bucket alloc sub_1804F7610(size, &outActual, align) -- outActual is MANDATORY
    static REL::Relocation<void* (__fastcall*)(size_t, long long*, unsigned long long)> f{ REL::Offset(0x4F7610) };
    long long actual = 0;
    void* p = f(nBytes, &actual, 8);
    *nActualBytes = (size_t)actual;
    return p;
}

void WHDynArrayFree(void* pBlockBase)
{
    // bucket free sub_1804FD8D0(rawBase, adjusted): bucket ptrs ignore the flag; >0x200
    // malloc-fallback blocks carry a shift at [base-4] that nonzero unadjusts (pairs with align=8)
    static REL::Relocation<size_t (__fastcall*)(void*, long long)> f{ REL::Offset(0x4FD8D0) };
    f(pBlockBase, 1);
}

void* WHDynArrayDefaultAllocFn()
{
    // sub_1804A2C50 -- the single default realloc fn every game DynArray block carries at
    // [D-16]; stamped into our blocks so the game frees/grows them exactly like its own
    static void* const s_fn = (void*)REL::Offset(0x4A2C50).address();
    return s_fn;
}
