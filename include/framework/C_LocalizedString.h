#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::framework::C_LocalizedString -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x10.
// -----------------------------------------------
// Polymorphic localized-string holder: {vfptr @+0x00, CryStringT<char> @+0x08}.
// Default ctor sub_1803D28B4 (writes &wh::framework::C_LocalizedString::vftable),
// copy ctor sub_1803D32D0. Embedded BY VALUE throughout the guimodule menu element
// data classes (C_UIMenuButton/Choice/Confirmation/Page) as an rttr property type.
// [G4d] Vtable slot roles NOT enumerated -- the [0] virtual dtor below is the standard
// polymorphic assumption, UNVERIFIED; do not call through it until certified. Flagged
// for the framework wave to deep-RE (localization-key resolution etc.).

namespace wh::framework {

class C_LocalizedString {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LocalizedString;
    virtual ~C_LocalizedString();   // [0] slot roles UNVERIFIED (see header note)

    CryStringT<char> m_text;        // +0x08  localized text / key [semantics UNVERIFIED]
};
static_assert(sizeof(C_LocalizedString) == 0x10, "C_LocalizedString must be 0x10 (ctor sub_1803D28B4)");

}  // namespace wh::framework
