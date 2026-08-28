#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "../../rttr/rttr_enable.h"
#include "../S_Genderace.h"
#include "S_Uberlod.h"

namespace wh::entitymodule::clothing {

using C_UberlodDatabaseBase =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<S_Uberlod, std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_Uberlod>>;

class C_UberlodDatabase : public C_UberlodDatabaseBase {
public:
    struct S_GenderaceUberlodData;

    ~C_UberlodDatabase() override; // [0] 0x182917460
    std::int32_t unk_01() const override; // [1] returns 4
    void CollectDependencies(
        std::vector<wh::databasemodule::C_ObjectDatabaseBase*>& dependencies) override; // [12]
    bool RebuildIndices() override; // [16] 0x180E733D8
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]

    std::vector<std::pair<S_Genderace, S_GenderaceUberlodData>>
        m_genderaceUberlodData; // +0x78
};

static_assert(offsetof(C_UberlodDatabase, m_genderaceUberlodData) == 0x78,
              "C_UberlodDatabase::m_genderaceUberlodData offset mismatch");
static_assert(sizeof(C_UberlodDatabase) == 0x90,
              "C_UberlodDatabase size mismatch");

} // namespace wh::entitymodule::clothing
