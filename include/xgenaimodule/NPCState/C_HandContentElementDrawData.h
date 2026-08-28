#pragma once

#include <cstddef>
#include <cstdint>

#include "C_HandContentElement.h"

namespace wh::xgenaimodule::NPCState {

class C_HandContentElementDrawData : public C_HandContentElement {
public:
    C_HandContentElementDrawData();                                      // 0x1813BD358
    ~C_HandContentElementDrawData() override;                            // [0]
    RTTR_ENABLE(C_HandContentElement)                                    // [30..32], vtable 0x18476F2F0

    std::uint8_t m_unknown40[0x20];                                      // +0x40
};

static_assert(sizeof(C_HandContentElementDrawData) == 0x60,
              "C_HandContentElementDrawData size mismatch");

} // namespace wh::xgenaimodule::NPCState
