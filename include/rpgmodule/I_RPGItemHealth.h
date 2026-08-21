#pragma once
#include <cstdint>

namespace wh::entitymodule {
class C_Item;
class S_ItemClass;
}

// -----------------------------------------------
// wh::rpgmodule::I_RPGItemHealth -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// Abstract 18-slot item-health service interface. C_RPGItemHealth's vtable is
// 0x183A84398; slots [7], [8], [13], and [14] form the quality-tier condition path.

namespace wh::rpgmodule {

class I_RPGItemHealth {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_RPGItemHealth;
    virtual ~I_RPGItemHealth() = default;                                                                    // [0]
    virtual void RPGItemHealthUnk01() = 0;                                                                   // [1] [U signature]
    virtual void RPGItemHealthUnk02() = 0;                                                                   // [2] [U signature]
    virtual void RPGItemHealthUnk03() = 0;                                                                   // [3] [U signature]
    virtual void RPGItemHealthUnk04() = 0;                                                                   // [4] [U signature]
    virtual void RPGItemHealthUnk05() = 0;                                                                   // [5] [U signature]
    virtual void RPGItemHealthUnk06() = 0;                                                                   // [6] [U signature]
    virtual float GetHealthLowerBound(const entitymodule::S_ItemClass* itemClass, std::uint32_t quality) const = 0; // [7] sub_1804678C4
    virtual float GetHealthUpperBound(const entitymodule::S_ItemClass* itemClass, std::uint32_t quality) const = 0; // [8] sub_180468C40
    virtual float ClampHealthToQuality(const entitymodule::S_ItemClass* itemClass, float health, std::uint32_t quality) const = 0; // [9] sub_1804698B0
    virtual void RPGItemHealthUnk10() = 0;                                                                   // [10] [U signature]
    virtual void RPGItemHealthUnk11() = 0;                                                                   // [11] [U signature]
    virtual void RPGItemHealthUnk12() = 0;                                                                   // [12] [U signature]
    virtual float HealthToCondition(const entitymodule::S_ItemClass* itemClass, float health, std::uint32_t quality) const = 0; // [13] sub_180466DB0
    virtual float GetItemCondition(const entitymodule::C_Item* item) const = 0;                              // [14] sub_180465CC0
    virtual void RPGItemHealthUnk15() = 0;                                                                   // [15] [U signature]
    virtual void RPGItemHealthUnk16() = 0;                                                                   // [16] [U signature]
    virtual void RPGItemHealthUnk17() = 0;                                                                   // [17] [U signature]
};

static_assert(sizeof(I_RPGItemHealth) == 0x08, "I_RPGItemHealth must be vptr-only");

}  // namespace wh::rpgmodule
