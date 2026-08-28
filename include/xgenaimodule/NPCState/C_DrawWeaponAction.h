#pragma once

#include <cstddef>
#include <cstdint>

#include "C_WeaponActionBase.h"
#include "E_UnknownWeaponSetMode.h"

namespace wh::xgenaimodule::NPCState {

class C_DrawWeaponAction : public C_WeaponActionBase {
public:
    ~C_DrawWeaponAction() override;
    RTTR_ENABLE(C_WeaponActionBase)                                          // [24..26], vtable 0x183BA4FB8

    E_UnknownWeaponSetMode::Type m_unknownWeaponSetModeRight;                // +0xF0 RTTR "UnknownWeaponSetModeRight"
    E_UnknownWeaponSetMode::Type m_unknownWeaponSetModeLeft;                 // +0xF1 RTTR "UnknownWeaponSetModeLeft"
    std::uint8_t m_unknownF2[0x36];                                          // +0xF2
};

static_assert(offsetof(C_DrawWeaponAction, m_unknownWeaponSetModeRight) == 0xF0,
              "C_DrawWeaponAction::m_unknownWeaponSetModeRight offset mismatch");
static_assert(offsetof(C_DrawWeaponAction, m_unknownWeaponSetModeLeft) == 0xF1,
              "C_DrawWeaponAction::m_unknownWeaponSetModeLeft offset mismatch");
static_assert(sizeof(C_DrawWeaponAction) == 0x128,
              "C_DrawWeaponAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
