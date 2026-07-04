#pragma once
#include <cstdint>
#include "C_AutoTriggerable.h"
#include "C_Node.h"
#include "C_TypedPortRef.h"

// -----------------------------------------------
// wh::conceptmodule::C_Effect -- concept-graph effect node (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// NOT the rpgmodule effect system: this is conceptmodule's PARALLEL effect hierarchy built on
// the rttr node graph (C_SharedResource -> C_Node -> C_AutoTriggerable<C_Node> -> here).
// Ctor sub_1806B19C0: node chain, own vftable, C_TypedPortRef<bool> @+0x40 (enabled port),
// byte 0 @+0x80.  sizeof 0x88 (PROVEN: derived C_BuffEffect/C_TemporaryFactionEffect members
// start at +0x88).

namespace wh::conceptmodule {

class C_Effect : public C_AutoTriggerable<C_Node> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_conceptmodule_C_Effect;
    C_TypedPortRef<bool> m_enabledPort;   // +0x40  [port role INFERRED from <bool> type]
    uint8_t m_flag80;                     // +0x80  ctor 0 [role UNVERIFIED]
    uint8_t _pad81[7];                    // +0x81
};
static_assert(sizeof(C_Effect) == 0x88, "conceptmodule::C_Effect must be 0x88");

}  // namespace wh::conceptmodule
