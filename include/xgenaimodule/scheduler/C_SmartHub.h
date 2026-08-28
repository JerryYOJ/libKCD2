#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::xgenaimodule::scheduler {

class C_SmartHub {
public:
    std::uint8_t m_unknown00[0x30];                                          // +0x00 accessor-backed
};

static_assert(sizeof(C_SmartHub) == 0x30,
              "C_SmartHub size mismatch");

} // namespace wh::xgenaimodule::scheduler
