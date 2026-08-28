#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include <vector>

#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "../../databasemodule/C_ObjectTreeDatabaseKeyIndexed.h"
#include "../../rttr/rttr_enable.h"
#include "C_Component.h"
#include "I_CharacterComponentDatabase.h"
#include "S_CharacterComponentQuery.h"
#include "S_CharacterComponentQueryCache.h"
#include "S_CharacterComponentSelectionWeights.h"

namespace wh::entitymodule::clothing {

using C_CharacterComponentDatabaseNameIndex =
    std::map<CryStringT<char>, std::shared_ptr<C_Component>>;

using C_CharacterComponentDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<
        wh::databasemodule::C_ObjectTreeDatabase<
            std::shared_ptr<C_Component>,
            std::vector>,
        C_CharacterComponentDatabaseNameIndex>;

class C_CharacterComponentDatabase
    : public C_CharacterComponentDatabaseBase,
      public I_CharacterComponentDatabase {
public:
    using candidate_map = std::map<
        S_CharacterComponentQuery,
        std::vector<std::shared_ptr<C_Component>>>;
    using selection_map = std::map<
        S_CharacterComponentQuery,
        S_CharacterComponentSelectionWeights>;

    ~C_CharacterComponentDatabase() override; // primary [0] 0x1829172C0
    std::int32_t unk_01() const override;      // primary [1] 0x181A72500; returns 4
    bool unk_11() override;                    // primary [11] 0x18041A6A0; returns true
    void CollectDependencies(
        std::vector<wh::databasemodule::C_ObjectDatabaseBase*>& dependencies) override; // primary [12] 0x180EF4FF4
    bool RebuildIndices() override;            // primary [16] 0x18176CD34
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // primary [18..20]

    const S_CharacterComponentName& SelectBody(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) override; // secondary [0]
    const S_CharacterComponentName& SelectHead(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) override; // secondary [1]
    const S_CharacterComponentName& SelectHair(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) override; // secondary [2]
    const S_CharacterComponentName& SelectBeard(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) override; // secondary [3]
    const S_CharacterComponentName& SelectClothing(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) override; // secondary [4]
    bool IsLoaded() const override;            // secondary [5]
    std::uint32_t UpdateFrameId() override;    // secondary [6]

    candidate_map m_candidates;                // +0x90
    S_CharacterComponentQueryCache m_queryCache; // +0xA0
    selection_map m_selectionWeights;          // +0x108
};

static_assert(sizeof(C_CharacterComponentDatabaseBase) == 0x88,
              "C_CharacterComponentDatabaseBase size mismatch");
static_assert(offsetof(C_CharacterComponentDatabase, m_candidates) == 0x90,
              "C_CharacterComponentDatabase::m_candidates offset mismatch");
static_assert(offsetof(C_CharacterComponentDatabase, m_queryCache) == 0xA0,
              "C_CharacterComponentDatabase::m_queryCache offset mismatch");
static_assert(offsetof(C_CharacterComponentDatabase, m_selectionWeights) == 0x108,
              "C_CharacterComponentDatabase::m_selectionWeights offset mismatch");
static_assert(sizeof(C_CharacterComponentDatabase) == 0x118,
              "C_CharacterComponentDatabase size mismatch");

} // namespace wh::entitymodule::clothing
