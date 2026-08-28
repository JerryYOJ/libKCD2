#pragma once
#include <cstddef>
#include <memory>
#include <unordered_set>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_ExternalPartialActivationEffect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../entitymodule/C_Stash.h"
#include "../entitymodule/I_ItemDescriptor.h"
#include "../entitymodule/S_ClothingPresetGUID.h"
#include "../entitymodule/S_WeaponPresetGUID.h"
#include "../framework/C_LocalizedString.h"
#include "../rpgmodule/E_PresetOverrideMode.h"
#include "../rpgmodule/I_Soul.h"

namespace wh::playermodule {

class C_PlayerOutfitOverride
    : public wh::conceptmodule::C_ExternalPartialActivationEffect<
          wh::rpgmodule::I_Soul> {
public:
    C_PlayerOutfitOverride();
    ~C_PlayerOutfitOverride() override;                         // [0] 0x180518A3C
    RTTR_ENABLE(wh::conceptmodule::C_ExternalPartialActivationEffect<
        wh::rpgmodule::I_Soul>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0694
    void OnEffectDeactivate() override;                         // [44] 0x180518DB8
    void ApplyToTarget(
        wh::rpgmodule::I_Soul* soul,
        CryStringT<char> const& key,
        bool initialApplication) override;                      // [46] 0x181057738
    void RemoveFromTarget(
        wh::rpgmodule::I_Soul* soul,
        CryStringT<char> const& key) override;                  // [47] 0x182DDEA74
    std::unordered_set<wh::rpgmodule::I_Soul*>
        GetAppliedTargets() const override;                     // [48] 0x1810573D4

    wh::conceptmodule::C_TypedPortRef<
        std::shared_ptr<wh::entitymodule::I_ItemDescriptor>> m_itemsToConfiscate; // +0xC8
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::C_Stash*> m_confiscationTarget;      // +0x108
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::S_ClothingPresetGUID> m_clothingPreset; // +0x148
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::S_WeaponPresetGUID> m_weaponPreset;  // +0x188
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::E_PresetOverrideMode::Type> m_deactivationMode; // +0x1C8
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::C_LocalizedString> m_deactivationMessage; // +0x208
    std::unordered_set<wh::rpgmodule::I_Soul*> m_appliedSouls; // +0x248
};

static_assert(sizeof(C_PlayerOutfitOverride) == 0x288,
              "C_PlayerOutfitOverride size mismatch");
static_assert(offsetof(C_PlayerOutfitOverride, m_itemsToConfiscate) == 0xC8,
              "C_PlayerOutfitOverride item descriptor offset mismatch");
static_assert(offsetof(C_PlayerOutfitOverride, m_deactivationMessage) == 0x208,
              "C_PlayerOutfitOverride message offset mismatch");
static_assert(offsetof(C_PlayerOutfitOverride, m_appliedSouls) == 0x248,
              "C_PlayerOutfitOverride applied souls offset mismatch");

} // namespace wh::playermodule
