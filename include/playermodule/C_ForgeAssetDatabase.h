#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_ForgeAsset.h"

namespace wh::playermodule {

using C_ForgeAssetDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<S_ForgeAsset>;

class C_ForgeAssetDatabase : public C_ForgeAssetDatabaseBase {
public:
    ~C_ForgeAssetDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_ForgeAssetDatabase) == 0x78,
              "C_ForgeAssetDatabase size mismatch");

} // namespace wh::playermodule
