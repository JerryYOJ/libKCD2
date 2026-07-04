#pragma once
#include <cstdint>
#include "I_DatabaseModule.h"
#include "C_DynamicEnumManager.h"
#include "../framework/C_BaseModule.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::databasemodule::C_DatabaseModule -- the database module (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184AEF568.  Vtables: primary 0x183C38C80 (C_BaseModule/I_ModuleMessageListener),
// +0x10 0x183C38CC0 (the 31-slot I_DatabaseModule impl).  sizeof 0xF8 (PROVEN: module
// bootstrap sub_180C9DA44 raw-allocs 248 then ctor sub_18192BBB4).  The bootstrap stores
// this+0x10 (the I_DatabaseModule subobject) into module-registry+0x148 (slot [41]); the ctor
// also publishes the undisplaced instance to global qword_185168B48.  Dtor sub_182740A88
// confirms the container roles annotated below.

namespace wh::databasemodule {

class C_DatabaseModule
    : public wh::framework::C_BaseModule   // +0x00
    , public I_DatabaseModule              // +0x10
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DatabaseModule;

    // dtor: elements destroyed via sub_180D182CC then freed
    void*    m_vec18Begin;      // +0x18
    void*    m_vec18End;        // +0x20
    void*    m_vec18Cap;        // +0x28
    // dtor: elements destroyed via their vfptr (deleting dtor)
    void*    m_vec30Begin;      // +0x30
    void*    m_vec30End;        // +0x38
    void*    m_vec30Cap;        // +0x40
    CryStringT<char> m_str48;   // +0x48  [role UNVERIFIED]
    uint64_t m_unk50;           // +0x50  ctor 0 } vector-shaped [role UNVERIFIED]
    uint64_t m_unk58;           // +0x58  ctor 0 }
    uint64_t m_unk60;           // +0x60  ctor 0 }
    // dtor: each element is an 8-byte heap block holding a CryString (released then freed)
    void*    m_vec68Begin;      // +0x68
    void*    m_vec68End;        // +0x70
    void*    m_vec68Cap;        // +0x78
    // dtor: raw heap pointers, freed
    void*    m_vec80Begin;      // +0x80
    void*    m_vec80End;        // +0x88
    void*    m_vec80Cap;        // +0x90
    C_DynamicEnumManager m_dynamicEnums;   // +0x98..0xDF
    void*    m_pSelfHandleE0;   // +0xE0  -> 8-byte heap block {this} [weak-handle candidate]
    uint64_t m_unkE8;           // +0xE8  never written by the ctor
    void*    m_pSelfHandleF0;   // +0xF0  -> 16-byte heap block {this, 0}

    // Reads the undisplaced instance global qword_185168B48 (RVA 0x5168B48).
    // Impl in src/databasemodule/databasemodule.cpp.
    static C_DatabaseModule* GetInstance();
};
static_assert(sizeof(C_DatabaseModule) == 0xF8, "C_DatabaseModule must be 0xF8 (bootstrap alloc(248))");

}  // namespace wh::databasemodule
