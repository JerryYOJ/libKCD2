#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_AngrinessChangeDefinitionID
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 4. No vtable.
// -----------------------------------------------
// Strong integer id: type-data sizeof 4, RTTR string converter.

namespace wh {
namespace rpgmodule {

struct S_AngrinessChangeDefinitionID {
    std::int32_t m_id;                                            // +0x00
};

static_assert(offsetof(S_AngrinessChangeDefinitionID, m_id) == 0x00,
              "S_AngrinessChangeDefinitionID::m_id offset mismatch");
static_assert(sizeof(S_AngrinessChangeDefinitionID) == 4,
              "S_AngrinessChangeDefinitionID size mismatch");

}  // namespace rpgmodule
}  // namespace wh
