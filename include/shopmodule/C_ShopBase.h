#pragma once
#include <cstddef>
#include <cstdint>
#include "../entitymodule/C_ItemCollection.h"
#include "I_Shop.h"

namespace wh::shopmodule {

class C_ShopBase : public I_Shop,
                   public wh::entitymodule::C_ItemCollection {
public:
    ~C_ShopBase() override;                                  // [0] 0x182EFE1A0
    void SetHagglingEnabled(bool enabled) override;          // [10] 0x181A7D970
    bool CanHaggle() const override;                         // [11] 0x1808C55E4
    const char* GetHagglingDisabledReason() const override;  // [12] 0x182EFE46C

    bool m_hagglingEnabled;                                  // +0x78
    std::uint8_t m_unknown79[7];                             // +0x79
};

static_assert(offsetof(C_ShopBase, m_hagglingEnabled) == 0x78,
              "C_ShopBase::m_hagglingEnabled offset mismatch");
static_assert(sizeof(C_ShopBase) == 0x80,
              "C_ShopBase size mismatch");

}  // namespace wh::shopmodule
