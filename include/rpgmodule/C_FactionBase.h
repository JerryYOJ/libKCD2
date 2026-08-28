#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "C_DebugReputationLog.h"

namespace wh::rpgmodule {

class C_Faction;

class C_FactionBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FactionBase;
    virtual ~C_FactionBase() = default;

    C_DebugReputationLog m_reputationLog;                       // +0x08
    std::weak_ptr<C_Faction> m_parent;                          // +0x50
    std::uint8_t m_runtime60[0x18];                            // +0x60
};

static_assert(sizeof(C_FactionBase) == 0x78,
              "C_FactionBase size mismatch");
static_assert(offsetof(C_FactionBase, m_reputationLog) == 0x08,
              "C_FactionBase reputation log offset mismatch");
static_assert(offsetof(C_FactionBase, m_parent) == 0x50,
              "C_FactionBase parent offset mismatch");
static_assert(offsetof(C_FactionBase, m_runtime60) == 0x60,
              "C_FactionBase runtime vector offset mismatch");

} // namespace wh::rpgmodule
