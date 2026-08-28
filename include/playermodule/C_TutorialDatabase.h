#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "S_Tutorial.h"

namespace wh::playermodule {

using C_TutorialDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<std::shared_ptr<S_Tutorial>>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<std::shared_ptr<S_Tutorial>>>;

class C_TutorialDatabase : public C_TutorialDatabaseBase {
public:
    ~C_TutorialDatabase() override;
    RTTR_ENABLE(C_TutorialDatabaseBase) // [18..20]

    std::uint8_t m_runtimeTail[0x90 - sizeof(C_TutorialDatabaseBase)]; // base extent to creator size
};

static_assert(sizeof(C_TutorialDatabase) == 0x90,
              "C_TutorialDatabase size mismatch");

} // namespace wh::playermodule
