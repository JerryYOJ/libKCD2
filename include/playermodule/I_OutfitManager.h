#pragma once
#include <cstdint>
#include "E_OutfitId.h"
#include "../entitymodule/I_EquipmentManagerListener.h"

namespace wh::playermodule {
class C_QAMManager;
}

// -----------------------------------------------
// wh::playermodule::I_OutfitManager -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// RTTI hierarchy proves I_EquipmentManagerListener at +0x00. C_OutfitManager's
// primary vtable contains 44 validated slots; the used outfit/QAM accessors are
// slot-certified below and the remaining signatures stay explicit unknowns.

namespace wh::playermodule {

class I_OutfitManager : public entitymodule::I_EquipmentManagerListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_OutfitManager;
    virtual void OutfitManagerUnk04() = 0;                                      // [4] [U signature]
    virtual void OutfitManagerUnk05() = 0;                                      // [5] [U signature]
    virtual void OutfitManagerUnk06() = 0;                                      // [6] [U signature]
    virtual void OutfitManagerUnk07() = 0;                                      // [7] [U signature]
    virtual void OutfitManagerUnk08() = 0;                                      // [8] [U signature]
    virtual void OutfitManagerUnk09() = 0;                                      // [9] [U signature]
    virtual void OutfitManagerUnk10() = 0;                                      // [10] [U signature]
    virtual E_OutfitId::Type GetCurrentOutfit() const = 0;                      // [11] sub_180C494A0
    virtual void OutfitManagerUnk12() = 0;                                      // [12] [U signature]
    virtual void OutfitManagerUnk13() = 0;                                      // [13] [U signature]
    virtual void OutfitManagerUnk14() = 0;                                      // [14] [U signature]
    virtual void OutfitManagerUnk15() = 0;                                      // [15] [U signature]
    virtual void OutfitManagerUnk16() = 0;                                      // [16] [U signature]
    virtual void OutfitManagerUnk17() = 0;                                      // [17] [U signature]
    virtual void OutfitManagerUnk18() = 0;                                      // [18] [U signature]
    virtual C_QAMManager* GetWeaponQAMManager(E_OutfitId::Type outfit) = 0;      // [19] sub_1808F88B0
    virtual C_QAMManager* GetConsumableQAMManager(E_OutfitId::Type outfit) = 0;  // [20] sub_180C48FA0
    virtual void OutfitManagerUnk21() = 0;                                      // [21] [U signature]
    virtual void OutfitManagerUnk22() = 0;                                      // [22] [U signature]
    virtual void OutfitManagerUnk23() = 0;                                      // [23] [U signature]
    virtual void OutfitManagerUnk24() = 0;                                      // [24] [U signature]
    virtual void OutfitManagerUnk25() = 0;                                      // [25] [U signature]
    virtual void OutfitManagerUnk26() = 0;                                      // [26] [U signature]
    virtual void OutfitManagerUnk27() = 0;                                      // [27] [U signature]
    virtual void OutfitManagerUnk28() = 0;                                      // [28] [U signature]
    virtual void OutfitManagerUnk29() = 0;                                      // [29] [U signature]
    virtual void OutfitManagerUnk30() = 0;                                      // [30] [U signature]
    virtual void OutfitManagerUnk31() = 0;                                      // [31] [U signature]
    virtual void OutfitManagerUnk32() = 0;                                      // [32] [U signature]
    virtual void OutfitManagerUnk33() = 0;                                      // [33] [U signature]
    virtual void OutfitManagerUnk34() = 0;                                      // [34] [U signature]
    virtual void OutfitManagerUnk35() = 0;                                      // [35] [U signature]
    virtual void OutfitManagerUnk36() = 0;                                      // [36] [U signature]
    virtual void OutfitManagerUnk37() = 0;                                      // [37] [U signature]
    virtual void OutfitManagerUnk38() = 0;                                      // [38] [U signature]
    virtual void OutfitManagerUnk39() = 0;                                      // [39] [U signature]
    virtual void OutfitManagerUnk40() = 0;                                      // [40] [U signature]
    virtual void OutfitManagerUnk41() = 0;                                      // [41] [U signature]
    virtual void OutfitManagerUnk42() = 0;                                      // [42] [U signature]
    virtual void OutfitManagerUnk43() = 0;                                      // [43] [U signature]
};

static_assert(sizeof(I_OutfitManager) == 0x08, "I_OutfitManager must be vptr-only");

}  // namespace wh::playermodule
