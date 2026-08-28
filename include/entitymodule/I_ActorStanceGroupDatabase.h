#pragma once
#include <cstddef>

namespace wh::entitymodule {

class C_ActorStanceGroupData;

class I_ActorStanceGroupDatabase {
public:
    virtual const C_ActorStanceGroupData* FindOrDefault(
        const CryStringT<char>& name) const = 0; // [0] 0x1828B341C
};

static_assert(sizeof(I_ActorStanceGroupDatabase) == 0x08,
              "I_ActorStanceGroupDatabase size mismatch");

} // namespace wh::entitymodule
