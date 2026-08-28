#pragma once

#include <cstddef>
#include <cstdint>

#include "C_HandContentElement.h"

namespace wh::xgenaimodule::NPCState {

class C_HandContentElementRequired : public C_HandContentElement {
public:
    C_HandContentElementRequired();                                      // 0x180FD7024
    ~C_HandContentElementRequired() override;                            // [0]
    RTTR_ENABLE(C_HandContentElement)                                    // [30..32], vtable 0x183A5E5C8

    std::uint8_t m_unknown40[0x18];                                      // +0x40
};

static_assert(sizeof(C_HandContentElementRequired) == 0x58,
              "C_HandContentElementRequired size mismatch");

} // namespace wh::xgenaimodule::NPCState
