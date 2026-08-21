#pragma once
#include <cstdint>
#include <cstddef>
#include "../framework/C_Signal.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseValueSignal<T> -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// [SYNTHETIC] 0x18 notifying field used eight times on S_HorseData (+0x30..+0xF0).
// ctor writes T at +0, empty C_Signal sentinel at +8, emit cursors 0xFFFF at +0x10/+0x12.
// Emit helper sub_180393524(this+8, newValue).

namespace wh::entitymodule {

template<typename T>
struct S_HorseValueSignal {
    T                         m_value;   // +0x00
    wh::shared::C_Signal<T>   m_signal;  // +0x08
};
static_assert(sizeof(S_HorseValueSignal<uint8_t>) == 0x18, "byte signal field is 0x18");
static_assert(sizeof(S_HorseValueSignal<bool>) == 0x18, "bool signal field is 0x18");
static_assert(sizeof(S_HorseValueSignal<int32_t>) == 0x18, "int signal field is 0x18");
static_assert(offsetof(S_HorseValueSignal<uint8_t>, m_signal) == 0x08, "signal at +8");

}  // namespace wh::entitymodule
