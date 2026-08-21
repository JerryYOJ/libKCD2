#pragma once
#include <cstdint>

namespace wh::combatmodule {

struct S_CombatActorObjectDebugLine {
    std::int32_t    kind;   // +0x00
    std::uint32_t   _pad04; // +0x04
    CryStringT<char> text;  // +0x08
};
static_assert(sizeof(S_CombatActorObjectDebugLine) == 0x10);

}  // namespace wh::combatmodule
