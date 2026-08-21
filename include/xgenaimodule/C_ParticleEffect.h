#pragma once

#include "C_LinkableObject.h"

namespace wh::xgenaimodule {

class C_ParticleEffect : public C_LinkableObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ParticleEffect;
    ~C_ParticleEffect() override; // [0] sub_1832A8848
    void _vf16() override;        // [16] sub_18320A8D4
    void _vf18() override;        // [18] sub_18320A894
};
static_assert(sizeof(C_ParticleEffect) == 0x60, "C_ParticleEffect must be 0x60");

}  // namespace wh::xgenaimodule
