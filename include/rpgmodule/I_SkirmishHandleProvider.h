#pragma once
#include <cstddef>

namespace wh::rpgmodule {

class I_SkirmishHandle;

class I_SkirmishHandleProvider {
public:
    virtual ~I_SkirmishHandleProvider() = default;                  // [0]
    virtual I_SkirmishHandle* CreateHandle() = 0;                   // [1]
};

static_assert(sizeof(I_SkirmishHandleProvider) == 0x08,
              "I_SkirmishHandleProvider size mismatch");

} // namespace wh::rpgmodule
