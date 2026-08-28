#pragma once
#include "../rttr/rttr_enable.h"

namespace wh::tests {

class Foo {
public:
    virtual ~Foo();                                         // [0] 0x1824126F4
    virtual int unk_01();                                   // [1] 0x181A72500, returns 4
    RTTR_ENABLE()                                            // [2..4]
};

static_assert(sizeof(Foo) == 0x08, "Foo size mismatch");

}  // namespace wh::tests
