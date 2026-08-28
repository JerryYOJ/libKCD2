#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../databasemodule/C_ObjectDatabaseBase.h"
#include "../../databasemodule/C_ObjectTreeDatabase.h"
#include "S_AnyElementPreset.h"

namespace wh::xgenaimodule::NPCState {

using C_AnyElementPresetDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<S_AnyElementPreset, std::vector>;

class C_AnyElementPresetDatabase : public C_AnyElementPresetDatabaseBase {
public:
    ~C_AnyElementPresetDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)                    // [18..20], vtable 0x183AD81F8

    std::uint8_t m_unknown78[0x18];                                          // +0x78
};

static_assert(sizeof(C_AnyElementPresetDatabase) == 0x90,
              "C_AnyElementPresetDatabase size mismatch");

} // namespace wh::xgenaimodule::NPCState
