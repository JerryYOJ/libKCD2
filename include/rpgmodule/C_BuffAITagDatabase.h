#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_BuffAITag.h"

namespace wh::rpgmodule {

using C_BuffAITagDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<S_BuffAITag>;

class C_BuffAITagDatabase : public C_BuffAITagDatabaseBase {
public:
    ~C_BuffAITagDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::uint8_t m_runtimeTail[0xF8 - sizeof(C_BuffAITagDatabaseBase)]; // base extent to creator size
};

static_assert(sizeof(C_BuffAITagDatabase) == 0xF8,
              "C_BuffAITagDatabase size mismatch");

} // namespace wh::rpgmodule
