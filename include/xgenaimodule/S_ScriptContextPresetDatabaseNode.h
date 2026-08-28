#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "C_ScriptContextDatabase.h"

namespace wh::xgenaimodule {

struct S_ScriptContextPresetDatabaseNode {
    std::vector<S_ScriptContextDatabaseNode> m_contexts;                     // +0x00 accessor "Contexts"
    CryStringT<char> m_name;                                                 // +0x18 RTTR "Name"
    S_ScriptContextDatabaseNode::E_ContextClass m_class;                     // +0x20 RTTR "Class"
    std::uint8_t m_padding24[4];                                             // +0x24
};

static_assert(offsetof(S_ScriptContextPresetDatabaseNode, m_name) == 0x18,
              "S_ScriptContextPresetDatabaseNode::m_name offset mismatch");
static_assert(offsetof(S_ScriptContextPresetDatabaseNode, m_class) == 0x20,
              "S_ScriptContextPresetDatabaseNode::m_class offset mismatch");
static_assert(sizeof(S_ScriptContextPresetDatabaseNode) == 0x28,
              "S_ScriptContextPresetDatabaseNode size mismatch");

} // namespace wh::xgenaimodule
