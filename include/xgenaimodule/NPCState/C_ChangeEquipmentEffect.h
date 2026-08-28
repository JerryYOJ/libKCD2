#pragma once
#include <cstddef>
#include <cstdint>
#include "C_EffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeEquipmentEffect : public C_EffectBase {
public:
    ~C_ChangeEquipmentEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    bool unk_05() override;
    bool unk_08() override;
    bool unk_09() override;
    RTTR_ENABLE(C_EffectBase)

    std::uint8_t m_unknown10[0x90];                          // +0x10
};

static_assert(sizeof(C_ChangeEquipmentEffect) == 0xA0,
              "C_ChangeEquipmentEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
