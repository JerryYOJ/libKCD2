#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include <vector>
#include <memory>
#include "C_CustomOperator.h"
#include "C_CustomSelector.h"
#include "C_Rule.h"

namespace wh::rpgmodule::storm {
class C_Source {
public:
    virtual ~C_Source();
    virtual void unk_01();
    virtual void unk_02();
    RTTR_ENABLE()  // [3..5]
    std::vector<std::shared_ptr<C_CustomSelector>> m_customSelectors;  // +0x8 RTTR "customSelectors"
    std::vector<std::shared_ptr<C_CustomOperator>> m_customOperations;  // +0x20 RTTR "customOperations"
    CryStringT<char> m_path;  // +0x38 RTTR "path"
    std::vector<C_Rule> m_rules;  // +0x40 RTTR "rules"
    std::uint8_t m_unknown58[0x8];                  // +0x58
};

static_assert(offsetof(C_Source, m_rules) == 0x40, "C_Source::m_rules offset mismatch");
static_assert(offsetof(C_Source, m_path) == 0x38, "C_Source::m_path offset mismatch");
static_assert(offsetof(C_Source, m_customOperations) == 0x20, "C_Source::m_customOperations offset mismatch");
static_assert(offsetof(C_Source, m_customSelectors) == 0x8, "C_Source::m_customSelectors offset mismatch");
static_assert(sizeof(C_Source) == 0x60, "C_Source size mismatch");

}  // namespace wh::rpgmodule::storm
