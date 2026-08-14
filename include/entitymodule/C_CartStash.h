#pragma once
#include "C_Stash.h"

namespace wh::entitymodule {

class C_CartStash
    : public Offsets::CGameObjectExtensionHelper<
          C_CartStash,
          C_Stash,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CartStash;

    ~C_CartStash() override;                        // [0] 0x1809652F4
    const char* GetExtensionName() const override; // [29] 0x1819DF580
};
static_assert(sizeof(C_CartStash) == 0x128,
              "C_CartStash must be 0x128");

}  // namespace wh::entitymodule
