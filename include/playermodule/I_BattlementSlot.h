#pragma once
#include <cstdint>
#include "../Offsets/vtables/IEntity.h"

namespace wh::playermodule {

class I_BattlementSlot {
public:
    virtual EntityId GetBattlementEntityId() const = 0; // [0], name reconstructed
    virtual std::uint32_t GetSlotIndex() const = 0;     // [1], name reconstructed
    virtual ~I_BattlementSlot();                        // [2]
};
static_assert(sizeof(I_BattlementSlot) == 0x08,
              "I_BattlementSlot must be vptr-only");

}  // namespace wh::playermodule
