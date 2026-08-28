#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::conceptmodule {

#pragma pack(push, 1)
struct S_ConceptResourceResolverEntry {
    std::uint64_t m_value; // +0x00, encoded resource pointer/free-list link
    std::uint8_t m_state;  // +0x08, free bit and generation
};
#pragma pack(pop)

static_assert(sizeof(S_ConceptResourceResolverEntry) == 0x09,
              "S_ConceptResourceResolverEntry size mismatch");

}  // namespace wh::conceptmodule
