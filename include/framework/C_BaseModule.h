#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::framework -- C_BaseModule / I_ModuleMessageListener  (KCD2 WHGame.dll 1.5.6, kd7u)
// -----------------------------------------------
// Base of every Warhorse game module (C_PlayerModule, C_CombatModule, ...).
//
// [FUNDAMENTAL vs KCD1] C_BaseModule was flattened. KCD1 had the ancestry
// C_BaseModule : C_Graph : S_Graph : S_Job (0x88 bytes, four graph-topology
// std::vectors, a stored m_moduleId, and I_ModuleMessageListener at +0x78).
// In KCD2 the graph ancestry is gone: C_BaseModule shares one primary vtable
// with I_ModuleMessageListener (mdisp 0, at +0x00) and carries only m_state.
// Module id is now a compile-time constant returned by GetModuleId, not stored.
//
// Primary vtable is 11 slots. Slot roles recovered from C_PlayerModule (the
// module ctor sub_180BE9208 installs this vtable):
//   [0] scalar-deleting dtor          [1] OnModuleMessage (I_ModuleMessageListener)
//   [2] Init                          [3] PostInit/register
//   [4] Update                        [5] GetModuleId (returns a constant)
//   [6] GetModuleName                 [7..10] helpers/thunks (roles unresolved)

namespace wh::framework {

// I_ModuleMessageListener -- framework message sink. Shares C_BaseModule's
// primary vtable in KCD2 (single-inheritance, subobject at +0x00).
class I_ModuleMessageListener {
public:
    virtual ~I_ModuleMessageListener() = default;         // [0]
    virtual void OnModuleMessage(void* msg) = 0;          // [1]
};

class C_BaseModule : public I_ModuleMessageListener {
public:
    virtual bool        Init() = 0;                       // [2]
    virtual void        PostInit() = 0;                   // [3]
    virtual void        Update() = 0;                     // [4]
    virtual int         GetModuleId() const = 0;          // [5]  KCD2 returns a constant
    virtual const char* GetModuleName() const = 0;        // [6]
    virtual void        _vf7() = 0;                       // [7]
    virtual void        _vf8() = 0;                       // [8]
    virtual void        _vf9() = 0;                       // [9]
    virtual void        _vf10() = 0;                      // [10]

    uint32_t m_state;        // +0x08  module state/flags (ctor inits 0)
    uint32_t _pad0C;         // +0x0C
};
static_assert(sizeof(C_BaseModule) == 0x10, "C_BaseModule must be 0x10 (vtable + m_state)");

}  // namespace wh::framework
