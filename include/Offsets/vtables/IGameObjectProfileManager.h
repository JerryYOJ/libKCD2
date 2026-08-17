#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryAction/GameObjectTypes.h"
#include "../../framework/C_Signal.h"

namespace Offsets {

struct IEntity;

using S_ProfileChangedDelegate = wh::shared::S_Delegate<
    IEntity*,
    EEntityAspects,
    std::uint8_t,
    std::uint8_t>;

// KCD2 binary-facing profile-manager interface. Slots [4]/[5] manage the
// entity/aspect/old-profile/new-profile change delegate.
class IGameObjectProfileManager {
public:
    virtual ~IGameObjectProfileManager() = default;                   // [0]
    virtual bool SetAspectProfile(EEntityAspects aspect,
                                  std::uint8_t profile) = 0;           // [1]
    virtual std::uint8_t GetDefaultProfile(EEntityAspects aspect) = 0; // [2]
    virtual std::uint8_t GetAspectProfile(
        EEntityAspects aspect) const = 0;                              // [3]
    virtual void ConnectProfileChanged(
        const S_ProfileChangedDelegate& delegate) = 0;                 // [4]
    virtual void DisconnectProfileChanged(
        const S_ProfileChangedDelegate& delegate) = 0;                 // [5]
};
static_assert(sizeof(IGameObjectProfileManager) == 0x08,
              "IGameObjectProfileManager must be 0x08");

}  // namespace Offsets
