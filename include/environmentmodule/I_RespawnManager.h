#pragma once
#include <cstdint>
#include <unordered_map>
#include <vector>

// -----------------------------------------------
// wh::environmentmodule::I_RespawnManager -- pickable-area respawn interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08, four slots.
// -----------------------------------------------
// Interface vtable 0x183ED0608: deleting destructor plus three pure virtuals.
// C_RespawnManager vtable 0x183AB92A8 supplies all four implementations.

namespace Offsets { struct IEntity; }
namespace wh::xgenaimodule { class I_Area; }

namespace wh::environmentmodule {

class I_RespawnManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_RespawnManager;

    virtual ~I_RespawnManager(); // [0]
    virtual Offsets::IEntity* FindPickableArea(const Vec3& rayStart,
                                                const Vec3& rayEnd) = 0; // [1]
    virtual int32_t ConsumeSelectedPickableArea() = 0;                  // [2]
    virtual bool CollectPickableAreaCounts(
        wh::xgenaimodule::I_Area& area,
        const std::vector<uint8_t>& pickableAreaIds,
        std::unordered_map<uint8_t, uint32_t>& counts) = 0;             // [3] [SYNTHETIC NAME]
};
static_assert(sizeof(I_RespawnManager) == 0x08,
              "I_RespawnManager is a vptr-only four-slot interface");

}  // namespace wh::environmentmodule
