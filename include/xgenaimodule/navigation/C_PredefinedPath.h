#pragma once

#include <cstddef>
#include <cstdint>

#include "../../rttr/rttr_enable.h"
#include "../C_LinkableObject.h"

namespace wh::xgenaimodule::navigation {

class C_PredefinedPath : public C_LinkableObject {
public:
    ~C_PredefinedPath() override;
    RTTR_ENABLE(C_LinkableObject)                                            // [16..18], vtable 0x183ABEB58

    std::uint8_t m_unknown60[0x20];                                          // +0x60
};

static_assert(sizeof(C_PredefinedPath) == 0x80,
              "C_PredefinedPath size mismatch");

} // namespace wh::xgenaimodule::navigation
