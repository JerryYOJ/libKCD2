#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

#include "../../rttr/type.h"

namespace wh::entitymodule::clothing {

struct S_CharacterComponentCacheKey {
    std::array<std::uint8_t, 0x10> m_identity; // +0x00, exact identity type unresolved
    rttr::type m_componentType;                // +0x10
    CryStringT<char> m_name;                   // +0x18
};

static_assert(offsetof(S_CharacterComponentCacheKey, m_componentType) == 0x10,
              "S_CharacterComponentCacheKey::m_componentType offset mismatch");
static_assert(offsetof(S_CharacterComponentCacheKey, m_name) == 0x18,
              "S_CharacterComponentCacheKey::m_name offset mismatch");
static_assert(sizeof(S_CharacterComponentCacheKey) == 0x20,
              "S_CharacterComponentCacheKey size mismatch");

} // namespace wh::entitymodule::clothing
