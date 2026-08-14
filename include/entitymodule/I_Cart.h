#pragma once
#include <cstddef>
#include <cstdint>
#include "S_CartDelegateToken.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/IGameObjectExtension.h"

namespace wh::entitymodule {

class I_Cart : public Offsets::IGameObjectExtension {
public:
    virtual std::uint8_t GetStateCode_29() const = 0;               // [29]
    virtual QuatT GetTransform_30() const = 0;                       // [30]
    virtual bool Operation_31(std::uint64_t argument1,
                              std::uint64_t argument2,
                              bool apply) = 0;                       // [31], argument types OPEN
    virtual bool QueryCandidate_32(std::uint64_t candidate) const = 0; // [32], argument type OPEN
    virtual void Operation_33() = 0;                                 // [33]
    virtual void SetStateFlag_34(bool enabled) = 0;                  // [34]
    virtual void SetFiveValue_35(std::uint8_t index,
                                 std::int32_t value) = 0;            // [35]
    virtual bool QueryLocalTransform_36(std::uint8_t selector,
                                        QuatT& result) = 0;          // [36]
    virtual bool QueryWorldTransform_37(std::uint8_t selector,
                                        QuatT& result) = 0;          // [37]
    virtual EntityId GetTwoEntityId_38(std::uint8_t index) const = 0; // [38]
    virtual EntityId GetSevenEntityId_39(std::uint8_t index) const = 0; // [39]
    virtual bool AcquireTwoSlot_40(Offsets::IGameObjectExtension* object,
                                   std::uint8_t index) = 0;          // [40]
    virtual bool AcquireSevenSlot_41(Offsets::IGameObjectExtension* object,
                                     std::uint8_t index) = 0;        // [41]
    virtual void ReleaseTwoSlot_42(std::uint8_t index) = 0;          // [42]
    virtual void ReleaseSevenSlot_43(std::uint8_t index) = 0;        // [43]
    virtual bool CanAcquireSevenSlot_44(
        std::uint8_t index,
        Offsets::IGameObjectExtension* object) const = 0;            // [44]
    virtual bool CanAcquireTwoSlot_45(std::uint8_t index) const = 0; // [45]
    virtual bool IsSevenSlot2Enabled_46() const = 0;                 // [46]
    virtual bool IsStateZero_47() const = 0;                         // [47]
    virtual void AdjustGateCount_48(bool acquire) = 0;              // [48], return type OPEN
    virtual void* GetSupportA8_49() = 0;                             // [49], pointee type OPEN
    virtual void* GetEmbeddedSupport_50() = 0;                       // [50], handle type OPEN
    virtual void AddCallback_51(const S_CartDelegateToken& token) = 0; // [51]
    virtual void RemoveCallback_52(const S_CartDelegateToken& token) = 0; // [52]
    virtual bool IsSevenStateOne_53(std::uint8_t index) const = 0;   // [53]
};

static_assert(sizeof(I_Cart) == 0x40,
              "I_Cart must be 0x40");

}  // namespace wh::entitymodule
