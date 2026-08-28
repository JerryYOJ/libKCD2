#pragma once

#include <cstddef>
#include <cstdint>

#include "../../framework/I_Queued.h"
#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_CartActionBase : public C_CodeAction, public wh::framework::I_Queued {
public:
    ~C_CartActionBase() override;
    void unk_0() override;                                                   // +0xC0 [0] 0x183321D68
    void unk_1() override;                                                   // +0xC0 [1] 0x180838AE0
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183B3F020

    std::uint8_t m_unknownC8[0x40];                                          // +0xC8
};

static_assert(sizeof(C_CartActionBase) == 0x108,
              "C_CartActionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
