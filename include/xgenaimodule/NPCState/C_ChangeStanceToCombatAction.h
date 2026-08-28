#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ChangeStanceAction.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeStanceToCombatAction : public C_ChangeStanceAction {
public:
    ~C_ChangeStanceToCombatAction() override;
    RTTR_ENABLE(C_ChangeStanceAction)                                        // [24..26], vtable 0x183B5B648

    std::uint8_t m_unknown248[0x28];                                         // +0x248
};

static_assert(sizeof(C_ChangeStanceToCombatAction) == 0x270,
              "C_ChangeStanceToCombatAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
