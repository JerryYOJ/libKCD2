#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include "S_SmartHelperCategory.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

class C_SmartHelper;

// Synthetic source-like name: the native non-polymorphic type has no surviving RTTI name.
struct S_SmartHelperClassDefinition {
    std::uint8_t m_sourceKind;                          // +0x00, values 0/1/2
    std::uint8_t _pad01[7];                             // +0x01
    std::vector<C_SmartHelper*> m_helpers;              // +0x08, owns pointees
    std::vector<S_SmartHelperCategory> m_categories;    // +0x20, borrowed helper index
    std::unordered_map<CryStringT<char>, std::size_t>
        m_helperIndices;                                // +0x38
    std::uint8_t _unknown78[0x50];                      // +0x78, runtime caches
};
static_assert(sizeof(S_SmartHelperClassDefinition) == 0xC8,
              "S_SmartHelperClassDefinition must be 0xC8");
static_assert(offsetof(S_SmartHelperClassDefinition, m_helpers) == 0x08,
              "helper vector must be at 0x08");
static_assert(offsetof(S_SmartHelperClassDefinition, m_helperIndices) == 0x38,
              "helper index must be at 0x38");

}  // namespace wh::xgenaimodule
