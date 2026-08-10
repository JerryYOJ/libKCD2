#pragma once
#include <cstddef>
#include <cstdint>
#include <set>
#include "S_DatabaseTableRecord.h"

// wh::databasemodule::I_TableSerializer -- registered-table loader interface.
// sizeof 0x10; vtable 0x183E3D1E0, exactly 9 slots.

namespace wh::databasemodule {

class I_TableSerializer {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_TableSerializer;

    virtual ~I_TableSerializer() = 0;  // [0] 0x182740E88
    virtual bool IsBinary() const = 0;  // [1]
    virtual const char* GetName() const = 0;  // [2]
    virtual void CollectFiles(
        const S_DatabaseTableRecord& table,
        std::set<CryStringT<char>>& files,
        void* watchContext);  // [3] watcher context type OPEN
    virtual void SetActive(bool active);  // [4] writes +0x08
    virtual bool SetLooseFilesOnly(bool enabled);  // [5]
    virtual bool Load(S_DatabaseTableRecord& table) = 0;  // [6]
    virtual bool unk_07();  // [7] constant false in retail
    virtual bool unk_08();  // [8] constant false in retail

    bool m_active;       // +0x08
    uint8_t _pad09[7];   // +0x09
};
static_assert(sizeof(I_TableSerializer) == 0x10,
              "I_TableSerializer must be 0x10");
static_assert(offsetof(I_TableSerializer, m_active) == 0x08,
              "serializer active flag at 0x08");

}  // namespace wh::databasemodule
