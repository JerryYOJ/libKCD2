#pragma once

#include <cstddef>
#include <optional>

#include "../../CryEngine/CryCommon/Cry_Color.h"
#include "C_Component.h"

namespace wh::entitymodule::clothing {

class C_Hair : public C_Component {
public:
    ~C_Hair() override;                                  // [0] 0x18291742C
    std::shared_ptr<C_Component> Clone() const override; // [1] 0x181E96110
    const CryStringT<char>& GetName() const override;    // [2] 0x181A71D30
    void unk_03(const C_Component* source) override;     // [3] 0x180FE2AB8
    bool unk_04() const override;                        // [4] 0x18152A284
    const void* unk_09() const override;                 // [9] 0x1817C7330
    RTTR_ENABLE(C_Component)                              // [12..14], vtable 0x183B63398

    std::optional<ColorF> m_diffuse;                     // +0x120 RTTR "Diffuse"
    std::uint32_t m_padding134;                          // +0x134
};

static_assert(offsetof(C_Hair, m_diffuse) == 0x120,
              "C_Hair::m_diffuse offset mismatch");
static_assert(sizeof(C_Hair) == 0x138,
              "C_Hair size mismatch");

}  // namespace wh::entitymodule::clothing
