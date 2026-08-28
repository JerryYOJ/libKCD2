#pragma once

#include <cstddef>
#include <optional>

#include "../../CryEngine/CryCommon/Cry_Color.h"
#include "C_Component.h"

namespace wh::entitymodule::clothing {

class C_Body : public C_Component {
public:
    ~C_Body() override;                                  // [0] 0x18291728C
    std::shared_ptr<C_Component> Clone() const override; // [1] 0x181E96000
    const CryStringT<char>& GetName() const override;    // [2] 0x181A71D30
    void unk_03(const C_Component* source) override;     // [3] 0x180FE2D60
    bool unk_04() const override;                        // [4] 0x18152A284
    const void* unk_09() const override;                 // [9] 0x1816B6B60
    void unk_10(void* collector) const override;         // [10] 0x1815B2CFC
    RTTR_ENABLE(C_Component)                              // [12..14], vtable 0x183B60890

    std::optional<float> m_scratchLevel;                 // +0x120 RTTR "ScratchLevel"
    std::optional<float> m_melanin;                      // +0x128 RTTR "Melanin"
    std::optional<ColorF> m_diffuse;                     // +0x130 RTTR "Diffuse"
    std::uint32_t m_padding144;                          // +0x144
};

static_assert(offsetof(C_Body, m_scratchLevel) == 0x120,
              "C_Body::m_scratchLevel offset mismatch");
static_assert(offsetof(C_Body, m_melanin) == 0x128,
              "C_Body::m_melanin offset mismatch");
static_assert(offsetof(C_Body, m_diffuse) == 0x130,
              "C_Body::m_diffuse offset mismatch");
static_assert(sizeof(C_Body) == 0x148,
              "C_Body size mismatch");

}  // namespace wh::entitymodule::clothing
