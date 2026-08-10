#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "E_ObjectDBResult.h"
#include "I_ObjectDatabase.h"

// wh::databasemodule::C_ObjectDatabaseBase -- object-database lifecycle and dependency base.
// sizeof 0x30; vtable 0x183E3D888, exactly 21 slots.

namespace wh::databasemodule {

struct S_DatabaseTableRecord;

class C_ObjectDatabaseBase : public I_ObjectDatabase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ObjectDatabaseBase;

    ~C_ObjectDatabaseBase() override;                              // [0] 0x182743D3C
    int32_t unk_01() const override;                               // [1] returns 1; meaning OPEN
    const char* GetTableName() const override = 0;                 // [2]
    virtual bool unk_03();                                        // [3] false by default
    virtual std::size_t GetObjectCount() const = 0;                // [4]
    virtual bool unk_05();                                        // [5] false by default
    virtual bool IsLoaded() const = 0;                             // [6]
    virtual void Register();                                      // [7] registration phase
    virtual void Unregister();                                    // [8]
    virtual E_ObjectDBResult Load();                               // [9] RTTR name "Load"
    virtual bool ParseRows() = 0;                                 // [10]
    virtual bool unk_11();                                        // [11] false by default
    virtual void CollectDependencies(
        std::vector<C_ObjectDatabaseBase*>& dependencies);         // [12]
    virtual bool IsTableRecord(const S_DatabaseTableRecord* record) const; // [13]
    virtual void unk_14();                                        // [14]
    virtual void Clear();                                         // [15]
    virtual bool RebuildIndices();                                // [16] synthetic semantic name
    virtual void OnLoaded();                                      // [17] synthetic semantic name
    RTTR_ENABLE()                                                 // [18..20]

    int32_t m_versionNumber;                             // +0x08
    uint32_t _pad0C;                                    // +0x0C
    int32_t m_dependencyDepth;                          // +0x10 [SYNTHETIC NAME]
    uint32_t _pad14;                                    // +0x14
    std::vector<C_ObjectDatabaseBase*> m_dependents;    // +0x18 [SYNTHETIC NAME]
};
static_assert(sizeof(C_ObjectDatabaseBase) == 0x30,
              "C_ObjectDatabaseBase must be 0x30");
static_assert(offsetof(C_ObjectDatabaseBase, m_versionNumber) == 0x08,
              "database version at 0x08");
static_assert(offsetof(C_ObjectDatabaseBase, m_dependencyDepth) == 0x10,
              "dependency depth at 0x10");
static_assert(offsetof(C_ObjectDatabaseBase, m_dependents) == 0x18,
              "reverse-dependent vector at 0x18");

}  // namespace wh::databasemodule
