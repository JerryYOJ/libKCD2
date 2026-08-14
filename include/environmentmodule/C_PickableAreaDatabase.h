#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include "C_PickableAreaData.h"
#include "S_PickableAreaRow.h"
#include "../databasemodule/C_ObjectDatabaseIdIndexed.h"
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "../REL/Relocation.h"

// -----------------------------------------------
// wh::environmentmodule::C_PickableAreaDatabase -- "pickable_area_desc" database
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0xF8.
// -----------------------------------------------
// Global object @0x185326030; ctor sub_1811106B8. Dense byte-ID base extent
// 0xB8 plus the concrete MSVC unordered_map at +0xB8. Rebuild sub_181F2A5A0
// inserts every case-folded material-path CRC with its parsed definition pointer.

namespace wh::environmentmodule {

class C_PickableAreaDatabase
    : public databasemodule::C_ObjectDatabaseIdIndexed<
          databasemodule::C_ObjectTableDatabase<C_PickableAreaData, S_PickableAreaRow>,
          uint8_t> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PickableAreaDatabase;

    [[nodiscard]] static C_PickableAreaDatabase* GetInstance()
    {
        return reinterpret_cast<C_PickableAreaDatabase*>(REL::ID(2326).address());
    }

    std::unordered_map<uint32_t, const C_PickableAreaData*> m_materialIndex; // +0xB8
};
static_assert(sizeof(C_PickableAreaDatabase) == 0xF8,
              "C_PickableAreaDatabase is the 0xB8 dense-ID base plus a 0x40 hash index");
static_assert(offsetof(C_PickableAreaDatabase, m_materialIndex) == 0xB8,
              "material CRC index must begin at +0xB8");

}  // namespace wh::environmentmodule
