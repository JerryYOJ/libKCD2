#pragma once

#include "C_Component.h"

namespace wh::entitymodule::clothing {

class C_Beard : public C_Component {
public:
    ~C_Beard() override;                                 // [0] 0x18291721C
    std::shared_ptr<C_Component> Clone() const override; // [1] 0x181E95F70
    const CryStringT<char>& GetName() const override;    // [2] 0x181A71D30
    bool unk_04() const override;                        // [4] 0x18152A284
    bool unk_06() const override;                        // [6] 0x18041A6A0
    const void* unk_09() const override;                 // [9] 0x181781E40
    RTTR_ENABLE(C_Component)                              // [12..14], vtable 0x183BB13B8
};

static_assert(sizeof(C_Beard) == 0x120,
              "C_Beard size mismatch");

}  // namespace wh::entitymodule::clothing
