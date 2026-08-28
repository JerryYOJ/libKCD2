#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "../../rttr/rttr_enable.h"
#include "C_BloodMask.h"

namespace wh::entitymodule::clothing {

using C_BloodMaskDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            std::shared_ptr<C_BloodMask>,
            std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            std::shared_ptr<C_BloodMask>>>;

class C_BloodMaskDatabase : public C_BloodMaskDatabaseBase {
public:
    ~C_BloodMaskDatabase() override;              // [0] 0x18291706C
    std::int32_t unk_01() const override;          // [1] returns 4
    bool unk_11() override;                        // [11] returns true
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_BloodMaskDatabase) == 0x78,
              "C_BloodMaskDatabase size mismatch");

} // namespace wh::entitymodule::clothing
