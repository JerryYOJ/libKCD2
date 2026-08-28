#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_BlacksmithTemperature.h"

namespace wh::playermodule {

using C_BlacksmithTemperatureDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<std::shared_ptr<C_BlacksmithTemperature>>;

class C_BlacksmithTemperatureDatabase : public C_BlacksmithTemperatureDatabaseBase {
public:
    ~C_BlacksmithTemperatureDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_BlacksmithTemperatureDatabase) == 0x78,
              "C_BlacksmithTemperatureDatabase size mismatch");

} // namespace wh::playermodule
