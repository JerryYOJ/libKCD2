#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::E_AddRemove -- add-vs-remove selector enum (KCD2 WHGame.dll
// 1.5.6, kd7u).
// -----------------------------------------------
// Known only as a template argument (nested E_AddRemove::Type):
// C_AreaLabelManager : framework::C_OverrideConflictManager<S_AreaLabelHandle,
// E_AddRemove::Type> and the C_AreaLabelEffect add/remove port
// C_TypedPortRef<E_AddRemove::Type>.  Enumerator values RESOLVED 2026-08-05 from the
// RTTR enum registration (reg fn 0x180248400, analysis/rttr/enum_registry_kcd2.json);
// underlying type assumed int32.

namespace wh::xgenaimodule {

struct E_AddRemove {
    enum Type : int32_t { Remove = 0, Add = 1 };
};

}  // namespace wh::xgenaimodule
