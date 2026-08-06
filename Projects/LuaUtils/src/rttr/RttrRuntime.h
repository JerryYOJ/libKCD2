#pragma once

#include "rttr/RttrHandleRegistry.h"
#include "rttr/RttrLuaConverter.h"

namespace luautils {

class RttrRuntime
{
public:
    RttrRuntime() noexcept;
    RttrRuntime(const RttrRuntime&) = delete;
    RttrRuntime& operator=(const RttrRuntime&) = delete;

    RttrHandleRegistry& Registry() noexcept { return m_registry; }
    const RttrHandleRegistry& Registry() const noexcept { return m_registry; }
    RttrLuaConverter& Converter() noexcept { return m_converter; }
    const RttrLuaConverter& Converter() const noexcept { return m_converter; }

    void ClearHandles() noexcept { m_registry.Clear(); }

private:
    RttrHandleRegistry m_registry;
    RttrLuaConverter m_converter;
};

inline RttrRuntime g_rttrRuntime;

}  // namespace luautils
