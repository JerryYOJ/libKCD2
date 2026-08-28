#pragma once
#include <cstddef>
#include <cstdint>
#include "E_DataSource.h"
#include "I_Effect.h"

namespace wh::xgenaimodule::NPCState {

class C_EffectBase : public I_Effect {
public:
    ~C_EffectBase() override;                             // [0] 0x181817F90
    bool unk_04() override;                               // [4] 0x18041A6A0 true
    bool unk_05() override;                               // [5] 0x18041A6A0 true
    bool unk_06() override;                               // [6] 0x180838AE0 false
    bool unk_07() override;                               // [7] 0x18041A6A0 true
    bool unk_08() override;                               // [8] 0x180838AE0 false
    bool unk_09() override;                               // [9] 0x180838AE0 false
    RTTR_ENABLE(I_Effect)                                 // [10..12]
    E_DataSource m_dataSource;                            // +0x08 RTTR "DataSource"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(offsetof(C_EffectBase, m_dataSource) == 0x08,
              "C_EffectBase::m_dataSource offset mismatch");
static_assert(sizeof(C_EffectBase) == 0x10,
              "C_EffectBase size mismatch");

}  // namespace wh::xgenaimodule::NPCState
