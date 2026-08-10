#pragma once
#include <cstddef>
#include <cstdint>
#include "I_TableSerializer.h"

// wh::databasemodule::C_FileTableSerializer -- shared file-backed serializer base.
// Abstract, sizeof 0x18; adds vtable slot [9].

namespace wh::databasemodule {

class C_FileTableSerializer : public I_TableSerializer {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FileTableSerializer;

    void CollectFiles(const S_DatabaseTableRecord& table,
                      std::set<CryStringT<char>>& files,
                      void* watchContext) override;  // [3] 0x180D18604
    bool SetLooseFilesOnly(bool enabled) override;   // [5] 0x180D19F30
    virtual const char* GetFileExtension() const = 0; // [9]

    bool m_looseFilesOnly;  // +0x10
    uint8_t _pad11[7];      // +0x11
};
static_assert(sizeof(C_FileTableSerializer) == 0x18,
              "C_FileTableSerializer must be 0x18");
static_assert(offsetof(C_FileTableSerializer, m_looseFilesOnly) == 0x10,
              "loose-file mode at 0x10");

}  // namespace wh::databasemodule
