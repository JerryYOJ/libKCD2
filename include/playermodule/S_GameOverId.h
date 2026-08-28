#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::S_GameOverId
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 4. No vtable.
// -----------------------------------------------
// Strong integer id: type-data sizeof 4, RTTR string converter.

namespace wh {
namespace playermodule {

struct S_GameOverId {
    std::int32_t m_id;                                            // +0x00
};

static_assert(offsetof(S_GameOverId, m_id) == 0x00,
              "S_GameOverId::m_id offset mismatch");
static_assert(sizeof(S_GameOverId) == 4,
              "S_GameOverId size mismatch");

}  // namespace playermodule
}  // namespace wh
