#pragma once
#include <cstdint>
#include <cstddef>
#include "I_DialogueExtension.h"

// -----------------------------------------------
// wh::dialogmodule::C_DialogueShieldPaintingExtension -- shield-painting minigame
// extension (KCD2 1.5.6, kd7u).  sizeof ~0xA8 UNVERIFIED.
// -----------------------------------------------
// RTTI TD 0x184B4FCC0; vtable 0x183E67C20 (11 slots); ctor sub_181E6B780; overrides
// [3] OnUpdate and [5] Reset. Interior observations CONFLICT: a "+0x18 worker object
// (112 bytes, built by sub_181E6EA10)" would span +0x18..+0x88, overlapping the
// "+0x68 intrusive-list node" observation -- the interior is therefore modeled as an
// opaque byte region pending a layout dump. Do NOT rely on interior offsets.

namespace wh::dialogmodule {

class C_DialogueShieldPaintingExtension : public I_DialogueExtension {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DialogueShieldPaintingExtension;
    bool    m_active;        // +0x08  [per-extension convention; UNVERIFIED]
    uint8_t _pad09[7];       // +0x09
    void*   m_pOwner;        // +0x10  owning C_DialogInstance [UNVERIFIED]
    uint8_t _unk18[0x90];    // +0x18..+0xA7  worker (112B @+0x18, sub_181E6EA10) +
                             //   intrusive-list node (@+0x68) -- observations conflict,
                             //   region opaque [UNVERIFIED]
};
static_assert(offsetof(C_DialogueShieldPaintingExtension, _unk18) == 0x18);
// sizeof == 0xA8 by construction; total size ~0xA8 UNVERIFIED (see header note).

}  // namespace wh::dialogmodule
