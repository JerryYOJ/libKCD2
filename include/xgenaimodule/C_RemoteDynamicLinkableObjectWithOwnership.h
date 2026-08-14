#pragma once
#include <cstdint>
#include "C_DynamicLinkableObjectWithOwnership.h"

namespace wh::xgenaimodule {

// Ownership-backed alternate selected when the holder's creation flag is true.
class C_RemoteDynamicLinkableObjectWithOwnership
    : public C_DynamicLinkableObjectWithOwnership {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RemoteDynamicLinkableObjectWithOwnership;
    ~C_RemoteDynamicLinkableObjectWithOwnership() override; // [0] 0x18096D5A8
    std::uint32_t GetTypeMask() override;                    // [1] 0x181440750
    bool _vf19() override;                                   // [19] 0x18041A6A0, true
};
static_assert(sizeof(C_RemoteDynamicLinkableObjectWithOwnership) == 0x90,
              "C_RemoteDynamicLinkableObjectWithOwnership must be 0x90");

}  // namespace wh::xgenaimodule
