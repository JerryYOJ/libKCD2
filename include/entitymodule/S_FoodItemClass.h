#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "S_ConsumableItemClass.h"
#include "S_TypedItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_FoodItemClass -- food item classes, fresh AND dried rows (KCD2
// WHGame.dll 1.5.6).  sizeof 0x138.  E_ItemType::Food (5).
// -----------------------------------------------
// RTTI .?AUS_FoodItemClass@entitymodule@wh@@; primary vtable 0x183A4DD20 (mixin thunk
// vtable 0x183A4DF30 at +0xE0); wrapper S_ItemClassWrapper<S_FoodItemClass,
// S_ConsumableItemClass, 5>.  Loaded from Libs/Tables/item/item.xml <Food> rows; member
// names ARE the game's RTTR property strings, offsets baked by registrar sub_180FCB93C
// ("wh::entitymodule::Food"; DriedItemId wrapper offset 0x124). pack(4) is required so
// CookedItemId stays at +0x104 after AlcoholContent float +0x100 (CryGUID natural align 8
// would pad to +0x108).  Runtime dry path: C_PrepareFoodEffect vf[11] when mode byte == 2.

namespace wh::entitymodule {

#pragma pack(push, 4)
class S_FoodItemClass
    : public S_ConsumableItemClass               // +0x00 .. 0xE0
    , public S_TypedItemClass {                  // +0xE0 .. 0xF0
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_FoodItemClass;
    float   m_healthBenefit;                     // +0xF0  "HealthBenefit"
    float   m_refreshBenefit;                    // +0xF4  "RefreshBenefit"
    float   m_nutritionBenefit;                  // +0xF8  "NutritionBenefit"
    float   m_shortTermNutritionBenefitRatio;    // +0xFC  "ShortTermNutritionBenefitRatio"
    float   m_alcoholContent;                    // +0x100 "AlcoholContent"
    CryGUID m_cookedItemId;                      // +0x104 "CookedItemId"
    CryGUID m_smokedItemId;                      // +0x114 "SmokedItemId"
    CryGUID m_driedItemId;                       // +0x124 "DriedItemId" -- fresh→dried; no native reverse index
    float   m_decayTime;                         // +0x134 "DecayTime" hours; 0 = never decays
};
#pragma pack(pop)

static_assert(sizeof(S_FoodItemClass) == 0x138, "S_FoodItemClass must be 0x138");
static_assert(offsetof(S_FoodItemClass, m_healthBenefit) == 0xF0, "food fields start at 0xF0");
static_assert(offsetof(S_FoodItemClass, m_driedItemId) == 0x124, "DriedItemId at 0x124");
static_assert(offsetof(S_FoodItemClass, m_decayTime) == 0x134, "DecayTime at 0x134");

}  // namespace wh::entitymodule
