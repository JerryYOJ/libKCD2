#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>

#include "../../framework/TinyOptional.h"
#include "../../rttr/rttr_enable.h"
#include "C_ClothingMaterial.h"

namespace wh::entitymodule::clothing {

class C_ClothingFeature {
public:
    C_ClothingFeature();
    ~C_ClothingFeature();
    RTTR_ENABLE() // [0..2], no virtual destructor

    const CryStringT<char>& GetMaterial() const; // 0x1829179E4
    void SetMaterial(const CryStringT<char>& material); // 0x18068E614

    CryStringT<char> m_name;                            // +0x08 RTTR "Name"
    std::shared_ptr<C_ClothingMaterial> m_material;     // +0x10 accessor-backed
    tiny::optional<float> m_tileU;                     // +0x20 RTTR "TileU"
    tiny::optional<float> m_tileV;                     // +0x24 RTTR "TileV"
    tiny::optional<float> m_offsetU;                   // +0x28 RTTR "OffsetU"
    tiny::optional<float> m_offsetV;                   // +0x2C RTTR "OffsetV"
    tiny::optional<float> m_rotateUV;                  // +0x30 RTTR "RotateUV"
    std::uint64_t m_runtimeToken;                      // +0x38, exact type unresolved
    std::uint32_t m_materialFeatureValue40;            // +0x40
    std::uint32_t m_materialFeatureValue44;            // +0x44
};

static_assert(offsetof(C_ClothingFeature, m_material) == 0x10,
              "C_ClothingFeature::m_material offset mismatch");
static_assert(offsetof(C_ClothingFeature, m_tileU) == 0x20,
              "C_ClothingFeature::m_tileU offset mismatch");
static_assert(offsetof(C_ClothingFeature, m_runtimeToken) == 0x38,
              "C_ClothingFeature::m_runtimeToken offset mismatch");
static_assert(sizeof(C_ClothingFeature) == 0x48,
              "C_ClothingFeature size mismatch");

} // namespace wh::entitymodule::clothing
