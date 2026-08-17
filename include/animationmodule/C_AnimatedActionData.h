#pragma once
#include <cstddef>
#include <cstdint>
#include "S_AnimatedActionTagState.h"

// -----------------------------------------------
// wh::animationmodule::C_AnimatedActionData<TData, TDBData> -- KCD2 WHGame.dll 1.5.6.
// -----------------------------------------------
// Polymorphic 0x40 base proven by ctor sub_180931AD8 and copy ctors
// sub_180931C2C/sub_18093203C. Vtable 0x183A642B8 has two slots.

namespace wh::animationmodule {

template <typename TData, typename TDBData>
class C_AnimatedActionData {
public:
    virtual ~C_AnimatedActionData() = default;                     // [0]
    virtual std::int32_t Compare(const TData& other) const { return 0; } // [1] sub_18066CD10

    std::int32_t            m_actorClassId;          // +0x08  resolved from actor_class_hash
    std::int32_t            m_fragmentId;            // +0x0C  resolved Mannequin FragmentID
    S_AnimatedActionTagState m_globalTags;           // +0x10
    S_AnimatedActionTagState m_fragmentTags;         // +0x24
    std::int32_t            m_globalTagStateIndex;   // +0x38
    std::int32_t            m_fragmentTagStateIndex; // +0x3C
};

using C_AnimatedActionDataLayoutProbe = C_AnimatedActionData<int, int>;
static_assert(sizeof(C_AnimatedActionDataLayoutProbe) == 0x40,
              "C_AnimatedActionData must be 0x40");
static_assert(offsetof(C_AnimatedActionDataLayoutProbe, m_globalTags) == 0x10,
              "C_AnimatedActionData tag state offset");

}  // namespace wh::animationmodule
