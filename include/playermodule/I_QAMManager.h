#pragma once
#include <cstddef>
#include <cstdint>
#include "E_QAM_FoodSlot.h"
#include "E_QAM_WeaponSlot.h"

namespace wh::entitymodule {
class C_Item;
}

// -----------------------------------------------
// wh::playermodule::I_QAMManager -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x30.
// -----------------------------------------------
// RTTI .?AVI_QAMManager@playermodule@wh@@, vtable 0x183A94B20 (39 slots).
// Slots [1..38] are pure in the interface. The base-state roles at +0x08..+0x2F
// remain unresolved; C_QAMManager ctor sub_180C48190 initializes the full region.

namespace wh::playermodule {

class I_QAMManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_QAMManager;
    virtual ~I_QAMManager() = default;                                                    // [0]
    virtual void QAMManagerUnk01() = 0;                                                   // [1] [U signature]
    virtual void QAMManagerUnk02() = 0;                                                   // [2] [U signature]
    virtual entitymodule::C_Item* GetWeaponItem(E_QAM_WeaponSlot::Type slot) const = 0;   // [3] sub_1808F87BC
    virtual entitymodule::C_Item* GetConsumableItem(E_QAM_FoodSlot::Type slot) const = 0; // [4] sub_1808F8D40
    virtual void QAMManagerUnk05() = 0;                                                   // [5] [U signature]
    virtual void QAMManagerUnk06() = 0;                                                   // [6] [U signature]
    virtual void QAMManagerUnk07() = 0;                                                   // [7] [U signature]
    virtual void QAMManagerUnk08() = 0;                                                   // [8] [U signature]
    virtual void QAMManagerUnk09() = 0;                                                   // [9] [U signature]
    virtual void QAMManagerUnk10() = 0;                                                   // [10] [U signature]
    virtual void QAMManagerUnk11() = 0;                                                   // [11] [U signature]
    virtual void QAMManagerUnk12() = 0;                                                   // [12] [U signature]
    virtual void QAMManagerUnk13() = 0;                                                   // [13] [U signature]
    virtual void QAMManagerUnk14() = 0;                                                   // [14] [U signature]
    virtual void QAMManagerUnk15() = 0;                                                   // [15] [U signature]
    virtual void QAMManagerUnk16() = 0;                                                   // [16] [U signature]
    virtual void QAMManagerUnk17() = 0;                                                   // [17] [U signature]
    virtual void QAMManagerUnk18() = 0;                                                   // [18] [U signature]
    virtual void QAMManagerUnk19() = 0;                                                   // [19] [U signature]
    virtual void QAMManagerUnk20() = 0;                                                   // [20] [U signature]
    virtual void QAMManagerUnk21() = 0;                                                   // [21] [U signature]
    virtual void QAMManagerUnk22() = 0;                                                   // [22] [U signature]
    virtual void QAMManagerUnk23() = 0;                                                   // [23] [U signature]
    virtual bool ClearItem(entitymodule::C_Item* item, std::uint32_t slot) = 0;            // [24] sub_182EAF8AC
    virtual void QAMManagerUnk25() = 0;                                                   // [25] [U signature]
    virtual void QAMManagerUnk26() = 0;                                                   // [26] [U signature]
    virtual void QAMManagerUnk27() = 0;                                                   // [27] [U signature]
    virtual void QAMManagerUnk28() = 0;                                                   // [28] [U signature]
    virtual void QAMManagerUnk29() = 0;                                                   // [29] [U signature]
    virtual void QAMManagerUnk30() = 0;                                                   // [30] [U signature]
    virtual void QAMManagerUnk31() = 0;                                                   // [31] [U signature]
    virtual void QAMManagerUnk32() = 0;                                                   // [32] [U signature]
    virtual void QAMManagerUnk33() = 0;                                                   // [33] [U signature]
    virtual bool IsSlotUsable(std::uint32_t slot) const = 0;                              // [34] sub_1808F8858
    virtual bool IsConsumableSlotUsable(E_QAM_FoodSlot::Type slot) const = 0;             // [35] sub_1808F89A0
    virtual bool IsWeaponSlotUsable(E_QAM_WeaponSlot::Type slot) const = 0;               // [36] sub_1808F884C
    virtual void QAMManagerUnk37() = 0;                                                   // [37] [U signature]
    virtual void QAMManagerUnk38() = 0;                                                   // [38] [U signature]

    std::uint8_t m_unknown08[0x28]; // +0x08
};

static_assert(sizeof(I_QAMManager) == 0x30, "I_QAMManager must be 0x30");

}  // namespace wh::playermodule
