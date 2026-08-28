#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

#include "../../rttr/type.h"

namespace wh::entitymodule::clothing {

struct S_CharacterComponentQuery {
    bool operator<(const S_CharacterComponentQuery& rhs) const;

    rttr::type m_componentType;                    // +0x00
    void* m_context;                               // +0x08, exact interface type unresolved
    bool m_flag10;                                 // +0x10
    std::uint8_t m_padding11[7];                   // +0x11
    std::array<CryStringT<char>, 3> m_names;       // +0x18
    std::int32_t m_value30;                        // +0x30
    bool m_flag34;                                 // +0x34
    bool m_flag35;                                 // +0x35
    std::uint8_t m_padding36[2];                   // +0x36
    std::int32_t m_value38;                        // +0x38
    std::uint32_t m_padding3C;                     // +0x3C
};

static_assert(offsetof(S_CharacterComponentQuery, m_context) == 0x08,
              "S_CharacterComponentQuery::m_context offset mismatch");
static_assert(offsetof(S_CharacterComponentQuery, m_names) == 0x18,
              "S_CharacterComponentQuery::m_names offset mismatch");
static_assert(offsetof(S_CharacterComponentQuery, m_value38) == 0x38,
              "S_CharacterComponentQuery::m_value38 offset mismatch");
static_assert(sizeof(S_CharacterComponentQuery) == 0x40,
              "S_CharacterComponentQuery size mismatch");

} // namespace wh::entitymodule::clothing
