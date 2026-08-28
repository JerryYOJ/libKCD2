#pragma once
#include "Foo.h"

namespace wh::tests {

class Bar : public Foo {
public:
    ~Bar() override;                                        // [0] 0x1824126B4
    int unk_01() override;                                  // [1] 0x181A724F0, returns 5
    RTTR_ENABLE(Foo)                                         // [2..4]
};

static_assert(sizeof(Bar) == 0x08, "Bar size mismatch");

}  // namespace wh::tests
