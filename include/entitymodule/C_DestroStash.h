#pragma once
#include "C_Stash.h"

namespace wh::entitymodule {

class C_DestroStash
    : public Offsets::CGameObjectExtensionHelper<
          C_DestroStash,
          C_Stash,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DestroStash;

    ~C_DestroStash() override;                        // [0] 0x1809652F4
    const char* GetExtensionName() const override;   // [29] 0x181A6ED70
};
static_assert(sizeof(C_DestroStash) == 0x128,
              "C_DestroStash must be 0x128");

}  // namespace wh::entitymodule
