#pragma once
#include <cstdint>
#include "C_PortRef.h"

// -----------------------------------------------
// wh::conceptmodule::C_TypedPortRef<T> -- typed port reference (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Instantiations seen: <bool> (conceptmodule::C_Effect enabled-port @+0x40),
// <rpgmodule::S_BuffDefinitionId> (C_BuffEffect @+0xC8),
// <rpgmodule::S_FactionDefinitionID> (C_TemporaryFactionEffect @+0xC8).  Embedded stride is
// 0x40 in every host (next member 0x40 after each port); the ctor writes nothing beyond the
// C_PortRef state, so the +0x38 tail qword is uninitialized [tail role UNVERIFIED -- typed
// value storage candidate; may simply be padding].

namespace wh::conceptmodule {

template <typename T>
class C_TypedPortRef : public C_PortRef {
public:
    _smart_ptr<C_SharedResource> m_boundValue;   // +0x38  bound resource; dtor sub_18266F018 Releases *(this+0x38) via C_SharedResource::Release when C_PortRef::m_flag30 (+0x30) set; set on bind, not at ctor
};

}  // namespace wh::conceptmodule
