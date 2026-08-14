#pragma once
#include <cstddef>
#include "../Offsets/Offsets_RTTI.h"

// -----------------------------------------------
// wh::entitymodule::I_DocumentActionListener -- document UI callback interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08.
// -----------------------------------------------
// C_OpenBookAction embeds this interface at +0x68. Its certified table has
// exactly three parameterless callbacks and no virtual destructor.

namespace wh::entitymodule {

class I_DocumentActionListener {
public:
    inline static constexpr auto RTTI =
        Offsets::RTTI_I_DocumentActionListener;

    virtual void _vf0() = 0;  // [0] 0x180A96158, page-direction callback; source name OPEN
    virtual void _vf1() = 0;  // [1] 0x182E17BD8, opposite page-direction callback; source name OPEN
    virtual void _vf2() = 0;  // [2] 0x18192ACA0, document-detail refresh; source name OPEN
};
static_assert(sizeof(I_DocumentActionListener) == 0x08,
              "I_DocumentActionListener must contain only its vptr");

}  // namespace wh::entitymodule
