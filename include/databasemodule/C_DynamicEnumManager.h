#pragma once
#include <cstddef>
#include <boost/container/vector.hpp>
#include "C_DatabaseDynamicEnum.h"
#include "I_DatabaseListener.h"
#include "S_DynamicEnumRecord.h"
#include "S_OwnedDynamicEnumEntry.h"

// wh::databasemodule::C_DynamicEnumManager -- embedded dynamic-enum registry.
// sizeof 0x40; vtable 0x183C38C70.

namespace wh::databasemodule {

class C_DatabaseModule;

class C_DynamicEnumManager : public I_DatabaseListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DynamicEnumManager;

    ~C_DynamicEnumManager() override;  // [0] 0x182740D00

    void Register(const char* tableName,
                  I_DynamicEnum* provider);  // [SYNTHETIC NAME]
    void Unregister(const char* tableName);  // [SYNTHETIC NAME]

    template <typename TCallback>
    void ForEach(TCallback&& callback) const
    {
        for (const auto& entry : m_ownedEnums) {
            if (entry.m_adapter) {
                callback(entry.m_adapter->m_tableName,
                         static_cast<const I_DynamicEnum&>(*entry.m_adapter));
            }
        }
        for (const auto& record : m_registeredEnums) {
            if (record.m_provider) {
                callback(record.m_tableName, *record.m_provider);
            }
        }
    }

    boost::container::vector<S_OwnedDynamicEnumEntry> m_ownedEnums;  // +0x08
    boost::container::vector<S_DynamicEnumRecord> m_registeredEnums; // +0x20
    C_DatabaseModule* m_owner;                                       // +0x38, borrowed
};
static_assert(sizeof(C_DynamicEnumManager) == 0x40,
              "C_DynamicEnumManager must be 0x40");
static_assert(offsetof(C_DynamicEnumManager, m_ownedEnums) == 0x08,
              "owned dynamic-enum adapters at 0x08");
static_assert(offsetof(C_DynamicEnumManager, m_registeredEnums) == 0x20,
              "borrowed dynamic-enum registrations at 0x20");
static_assert(offsetof(C_DynamicEnumManager, m_owner) == 0x38,
              "database-module owner at 0x38");

}  // namespace wh::databasemodule
