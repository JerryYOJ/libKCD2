#pragma once
#include "C_Stash.h"

namespace wh::entitymodule {

class C_Nest
    : public Offsets::CGameObjectExtensionHelper<
          C_Nest,
          C_Stash,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Nest;

    ~C_Nest() override;                        // [0] 0x1809652F4
    const char* GetExtensionName() const override; // [29] 0x18175D900
};
static_assert(sizeof(C_Nest) == 0x128,
              "C_Nest must be 0x128");

}  // namespace wh::entitymodule
