#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::conceptmodule::C_SharedResource -- refcounted node-graph resource root
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Root of the conceptmodule node graph (C_Node, I_Port, rpgmodule::C_BuffEffect, ...); the
// rttr reflection layer passes these as _smart_ptr<C_SharedResource>.  Layout from the inlined
// base init in sub_1806B28F0 / sub_1806B2850: +0x08 unique id pulled from the id service
// (module-registry+0x120 object -> +0x18 -> +0x10, vfunc[3]); +0x0C..+0x0F zeroed, with the
// word at +0x0E used as flag bits by C_AutoTriggerable (bit 1).  addref/release pair
// sub_181E38F20 / sub_181E39320.

namespace wh::conceptmodule {

class C_SharedResource {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SharedResource;
    virtual ~C_SharedResource();   // slot layout not yet mapped

    int32_t  m_resourceId;   // +0x08  from the global id counter service
    uint16_t m_refCount;     // +0x0C  [split of the zeroed dword INFERRED from +0x0E flag use]
    uint16_t m_flags;        // +0x0E  bit 1 = auto-triggerable (set by C_AutoTriggerable ctor)
};
static_assert(sizeof(C_SharedResource) == 0x10, "C_SharedResource must be 0x10");

}  // namespace wh::conceptmodule
