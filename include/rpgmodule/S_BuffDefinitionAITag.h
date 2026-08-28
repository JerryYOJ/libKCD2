#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::rpgmodule {

struct S_BuffDefinitionAITag {
    std::int32_t m_tag;                                   // +0x00
};

static_assert(sizeof(S_BuffDefinitionAITag) == 0x04,
              "S_BuffDefinitionAITag size mismatch");

}  // namespace wh::rpgmodule
