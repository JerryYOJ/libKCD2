#pragma once
#include <memory>
#include <unordered_map>
#include "../crysystem/CXConsole.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectTreeDatabaseKeyIndexed.h"
#include "C_AddressKeyword.h"

namespace wh::musicmodule {

class C_AddressKeywordsDatabase
    : public wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<
              std::shared_ptr<C_AddressKeyword>>,
          std::unordered_map<int, std::shared_ptr<C_AddressKeyword>>>
    , public IConsoleArgumentAutoComplete {                    // +0xB8
public:
    ~C_AddressKeywordsDatabase() override;                     // [0] 0x182F10174
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)     // [18..20]

    int GetCount() const override;                             // secondary [1] 0x180BE29A0
    const char* GetValue(int index) const override;            // secondary [2] 0x180C9C484
};

static_assert(sizeof(C_AddressKeywordsDatabase) == 0xC0,
              "C_AddressKeywordsDatabase size mismatch");

}  // namespace wh::musicmodule
