#pragma once
#include <cstdint>
#include <vector>
#include "S_DatabaseNameRange.h"
#include "S_TableLayout.h"
#include "rttr/rttr_enable.h"

// wh::databasemodule::I_DatabaseModule -- database control interface.
// sizeof 0x08; vtable 0x183E3D240, exactly 31 slots.

namespace wh::databasemodule {

class C_DynamicEnumManager;
class C_ObjectDatabaseManager;
class I_TableSerializer;
struct S_DatabaseModuleSelfCell;
struct S_DatabaseTableRecord;
struct S_SerializationStringPoolBuilder;

class I_DatabaseModule {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_DatabaseModule;

    virtual ~I_DatabaseModule() = 0;  // [0] 0x182740E5C
    virtual bool ConfigureSerializers(const char* names) = 0;  // [1] 0x1817DE314
    virtual const char* GetConfiguredSerializers() const = 0;  // [2] 0x180602360
    virtual I_TableSerializer* FindSerializer(const char* name) = 0;  // [3] 0x1817DE480
    virtual I_TableSerializer* GetSerializer(uint32_t index) = 0;  // [4] 0x182740FB4
    virtual void SetAutoPatchDB(bool enabled) = 0;  // [5] 0x181A7CC90
    virtual bool IsAutoPatchDBEnabled() const = 0;  // [6] 0x181A7CD00
    virtual bool RegisterTable(const char* name, S_TableLayout* layout,
                               const char* path, uint32_t flags) = 0;  // [7] 0x180D17E54
    virtual bool RegisterGeneratedTable(const char* name,
                                        const S_TableLayout* layoutTemplate,
                                        const char* substitution,
                                        const char* path,
                                        uint32_t flags) = 0;  // [8] 0x180D16F58
    virtual bool LoadTable(const char* name, bool reload) = 0;  // [9] 0x180D18444
    virtual bool LoadTablesByName(const S_DatabaseNameRange& names,
                                  bool reload) = 0;  // [10] 0x18199D3E8
    virtual bool LoadTableRecords(const std::vector<S_DatabaseTableRecord*>& records,
                                  bool reload) = 0;  // [11] 0x182740FE0
    virtual S_DatabaseTableRecord* FindTableChecked(const char* name,
                                                     int32_t rowStride) = 0;  // [12] 0x18068B5A4
    virtual S_DatabaseTableRecord* GetTableRecord(const char* name) = 0;  // [13] 0x182740FAC
    virtual S_DatabaseTableRecord* FindTableRecord(const char* name) = 0;  // [14] 0x180697D60
    virtual bool UnloadTable(const char* name) = 0;  // [15] 0x180D17A9C
    virtual bool UnloadTablesByName(const S_DatabaseNameRange& names) = 0;  // [16] 0x18274107C
    virtual void UnloadTableRecords(
        const std::vector<S_DatabaseTableRecord*>& records) = 0;  // [17] 0x18274104C
    virtual void AssignInternedString(const char** target,
                                      const char* value) = 0;  // [18] 0x1803F5C20
    virtual const char* InternString(const char* value) = 0;  // [19] 0x182740EB4
    virtual uint32_t GetInternedStringCount() const = 0;  // [20] 0x181A7CCC0
    virtual uint32_t GetInternedStringBytes() const = 0;  // [21] 0x181A7CCD0
    virtual C_DynamicEnumManager* GetDynamicEnumManager() = 0;  // [22] 0x181A7CCA0
    virtual C_ObjectDatabaseManager* GetObjectDatabaseManager() = 0;  // [23] 0x180EF4964
    virtual S_SerializationStringPoolBuilder*
        GetSerializationStringPoolBuilder() = 0;  // [24] 0x180564FA0
    virtual uint32_t GetLoadErrorCount() const = 0;  // [25] 0x181A7CCB0
    virtual S_DatabaseModuleSelfCell* GetSelfCell() = 0;  // [26] 0x181A7CCF0
    virtual bool IsPatchingAllowed() const = 0;  // [27] 0x182740FD4; wh_db_AllowPatching > 0
    RTTR_ENABLE()  // [28..30]
};
static_assert(sizeof(I_DatabaseModule) == 0x08,
              "I_DatabaseModule must be 0x08");

}  // namespace wh::databasemodule
