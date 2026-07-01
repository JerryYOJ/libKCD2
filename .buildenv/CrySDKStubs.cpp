#include <Windows.h>
#include <cstddef>
#include "Offsets/Offsets.h"

void CryCreateCriticalSectionInplace(void* p) { InitializeCriticalSection(static_cast<CRITICAL_SECTION*>(p)); }
void CryDeleteCriticalSectionInplace(void* p) { DeleteCriticalSection(static_cast<CRITICAL_SECTION*>(p)); }

struct IMemoryManager;
IMemoryManager* CryGetIMemoryManager() { return nullptr; }
void CryGetIMemoryManagerInterface(void** p) { if (p) *p = nullptr; }

// Game CRT allocator thunks (WHGame.dll, all jmp -> __imp_*). Plugin allocations
// live on the GAME's heap (matched malloc/free).
__declspec(dllexport) void* CryModuleMalloc(size_t size) throw()
{
    // 0x28D0A8: malloc thunk (-> __imp_malloc)
    static REL::Relocation<void* (__cdecl*)(size_t)> f{ REL::ID(887) };
    return f(size);
}
__declspec(dllexport) void* CryModuleCalloc(size_t count, size_t size)
{
    // 0xA2CB13: calloc thunk
    static REL::Relocation<void* (__cdecl*)(size_t, size_t)> f{ REL::ID(888) };
    return f(count, size);
}
__declspec(dllexport) void* CryModuleRealloc(void* p, size_t size) throw()
{
    // 0xA2CB31: realloc thunk
    static REL::Relocation<void* (__cdecl*)(void*, size_t)> f{ REL::ID(890) };
    return f(p, size);
}
__declspec(dllexport) void CryModuleFree(void* p) throw()
{
    // 0xA2CB19: free thunk
    static REL::Relocation<void (__cdecl*)(void*)> f{ REL::ID(889) };
    f(p);
}
