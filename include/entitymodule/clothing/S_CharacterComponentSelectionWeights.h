#pragma once
#include <cstddef>
#include <vector>

namespace wh::entitymodule::clothing {

struct S_CharacterComponentSelectionWeights {
    std::vector<double> m_probabilities; // +0x00
    std::vector<double> m_cumulative;    // +0x18
};

static_assert(offsetof(S_CharacterComponentSelectionWeights, m_cumulative) == 0x18,
              "S_CharacterComponentSelectionWeights::m_cumulative offset mismatch");
static_assert(sizeof(S_CharacterComponentSelectionWeights) == 0x30,
              "S_CharacterComponentSelectionWeights size mismatch");

} // namespace wh::entitymodule::clothing
