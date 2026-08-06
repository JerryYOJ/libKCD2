#include "rttr/RttrRuntime.h"

namespace luautils {

RttrRuntime::RttrRuntime() noexcept
    : m_converter(m_registry)
{}

}  // namespace luautils
