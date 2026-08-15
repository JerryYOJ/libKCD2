#pragma once
#include <cstdint>
#include <functional>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/Offsets_RTTI.h"
#include "../Offsets/vtables/IEntity.h"

struct IAnimatedCharacter;
struct ICharacterInstance;
struct ISkeletonAnim;
class CAnimation;
class IActionController;
class IScope;

namespace Offsets {
class IActor;
}

namespace wh::animationmodule {

struct S_LODAnimationControllerData;
struct S_LODScope;

// Native vptr-only interface. It has no virtual destructor in the KCD2 table.
class I_LODAnimationController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_LODAnimationController;

    virtual Offsets::IEntity* GetEntity() = 0;                             // [0] 0x180685D74
    virtual Offsets::IActor* GetActorById(EntityId entityId) = 0;          // [1] 0x180AA70B4
    virtual Offsets::IActor* GetOwnerActor() = 0;                          // [2] 0x1827D211C
    virtual IAnimatedCharacter* GetAnimatedCharacter() = 0;               // [3] 0x180685CAC
    virtual IAnimatedCharacter* GetCachedAnimatedCharacter() = 0;         // [4] 0x181A7F940
    virtual ICharacterInstance* GetCharacterById(EntityId entityId) = 0;  // [5] 0x180AA7254
    virtual ICharacterInstance* GetCharacter() = 0;                       // [6] 0x180ADD7B0
    virtual ISkeletonAnim* GetSkeletonAnimById(EntityId entityId) = 0;    // [7] 0x180AA72A4
    virtual ISkeletonAnim* GetSkeletonAnim() = 0;                         // [8] 0x180ADD778
    virtual IActionController* GetActionController() = 0;                 // [9] 0x18083D2CC
    virtual S_LODAnimationControllerData* GetData10() = 0;                // [10] 0x181A72EB0, source ptr/ref form OPEN
    virtual const S_LODAnimationControllerData* GetData11() const = 0;    // [11] 0x181A72EB0, overload order OPEN
    virtual bool IsEnabled() const = 0;                                   // [12] 0x181A751C0
    virtual bool IsPaused() const = 0;                                    // [13] 0x18083D0A4
    virtual void InvokeGuarded(const std::function<void()>& callback) = 0; // [14] 0x181E5A980, source ref constness OPEN
    virtual void ApplyDeferredEnableUpdate() = 0;                         // [15] 0x181E5AC70
    virtual float _vf16(IScope* scope, std::uint32_t layer,
                        std::int32_t animationIndex) = 0;                  // [16] 0x180AA7670, pointer/reference form OPEN
    virtual float _vf17(const CAnimation* animation) = 0;                  // [17] 0x180AA7714, pointee constness OPEN
    virtual float _vf18(IScope* scope) = 0;                               // [18] 0x180AA7308, pointer/reference form OPEN
    virtual void _vf19(S_LODScope* lodScope, IScope* scope) = 0;          // [19] 0x1804AE2A0, pointer/reference form OPEN
    virtual void SuppressRootMotion() = 0;                                // [20] 0x1813CB480
    virtual bool _vf21() const = 0;                                       // [21] false stub
    virtual void _vf22() = 0;                                             // [22] nullsub
};
static_assert(sizeof(I_LODAnimationController) == 0x08,
              "I_LODAnimationController must be vptr-only");

}  // namespace wh::animationmodule
