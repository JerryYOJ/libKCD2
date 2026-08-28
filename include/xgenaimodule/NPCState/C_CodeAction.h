#pragma once

#include <cstddef>
#include <cstdint>

#include "../I_AIObjectNotifyListener.h"
#include "C_Action.h"

namespace wh::xgenaimodule::NPCState {

class C_CodeAction
    : public C_Action,
      public wh::xgenaimodule::I_AIObjectNotifyListener {
public:
    ~C_CodeAction() override;
    void unk_00(std::uint64_t arg) override;                             // +0x90 [0]
    RTTR_ENABLE(C_Action)                                                // [24..26], vtable 0x183A2E1A0

    std::uint8_t m_unknown98[0x28];                                      // +0x98
};

static_assert(sizeof(C_CodeAction) == 0xC0,
              "C_CodeAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
