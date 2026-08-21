#pragma once
#include <cstddef>
#include <cstdint>
#include "C_QAMSlot.h"
#include "I_QAMManager.h"

// -----------------------------------------------
// wh::playermodule::C_QAMManager -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x100.
// -----------------------------------------------
// RTTI .?AVC_QAMManager@playermodule@wh@@, vtable 0x183A89120 (39 slots),
// ctor sub_180C48190. Four C_QAMSlot records begin at +0x30.

namespace wh::playermodule {

class C_QAMManager : public I_QAMManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_QAMManager;
    ~C_QAMManager() override;                                                              // [0] sub_182EA7C2C
    void QAMManagerUnk01() override;                                                       // [1] [U signature]
    void QAMManagerUnk02() override;                                                       // [2] [U signature]
    entitymodule::C_Item* GetWeaponItem(E_QAM_WeaponSlot::Type slot) const override;       // [3] sub_1808F87BC
    entitymodule::C_Item* GetConsumableItem(E_QAM_FoodSlot::Type slot) const override;     // [4] sub_1808F8D40
    void QAMManagerUnk05() override;                                                       // [5] [U signature]
    void QAMManagerUnk06() override;                                                       // [6] [U signature]
    void QAMManagerUnk07() override;                                                       // [7] [U signature]
    void QAMManagerUnk08() override;                                                       // [8] [U signature]
    void QAMManagerUnk09() override;                                                       // [9] [U signature]
    void QAMManagerUnk10() override;                                                       // [10] [U signature]
    void QAMManagerUnk11() override;                                                       // [11] [U signature]
    void QAMManagerUnk12() override;                                                       // [12] [U signature]
    void QAMManagerUnk13() override;                                                       // [13] [U signature]
    void QAMManagerUnk14() override;                                                       // [14] [U signature]
    void QAMManagerUnk15() override;                                                       // [15] [U signature]
    void QAMManagerUnk16() override;                                                       // [16] [U signature]
    void QAMManagerUnk17() override;                                                       // [17] [U signature]
    void QAMManagerUnk18() override;                                                       // [18] [U signature]
    void QAMManagerUnk19() override;                                                       // [19] [U signature]
    void QAMManagerUnk20() override;                                                       // [20] [U signature]
    void QAMManagerUnk21() override;                                                       // [21] [U signature]
    void QAMManagerUnk22() override;                                                       // [22] [U signature]
    void QAMManagerUnk23() override;                                                       // [23] [U signature]
    bool ClearItem(entitymodule::C_Item* item, std::uint32_t slot) override;               // [24] sub_182EAF8AC
    void QAMManagerUnk25() override;                                                       // [25] [U signature]
    void QAMManagerUnk26() override;                                                       // [26] [U signature]
    void QAMManagerUnk27() override;                                                       // [27] [U signature]
    void QAMManagerUnk28() override;                                                       // [28] [U signature]
    void QAMManagerUnk29() override;                                                       // [29] [U signature]
    void QAMManagerUnk30() override;                                                       // [30] [U signature]
    void QAMManagerUnk31() override;                                                       // [31] [U signature]
    void QAMManagerUnk32() override;                                                       // [32] [U signature]
    void QAMManagerUnk33() override;                                                       // [33] [U signature]
    bool IsSlotUsable(std::uint32_t slot) const override;                                  // [34] sub_1808F8858
    bool IsConsumableSlotUsable(E_QAM_FoodSlot::Type slot) const override;                 // [35] sub_1808F89A0
    bool IsWeaponSlotUsable(E_QAM_WeaponSlot::Type slot) const override;                   // [36] sub_1808F884C
    void QAMManagerUnk37() override;                                                       // [37] [U signature]
    void QAMManagerUnk38() override;                                                       // [38] [U signature]

    void SetItem(entitymodule::C_Item* item, std::uint32_t slot);                          // sub_18203C030
    bool ClearWeaponItem(entitymodule::C_Item* item, E_QAM_WeaponSlot::Type slot);         // sub_18203CF70

    C_QAMSlot m_slots[4];             // +0x30
    std::uint32_t m_selectedSlot;     // +0xF0
    std::uint32_t m_usableSlotCount;  // +0xF4
    void* m_pOwner;                   // +0xF8  concrete pointee type unresolved
};

static_assert(sizeof(C_QAMManager) == 0x100, "C_QAMManager must be 0x100");
static_assert(offsetof(C_QAMManager, m_slots) == 0x30, "QAM slots must be at +0x30");
static_assert(offsetof(C_QAMManager, m_selectedSlot) == 0xF0, "selected slot must be at +0xF0");
static_assert(offsetof(C_QAMManager, m_usableSlotCount) == 0xF4, "usable slot count must be at +0xF4");

}  // namespace wh::playermodule
