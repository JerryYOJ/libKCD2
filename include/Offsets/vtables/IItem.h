#pragma once
#include <cstddef>
#include <cstdint>
#include "IGameObjectExtension.h"
#include "../../CryEngine/CryCommon/ActionId.h"
#include "../../CryEngine/CryCommon/Cry_Math.h"

typedef unsigned int EntityId;

struct IActionController;
struct IEntityClass;
struct IInventory;
struct IWeapon;
struct SViewParams;

namespace Offsets {

// KCD2 binary-facing IItem order. Interfuscator places the KCD2-only slot at
// [69]; the remaining CryAction item methods resume at [70].
class IItem : public IGameObjectExtension {
public:
    virtual const char* GetType() const = 0;                           // [29]
    virtual EntityId GetOwnerId() const = 0;                           // [30]
    virtual void SetOwnerId(EntityId ownerId) = 0;                     // [31]
    virtual void EnableUpdate(bool enable, int slot = -1) = 0;         // [32]
    virtual void RequireUpdate(int slot) = 0;                          // [33]
    virtual void ForcePendingActions(std::uint8_t blockedActions = 0) = 0; // [34]
    virtual void OnAction(EntityId actorId,
                          const ActionId& actionId,
                          int activationMode,
                          float value) = 0;                            // [35]
    virtual void OnParentSelect(bool select) = 0;                      // [36]
    virtual void OnAttach(bool attach) = 0;                            // [37]
    virtual void OnPickedUp(EntityId actorId, bool destroyed) = 0;     // [38]
    virtual void OnHit(float damage, int hitType) = 0;                 // [39]
    virtual void Select(bool select) = 0;                              // [40]
    virtual bool IsSelected() const = 0;                               // [41]
    virtual bool CanSelect() const = 0;                                // [42]
    virtual bool CanDeselect() const = 0;                              // [43]
    virtual void RemoveOwnerAttachedAccessories() = 0;                 // [44]
    virtual void Physicalize(bool enable, bool rigid) = 0;             // [45]
    virtual bool CanDrop() const = 0;                                  // [46]
    virtual void Drop(float impulseScale = 1.0f,
                      bool selectNext = true,
                      bool byDeath = false) = 0;                       // [47]
    virtual void UpdateFPView(float frameTime) = 0;                    // [48]
    virtual Vec3 GetMountedAngleLimits() const = 0;                    // [49]
    virtual void PickUp(EntityId picker,
                        bool sound,
                        bool select = true,
                        bool keepHistory = true,
                        const char* setup = nullptr) = 0;              // [50]
    virtual void MountAtEntity(EntityId entityId,
                               const Vec3& pos,
                               const Ang3& angles) = 0;                // [51]
    virtual bool FilterView(SViewParams& viewParams) = 0;              // [52]
    virtual void RemoveAllAccessories() = 0;                           // [53]
    virtual void DetachAllAccessories() = 0;                           // [54]
    virtual void AttachAccessory(IEntityClass* entityClass,
                                 bool attach,
                                 bool noAnimation,
                                 bool force = false,
                                 bool firstTimeAttached = false,
                                 bool initialLoadoutSetup = false) = 0; // [55]
    virtual void SetCurrentActionController(
        IActionController* actionController) = 0;                      // [56]
    virtual void UpdateCurrentActionController() = 0;                  // [57]
    virtual CryStringT<char> GetAttachedAccessoriesString() = 0;       // [58]
    virtual void SetHand(int hand) = 0;                                // [59]
    virtual void StartUse(EntityId userId) = 0;                        // [60]
    virtual void StopUse(EntityId userId) = 0;                         // [61]
    virtual void SetBusy(bool busy) = 0;                               // [62]
    virtual bool IsBusy() const = 0;                                   // [63]
    virtual bool CanUse(EntityId userId) const = 0;                    // [64]
    virtual bool IsUsed() const = 0;                                   // [65]
    virtual void Use(EntityId userId) = 0;                             // [66]
    virtual bool AttachToHand(bool attach,
                              bool checkAttachment = false) = 0;       // [67]
    virtual bool AttachToBack(bool attach) = 0;                        // [68]
    virtual bool _vf69(IEntity* entity, std::uint16_t slot) = 0;       // [69], role/name OPEN
    virtual bool IsModifying() const = 0;                              // [70]
    virtual bool CheckAmmoRestrictions(IInventory* inventory) = 0;     // [71]
    virtual void Reset() = 0;                                         // [72]
    virtual bool ResetParams() = 0;                                   // [73]
    virtual void PreResetParams() = 0;                                // [74]
    virtual bool GivesAmmo() = 0;                                     // [75]
    virtual const char* GetDisplayName() const = 0;                    // [76]
    virtual void HideItem(bool hide) = 0;                              // [77]
    virtual void SetSubContextID(int tagContext) = 0;                  // [78]
    virtual int GetSubContextID() = 0;                                // [79]
    virtual const IWeapon* GetIWeaponConst() const = 0;                // [80], de-overloaded
    virtual IWeapon* GetIWeaponMutable() = 0;                          // [81], de-overloaded
    virtual bool IsAccessory() = 0;                                   // [82]
    virtual void SerializeLTL(TSerialize serializer) = 0;              // [83]
    virtual Vec3 GetMountedDir() const = 0;                            // [84]
};
static_assert(sizeof(IItem) == 0x40, "IItem must be 0x40");

}  // namespace Offsets
