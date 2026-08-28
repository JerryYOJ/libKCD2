#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "C_EffectBase.h"
#include "E_ValidationMode.h"

namespace wh::xgenaimodule::NPCState {

#pragma pack(push, 4)
class C_ChangeItemSetAsideEffect : public C_EffectBase {
public:
    ~C_ChangeItemSetAsideEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    bool unk_04() override;
    bool unk_05() override;
    bool unk_08() override;
    bool unk_09() override;
    RTTR_ENABLE(C_EffectBase)

    E_ValidationMode::Type m_validationMode;                 // +0x10 RTTR "ValidationMode"
    std::uint8_t _pad11[3];                                 // +0x11
    std::optional<CryGUID> m_itemClassId;                    // +0x14 RTTR "ItemClassId"
    std::uint8_t m_unknown2C[0x14];                          // +0x2C
};
#pragma pack(pop)

static_assert(offsetof(C_ChangeItemSetAsideEffect, m_validationMode) == 0x10,
              "C_ChangeItemSetAsideEffect::m_validationMode offset mismatch");
static_assert(offsetof(C_ChangeItemSetAsideEffect, m_itemClassId) == 0x14,
              "C_ChangeItemSetAsideEffect::m_itemClassId offset mismatch");
static_assert(sizeof(C_ChangeItemSetAsideEffect) == 0x40,
              "C_ChangeItemSetAsideEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
