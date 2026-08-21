#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "E_HandContextSerializationMode.h"
#include "S_ItemClass.h"
#include "S_ItemClassPhase.h"

// -----------------------------------------------
// wh::entitymodule::S_PickableItemClass -- world-pickable item classes (KCD2 1.5.6).
// sizeof 0x90.  E_ItemType::Pickable (22).
// -----------------------------------------------
// Vtable 0x183A4EE38, ctor sub_180754C3C, copy-ctor sub_180D28FD4, Clone alloc 0x90
// (sub_182A1E8A4). RTTR registrar sub_180FCD148 ("wh::entitymodule::PickableItem").
// Dual-verifier 2026-08-21. VisibilityCoef is a 4-byte clamped float; RTTR type is
// C_NumberWrapper<Clamp<0,1,float>> (same storage as float).

namespace wh::entitymodule {

class S_PickableItemClass : public S_ItemClass {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_PickableItemClass;

    CryStringT<char> m_model;                    // +0x38  RTTR "Model"
    CryStringT<char> m_material;                 // +0x40  RTTR "Material"
    CryStringT<char> m_entityScript;             // +0x48  RTTR "EntityScript"
    CryStringT<char> m_attachmentName;           // +0x50  RTTR "AttachmentName"
    float            m_weight;                   // +0x58  RTTR "Weight"  ctor 0.1f
    std::uint32_t    m_price;                    // +0x5C  RTTR "Price"
    float            m_fadeCoef;                 // +0x60  RTTR "FadeCoef"  ctor 1.0f
    float            m_visibilityCoef;           // +0x64  RTTR "VisibilityCoef"  ctor 1.0 clamped [0,1]
    std::uint32_t    m_lightSourcePriority;      // +0x68  RTTR "LightSourcePriority"
    E_HandContextSerializationMode::Type m_handContentSerializationMode; // +0x6C  1-byte enum
    std::uint8_t     _pad6D[3];                  // +0x6D
    std::vector<S_ItemClassPhase> m_phases;      // +0x70  RTTR "Phases"  elem 0x28
    bool             m_homeSlotAutoReturn;       // +0x88  RTTR "HomeSlotAutoReturn"
    bool             m_projectileCollisionWhenCarried; // +0x89  RTTR "ProjectileCollisionWhenCarried"
    bool             m_phaseResetOnDrop;         // +0x8A  RTTR "PhaseResetOnDrop"
    bool             m_phaseResetOnSlotReturn;   // +0x8B  RTTR "PhaseResetOnSlotReturn"
    bool             m_phaseResetOnSlotAbandon;  // +0x8C  RTTR "PhaseResetOnSlotAbandon"
    std::uint8_t     _pad8D[3];                  // +0x8D
};
static_assert(sizeof(S_PickableItemClass) == 0x90, "S_PickableItemClass must be 0x90");
static_assert(offsetof(S_PickableItemClass, m_weight) == 0x58);
static_assert(offsetof(S_PickableItemClass, m_phases) == 0x70);
static_assert(offsetof(S_PickableItemClass, m_homeSlotAutoReturn) == 0x88);

}  // namespace wh::entitymodule
