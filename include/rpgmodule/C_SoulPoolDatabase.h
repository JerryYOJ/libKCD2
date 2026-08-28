#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../crysystem/CXConsole.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "C_SoulPoolBase.h"

namespace wh::rpgmodule {

using C_SoulPoolDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            std::shared_ptr<C_SoulPoolBase>, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            std::shared_ptr<C_SoulPoolBase>>>;

class C_SoulPoolDatabase
    : public C_SoulPoolDatabaseBase,
      public IConsoleArgumentAutoComplete {
public:
    ~C_SoulPoolDatabase() override;                               // primary [0], secondary [0]
    std::int32_t unk_01() const override;                         // primary [1], returns 10
    bool unk_11() override;                                      // primary [11], returns true
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // primary [18..20]

    int GetCount() const override;                               // secondary [1] 0x182B36C38
    const char* GetValue(int index) const override;              // secondary [2] 0x181A8CA30
};

static_assert(sizeof(C_SoulPoolDatabase) == 0x80,
              "C_SoulPoolDatabase size mismatch");

} // namespace wh::rpgmodule
