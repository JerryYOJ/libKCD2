#pragma once
#include <cstddef>
#include <cstdint>

struct RChunk {
    std::uint32_t m_firstIndexId;
    std::uint32_t m_numIndices;
};

static_assert(sizeof(RChunk) == 0x08, "RChunk size mismatch");
