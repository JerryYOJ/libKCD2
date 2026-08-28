#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseBase.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "C_Action.h"

namespace wh::xgenaimodule::NPCState {

using C_ActionDatabaseBase = wh::databasemodule::C_ObjectTreeDatabase<
    std::shared_ptr<C_Action>, std::vector>;

class C_ActionDatabase : public C_ActionDatabaseBase {
public:
    ~C_ActionDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)                    // [18..20], vtable 0x183FF1878

    std::uint8_t m_unknown78[0x130];                                         // +0x78
};

static_assert(sizeof(C_ActionDatabase) == 0x1A8,
              "C_ActionDatabase size mismatch");

} // namespace wh::xgenaimodule::NPCState
