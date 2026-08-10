#pragma once
#include <cstddef>
#include <cstdint>
#include <list>
#include <set>
#include <vector>
#include "C_ObjectDatabase.h"

// wh::databasemodule::C_ObjectTreeDatabase<TObject, TContainer> -- RTTR/XML tree database.
// vector form sizeof 0x78; list form sizeof 0x70; primary vtable has 22 slots.

namespace wh::databasemodule {

template <typename TObject,
          template <typename, typename> class TContainer = std::vector>
class C_ObjectTreeDatabase : public C_ObjectDatabase<TObject, TContainer> {
public:
    const char* GetTableName() const override;          // [2] returns m_name
    std::size_t GetObjectCount() const override;        // [4] specialization
    bool IsLoaded() const override;                     // [6] reads m_loaded
    E_ObjectDBResult Load() override;                   // [9] main XML plus multipart files
    bool ParseRows() override;                          // [10] dispatches RebuildIndices
    void Clear() override;                              // [15] clears objects and loaded flag
    virtual void unk_21();                              // [21] RTTR/XML row parser; signature OPEN

    CryStringT<char> m_namespace;                       // +0x48 vector / +0x40 list
    CryStringT<char> m_name;                            // +0x50 vector / +0x48 list
    CryStringT<char> m_group;                           // +0x58 vector / +0x50 list
    bool m_loaded;                                      // +0x60 vector / +0x58 list
    uint8_t _padLoaded[7];
    std::set<CryStringT<char>> m_multipartFiles;        // +0x68 vector / +0x60 list
};

static_assert(sizeof(C_ObjectTreeDatabase<int, std::vector>) == 0x78,
              "vector tree database must be 0x78");
static_assert(sizeof(C_ObjectTreeDatabase<int, std::list>) == 0x70,
              "list tree database must be 0x70");

}  // namespace wh::databasemodule
