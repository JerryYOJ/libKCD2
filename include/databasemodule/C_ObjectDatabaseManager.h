#pragma once
#include <cstdint>
#include <cstddef>
#include <unordered_map>
#include <vector>
#include "I_DatabaseListener.h"
#include "../Offsets/vtables/ISystem.h"   // Offsets::ISystemEventListener replica
#include "../framework/HashPrimitives.h"

// ===========================================================================
// wh::databasemodule::C_ObjectDatabaseManager -- global database registry
// (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0xB0.
// ===========================================================================
// RTTI .?AVC_ObjectDatabaseManager@databasemodule@wh@@ (TD 0x184AF0870).  Vtables: primary
// 0x183E3D860 (I_DatabaseListener), +0x08 0x183E3D840 (ISystemEventListener).
// FUNCTION-LOCAL STATIC singleton @0x1854A49A0 -- accessor sub_180EF4F8C (TLS-guarded lazy init,
// ctor sub_1814BCFF8, atexit dtor). Every C_ObjectDatabaseBase ctor pushes itself into the
// +0x48 vector at static-init time.
// The two 0x10 blocks @+0x10/+0x20 are the bespoke wh compact 16B-entry containers (pointer to
// the shared zero sentinel unk_1856664D8 + two int16 -1 hints -- same family as
// C_FactionManager's S_FactionCompactMap).

namespace wh::databasemodule {

class C_ObjectDatabaseBase;

// Compact 16B-entry container (shared zero sentinel + two int16 hints); see C_FactionManager.h
// for the family notes.
struct S_DbCompactMap {
    void*   m_entries;   // +0x00  shared zero sentinel while empty (unk_1856664D8)
    int16_t m_hint0;     // +0x08  init -1
    int16_t m_hint1;     // +0x0A  init -1
    uint8_t _pad0C[4];   // +0x0C
};
static_assert(sizeof(S_DbCompactMap) == 0x10, "S_DbCompactMap must be 0x10");

class C_ObjectDatabaseManager
    : public I_DatabaseListener              // +0x00
    , public Offsets::ISystemEventListener   // +0x08
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ObjectDatabaseManager;
    // Forwards to the engine accessor sub_180EF4F8C (lazy-inits the 0x1854A49A0 static).
    // Impl in src/databasemodule/databasemodule.cpp.
    static C_ObjectDatabaseManager* GetInstance();

    S_DbCompactMap m_compact10;   // +0x10  [role UNRESOLVED]
    S_DbCompactMap m_compact20;   // +0x20  [role UNRESOLVED]
    uint64_t m_unk30[3];          // +0x30  ctor zeroes +0x30..+0x47
    std::vector<C_ObjectDatabaseBase*> m_databases;  // +0x48  every db self-registers here (ctor push)
    // +0x60  stock MSVC std::unordered_map (1.0f/mask 7/maxidx 8 fingerprint; 56-byte nodes) --
    // name -> database candidate [key/value typing UNVERIFIED]
    std::unordered_map<uint64_t, void*,
                       wh::shared::S_DefaultHash<uint64_t>> m_map60;   // +0x60
    uint16_t m_flagsA0;           // +0xA0  ctor 0
    uint8_t  _padA2[6];           // +0xA2
    uint64_t m_unkA8;             // +0xA8  ctor 0
};
static_assert(sizeof(C_ObjectDatabaseManager) == 0xB0, "C_ObjectDatabaseManager must be 0xB0 (ctor sub_1814BCFF8)");
static_assert(offsetof(C_ObjectDatabaseManager, m_databases) == 0x48, "database vector at 0x48");

}  // namespace wh::databasemodule
