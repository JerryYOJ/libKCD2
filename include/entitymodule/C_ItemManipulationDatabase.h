#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_ItemManipulationData.h"

namespace wh::entitymodule {

using C_ItemManipulationDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<
        S_ItemManipulationData,
        std::vector>;

class C_ItemManipulationDatabase : public C_ItemManipulationDatabaseBase {
public:
    ~C_ItemManipulationDatabase() override;       // [0] 0x182A87A14
    std::int32_t unk_01() const override;         // [1] returns 4
    bool unk_11() override;                       // [11] returns true
    RTTR_ENABLE(C_ItemManipulationDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ItemManipulationDatabase) == 0x78,
              "C_ItemManipulationDatabase size mismatch");

} // namespace wh::entitymodule
