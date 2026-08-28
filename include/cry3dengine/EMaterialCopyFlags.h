#pragma once
#include <cstdint>

enum EMaterialCopyFlags : std::int32_t {
    MTL_COPY_DEFAULT = 0,
    MTL_COPY_NAME = 1 << 0,
    MTL_COPY_TEMPLATE = 1 << 1,
    MTL_COPY_TEXTURES = 1 << 2,
};

static_assert(sizeof(EMaterialCopyFlags) == 0x04,
              "EMaterialCopyFlags size mismatch");
