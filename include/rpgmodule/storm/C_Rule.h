#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include <vector>
#include <memory>
#include "I_Operator.h"
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_Rule {
public:
    RTTR_ENABLE()  // [0..2]
    std::uint8_t m_unknown08[0x8];                  // +0x8
    CryStringT<char> m_name;  // +0x10 RTTR "name"
    std::vector<std::shared_ptr<I_Operator>> m_operations;  // +0x18 RTTR "operations"
    std::vector<std::shared_ptr<I_Selector>> m_selectors;  // +0x30 RTTR "selectors"
    std::int32_t m_order;  // +0x48 RTTR "order"
    std::uint8_t m_unknown4C[0x4];                  // +0x4C
};

static_assert(offsetof(C_Rule, m_order) == 0x48, "C_Rule::m_order offset mismatch");
static_assert(offsetof(C_Rule, m_selectors) == 0x30, "C_Rule::m_selectors offset mismatch");
static_assert(offsetof(C_Rule, m_operations) == 0x18, "C_Rule::m_operations offset mismatch");
static_assert(offsetof(C_Rule, m_name) == 0x10, "C_Rule::m_name offset mismatch");
static_assert(sizeof(C_Rule) == 0x50, "C_Rule size mismatch");

}  // namespace wh::rpgmodule::storm
