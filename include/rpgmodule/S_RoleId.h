#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_RoleId
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 2. No vtable.
// -----------------------------------------------
// Strong integer id: type-data sizeof 2, RTTR string converter (role_name).

namespace wh {
namespace rpgmodule {

struct S_RoleId {
    std::uint16_t m_id;                                            // +0x00
};

static_assert(offsetof(S_RoleId, m_id) == 0x00,
              "S_RoleId::m_id offset mismatch");
static_assert(sizeof(S_RoleId) == 2,
              "S_RoleId size mismatch");

}  // namespace rpgmodule
}  // namespace wh
