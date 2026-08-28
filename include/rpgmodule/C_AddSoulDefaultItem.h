#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include "I_Soul.h"
#include "../conceptmodule/C_ExternalPartialActivationEffect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../entitymodule/E_AddDefaultItemMode.h"
#include "../entitymodule/S_ItemClassGUID.h"

// -----------------------------------------------
// wh::rpgmodule::C_AddSoulDefaultItem -- reversible default-item effect
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x348, vtable 0x183A753C8
// (49 slots).
// -----------------------------------------------
// Direct base and zero adjustment are MSVC/RTTR reconciled. Nine reflected
// C_TypedPortRef members occupy exact 0x40 strides; +0x308 is the tracking hash
// used by deactivate and GetAppliedTargets. Mapped value type remains unresolved.

namespace wh::rpgmodule {

class C_AddSoulDefaultItem
    : public conceptmodule::C_ExternalPartialActivationEffect<I_Soul> {
public:
    struct E_Purpose {
        enum Type : std::uint8_t {
            Inventory           = 0,
            EquipPreset         = 1,
            EquipPresetPriority = 2,
        };
    };

    ~C_AddSoulDefaultItem() override;                         // [0] 0x180968AFC
    RTTR_ENABLE(conceptmodule::C_ExternalPartialActivationEffect<I_Soul>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                    // [27] 0x182BFE5EC
    void OnEffectDeactivate() override;                       // [44] 0x180518770
    void ApplyToTarget(I_Soul* soul,
                       CryStringT<char> const& key,
                       bool initialApplication) override;     // [46] 0x1808D5ABC
    void RemoveFromTarget(I_Soul* soul,
                          CryStringT<char> const& key) override; // [47] 0x182BFDD6C
    std::unordered_set<I_Soul*> GetAppliedTargets() const override; // [48] 0x1817F7BB8

    conceptmodule::C_TypedPortRef<entitymodule::S_ItemClassGUID> m_itemClass; // +0x0C8
    conceptmodule::C_TypedPortRef<E_Purpose::Type> m_purpose;                 // +0x108
    conceptmodule::C_TypedPortRef<entitymodule::E_AddDefaultItemMode::Type> m_mode; // +0x148
    conceptmodule::C_TypedPortRef<bool> m_disableRestock;                     // +0x188
    conceptmodule::C_TypedPortRef<bool> m_equipImmediately;                   // +0x1C8
    conceptmodule::C_TypedPortRef<std::uint32_t> m_amount;                    // +0x208
    conceptmodule::C_TypedPortRef<std::uint32_t> m_quality;                   // +0x248
    conceptmodule::C_TypedPortRef<float> m_health;                            // +0x288
    conceptmodule::C_TypedPortRef<float> m_condition;                         // +0x2C8
    std::unordered_map<I_Soul*, void*> m_appliedItems;                        // +0x308 mapped type [U]
};

static_assert(sizeof(C_AddSoulDefaultItem::E_Purpose::Type) == 1,
              "C_AddSoulDefaultItem::E_Purpose::Type size mismatch");
static_assert(sizeof(conceptmodule::C_ExternalPartialActivationEffect<I_Soul>) == 0xC8,
              "C_ExternalPartialActivationEffect<I_Soul> size mismatch");
static_assert(offsetof(C_AddSoulDefaultItem, m_itemClass) == 0x0C8,
              "C_AddSoulDefaultItem::m_itemClass offset mismatch");
static_assert(offsetof(C_AddSoulDefaultItem, m_purpose) == 0x108,
              "C_AddSoulDefaultItem::m_purpose offset mismatch");
static_assert(offsetof(C_AddSoulDefaultItem, m_appliedItems) == 0x308,
              "C_AddSoulDefaultItem::m_appliedItems offset mismatch");
static_assert(sizeof(C_AddSoulDefaultItem) == 0x348,
              "C_AddSoulDefaultItem size mismatch");

}  // namespace wh::rpgmodule
