#pragma once
#include <cstddef>
#include <unordered_map>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../databasemodule/C_ObjectDatabaseKeyMultiIndexed.h"
#include "../databasemodule/C_ObjectTableDatabase.h"
#include "../databasemodule/CryGUIDHasher.h"

// wh::rpgmodule::C_DocumentRewardPerkDatabase -- document_reward_perk table.
// sizeof 0xD8; RTTI TD 0x184D398A0, vtable 0x183BAFFE0.

namespace wh::rpgmodule {

struct S_DocumentRewardPerk;
struct S_DocumentRewardPerkDBData;

using T_DocumentRewardPerkIndex =
    std::unordered_multimap<CryGUID,
                            const S_DocumentRewardPerk*,
                            wh::databasemodule::CryGUIDHasher>;

class C_DocumentRewardPerkDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyMultiIndexed<
          wh::databasemodule::C_ObjectTableDatabase<S_DocumentRewardPerk,
                                                     S_DocumentRewardPerkDBData>,
          T_DocumentRewardPerkIndex>
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DocumentRewardPerkDatabase;
    static C_DocumentRewardPerkDatabase* GetInstance();
};
static_assert(sizeof(C_DocumentRewardPerkDatabase) == 0xD8,
              "C_DocumentRewardPerkDatabase must be 0xD8");

}  // namespace wh::rpgmodule
