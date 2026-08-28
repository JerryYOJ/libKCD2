#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseBase.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "S_UnstanceTransitionData.h"

namespace wh::xgenaimodule::NPCState {

using C_UnstanceTransitionDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<S_UnstanceTransitionData,
                                             std::vector>;

class C_UnstanceTransitionDatabase : public C_UnstanceTransitionDatabaseBase {
public:
    ~C_UnstanceTransitionDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)                    // [18..20], vtable 0x184004D38

    std::uint8_t m_unknown78[0x40];                                          // +0x78
};

static_assert(sizeof(C_UnstanceTransitionDatabase) == 0xB8,
              "C_UnstanceTransitionDatabase size mismatch");

} // namespace wh::xgenaimodule::NPCState
