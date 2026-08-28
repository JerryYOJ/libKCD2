#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"

namespace wh::rpgmodule {

class C_FactionBase;

class C_FactionRelationBase : public wh::conceptmodule::C_Effect {
public:
    C_FactionRelationBase();
    ~C_FactionRelationBase() override;                         // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    bool Load(XmlNodeRef node) override;                       // [11]
    void OnEffectActivate() override;                          // [43]
    void OnEffectDeactivate() override;                        // [44]

    wh::conceptmodule::C_TypedPortRef<float> m_relationValue;  // +0x88
    std::vector<C_FactionBase*> m_factions0;                   // +0xC8
    std::vector<C_FactionBase*> m_factions1;                   // +0xE0
    bool m_active0;                                             // +0xF8
    bool m_active1;                                             // +0xF9
    std::uint8_t m_paddingFA[6];                              // +0xFA
};

static_assert(sizeof(C_FactionRelationBase) == 0x100,
              "C_FactionRelationBase size mismatch");
static_assert(offsetof(C_FactionRelationBase, m_relationValue) == 0x88,
              "C_FactionRelationBase relation offset mismatch");
static_assert(offsetof(C_FactionRelationBase, m_factions0) == 0xC8,
              "C_FactionRelationBase first faction array offset mismatch");
static_assert(offsetof(C_FactionRelationBase, m_factions1) == 0xE0,
              "C_FactionRelationBase second faction array offset mismatch");

} // namespace wh::rpgmodule
