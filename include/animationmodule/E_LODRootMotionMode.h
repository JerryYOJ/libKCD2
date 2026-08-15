#pragma once
#include <cstdint>

namespace wh::animationmodule {

// Source-reconstructed type/enumerator names; the complete 0/1/2 dword domain is proved.
enum class E_LODRootMotionMode : std::uint32_t {
    Disabled = 0,       // setup unavailable
    Standard = 1,       // ordinary collider modes
    ColliderManaged = 2 // GroundedOnly, Pushable, or Spectator
};
static_assert(sizeof(E_LODRootMotionMode) == 0x04,
              "LOD root-motion mode must be four bytes");

}  // namespace wh::animationmodule
