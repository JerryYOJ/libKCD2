#pragma once
#include "C_AIPuppet.h"

namespace wh::xgenaimodule {

// SmartObject-side leaf created only by 0x180A2A308. It adds no data and its
// binary vtable contains the same 25 function addresses as C_AIPuppet.
class C_SOPuppet : public C_AIPuppet {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SOPuppet;
};
static_assert(sizeof(C_SOPuppet) == 0x48,
              "C_SOPuppet must add no data to C_AIPuppet");

}  // namespace wh::xgenaimodule
