#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "SEffectInfo.h"

namespace Offsets {
struct IEntity;
}

namespace EntityEffects {

class CEffectsController {
public:
    Offsets::IEntity* m_pOwner;       // +0x00, borrowed
    std::vector<SEffectInfo> m_effects; // +0x08
    TAttachedEffectId m_generatorId;  // +0x20
    std::uint32_t _pad24;             // +0x24
};
static_assert(sizeof(CEffectsController) == 0x28,
              "CEffectsController must be 0x28");
static_assert(offsetof(CEffectsController, m_effects) == 0x08,
              "attached effects must be at 0x08");
static_assert(offsetof(CEffectsController, m_generatorId) == 0x20,
              "effect id generator must be at 0x20");

}  // namespace EntityEffects
