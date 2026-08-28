#pragma once
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"

namespace wh::playermodule {

class C_FilterInput : public wh::conceptmodule::C_Effect {
public:
    C_FilterInput();
    ~C_FilterInput() override;                                  // [0] 0x18155B22C
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0424
    void OnEffectActivate() override;                           // [43] 0x182DE114C
    void OnEffectDeactivate() override;                         // [44] 0x182DE1818

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<CryStringT<char>>> m_filters;               // +0x88
    std::vector<CryStringT<char>> m_enabledFilters;             // +0xC8
};

static_assert(sizeof(C_FilterInput) == 0xE0,
              "C_FilterInput size mismatch");
static_assert(offsetof(C_FilterInput, m_filters) == 0x88,
              "C_FilterInput filters offset mismatch");
static_assert(offsetof(C_FilterInput, m_enabledFilters) == 0xC8,
              "C_FilterInput enabled filters offset mismatch");

} // namespace wh::playermodule
