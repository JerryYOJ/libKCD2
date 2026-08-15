#pragma once
#include "C_LedgeObject.h"

namespace wh::entitymodule {

class C_LedgeObjectStatic : public C_LedgeObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LedgeObjectStatic;

    ~C_LedgeObjectStatic() override;      // [0] 0x182A87AF8
    bool IsStaticLedge() const override;  // [29] true stub
};
static_assert(sizeof(C_LedgeObjectStatic) == 0x48,
              "C_LedgeObjectStatic must be 0x48");

}  // namespace wh::entitymodule
