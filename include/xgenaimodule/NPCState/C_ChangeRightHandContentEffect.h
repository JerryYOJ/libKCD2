#pragma once
#include <cstddef>
#include "C_ChangeHandContentEffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeRightHandContentEffect : public C_ChangeHandContentEffectBase {
public:
    ~C_ChangeRightHandContentEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    bool unk_05() override;
    bool unk_09() override;
    RTTR_ENABLE(C_ChangeHandContentEffectBase)
    wh::xgenaimodule::E_HandType::Type unk_13() override;    // returns Right
};

static_assert(sizeof(C_ChangeRightHandContentEffect) == 0x80,
              "C_ChangeRightHandContentEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
