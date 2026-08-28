#pragma once
#include <cstddef>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

using C_ItemTagDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<CryStringT<char>, std::vector>;

class C_ItemTagDatabase : public C_ItemTagDatabaseBase {
public:
    ~C_ItemTagDatabase() override; // [0] 0x182A43D98
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ItemTagDatabase) == 0x78,
              "C_ItemTagDatabase size mismatch");

} // namespace wh::entitymodule
