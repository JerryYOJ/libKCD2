#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_AlchemyFeedback.h"

namespace wh::playermodule {

using C_AlchemyFeedbackDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<C_AlchemyFeedback>;

class C_AlchemyFeedbackDatabase : public C_AlchemyFeedbackDatabaseBase {
public:
    ~C_AlchemyFeedbackDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_AlchemyFeedbackDatabase) == 0x78,
              "C_AlchemyFeedbackDatabase size mismatch");

} // namespace wh::playermodule
