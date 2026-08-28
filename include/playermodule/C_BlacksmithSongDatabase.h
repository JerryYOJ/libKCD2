#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "C_BlacksmithSong.h"

namespace wh::playermodule {

using C_BlacksmithSongDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<std::shared_ptr<C_BlacksmithSong>>;

class C_BlacksmithSongDatabase : public C_BlacksmithSongDatabaseBase {
public:
    ~C_BlacksmithSongDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase) // [18..20]
};

static_assert(sizeof(C_BlacksmithSongDatabase) == 0x78,
              "C_BlacksmithSongDatabase size mismatch");

} // namespace wh::playermodule
