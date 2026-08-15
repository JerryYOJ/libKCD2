#pragma once
#include "../Offsets/Offsets_RTTI.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

namespace wh::entitymodule {

class I_AnimChar : public Offsets::IGameObjectExtension {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_AnimChar;

    virtual void _vf29() = 0; // [29] 0x1828C4F00, binding/register operation; source name OPEN
    virtual void _vf30() = 0; // [30] 0x1828C5004, binding reset/rebuild; source name OPEN
};
static_assert(sizeof(I_AnimChar) == 0x40,
              "I_AnimChar must remain the 0x40 extension interface");

}  // namespace wh::entitymodule
