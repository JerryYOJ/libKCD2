#pragma once
#include <cstddef>
#include <cstdint>
#include "C_DynamicLinkableObject.h"
#include "C_Ownership.h"

namespace wh::xgenaimodule {

class C_DynamicLinkableObjectWithOwnership : public C_DynamicLinkableObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DynamicLinkableObjectWithOwnership;
    ~C_DynamicLinkableObjectWithOwnership() override; // [0] 0x18096D6FC
    std::uint32_t GetTypeMask() override;              // [1] 0x1812F7A10
    I_Ownership* GetOwnership() override;              // [11] 0x181A7FAD0

    C_Ownership m_ownership; // +0x60
};
static_assert(sizeof(C_DynamicLinkableObjectWithOwnership) == 0x90,
              "C_DynamicLinkableObjectWithOwnership must be 0x90");
static_assert(offsetof(C_DynamicLinkableObjectWithOwnership, m_ownership) == 0x60,
              "ownership component must be at 0x60");

}  // namespace wh::xgenaimodule
