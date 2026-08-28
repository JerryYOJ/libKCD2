#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::dialogmodule::data::S_VariableContextId
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 4. No vtable.
// -----------------------------------------------
// Strong integer id: type-data sizeof 4, RTTR string converter.

namespace wh {
namespace dialogmodule {
namespace data {

struct S_VariableContextId {
    std::int32_t m_id;                                            // +0x00
};

static_assert(offsetof(S_VariableContextId, m_id) == 0x00,
              "S_VariableContextId::m_id offset mismatch");
static_assert(sizeof(S_VariableContextId) == 4,
              "S_VariableContextId size mismatch");

}  // namespace data
}  // namespace dialogmodule
}  // namespace wh
