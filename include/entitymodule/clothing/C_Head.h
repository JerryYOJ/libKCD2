#pragma once

#include "C_Component.h"

namespace wh::entitymodule::clothing {

class C_Head : public C_Component {
public:
    ~C_Head() override;                                  // [0] 0x18291721C
    std::shared_ptr<C_Component> Clone() const override; // [1] 0x181E96160
    const CryStringT<char>& GetName() const override;    // [2] 0x181A71D30
    bool unk_04() const override;                        // [4] 0x18152A284
    const void* unk_09() const override;                 // [9] 0x181718390
    RTTR_ENABLE(C_Component)                              // [12..14], vtable 0x183B6B5D8
};

static_assert(sizeof(C_Head) == 0x120,
              "C_Head size mismatch");

}  // namespace wh::entitymodule::clothing
