#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace wh::rpgmodule::storm {

class C_Rule;
struct S_StormDebugRuleRecord;

class C_StormDebug {
public:
    C_StormDebug();
    ~C_StormDebug();

    std::vector<const C_Rule*> GetMatchedRules() const;       // 0x182DAB3BC

    std::uint8_t m_runtime00[0x10];                           // +0x00
    std::vector<S_StormDebugRuleRecord>* m_ruleRecords;       // +0x10
    std::uint8_t m_runtime18[0x30 - 0x18];                   // +0x18
};

static_assert(offsetof(C_StormDebug, m_ruleRecords) == 0x10,
              "C_StormDebug rule-record offset mismatch");
static_assert(sizeof(C_StormDebug) == 0x30,
              "C_StormDebug size mismatch");

} // namespace wh::rpgmodule::storm
