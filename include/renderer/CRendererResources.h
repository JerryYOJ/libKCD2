#pragma once
#include <cstddef>

class CRendererResources {
};

static_assert(sizeof(CRendererResources) == 0x01,
              "CRendererResources must remain an empty base");
