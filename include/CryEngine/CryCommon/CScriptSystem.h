#pragma once
#include <cstdint>
#include <cstddef>
#include "../../Offsets/vtables/IScriptSystem.h"
#include "../../Offsets/vtables/ISystem.h"   // Offsets::ISystemEventListener (secondary base)

// -----------------------------------------------
// CScriptSystem - CryScriptSystem concrete Lua VM owner  (KCD2)
// -----------------------------------------------
// RTTI:   .?AVCScriptSystem@@      primary vtable 0x183b8c610 (69 slots)
// Target: WHGame.dll 1.5.6 (base 0x180000000)
// Constructor:        0x18144913c   |  Complete dtor: 0x1839ae5c8
// Scalar deleting dtor (vtable[0]): 0x1839ae87c -> operator delete(this, 17368)
//
// Multiple inheritance (from ctor/dtor vtable stores):
//   CScriptSystem : IScriptSystem (primary, +0x00), ISystemEventListener (+0x08)
//
// sizeof recovered from the scalar-deleting destructor:
//   sub_1839AE87C: sub_1839AE5C8(this); if(flag&1) sub_181AB5160(this, 17368);
//   => operator delete(this, 0x43D8).  VERIFIED.
//
// The bulk of the object (0x4300 of 0x43D8) is an inline array of 32 call/parse
// frames of 0x218 bytes each, built by the ctor loop
//   sub_18050B734(this+0xC0, /*stride*/536, /*count*/32, sub_181845230)
// and torn down by sub_180697F80(this+0xC0, 536, 32, ...).  VERIFIED extent.
//
// Global singleton pointer set by ctor: CScriptSystem* @ 0x18549CFB0.
// Shared lua_State* also cached at global 0x18549CFA0.

typedef struct lua_State lua_State;
struct IScriptTable;

// -----------------------------------------------
// ScriptAnyValue - type-discriminated get/set/call payload (0x18 bytes in KCD2)
// -----------------------------------------------
// type tags (from wrappers): 0=Nil/Any, 2=Bool, 3=Handle(int64), 4=Number(float),
// 5=String, 6=Table(IScriptTable*), 7/8=Function, 9=Vec3.
// CloneAny [28] writes value@+0x08 (qword) and an aux dword@+0x10 (userdata nRef /
// func ref); EndCallAnyN [21] strides results by 0x18 -> sizeof confirmed 0x18.
struct ScriptAnyValue {
    int             type;           // +0x00
    int             _pad04;         // +0x04
    union {                         // +0x08 .. +0x18
        bool            b;              // type 2
        int64_t         nHandle;        // type 3 (ScriptHandle / WUID / EntityId)
        float           number;         // type 4
        const char*     str;            // type 5
        IScriptTable*   table;          // type 6
        HSCRIPTFUNCTION function;       // type 7/8
        struct { float x, y, z; } vec3; // type 9  (z lands at +0x10)
        struct { void* ptr; int nRef; } ud; // userdata (nRef at +0x10)
    };
};
static_assert(sizeof(ScriptAnyValue) == 0x18, "ScriptAnyValue must be 0x18 in KCD2");

// -----------------------------------------------
// CScriptSystem
// -----------------------------------------------
class CScriptSystem
    : public Offsets::IScriptSystem          // +0x00  primary vtable (IScriptSystem)
    , public Offsets::ISystemEventListener   // +0x08  secondary base (dtor removes this as a system-event listener)
{
public:
    // ---- Lua VM ----
    lua_State*   m_pLuaState;                    // +0x10  Lua state; every script op reads this+0x10  VERIFIED
    void*        _field18;                       // +0x18  (unset in ctor)
    void*        _field20;                       // +0x20  (unset in ctor)

    int          m_nParamCount;                  // +0x28  active-call param counter (BeginCall sets 0/-1, PushFuncParam++)  VERIFIED
    int          _pad2C;                         // +0x2C
    void*        _field30;                       // +0x30  (ctor 0)
    void*        _field38;                       // +0x38  (ctor 0)

    uint8_t      m_field40[0x20];                // +0x40  embedded sub-object (dtor sub_1803F70D8); spans 0x40..0x60   tentative
    void*        m_pLoadedScripts;               // +0x60  loaded-script registry (0x28-byte obj; used by Reload/DumpLoadedScripts)  tentative
    void*        _field68;                       // +0x68  (ctor 0)

    uint8_t      m_scriptBindings[0x28];         // +0x70  embedded CScriptBindings (vtable@+0x70; dtor sub_1839AF040/sub_1839AE520)  tentative
    void*        m_pSystem;                      // +0x98  ISystem* (dtor uses it to remove this as system-event listener)  tentative

    float        m_fGCFreq;                      // +0xA0  GC frequency, seconds (ctor 10.0f; SetGCFrequency stores here)  VERIFIED
    uint8_t      _padA4[4];                      // +0xA4
    void*        _fieldA8;                        // +0xA8  (ctor 0)
    void*        m_pScriptBindManager;           // +0xB0  refcounted; RegisterScriptBind/FlushBindings read this+0xB0; Release()d in dtor  tentative
    void*        _fieldB8;                        // +0xB8  (unset in ctor)

    // ---- inline call/parse frame pool: 32 x 0x218 = 0x4300 ----
    uint8_t      m_callFrames[0x4300];           // +0xC0   ctor sub_18050B734(+0xC0, 536, 32, ...)      VERIFIED extent

    void*        m_pAllocator;                   // +0x43C0 script heap/allocator handle (stored base+12; dtor sub_1804FD898(x-12))  tentative
    void*        _field43C8;                      // +0x43C8 (unset in ctor)
    void*        m_pCallStackTable;              // +0x43D0 IScriptTable* debug call-stack (global @0x1856652B0; Release()d in dtor)  tentative
};
static_assert(sizeof(CScriptSystem) == 0x43D8, "CScriptSystem must be 0x43D8 (operator delete size)");
