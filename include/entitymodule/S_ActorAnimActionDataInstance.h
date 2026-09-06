#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::S_ActorAnimActionDataInstance -- by-value return of
// C_AnimActionBase::GetAnimActionData (slot 46). sizeof 0x74; ctor 0x18039ED14.
// (KCD2 WHGame.dll Steam 1.5.6.) [RTTI: factory template arg + _Func_base
// 0x184B94530; field layout pending writer tracing]
// -----------------------------------------------

namespace wh::entitymodule {

struct S_ActorAnimActionDataInstance {
    std::uint8_t _opaque[0x74];   // +0x00 ctor writes through +0x70
};

static_assert(sizeof(S_ActorAnimActionDataInstance) == 0x74,
              "S_ActorAnimActionDataInstance size mismatch");

}  // namespace wh::entitymodule
