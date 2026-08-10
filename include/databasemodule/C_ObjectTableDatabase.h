#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include "C_ObjectDatabase.h"
#include "S_DatabaseTableRecord.h"

// wh::databasemodule::C_ObjectTableDatabase<TObject, TDBData> -- registered table adapter.
// sizeof 0x98; primary vtable has 22 slots.

namespace wh::databasemodule {

template <typename TObject, typename TDBData>
class C_ObjectTableDatabase : public C_ObjectDatabase<TObject, std::vector> {
public:
    using db_data_type = TDBData;

    const char* GetTableName() const override;                         // [2] 0x180EF35F8
    std::size_t GetObjectCount() const override;                       // [4] specialization
    bool IsLoaded() const override;                                    // [6] reads +0x94
    void Register() override;                                         // [7] schema registration
    E_ObjectDBResult Load() override;                                 // [9] 0x180EF3A4C
    bool ParseRows() override;                                        // [10] specialization
    bool IsTableRecord(const S_DatabaseTableRecord* record) const override; // [13] 0x181FA8CE0
    void unk_14() override;                                           // [14] signature unresolved
    virtual void unk_21(int32_t value);                               // [21] writes +0x90

    S_DatabaseTableRecord* m_tableRecord;  // +0x48, borrowed
    std::string m_tableName;               // +0x50
    std::string m_groupName;               // +0x70
    int32_t m_unk90;                       // +0x90, slot [21] value
    bool m_loaded;                         // +0x94
    uint8_t _pad95[3];                     // +0x95
};

static_assert(sizeof(C_ObjectTableDatabase<int, int>) == 0x98,
              "table database must be 0x98");

}  // namespace wh::databasemodule
