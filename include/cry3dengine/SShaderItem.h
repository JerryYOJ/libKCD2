#pragma once
#include <cstddef>
#include <cstdint>

struct IRenderShaderResources;
struct IShader;

struct SShaderItem {
    IShader* m_shader;                                         // +0x00
    IRenderShaderResources* m_shaderResources;                  // +0x08
    std::int32_t m_technique;                                  // +0x10
    std::uint32_t m_preprocessFlags;                           // +0x14
};

static_assert(offsetof(SShaderItem, m_shaderResources) == 0x08,
              "SShaderItem resource offset mismatch");
static_assert(offsetof(SShaderItem, m_technique) == 0x10,
              "SShaderItem technique offset mismatch");
static_assert(sizeof(SShaderItem) == 0x18,
              "SShaderItem size mismatch");
