#pragma once
#include <cstddef>
#include <cstdint>
#include "../S_TriggerEffect.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"

namespace wh::playermodule {

using C_ControllerFeedbackDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<::S_TriggerEffect>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<::S_TriggerEffect>>;

class C_ControllerFeedbackDatabase : public C_ControllerFeedbackDatabaseBase {
public:
    ~C_ControllerFeedbackDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ControllerFeedbackDatabase) == 0x78,
              "C_ControllerFeedbackDatabase size mismatch");

} // namespace wh::playermodule
