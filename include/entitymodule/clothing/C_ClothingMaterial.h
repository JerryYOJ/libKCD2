#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <optional>
#include <vector>

#include "../../CryEngine/CryCommon/Cry_Color.h"
#include "../../framework/TinyOptional.h"
#include "../../rttr/rttr_enable.h"

namespace wh::entitymodule::clothing {

class C_ClothingMaterial {
public:
    C_ClothingMaterial();
    virtual ~C_ClothingMaterial(); // [0] 0x1829173C4
    RTTR_ENABLE() // [1..3]

    CryStringT<char> m_name; // +0x08 RTTR "Name"
    tiny::optional<int, std::numeric_limits<int>::min()> m_textureId; // +0x10
    tiny::optional<float> m_hue;                       // +0x14
    tiny::optional<float> m_saturation;                // +0x18
    tiny::optional<float> m_brightness;                // +0x1C
    tiny::optional<int, std::numeric_limits<int>::min()> m_smoothness; // +0x20
    tiny::optional<float> m_tileU;                     // +0x24
    tiny::optional<float> m_tileV;                     // +0x28
    tiny::optional<float> m_offsetU;                   // +0x2C
    tiny::optional<float> m_offsetV;                   // +0x30
    tiny::optional<float> m_rotateUV;                  // +0x34
    tiny::optional<int, std::numeric_limits<int>::min()> m_alphaTest; // +0x38
    tiny::optional<float> m_grimeGloss;                // +0x3C
    tiny::optional<float> m_scratchHue;                // +0x40
    tiny::optional<float> m_scratchSaturation;         // +0x44
    tiny::optional<float> m_scratchBrightness;         // +0x48
    tiny::optional<int, std::numeric_limits<int>::min()> m_scratchTextureId; // +0x4C
    std::optional<ColorF> m_specular;                   // +0x50
    std::optional<ColorF> m_grimeDiffuse;               // +0x64
    std::optional<ColorF> m_grimeSpecular;              // +0x78
    std::uint32_t m_padding8C;
    std::vector<std::shared_ptr<C_ClothingMaterial>> m_derivedMaterials; // +0x90
};

static_assert(offsetof(C_ClothingMaterial, m_textureId) == 0x10,
              "C_ClothingMaterial::m_textureId offset mismatch");
static_assert(offsetof(C_ClothingMaterial, m_specular) == 0x50,
              "C_ClothingMaterial::m_specular offset mismatch");
static_assert(offsetof(C_ClothingMaterial, m_derivedMaterials) == 0x90,
              "C_ClothingMaterial::m_derivedMaterials offset mismatch");
static_assert(sizeof(C_ClothingMaterial) == 0xA8,
              "C_ClothingMaterial size mismatch");

} // namespace wh::entitymodule::clothing
