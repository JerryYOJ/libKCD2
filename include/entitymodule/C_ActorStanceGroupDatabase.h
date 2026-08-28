#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../animationmodule/C_AnimationDatabaseBase.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "C_ActorStanceGroupData.h"
#include "I_ActorStanceGroupDatabase.h"

namespace wh::entitymodule {

using C_ActorStanceGroupDatabaseStorage =
    wh::databasemodule::C_ObjectDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            C_ActorStanceGroupData,
            std::vector>,
        wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<
            C_ActorStanceGroupData>>;

using C_ActorStanceGroupDatabaseBase =
    wh::animationmodule::C_AnimationDatabaseBase<
        C_ActorStanceGroupData,
        void,
        C_ActorStanceGroupDatabaseStorage>;

class C_ActorStanceGroupDatabase
    : public C_ActorStanceGroupDatabaseBase,
      public I_ActorStanceGroupDatabase {
public:
    ~C_ActorStanceGroupDatabase() override; // primary [0] 0x1828B1518
    std::int32_t unk_01() const override;   // primary [1] 0x181A72500; returns 4
    bool unk_11() override;                 // primary [11] 0x18041A6A0; returns true
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // primary [18..20]

    const C_ActorStanceGroupData* FindOrDefault(
        const CryStringT<char>& name) const override; // secondary [0] 0x1828B341C
};

static_assert(sizeof(C_ActorStanceGroupDatabaseStorage) == 0x78,
              "C_ActorStanceGroupDatabaseStorage size mismatch");
static_assert(sizeof(C_ActorStanceGroupDatabaseBase) == 0x78,
              "C_ActorStanceGroupDatabaseBase size mismatch");
static_assert(sizeof(C_ActorStanceGroupDatabase) == 0x80,
              "C_ActorStanceGroupDatabase size mismatch");

} // namespace wh::entitymodule
