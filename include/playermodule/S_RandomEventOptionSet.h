#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::playermodule {

struct S_RandomEventOption;

struct S_RandomEventOptionSet {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    std::vector<S_RandomEventOption*> m_options;          // +0x08 accessor-backed "Options"
};

static_assert(sizeof(S_RandomEventOptionSet) == 0x20,
              "S_RandomEventOptionSet size mismatch");

}  // namespace wh::playermodule
