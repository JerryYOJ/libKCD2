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
