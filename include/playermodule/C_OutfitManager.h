#pragma once
#include <cstddef>
#include <cstdint>
#include "C_QAMManager.h"
#include "I_OutfitManager.h"
#include "../entitymodule/I_ItemCollectionListener.h"

// -----------------------------------------------
// wh::playermodule::C_OutfitManager -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x6F0.
// -----------------------------------------------
// RTTI .?AVC_OutfitManager@playermodule@wh@@, primary vtable 0x183F74570
// (44 slots), ctor sub_180C47E2C. I_ItemCollectionListener is the +0x08 base.
// Three 0x220-byte outfit records begin at +0x80; each embeds weapon and
// consumable C_QAMManager objects at record offsets +0x08 and +0x108.

namespace wh::playermodule {

class C_OutfitManager
    : public I_OutfitManager
    , public entitymodule::I_ItemCollectionListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_OutfitManager;
    ~C_OutfitManager() override;                                                   // [0] sub_180D89A54
    void OnItemEquipped(void* a2, std::uint64_t itemWuid) override;                // [1] [U signature]
    void OnItemUnequipped(void* a2, std::uint64_t itemWuid) override;              // [2] [U signature]
    void OnEquipmentReset() override;                                               // [3] [U signature]
    void OutfitManagerUnk04() override;                                             // [4] [U signature]
    void OutfitManagerUnk05() override;                                             // [5] [U signature]
    void OutfitManagerUnk06() override;                                             // [6] [U signature]
    void OutfitManagerUnk07() override;                                             // [7] [U signature]
    void OutfitManagerUnk08() override;                                             // [8] [U signature]
    void OutfitManagerUnk09() override;                                             // [9] [U signature]
    void OutfitManagerUnk10() override;                                             // [10] [U signature]
    E_OutfitId::Type GetCurrentOutfit() const override;                             // [11] sub_180C494A0
    void OutfitManagerUnk12() override;                                             // [12] [U signature]
    void OutfitManagerUnk13() override;                                             // [13] [U signature]
    void OutfitManagerUnk14() override;                                             // [14] [U signature]
    void OutfitManagerUnk15() override;                                             // [15] [U signature]
    void OutfitManagerUnk16() override;                                             // [16] [U signature]
    void OutfitManagerUnk17() override;                                             // [17] [U signature]
    void OutfitManagerUnk18() override;                                             // [18] [U signature]
    C_QAMManager* GetWeaponQAMManager(E_OutfitId::Type outfit) override;            // [19] sub_1808F88B0
    C_QAMManager* GetConsumableQAMManager(E_OutfitId::Type outfit) override;        // [20] sub_180C48FA0
    void OutfitManagerUnk21() override;                                             // [21] [U signature]
    void OutfitManagerUnk22() override;                                             // [22] [U signature]
    void OutfitManagerUnk23() override;                                             // [23] [U signature]
    void OutfitManagerUnk24() override;                                             // [24] [U signature]
    void OutfitManagerUnk25() override;                                             // [25] [U signature]
    void OutfitManagerUnk26() override;                                             // [26] [U signature]
    void OutfitManagerUnk27() override;                                             // [27] [U signature]
    void OutfitManagerUnk28() override;                                             // [28] [U signature]
    void OutfitManagerUnk29() override;                                             // [29] [U signature]
    void OutfitManagerUnk30() override;                                             // [30] [U signature]
    void OutfitManagerUnk31() override;                                             // [31] [U signature]
    void OutfitManagerUnk32() override;                                             // [32] [U signature]
    void OutfitManagerUnk33() override;                                             // [33] [U signature]
    void OutfitManagerUnk34() override;                                             // [34] [U signature]
    void OutfitManagerUnk35() override;                                             // [35] [U signature]
    void OutfitManagerUnk36() override;                                             // [36] [U signature]
    void OutfitManagerUnk37() override;                                             // [37] [U signature]
    void OutfitManagerUnk38() override;                                             // [38] [U signature]
    void OutfitManagerUnk39() override;                                             // [39] [U signature]
    void OutfitManagerUnk40() override;                                             // [40] [U signature]
    void OutfitManagerUnk41() override;                                             // [41] [U signature]
    void OutfitManagerUnk42() override;                                             // [42] [U signature]
    void OutfitManagerUnk43() override;                                             // [43] [U signature]

    void ItemCollectionListenerUnk1(entitymodule::C_Item* consumedItem) override; // secondary [1] 0x1808F77A8
    void ItemCollectionListenerUnk3(entitymodule::C_Item* item,
                                    std::int32_t amountDelta,
                                    std::uint32_t changeMask) override; // secondary [3] 0x181390518
    void ItemCollectionListenerUnk4(entitymodule::C_ItemCollection* collection) override; // secondary [4] 0x182EADDC8

    std::uint8_t m_unknown10[0x70]; // +0x10

    void* m_pOutfitAData;                    // +0x080  pointee type unresolved
    C_QAMManager m_outfitAWeaponQAM;         // +0x088
    C_QAMManager m_outfitAConsumableQAM;     // +0x188
    std::uint8_t m_outfitAUnknown288[0x18];  // +0x288

    void* m_pOutfitBData;                    // +0x2A0  pointee type unresolved
    C_QAMManager m_outfitBWeaponQAM;         // +0x2A8
    C_QAMManager m_outfitBConsumableQAM;     // +0x3A8
    std::uint8_t m_outfitBUnknown4A8[0x18];  // +0x4A8

    void* m_pOutfitCData;                    // +0x4C0  pointee type unresolved
    C_QAMManager m_outfitCWeaponQAM;         // +0x4C8
    C_QAMManager m_outfitCConsumableQAM;     // +0x5C8
    std::uint8_t m_outfitCUnknown6C8[0x18];  // +0x6C8

    std::uint8_t m_currentOutfit;  // +0x6E0  E_OutfitId::Type stored as one byte
    std::uint8_t m_unknown6E1;     // +0x6E1
    std::uint8_t _pad6E2[6];       // +0x6E2
    void* m_pOwner;                // +0x6E8  concrete pointee type unresolved
};

static_assert(sizeof(C_OutfitManager) == 0x6F0, "C_OutfitManager must be 0x6F0");
static_assert(offsetof(C_OutfitManager, m_outfitAWeaponQAM) == 0x88, "outfit A weapon QAM must be at +0x88");
static_assert(offsetof(C_OutfitManager, m_outfitAConsumableQAM) == 0x188, "outfit A consumable QAM must be at +0x188");
static_assert(offsetof(C_OutfitManager, m_outfitBWeaponQAM) == 0x2A8, "outfit B weapon QAM must be at +0x2A8");
static_assert(offsetof(C_OutfitManager, m_outfitCWeaponQAM) == 0x4C8, "outfit C weapon QAM must be at +0x4C8");
static_assert(offsetof(C_OutfitManager, m_currentOutfit) == 0x6E0, "current outfit must be at +0x6E0");
static_assert(offsetof(C_OutfitManager, m_pOwner) == 0x6E8, "owner must be at +0x6E8");

}  // namespace wh::playermodule
