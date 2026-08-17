#pragma once
#include <cstdint>
#include "../animationmodule/C_AnimatedActionData.h"

// -----------------------------------------------
// wh::combatmodule::C_CombatActionData<TData, TDBData> -- KCD2 WHGame.dll 1.5.6.
// -----------------------------------------------
// Zero-storage combat specialization. Ctor sub_180931A98 only constructs the animated
// base and replaces its vtable; comparison thunk sub_182794E94 calls sub_18278DF70.

namespace wh::combatmodule {

template <typename TData, typename TDBData>
class C_CombatActionData : public wh::animationmodule::C_AnimatedActionData<TData, TDBData> {
public:
    std::int32_t Compare(const TData& other) const override; // [1]
};

static_assert(sizeof(C_CombatActionData<int, int>) == 0x40);

}  // namespace wh::combatmodule
