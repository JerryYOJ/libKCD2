#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "../../rttr/rttr_enable.h"
#include "IStaticMorphDatabaseWH.h"
#include "S_ClothingMorph.h"

namespace wh::entitymodule::clothing {

using C_ClothingMorphDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            S_ClothingMorph,
            std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            S_ClothingMorph>>;

class C_ClothingMorphDatabase
    : public C_ClothingMorphDatabaseBase,
      public ::IStaticMorphDatabaseWH {
public:
    ~C_ClothingMorphDatabase() override; // primary [0] 0x18295C374
    std::int32_t unk_01() const override; // primary [1] 0x181A72500; returns 4
    void Register() override;             // primary [7] 0x1819DF328
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // primary [18..20]

    bool HasMorph(const CryStringT<char>& name) const override; // secondary [0] 0x18114934C
};

static_assert(sizeof(C_ClothingMorphDatabaseBase) == 0x78,
              "C_ClothingMorphDatabaseBase size mismatch");
static_assert(sizeof(C_ClothingMorphDatabase) == 0x80,
              "C_ClothingMorphDatabase size mismatch");

} // namespace wh::entitymodule::clothing
