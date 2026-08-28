#pragma once
#include <cstddef>

class CRendererCVars {
};

static_assert(sizeof(CRendererCVars) == 0x01,
              "CRendererCVars must remain an empty base");
