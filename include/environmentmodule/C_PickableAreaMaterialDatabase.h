#pragma once
#include <cstddef>
#include <cstdint>
#include "S_PickableAreaMaterial.h"
#include "S_PickableAreaMaterialDBData.h"
#include "../databasemodule/C_ObjectDatabaseIdIndexed.h"
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "../REL/Relocation.h"

// -----------------------------------------------
// wh::environmentmodule::C_PickableAreaMaterialDatabase --
// "pickable_area_material" database (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0xB8.
// -----------------------------------------------
// Global object @0x185326130; ctor sub_181936D4C. The specialization is exactly
// C_ObjectDatabaseIdIndexed<C_ObjectTableDatabase<S_PickableAreaMaterial,
// S_PickableAreaMaterialDBData>, int32_t>; the next global begins at +0x110.

namespace wh::environmentmodule {

class C_PickableAreaMaterialDatabase
    : public databasemodule::C_ObjectDatabaseIdIndexed<
          databasemodule::C_ObjectTableDatabase<S_PickableAreaMaterial,
                                                S_PickableAreaMaterialDBData>,
          int32_t> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PickableAreaMaterialDatabase;

    [[nodiscard]] static C_PickableAreaMaterialDatabase* GetInstance()
    {
        return reinterpret_cast<C_PickableAreaMaterialDatabase*>(REL::ID(2327).address());
    }
};
static_assert(sizeof(C_PickableAreaMaterialDatabase) == 0xB8,
              "C_PickableAreaMaterialDatabase must match the IdIndexed extent");

}  // namespace wh::environmentmodule
