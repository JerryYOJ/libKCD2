#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::conceptmodule {

class C_Resource {
public:
    virtual ~C_Resource();                                // [0]
    virtual void OnBeforeSerialization()= 0; // [1]
    virtual void OnAfterSerialization()= 0; // [2]
    virtual void OnBeforeDeserialization()= 0; // [3]
    virtual void OnAfterDeserialization()= 0; // [4]
    RTTR_ENABLE()                                         // [5..7]
};

static_assert(sizeof(C_Resource) == 0x08,
              "C_Resource size mismatch");

}  // namespace wh::conceptmodule
