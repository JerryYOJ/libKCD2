#pragma once
#include <cstdint>
#include "I_RPGItemHealth.h"

namespace wh::entitymodule {
class S_EquippableItemClass;
}

// -----------------------------------------------
// wh::rpgmodule::C_RPGItemHealth -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x08.
// -----------------------------------------------
// RTTI .?AVC_RPGItemHealth@rpgmodule@wh@@, vtable 0x183A84398 (18 slots).
// The singleton object is returned by sub_1808D6070.

namespace wh::rpgmodule {

class C_RPGItemHealth : public I_RPGItemHealth {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RPGItemHealth;
    ~C_RPGItemHealth() override;                                                                                  // [0] sub_180466F30
    void RPGItemHealthUnk01() override;                                                                           // [1] [U signature]
    void RPGItemHealthUnk02() override;                                                                           // [2] [U signature]
    void RPGItemHealthUnk03() override;                                                                           // [3] [U signature]
    void RPGItemHealthUnk04() override;                                                                           // [4] [U signature]
    void RPGItemHealthUnk05() override;                                                                           // [5] [U signature]
    void RPGItemHealthUnk06() override;                                                                           // [6] [U signature]
    float GetHealthLowerBound(const entitymodule::S_ItemClass* itemClass, std::uint32_t quality) const override;  // [7] sub_1804678C4
    float GetHealthUpperBound(const entitymodule::S_ItemClass* itemClass, std::uint32_t quality) const override;  // [8] sub_180468C40
    float ClampHealthToQuality(const entitymodule::S_ItemClass* itemClass, float health, std::uint32_t quality) const override; // [9] sub_1804698B0
    void RPGItemHealthUnk10() override;                                                                           // [10] [U signature]
    void RPGItemHealthUnk11() override;                                                                           // [11] [U signature]
    void RPGItemHealthUnk12() override;                                                                           // [12] [U signature]
    float HealthToCondition(const entitymodule::S_ItemClass* itemClass, float health, std::uint32_t quality) const override; // [13] sub_180466DB0
    float GetItemCondition(const entitymodule::C_Item* item) const override;                                      // [14] sub_180465CC0
    void RPGItemHealthUnk15() override;                                                                           // [15] [U signature]
    void RPGItemHealthUnk16() override;                                                                           // [16] [U signature]
    void RPGItemHealthUnk17() override;                                                                           // [17] [U signature]

    static C_RPGItemHealth* GetInstance();                                                                         // sub_1808D6070
    float ConditionToHealth(const entitymodule::S_EquippableItemClass* itemClass,
                            float condition, std::uint32_t quality) const;                                         // sub_18096EE58
};

static_assert(sizeof(C_RPGItemHealth) == 0x08, "C_RPGItemHealth must be vptr-only");

}  // namespace wh::rpgmodule
