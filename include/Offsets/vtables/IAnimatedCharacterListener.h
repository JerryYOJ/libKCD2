#pragma once
#include <cstddef>

namespace Offsets {

// Current two-slot listener; callback spelling is behavior-derived.
class IAnimatedCharacterListener {
public:
    virtual ~IAnimatedCharacterListener() = default; // [0]
    virtual void OnCharacterPointersChanged() = 0;   // [1]
};
static_assert(sizeof(IAnimatedCharacterListener) == 0x08,
              "IAnimatedCharacterListener must be vptr-only");

}  // namespace Offsets
