#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseDynamicEnum.h"
#include "../databasemodule/C_ObjectDatabaseIdIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_WeaponClass.h"

namespace wh::entitymodule {

using C_WeaponClassDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseDynamicEnum<
        wh::databasemodule::C_ObjectDatabaseIdIndexed<
            wh::databasemodule::C_ObjectTreeDatabase<
                std::shared_ptr<S_WeaponClass>,
                std::vector>,
            int>>;

class C_WeaponClassDatabase : public C_WeaponClassDatabaseBase {
public:
    ~C_WeaponClassDatabase() override;             // [0] ICF-identical to base specialization
    std::int32_t unk_01() const override;           // [1] returns 4
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_WeaponClassDatabaseBase) == 0xA0,
              "C_WeaponClassDatabaseBase size mismatch");
static_assert(sizeof(C_WeaponClassDatabase) == 0xA0,
              "C_WeaponClassDatabase size mismatch");

} // namespace wh::entitymodule
