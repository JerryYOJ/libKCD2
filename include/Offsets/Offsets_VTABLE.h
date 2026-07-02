#pragma once
#include <array>
#include "REL/Offset.h"

// -----------------------------------------------
// VTABLE offsets for RE'd KCD2 classes (image RVAs from WHGame.dll base 0x180000000).
// -----------------------------------------------
// Pattern: VTABLE_ClassName is a std::array<REL::Offset, N>, one entry per MI vtable.
// KCD2 stores the raw RVA via REL::Offset (KCD1 used REL::ID against the address-library
// id table, which is not regenerated for KCD2 yet). Resolve at runtime with VTABLE[i].address().

namespace Offsets {

// CMovieSystem : IMovieSystem @ +0x00 (single vtable).
inline constexpr std::array<::REL::Offset, 1> VTABLE_CMovieSystem{ ::REL::Offset(0x407E648) };

}  // namespace Offsets
