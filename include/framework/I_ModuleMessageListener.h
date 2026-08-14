#pragma once
#include <cstddef>
#include "../Offsets/Offsets_RTTI.h"

namespace wh::framework {

class I_ModuleMessageListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ModuleMessageListener;
    virtual ~I_ModuleMessageListener() = default; // [0]
    virtual void OnModuleMessage(void* message) = 0; // [1]
};
static_assert(sizeof(I_ModuleMessageListener) == 0x08,
              "I_ModuleMessageListener must be 0x08");

}  // namespace wh::framework
