#pragma once
#include <cstddef>

namespace wh::playermodule {

struct S_RandomEventTagDBData {
    const char* m_name;                                        // +0x00 Name
};

static_assert(sizeof(S_RandomEventTagDBData) == 0x08,
              "S_RandomEventTagDBData size mismatch");

} // namespace wh::playermodule
