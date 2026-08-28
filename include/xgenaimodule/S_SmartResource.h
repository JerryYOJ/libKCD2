#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::xgenaimodule {

struct S_SmartResource {
    std::uint8_t m_unknown00[4];                          // +0x00
    std::int32_t m_maxInstances;                          // +0x04 RTTR "MaxInstances"
};

static_assert(offsetof(S_SmartResource, m_maxInstances) == 0x04,
              "S_SmartResource::m_maxInstances offset mismatch");
static_assert(sizeof(S_SmartResource) == 0x08,
              "S_SmartResource size mismatch");

}  // namespace wh::xgenaimodule
