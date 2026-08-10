#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_DynamicEnumManager.h"
#include "I_DatabaseModule.h"
#include "S_DatabaseLoadContext.h"
#include "S_DatabaseModuleSelfCell.h"
#include "S_DatabaseTableRecord.h"
#include "S_TableLayoutCacheEntry.h"
#include "../framework/C_BaseModule.h"

// wh::databasemodule::C_DatabaseModule -- concrete database module.
// sizeof 0xF8; primary vtable 0x183C38C80 (7 slots), I_DatabaseModule at +0x10.

namespace wh::databasemodule {

class C_DatabaseStringPool;
class C_ScriptBindDatabase;
class I_TableSerializer;
struct S_SerializationStringPoolBuilder;

class C_DatabaseModule
    : public wh::framework::C_BaseModule
    , public I_DatabaseModule
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DatabaseModule;

    ~C_DatabaseModule() override;                       // primary [0] 0x182740CCC
    void OnModuleMessage(void* message) override;       // primary [1] 0x1803B6E80
    bool Init(void* context) override;                  // primary [2] 0x180EF5D54
    void Deinit() override;                             // primary [3] 0x182740ED0
    void Update() override;                             // primary [4] 0x1803B6E80
    int GetModuleId() const override;                   // primary [5] 0x181A72470
    const char* GetModuleName() const override;         // primary [6] 0x181A71AE0

    bool ConfigureSerializers(const char* names) override;  // secondary [1]
    const char* GetConfiguredSerializers() const override;  // secondary [2]
    I_TableSerializer* FindSerializer(const char* name) override;  // secondary [3]
    I_TableSerializer* GetSerializer(uint32_t index) override;  // secondary [4]
    void SetAutoPatchDB(bool enabled) override;  // secondary [5]
    bool IsAutoPatchDBEnabled() const override;  // secondary [6]
    bool RegisterTable(const char* name, S_TableLayout* layout,
                       const char* path, uint32_t flags) override;  // secondary [7]
    bool RegisterGeneratedTable(const char* name,
                                const S_TableLayout* layoutTemplate,
                                const char* substitution,
                                const char* path,
                                uint32_t flags) override;  // secondary [8]
    bool LoadTable(const char* name, bool reload) override;  // secondary [9]
    bool LoadTablesByName(const S_DatabaseNameRange& names,
                          bool reload) override;  // secondary [10]
    bool LoadTableRecords(const std::vector<S_DatabaseTableRecord*>& records,
                          bool reload) override;  // secondary [11]
    S_DatabaseTableRecord* FindTableChecked(const char* name,
                                             int32_t rowStride) override;  // secondary [12]
    S_DatabaseTableRecord* GetTableRecord(const char* name) override;  // secondary [13]
    S_DatabaseTableRecord* FindTableRecord(const char* name) override;  // secondary [14]
    bool UnloadTable(const char* name) override;  // secondary [15]
    bool UnloadTablesByName(const S_DatabaseNameRange& names) override;  // secondary [16]
    void UnloadTableRecords(
        const std::vector<S_DatabaseTableRecord*>& records) override;  // secondary [17]
    void AssignInternedString(const char** target,
                              const char* value) override;  // secondary [18]
    const char* InternString(const char* value) override;  // secondary [19]
    uint32_t GetInternedStringCount() const override;  // secondary [20]
    uint32_t GetInternedStringBytes() const override;  // secondary [21]
    C_DynamicEnumManager* GetDynamicEnumManager() override;  // secondary [22]
    C_ObjectDatabaseManager* GetObjectDatabaseManager() override;  // secondary [23]
    S_SerializationStringPoolBuilder*
        GetSerializationStringPoolBuilder() override;  // secondary [24]
    uint32_t GetLoadErrorCount() const override;  // secondary [25]
    S_DatabaseModuleSelfCell* GetSelfCell() override;  // secondary [26]
    bool IsPatchingAllowed() const override;  // secondary [27]
    RTTR_ENABLE()  // secondary [28..30]

    static C_DatabaseModule* GetInstance();

    std::vector<S_DatabaseTableRecord*> m_tableRecords;    // +0x18, owned
    std::vector<I_TableSerializer*> m_serializers;          // +0x30, owned
    CryStringT<char> m_configuredSerializers;               // +0x48
    C_ScriptBindDatabase* m_scriptBind;                      // +0x50, owned by Init/Deinit
    C_DatabaseStringPool* m_internPool;                      // +0x58, owned by Init/Deinit
    S_SerializationStringPoolBuilder* m_serializationStringPoolBuilder; // +0x60
    std::vector<S_TableLayoutCacheEntry*> m_layoutCache;     // +0x68
    std::vector<char*> m_formattedColumnNames;               // +0x80, owned buffers
    C_DynamicEnumManager m_dynamicEnums;                     // +0x98
    bool m_autoPatchDB;                                      // +0xD8
    uint8_t _padD9[7];                                       // +0xD9
    S_DatabaseModuleSelfCell* m_selfCell;                    // +0xE0, owned
    int32_t m_allowPatching;                                 // +0xE8, wh_db_AllowPatching storage
    uint32_t _padEC;                                         // +0xEC
    S_DatabaseLoadContext* m_loadContext;                    // +0xF0, owned
};
static_assert(sizeof(C_DatabaseModule) == 0xF8,
              "C_DatabaseModule must be 0xF8");
static_assert(offsetof(C_DatabaseModule, m_tableRecords) == 0x18,
              "table-record vector at 0x18");
static_assert(offsetof(C_DatabaseModule, m_serializers) == 0x30,
              "serializer vector at 0x30");
static_assert(offsetof(C_DatabaseModule, m_configuredSerializers) == 0x48,
              "configured serializer string at 0x48");
static_assert(offsetof(C_DatabaseModule, m_scriptBind) == 0x50,
              "ScriptBind pointer at 0x50");
static_assert(offsetof(C_DatabaseModule, m_internPool) == 0x58,
              "intern pool at 0x58");
static_assert(offsetof(C_DatabaseModule, m_serializationStringPoolBuilder) == 0x60,
              "serialization string-pool builder at 0x60");
static_assert(offsetof(C_DatabaseModule, m_layoutCache) == 0x68,
              "layout cache at 0x68");
static_assert(offsetof(C_DatabaseModule, m_formattedColumnNames) == 0x80,
              "formatted column names at 0x80");
static_assert(offsetof(C_DatabaseModule, m_dynamicEnums) == 0x98,
              "dynamic-enum manager at 0x98");
static_assert(offsetof(C_DatabaseModule, m_autoPatchDB) == 0xD8,
              "auto-patch policy byte at 0xD8");
static_assert(offsetof(C_DatabaseModule, m_selfCell) == 0xE0,
              "self cell at 0xE0");
static_assert(offsetof(C_DatabaseModule, m_allowPatching) == 0xE8,
              "allow-patching CVar storage at 0xE8");
static_assert(offsetof(C_DatabaseModule, m_loadContext) == 0xF0,
              "load context at 0xF0");

}  // namespace wh::databasemodule
