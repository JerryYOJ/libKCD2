#pragma once
#include "C_Stash.h"

namespace wh::entitymodule {

class C_StashCorpse
    : public Offsets::CGameObjectExtensionHelper<
          C_StashCorpse,
          C_Stash,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_StashCorpse;

    ~C_StashCorpse() override;                        // [0] 0x1809652F4
    const char* GetExtensionName() const override;   // [29] 0x1819C2CA0
};
static_assert(sizeof(C_StashCorpse) == 0x128,
              "C_StashCorpse must be 0x128");

}  // namespace wh::entitymodule
