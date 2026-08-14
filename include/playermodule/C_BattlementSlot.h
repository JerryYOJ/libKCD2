#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "I_BattlementSlot.h"

namespace wh::playermodule {

class C_BattlementSlot : public I_BattlementSlot {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_BattlementSlot;

    EntityId GetBattlementEntityId() const override; // [0] 0x181A72970
    std::uint32_t GetSlotIndex() const override;     // [1] 0x181A73F90
    ~C_BattlementSlot() override;                    // [2] 0x180DCB4E0

    EntityId m_battlementEntityId;       // +0x08
    Vec3 m_position;                     // +0x0C
    Vec3 m_normal;                       // +0x18, horizontal segment perpendicular
    Vec2i m_gridCell;                    // +0x24, initialized {-1, -1}
    std::uint32_t m_slotIndex;           // +0x2C
    EntityId m_occupantEntityId;         // +0x30
    EntityId m_reservationEntityId;      // +0x34
};
static_assert(sizeof(C_BattlementSlot) == 0x38,
              "C_BattlementSlot must be 0x38");
static_assert(offsetof(C_BattlementSlot, m_battlementEntityId) == 0x08,
              "Battlement EntityId must be at 0x08");
static_assert(offsetof(C_BattlementSlot, m_gridCell) == 0x24,
              "regular-grid cell must be at 0x24");
static_assert(offsetof(C_BattlementSlot, m_slotIndex) == 0x2C,
              "local slot index must be at 0x2C");

}  // namespace wh::playermodule
