#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CompositeSelector.h"
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::rpgmodule::storm::C_CustomSelector : C_CompositeSelector
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x30, vtable 0x183B30D50
// (5 slots).
// -----------------------------------------------
// Direct inheritance and zero adjustment are MSVC/RTTR reconciled. Name and
// Mode are exact RTTR members. Mode::And requires every child selector to pass;
// Mode::Or requires at least one child selector to pass.

namespace wh::rpgmodule::storm {

class C_CustomSelector : public C_CompositeSelector {
public:
    enum class Mode : std::int32_t {
        And = 0, // RTTR "and"
        Or  = 1, // RTTR "or"
    };

    ~C_CustomSelector() override;                 // [0] 0x182D84F14
    bool unk_01(C_Soul* soul) override;           // [1] 0x1806990F4
    RTTR_ENABLE(C_CompositeSelector)               // [2..4] 0x181A6D30C/0x1805F5DA0/0x1814CADC0

    CryStringT<char> m_name;                      // +0x20 RTTR "name"
    Mode m_mode;                                  // +0x28 RTTR "mode"
    std::uint8_t _pad2C[4];                       // +0x2C
};

static_assert(sizeof(C_CustomSelector::Mode) == 4,
              "C_CustomSelector::Mode size mismatch");
static_assert(sizeof(C_CompositeSelector) == 0x20,
              "C_CompositeSelector size mismatch");
static_assert(offsetof(C_CustomSelector, m_name) == 0x20,
              "C_CustomSelector::m_name offset mismatch");
static_assert(offsetof(C_CustomSelector, m_mode) == 0x28,
              "C_CustomSelector::m_mode offset mismatch");
static_assert(sizeof(C_CustomSelector) == 0x30,
              "C_CustomSelector size mismatch");

}  // namespace wh::rpgmodule::storm
