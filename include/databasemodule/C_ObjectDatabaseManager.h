#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>
#include "I_DatabaseListener.h"
#include "S_ObjectDatabaseOpaqueDelegateList.h"
#include "S_ObjectDatabaseSetCallbackList.h"
#include "../Offsets/vtables/ISystem.h"

// wh::databasemodule::C_ObjectDatabaseManager -- global object-database registry.
// sizeof 0xB0; primary vtable 0x183E3D860, ISystemEventListener at +0x08.

namespace wh::databasemodule {

class C_ObjectDatabaseBase;

class C_ObjectDatabaseManager
    : public I_DatabaseListener
    , public Offsets::ISystemEventListener
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ObjectDatabaseManager;

    ~C_ObjectDatabaseManager() override;  // primary [0] 0x182743D80
    RTTR_ENABLE()                         // primary [1..3]

    void _vf0() override;  // secondary [0], project replica of the deleting-dtor thunk
    void OnSystemEventAnyThread(uint32_t event,
                                uint64_t wparam,
                                uint64_t lparam) override;  // secondary [1]
    void OnSystemEvent(uint32_t event,
                       uint64_t wparam,
                       uint64_t lparam) override;           // secondary [2]

    static C_ObjectDatabaseManager* GetInstance();
    bool LoadAll(bool force);  // RTTR name; 0x182743DE0

    S_ObjectDatabaseOpaqueDelegateList m_callbacks10;       // +0x10, role OPEN
    S_ObjectDatabaseSetCallbackList m_databaseSetCallbacks; // +0x20
    std::vector<C_ObjectDatabaseBase*> m_databases;         // +0x30, RTTR "Databases"
    std::vector<C_ObjectDatabaseBase*> m_pendingDatabases;  // +0x48
    std::unordered_map<std::string, C_ObjectDatabaseBase*>
        m_nameIndexedDatabases;                             // +0x60
    bool m_dependencyGraphDirty;                            // +0xA0
    bool m_loadInProgress;                                  // +0xA1
    uint8_t _padA2[6];                                      // +0xA2
    void* m_levelLoadJob;                                   // +0xA8, exact handle type OPEN
};
static_assert(sizeof(C_ObjectDatabaseManager) == 0xB0,
              "C_ObjectDatabaseManager must be 0xB0");
static_assert(offsetof(C_ObjectDatabaseManager, m_callbacks10) == 0x10,
              "opaque callback channel at 0x10");
static_assert(offsetof(C_ObjectDatabaseManager, m_databaseSetCallbacks) == 0x20,
              "database-set callbacks at 0x20");
static_assert(offsetof(C_ObjectDatabaseManager, m_databases) == 0x30,
              "registered databases at 0x30");
static_assert(offsetof(C_ObjectDatabaseManager, m_pendingDatabases) == 0x48,
              "pending databases at 0x48");
static_assert(offsetof(C_ObjectDatabaseManager, m_nameIndexedDatabases) == 0x60,
              "name-indexed databases at 0x60");
static_assert(offsetof(C_ObjectDatabaseManager, m_dependencyGraphDirty) == 0xA0,
              "dependency-graph flag at 0xA0");
static_assert(offsetof(C_ObjectDatabaseManager, m_loadInProgress) == 0xA1,
              "load-in-progress flag at 0xA1");
static_assert(offsetof(C_ObjectDatabaseManager, m_levelLoadJob) == 0xA8,
              "level-load handle at 0xA8");

}  // namespace wh::databasemodule
